	.text	
	.globl		main
main:
	li		$t0, 10
	sw		$t0, num1
	li		$t0, 20
	sw		$t0, num2
	li		$t0, 13
	sw		$t0, num3
	li		$t0, 1
	sw		$t0, num4
	lw		$t0, num2
	li		$t1, 20
	add		$t2, $t0, $t1
	lw		$t0, num2
	add		$t1, $t2, $t0
	li		$t0, 3
	lw		$t2, num2
	mul		$t3, $t0, $t2
	seq		$t0, $t1, $t3
	beq		$zero, $t0, L1
	lw		$t1, num1
	li		$v0, 1
	move		$a0, $t1
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
L1:
	lw		$t1, num1
	lw		$t2, num2
	sub		$t3, $t1, $t2
	sw		$t3, num1
	lw		$t1, num2
	li		$t2, 4
	div		$t3, $t1, $t2
	sw		$t3, num2
	lw		$t1, num2
	li		$t2, 3
	div		$t3, $t1, $t2
	mfhi		$t3
	sw		$t3, num2
	lw		$t1, num3
	li		$t2, 5
	div		$t3, $t1, $t2
	mfhi		$t3
	sw		$t3, num3
	lw		$t1, num3
	mul		$t2, $t1, -1
	sw		$t2, num3
	lw		$t1, num3
	mul		$t2, $t1, -1
	sw		$t2, num3
	li		$t1, 2
	li		$t2, 7
	move		$t4, $t2
	move		$t5, $t1
	beq		$t4, $zero, L4
	sub		$t4, $t4, 1
L2:	beq		$t4, $zero, L3
	mul		$t5, $t5, $t1
	sub		$t4, $t4, 1
	j		L2
L4:	li		$t5, 1
L3:
	sw		$t5, num2
	lw		$t1, num2
	li		$t2, 0
	move		$t5, $t2
	move		$t6, $t1
	beq		$t5, $zero, L7
	sub		$t5, $t5, 1
L5:	beq		$t5, $zero, L6
	mul		$t6, $t6, $t1
	sub		$t5, $t5, 1
	j		L5
L7:	li		$t6, 1
L6:
	sw		$t6, num2
	li		$t1, 1
	li		$t2, 0
	slt		$t5, $t1, $t2
	sw		$t5, num4
	li		$t1, 0
	li		$t2, 1
	slt		$t5, $t1, $t2
	sw		$t5, num4
	lw		$t1, num4
	li		$t2, 1
	slt		$t5, $t1, $t2
	sw		$t5, num4
	li		$t1, 1
	sw		$t1, num5
	li		$t1, 0
	sw		$t1, num5
	li		$t1, 1
	li		$t2, 0
	slt		$t5, $t2, $t1
	sw		$t5, num5
	lw		$t1, num5
	sw		$t1, num4
	li		$t1, 1
	li		$t2, 1
	sle		$t5, $t1, $t2
	sw		$t5, num4
	li		$t1, 2
	li		$t2, 1
	sle		$t5, $t1, $t2
	sw		$t5, num4
	li		$t1, 0
	sw		$t1, num5
	li		$t1, 1
	li		$t2, 1
	sge		$t5, $t1, $t2
	sw		$t5, num5
	li		$t1, 1
	li		$t2, 2
	sge		$t5, $t1, $t2
	sw		$t5, num5
	li		$t1, 0
	sw		$t1, num5
	lw		$t1, num5
	li		$v0, 1
	move		$a0, $t1
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	li		$t1, 1
	li		$t2, 1
	seq		$t5, $t1, $t2
	sw		$t5, num5
	lw		$t1, num5
	li		$v0, 1
	move		$a0, $t1
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	li		$t1, 1
	li		$t2, 1
	sne		$t5, $t1, $t2
	sw		$t5, num5
	lw		$t1, num5
	li		$v0, 1
	move		$a0, $t1
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	li		$v0, 10
	syscall	
	.data	
	.align		4
_nl:	.asciiz		"\n"
num1:	.word		0
num2:	.word		0
num3:	.word		0
num4:	.word		0
num5:	.word		0
