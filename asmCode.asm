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
	lw		$t0, num1
	lw		$t1, num2
	sub		$t2, $t0, $t1
	sw		$t2, num1
	lw		$t0, num2
	li		$t1, 4
	div		$t2, $t0, $t1
	sw		$t2, num2
	lw		$t0, num2
	li		$t1, 3
	div		$t2, $t0, $t1
	mfhi		$t2
	sw		$t2, num2
	lw		$t0, num3
	li		$t1, 5
	div		$t2, $t0, $t1
	mfhi		$t2
	sw		$t2, num3
	lw		$t0, num3
	mul		$t1, $t0, -1
	sw		$t1, num3
	lw		$t0, num3
	mul		$t1, $t0, -1
	sw		$t1, num3
	li		$t0, 2
	li		$t1, 7
	move		$t3, $t1
	move		$t4, $t0
	beq		$t3, $zero, L4
	sub		$t3, $t3, 1
L2:	beq		$t3, $zero, L3
	mul		$t4, $t4, $t0
	sub		$t3, $t3, 1
	j		L2
L4:	li		$t4, 1
L3:
	sw		$t4, num2
	lw		$t0, num2
	li		$t1, 0
	move		$t4, $t1
	move		$t5, $t0
	beq		$t4, $zero, L7
	sub		$t4, $t4, 1
L5:	beq		$t4, $zero, L6
	mul		$t5, $t5, $t0
	sub		$t4, $t4, 1
	j		L5
L7:	li		$t5, 1
L6:
	sw		$t5, num2
	li		$t0, 1
	li		$t1, 0
	slt		$t4, $t0, $t1
	sw		$t4, num4
	li		$t0, 0
	li		$t1, 1
	slt		$t4, $t0, $t1
	sw		$t4, num4
	lw		$t0, num4
	li		$t1, 1
	slt		$t4, $t0, $t1
	sw		$t4, num4
	li		$t0, 1
	sw		$t0, num5
	li		$t0, 0
	sw		$t0, num5
	li		$t0, 1
	li		$t1, 0
	slt		$t4, $t1, $t0
	sw		$t4, num5
	lw		$t0, num5
	sw		$t0, num4
	li		$t0, 1
	li		$t1, 1
	sle		$t4, $t0, $t1
	sw		$t4, num4
	li		$t0, 2
	li		$t1, 1
	sle		$t4, $t0, $t1
	sw		$t4, num4
	li		$t0, 0
	sw		$t0, num5
	li		$t0, 1
	li		$t1, 1
	sge		$t4, $t0, $t1
	sw		$t4, num5
	li		$t0, 1
	li		$t1, 2
	sge		$t4, $t0, $t1
	sw		$t4, num5
	li		$t0, 0
	sw		$t0, num5
	li		$t0, 1
	li		$t1, 1
	seq		$t4, $t0, $t1
	sw		$t4, num5
	li		$t0, 1
	li		$t1, 1
	sne		$t4, $t0, $t1
	sw		$t4, num5
	li		$t0, 0
	sw		$t0, num5
	lw		$t0, num5
	not		$t1, $t0
	sw		$t1, num5
	lw		$t0, num5
	not		$t1, $t0
	sw		$t1, num5
	li		$t0, 1
	sw		$t0, num5
	lw		$t0, num5
	lw		$t1, num5
	and		$t4, $t0, $t1
	sw		$t4, num5
	lw		$t0, num5
	li		$t1, 0
	and		$t4, $t0, $t1
	sw		$t4, num5
	li		$t0, 0
	sw		$t0, num5
	lw		$t0, num5
	li		$v0, 1
	move		$a0, $t0
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	lw		$t0, num5
	li		$t1, 1
	or		$t4, $t0, $t1
	sw		$t4, num5
	lw		$t0, num5
	li		$v0, 1
	move		$a0, $t0
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	lw		$t0, num5
	li		$t1, 0
	or		$t4, $t0, $t1
	sw		$t4, num5
	lw		$t0, num5
	li		$v0, 1
	move		$a0, $t0
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	li		$t0, 0
	li		$t1, 0
	or		$t4, $t0, $t1
	sw		$t4, num5
	lw		$t0, num5
	li		$v0, 1
	move		$a0, $t0
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	li		$t0, 1
	lw		$t1, num5
	or		$t4, $t0, $t1
	sw		$t4, num5
	li		$t0, 1
	move		$t1, $t0
L8:	beq		$t1, $zero, L9
	sub		$t1, $t1, 1
	li		$v0, 4
	la		$a0, _nl
	syscall	
	j		L8
L9:
	lw		$t0, num5
	li		$v0, 1
	move		$a0, $t0
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	li		$t0, 10
	move		$t1, $t0
L10:	beq		$t1, $zero, L11
	sub		$t1, $t1, 1
	li		$v0, 4
	la		$a0, _space
	syscall	
	j		L10
L11:
	li		$v0, 4
	la		$a0, L12
	syscall	
	li		$v0, 4
	la		$a0, L13
	syscall	
	li		$v0, 4
	la		$a0, L14
	syscall	
	li		$v0, 4
	la		$a0, L15
	syscall	
	li		$t0, 1
	sw		$t0, num1
L17:
	lw		$t0, num1
	li		$t1, 5
	sle		$t4, $t0, $t1
	beq		$zero, $t4, L18
	li		$v0, 4
	la		$a0, L16
	syscall	
	lw		$t0, num1
	li		$t1, 1
	add		$t5, $t0, $t1
	sw		$t5, num1
	j		L17
L18:
	li		$t0, 1
	sw		$t0, num5
	li		$t0, 1
	sw		$t0, num1
L21:
	lw		$t0, num5
	beq		$zero, $t0, L22
	lw		$t1, num1
	li		$t5, 5
	seq		$t6, $t1, $t5
	beq		$zero, $t6, L19
	li		$t1, 0
	sw		$t1, num5
L19:
	li		$v0, 4
	la		$a0, L20
	syscall	
	lw		$t1, num1
	li		$t5, 1
	add		$t6, $t1, $t5
	sw		$t6, num1
	j		L21
L22:
	li		$t1, 1
	sw		$t1, num5
	lw		$t1, num5
	beq		$zero, $t1, L25
	li		$v0, 4
	la		$a0, L23
	syscall	
	j		L26
L25:
	li		$v0, 4
	la		$a0, L24
	syscall	
L26:
	li		$t1, 0
	sw		$t1, num5
	lw		$t1, num5
	beq		$zero, $t1, L27
	li		$v0, 4
	la		$a0, L23
	syscall	
	j		L28
L27:
	li		$v0, 4
	la		$a0, L24
	syscall	
L28:
	lw		$t1, num1
	li		$t5, 10
	seq		$t6, $t1, $t5
	beq		$zero, $t6, L31
	li		$v0, 4
	la		$a0, L29
	syscall	
	j		L32
L31:
	li		$v0, 4
	la		$a0, L30
	syscall	
L32:
	lw		$t1, num2
	li		$v0, 1
	move		$a0, $t1
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	li		$v0, 5
	syscall	
	sw		$v0, num1
	li		$v0, 5
	syscall	
	sw		$v0, num2
	li		$v0, 5
	syscall	
	sw		$v0, num3
	li		$v0, 5
	syscall	
	sw		$v0, num4
	li		$v0, 5
	syscall	
	sw		$v0, num5
	li		$v0, 4
	la		$a0, L33
	syscall	
	lw		$t1, num1
	li		$v0, 1
	move		$a0, $t1
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	li		$v0, 4
	la		$a0, L34
	syscall	
	lw		$t1, num2
	li		$v0, 1
	move		$a0, $t1
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	li		$v0, 4
	la		$a0, L35
	syscall	
	lw		$t1, num3
	li		$v0, 1
	move		$a0, $t1
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	li		$v0, 4
	la		$a0, L36
	syscall	
	lw		$t1, num4
	li		$v0, 1
	move		$a0, $t1
	syscall	
	li		$v0, 4
	la		$a0, _nl
	syscall	
	li		$v0, 4
	la		$a0, L37
	syscall	
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
_space:	.asciiz		" "
_true:	.asciiz		"true"
_false:	.asciiz		"false"
L14:	.asciiz		"Hello world\n"
L13:	.asciiz		"It works\n"
L33:	.asciiz		"num1 value "
L34:	.asciiz		"num2 value "
L35:	.asciiz		"num3 value "
L36:	.asciiz		"num4 value "
L12:	.asciiz		"\nHello world\n"
L37:	.asciiz		"num5 value "
L29:	.asciiz		"num1 is 10\n"
L30:	.asciiz		"num2 is not 10\n"
L23:	.asciiz		"Condition is true\n"
L15:	.asciiz		"Testing newlines\n"
L16:	.asciiz		"While loop\n"
L20:	.asciiz		"if while statement test\n"
L24:	.asciiz		"Condition is false\n"
num1:	.word		0
num2:	.word		0
num3:	.word		0
num4:	.word		0
num5:	.word		0
