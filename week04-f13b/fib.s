# - functions CANNOT permanently change $s registers
#	- however, they can store the original value somewhere
#	  else, then use the $s register however it wants, and then
#	  restore the original value right before returning

# we CANNOT make any assumptions about the contents
# of the $t registers
# other functions may COMPLETELY obliterate any $t registers
# other functions may also completely obliterate any $a registers



main:
	# Args: void
	#
	# Returns:
	#	- $v0: int
	#
	#
	# Registers:
	# - Frame:	[$ra]
	# - Uses:	[$v0, $a0, $t0]
	# - Clobbers: 	[$v0, $a0, $t0]
	#
	# Locals:
	#	- $t0: int n
	#
	# Structure:
	#  main
	#	-> [prologue]
	#	-> [body]
	#	-> [epilogue]


main__prologue:
	begin
	push	$ra

main__body:

	li	$v0, 4
	la	$a0, enter_number_msg
	syscall

	li	$v0, 5
	syscall
	move	$t0, $v0

	li	$v0, 4
	la	$a0, result_msg_1
	syscall

	li	$v0, 1
	move	$a0, $t0
	syscall

	li	$v0, 4
	la	$a0, result_msg_2
	syscall

	
	move	$a0, $t0
	jal	fib					# fib(n)

	move	$a0, $v0
	li	$v0, 1
	syscall						# printf("%d", fib(n));

	li	$v0, 11
	li	$a0, '\n'
	syscall

main__epilogue:
	pop	$ra
	end

	li	$v0, 0
	jr	$ra			# return 0;









fib:

	# Args:
	# 	- $a0: int n
	# Returns:
	#	- $v0: int
	#
	# Registers:
	# - Frame:	[$ra, $s0, $s1]
	# - Uses:	[$a0, $v0, $s0, $s1]	
	# - Clobbers:	[$a0, $v0]
	# 
	# Locals:
	#	- $s0: 	int n
	#	- $s1:	int fib(n - 1)
	#
	# Structure:
	# fib
	#	-> [prologue]
	#	-> [body]
	#		-> n_lt_2
	#	-> [epilogue]

fib__prologue:
	push	$ra
	push	$s0
	push	$s1

fib__body:
	move	$s0, $a0

	blt	$a0, 2, fib__n_lt_2

	addi	$a0, $s0, -1
	jal	fib

	move	$s1, $v0

	addi	$a0, $s0, -2
	jal	fib

	add	$v0, $s1, $v0				# fib(n - 1) + fib(n - 2)
	j	fib__epilogue


fib__n_lt_2:
	move	$v0, $a0


fib__epilogue:
	pop	$s1
	pop	$s0
	pop	$ra

	jr	$ra


	.data
enter_number_msg:
	.asciiz	"Enter a number: "
result_msg_1:
	.asciiz	"Fibonacci of "
result_msg_2:
	.asciiz	" is "
