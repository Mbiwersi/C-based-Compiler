	.text	
	.globl		main
	j		main
function1:
	li		$v0, 4
	la		$a0, L1
	syscall	
	jr		$ra
function2:
	li		$v0, 4
	la		$a0, L2
	syscall	
	jr		$ra
function3:
	li		$v0, 4
	la		$a0, L3
	syscall	
	jr		$ra
main:
	jal		function1
	jal		function2
	jal		function3
	li		$v0, 10
	syscall	
	.data	
	.align		4
_nl:	.asciiz		"\n"
_space:	.asciiz		" "
_true:	.asciiz		"true"
_false:	.asciiz		"false"
L1:	.asciiz		"Function1 call\n"
L2:	.asciiz		"Function2 call\n"
L3:	.asciiz		"Function3 call\n"
