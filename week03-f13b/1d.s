# Constants
N_ELEMENTS = 5


main:
	# Registers:
	#	$t0: int i
	#	$t1: intermediate value
	#	$t2: intermediate value
loop_i_to_N_ELEMENTS_init:
	li	$t0, 0							# int i = 0;
loop_i_to_N_ELEMENTS_cond:
	bge	$t0, N_ELEMENTS, loop_i_to_N_ELEMENTS_end		# if (i >= N_ELEMENTS) goto loop_i_to_N_ELEMENTS_end;
loop_i_to_N_ELEMENTS_body:
	# METHOD 1:
	# mul	$t1, $t0, 4						# 4 * i
	# lw	$a0, array($t1)						# array + 4 * i

	mul	$t1, $t0, 4						# 4 * i
	la	$t2, array						# array
	add	$t2, $t1, $t2						# array + 4 * i

	lw	$a0, ($t2)
	li	$v0, 1							# syscall 1: print_int
	syscall								# printf("%d", array[i]);    

	li	$v0, 11							# syscall 11: print_char
	la	$a0, '\n'						# 
	syscall						# putchar('\n');

	addi	$t0, $t0, 1
	
	j 	loop_i_to_N_ELEMENTS_cond						# i++;  (or, i = i + 1)

loop_i_to_N_ELEMENTS_end:

	li	$v0, 0
	jr	$ra							# return 0;

	.data

array:
	.word	3, 1, 4, 1, 5
