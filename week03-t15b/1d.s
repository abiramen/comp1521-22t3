N_ELEMENTS = 5


main:
	# Registers:
	#	- $t0: int i
	#	- $t1: intermediate value
	#	- $t2: intermediate value
	#	- $t3: intermediate value


loop_i_to_N_ELEMENTS_init:

	li	$t0, 0						# int i = -;

loop_i_to_N_ELEMENTS_cond:
	bge	$t0, N_ELEMENTS, loop_i_to_N_ELEMENTS_end
loop_i_to_N_ELEMENTS_body:

	# la	$t1, array					# array
	# mul	$t2, $t0, 4					# 4 * i
	# add 	$t2, $t2, $t1					# array + 4 * i

	# lw	$a0, ($t3)					#
	# li	$v0, 1						# syscall 1: print_int
	# syscall						# printf("%d", array[i]);

	mul	$t2, $t0, 4					# 4 * i
	lw	$a0, array($t2)					#
	li	$v0, 1						# syscall 1: print_int
	syscall							# printf("%d", array[i]);





	li	$v0, 11						# syscall 11: print_char
	la	$a0, '\n'					# 
	syscall							# putchar('\n');

	addi	$t0, $t0, 1					# i++;

	j 	loop_i_to_N_ELEMENTS_cond			# goto loop_i_to_N_ELEMENTS_cond

loop_i_to_N_ELEMENTS_end:



	li	$v0, 0
	jr	$ra						# return 0;

	.data

array:
	.word	3, 1, 4, 1, 5
