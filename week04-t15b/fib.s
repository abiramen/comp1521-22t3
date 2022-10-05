	.text
fib:
	# Args:
	#	- $a0: int n
	#
	# Returns:
	#	- $v0: int
	#
	# Registers:
	# - Frame:	[$ra, $s0, $s1]
	# - Uses:	[$v0, $a0, $s0, $s1]
	# - Clobbers:	[$v0, $a0]
	#
	# Locals:
	#	- $t0: int n
	#
	# Structure:
	# -> fib
	#	-> [prologue]
	#	-> [body]
	#		-> n_lt_2
	#		-> row_loop
	#	-> [epilogue]

fib__prologue:
	begin
	push	$ra
	push	$s0
	push	$s1

fib__body:
	move	$s0, $a0

	blt	$s0, 2, fib__n_lt_2			# if (n < 2) goto fib__n_lt_2;

	addi	$a0, $s0, -1				#
	jal	fib					#
	move	$s1, $v0				# fib(n - 1)


	addi	$a0, $s0, -2				#
	jal	fib					# fib(n - 2)

	add	$v0, $v0, $s1				# 
	j	fib__epilogue				# return fib(n - 1) + fib(n - 2)


fib__n_lt_2:
	move	$v0, $s0				# return n;	

fib__epilogue:

	pop	$s1
	pop	$s0
	pop	$ra
	end

	jr	$ra


	.text
main:
	# Args:
	#	- void
	#
	# Returns:
	#	- $v0: int
	#
	# Registers:
	# - Frame:	[$ra]
	# - Uses:	[$v0, $a0, $t0]
	# - Clobbers:	[$v0, $a0, $t0]
	#
	# Locals:
	#	- $t0: int n
	#
	# Structure:
	# -> main
	#	-> [prologue]
	#	-> [body]
	#	-> [epilogue]

main__prologue:
	begin
	push	$ra

main__body:

	li	$v0, 4				# syscall 4: print_string
	la	$a0, enter_number_msg		#
	syscall					# printf("Enter a number: ");

	li	$v0, 5				# syscall 5: read_int
	syscall					#
	move	$t0, $v0			# scanf("%d", &n);

	li	$v0, 4				# syscall 4: print_string
	la	$a0, result_msg_1		#
	syscall					# printf("Fibonacci of ");

	li	$v0, 1				# syscall 1: print_int
	move	$a0, $t0			#
	syscall					# printf("%d", n);

	li	$v0, 4				# syscall 4: print_string
	la	$a0, result_msg_2		#
	syscall					# printf(" is ");

	move	$a0, $t0
	jal	fib				# fib(n)


	move	$a0, $v0			#
	li	$v0, 1				# syscall 1: print_int
	syscall					# printf("%d", fib(n));

	li	$v0, 11				# syscall 11: print_char
	li	$a0, '\n'			#
	syscall					# putchar('\n');


main__epilogue:

	pop	$ra
	end

	li	$v0, 0
	jr	$ra				# return 0;




	.data
enter_number_msg:
	.asciiz	"Enter a number: "
result_msg_1:
	.asciiz "Fibonacci of "
result_msg_2:
	.asciiz " is "
