N_ELEMENTS = 5

main:
	# Registers:
	#       $t0: int i
	#       $t1: 4 * i
loop_scan_init:
	li      $t0, 0						# i = 0;
loop_scan_cond:
	bge     $t0, N_ELEMENTS, loop_scan_end			# if (i >= N_ELEMENTS) goto loop_scan_end;

loop_scan_body:
	li      $v0, 5						# syscall 5: read_int
	syscall							#
	mul     $t1, $t0, 4					# 4 * i
	sw      $v0, numbers($t1)				# scanf("%d", &numbers[i]);

	addi    $t0, $t0, 1					# i++;
	j       loop_scan_cond
loop_scan_end:

loop_print_init:
	li	$t0, 0						# int i = 0;
loop_print_cond:
	bge	$t0, N_ELEMENTS, loop_print_end			# if (i >= N_ELEMENTS) goto loop_print_end;
loop_print_body:
	mul	$t1, $t0, 4					# 4 * i
	lw	$a0, numbers($t1)				# numbers + 4 * i
	li	$v0, 1						# syscall 1: print_int
	syscall							# printf("%d", array[i]);    

	li	$v0, 11						# syscall 11: print_char
	la	$a0, '\n'					# 
	syscall							# putchar('\n');

	addi	$t0, $t0, 1					# i++;
	
	j 	loop_print_cond					

loop_print_end:

	li      $v0, 0
	jr      $ra						# return 0;
	

	.data
numbers:
	.word   0: N_ELEMENTS
