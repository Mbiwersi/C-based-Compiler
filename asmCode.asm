	.text	
	.globl		main
	j		main
readNums:
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
	jr		$ra
printNums:
	li		$v0, 4
	la		$a0, L9
	syscall	
	li		$t0, 0
	sw		$t0, i
L10:
	lw		$t0, i
	lw		$t1, count
	slt		$t2, $t0, $t1
	beq		$zero, $t2, L11
	lw		$t0, i
	mul		$t3, $t0, 4
	lw		$t1, numbers($t3)
	li		$v0, 1
	move		$a0, $t1
	syscall	
	li		$v0, 4
	la		$a0, _space
	syscall	
	lw		$t0, i
	li		$t1, 1
	add		$t3, $t0, $t1
	sw		$t3, i
	j		L10
L11:
	li		$v0, 4
	la		$a0, L12
	syscall	
	jr		$ra
sort:
	li		$t0, 1
	sw		$t0, i
L7:
	lw		$t0, i
	lw		$t1, count
	slt		$t2, $t0, $t1
	beq		$zero, $t2, L8
	lw		$t0, i
	li		$t1, 1
	sub		$t3, $t0, $t1
	sw		$t3, j
	lw		$t0, i
	mul		$t3, $t0, 4
	lw		$t1, numbers($t3)
	sw		$t1, temp
L5:
	lw		$t0, j
	li		$t1, 0
	sge		$t3, $t0, $t1
	lw		$t0, j
	mul		$t4, $t0, 4
	lw		$t1, numbers($t4)
	lw		$t0, temp
	slt		$t4, $t1, $t0
	and		$t0, $t3, $t4
	beq		$zero, $t0, L6
	lw		$t1, j
	li		$t3, 1
	add		$t4, $t1, $t3
	lw		$t1, j
	mul		$t5, $t1, 4
	lw		$t3, numbers($t5)
	mul		$t1, $t4, 4
	sw		$t3, numbers($t1)
	lw		$t1, j
	li		$t3, 1
	sub		$t4, $t1, $t3
	sw		$t4, j
	j		L5
L6:
	lw		$t0, j
	li		$t1, 1
	add		$t3, $t0, $t1
	lw		$t0, temp
	mul		$t1, $t3, 4
	sw		$t0, numbers($t1)
	lw		$t0, i
	li		$t1, 1
	add		$t3, $t0, $t1
	sw		$t3, i
	j		L7
L8:
	jr		$ra
main:
	jal		readNums
	jal		sort
	jal		printNums
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
