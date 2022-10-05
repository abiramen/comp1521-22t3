
N_ROWS = 6
N_COLS = 12

main:

	# Locals:
	#	- $t0: int row
	#	- $t1: int col
	#	- $t2: temporary result

main__for_row_init:
	li	$t0, 0						# int row = 0;

main__for_row_cond:
	bge	$t0, N_ROWS, main__for_row_end			# if (row >= N_ROWS) goto main__for_row_end;

main__for_row_body:

main__for_col_init:
	li	$t1, 0						# int col = 0;

main__for_col_cond:
	bge	$t1, N_COLS, main__for_col_end			# if (col >= N_COLS) goto main__for_col_end;

main__for_col_body:
	mul     $t2, $t0, N_COLS				# (row * N_COLS
	add     $t2, $t2, $t1					# + col)
	mul     $t2, $t2, 1					# * sizeof(char)
	lb      $a0, flag($t2)					# = &flag[row][col]
								#
	li      $v0, 11                                         # syscall 11: print_char
	syscall							# printf("%c", flag[row][col]);


main__for_col_step:
	addi	$t1, $t1, 1					# col++;
	j	main__for_col_cond


main__for_col_end:
	li	$v0, 11						# syscall 11: print_char
	li	$a0, '\n'					#
	syscall							# putchar('\n');

main__for_row_step:
	addi	$t0, $t0, 1					# i++;
	j	main__for_row_cond

main__for_row_end:
	li      $v0, 0
	jr      $ra						# return 0;



	.data
flag:

	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
