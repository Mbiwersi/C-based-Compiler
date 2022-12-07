	.text	
	.globl		main
main:
	li		$v0, 4
	la		$a0, L1
	syscall	
	li		$v0, 5
	syscall	
	sw		$v0, count
	li		$t0, 0
	sw		$t0, i
L3:
	lw		$t0, i
	lw		$t1, count
	slt		$t2, $t0, $t1
	beq		$zero, $t2, L4
	li		$v0, 4
	la		$a0, L2
	syscall	
	li		$v0, 5
	syscall	
	sw		$v0, temp
	lw		$t0, i
	lw		$t1, temp
	mul		$t3, $t0, 4
	sw		$t1, numbers($t3)
	lw		$t0, i
	li		$t1, 1
	add		$t3, $t0, $t1
	sw		$t3, i
	j		L3
L4:
	li		$t0, 1
	sw		$t0, i
L7:
	lw		$t0, i
	lw		$t1, count
	slt		$t3, $t0, $t1
	beq		$zero, $t3, L8
	lw		$t0, i
	li		$t1, 1
	sub		$t4, $t0, $t1
	sw		$t4, j
	lw		$t0, i
	mul		$t4, $t0, 4
	lw		$t1, numbers($t4)
	sw		$t1, temp
L5:
	lw		$t0, j
	li		$t1, 0
	sge		$t4, $t0, $t1
	lw		$t0, j
	mul		$t5, $t0, 4
	lw		$t1, numbers($t5)
	lw		$t0, temp
	slt		$t5, $t1, $t0
	and		$t0, $t4, $t5
	beq		$zero, $t0, L6
	lw		$t1, j
	li		$t4, 1
	add		$t5, $t1, $t4
	lw		$t1, j
	mul		$t6, $t1, 4
	lw		$t4, numbers($t6)
	mul		$t1, $t5, 4
	sw		$t4, numbers($t1)
	lw		$t1, j
	li		$t4, 1
	sub		$t5, $t1, $t4
	sw		$t5, j
	j		L5
L6:
	lw		$t1, j
	li		$t4, 1
	add		$t5, $t1, $t4
	lw		$t1, temp
	mul		$t4, $t5, 4
	sw		$t1, numbers($t4)
	lw		$t1, i
	li		$t4, 1
	add		$t5, $t1, $t4
	sw		$t5, i
	j		L7
L8:
	li		$v0, 4
	la		$a0, L9
	syscall	
	li		$t1, 0
	sw		$t1, i
L10:
	lw		$t1, i
	lw		$t4, count
	slt		$t5, $t1, $t4
	beq		$zero, $t5, L11
	lw		$t1, i
	mul		$t6, $t1, 4
	lw		$t4, numbers($t6)
	li		$v0, 1
	move		$a0, $t4
	syscall	
	li		$v0, 4
	la		$a0, _space
	syscall	
	lw		$t1, i
	li		$t4, 1
	add		$t6, $t1, $t4
	sw		$t6, i
	j		L10
L11:
	li		$v0, 4
	la		$a0, L12
	syscall	
	li		$v0, 10
	syscall	
	.data	
numbers:	.space		120
	.align		4
_nl:	.asciiz		"\n"
_space:	.asciiz		" "
_true:	.asciiz		"true"
_false:	.asciiz		"false"
L12:	.asciiz		"\n"
L9:	.asciiz		"\n\n"
L2:	.asciiz		"Enter an int: "
L1:	.asciiz		"Enter the number of ints (30 or less) in the array: "
i:	.word		0
j:	.word		0
temp:	.word		0
count:	.word		0
