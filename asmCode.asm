	.text	
	.globl		main
main:
	li		$v0, 4
	la		$a0, L1
	syscall	
	li		$t0, 0
	sw		$t0, i
L4:
	lw		$t0, i
	li		$t1, 5
	slt		$t2, $t0, $t1
	beq		$zero, $t2, L5
	li		$t0, 0
	sw		$t0, j
L2:
	lw		$t0, j
	li		$t1, 4
	slt		$t3, $t0, $t1
	beq		$zero, $t3, L3
	li		$v0, 5
	syscall	
	sw		$v0, k
	lw		$t0, i
	lw		$t1, j
	lw		$t4, k
	mul		$t5, $t0, 4
	add		$t5, $t5, $t1
	mul		$t5, $t5, 4
	sw		$t4, twoD($t5)
	lw		$t0, j
	li		$t1, 1
	add		$t4, $t0, $t1
	sw		$t4, j
	j		L2
L3:
	lw		$t0, i
	li		$t1, 1
	add		$t3, $t0, $t1
	sw		$t3, i
	j		L4
L5:
	li		$t0, 0
	sw		$t0, i
L8:
	lw		$t0, i
	li		$t1, 5
	slt		$t2, $t0, $t1
	beq		$zero, $t2, L9
	li		$t0, 0
	sw		$t0, j
	lw		$t0, i
	li		$t1, 0
	mul		$t3, $t0, 4
	sw		$t1, rowSums($t3)
L6:
	lw		$t0, j
	li		$t1, 4
	slt		$t3, $t0, $t1
	beq		$zero, $t3, L7
	lw		$t0, i
	lw		$t1, i
	mul		$t5, $t1, 4
	lw		$t4, rowSums($t5)
	lw		$t1, i
	lw		$t5, j
	mul		$t7, $t1, 4
	add		$t7, $t7, $t5
	mul		$t7, $t7, 4
	lw		$t6, twoD($t7)
	add		$t1, $t4, $t6
	mul		$t4, $t0, 4
	sw		$t1, rowSums($t4)
	lw		$t0, j
	li		$t1, 1
	add		$t4, $t0, $t1
	sw		$t4, j
	j		L6
L7:
	lw		$t0, i
	li		$t1, 1
	add		$t3, $t0, $t1
	sw		$t3, i
	j		L8
L9:
	li		$t0, 0
	sw		$t0, j
L12:
	lw		$t0, j
	li		$t1, 4
	slt		$t2, $t0, $t1
	beq		$zero, $t2, L13
	li		$t0, 0
	sw		$t0, i
L10:
	lw		$t0, i
	li		$t1, 5
	slt		$t3, $t0, $t1
	beq		$zero, $t3, L11
	lw		$t0, j
	lw		$t1, j
	mul		$t5, $t1, 4
	lw		$t4, colSums($t5)
	lw		$t1, i
	lw		$t5, j
	mul		$t7, $t1, 4
	add		$t7, $t7, $t5
	mul		$t7, $t7, 4
	lw		$t6, twoD($t7)
	add		$t1, $t4, $t6
	mul		$t4, $t0, 4
	sw		$t1, colSums($t4)
	lw		$t0, i
	li		$t1, 1
	add		$t4, $t0, $t1
	sw		$t4, i
	j		L10
L11:
	lw		$t0, j
	li		$t1, 1
	add		$t3, $t0, $t1
	sw		$t3, j
	j		L12
L13:
	li		$t0, 0
	sw		$t0, i
L19:
	lw		$t0, i
	li		$t1, 5
	slt		$t2, $t0, $t1
	beq		$zero, $t2, L20
	li		$t0, 0
	sw		$t0, j
	lw		$t0, i
	mul		$t3, $t0, 4
	lw		$t1, rowSums($t3)
	li		$v0, 1
	move		$a0, $t1
	syscall	
	li		$v0, 4
	la		$a0, _space
	syscall	
	li		$v0, 4
	la		$a0, L14
	syscall	
L16:
	lw		$t0, j
	li		$t1, 4
	slt		$t3, $t0, $t1
	beq		$zero, $t3, L17
	lw		$t0, i
	lw		$t1, j
	mul		$t5, $t0, 4
	add		$t5, $t5, $t1
	mul		$t5, $t5, 4
	lw		$t4, twoD($t5)
	li		$v0, 1
	move		$a0, $t4
	syscall	
	li		$v0, 4
	la		$a0, _space
	syscall	
	li		$v0, 4
	la		$a0, L15
	syscall	
	lw		$t0, j
	li		$t1, 1
	add		$t4, $t0, $t1
	sw		$t4, j
	j		L16
L17:
	li		$v0, 4
	la		$a0, L18
	syscall	
	lw		$t0, i
	li		$t1, 1
	add		$t3, $t0, $t1
	sw		$t3, i
	j		L19
L20:
	li		$t0, 0
	sw		$t0, j
	li		$v0, 4
	la		$a0, L15
	syscall	
L21:
	lw		$t0, j
	li		$t1, 4
	slt		$t2, $t0, $t1
	beq		$zero, $t2, L22
	lw		$t0, j
	mul		$t3, $t0, 4
	lw		$t1, colSums($t3)
	li		$v0, 1
	move		$a0, $t1
	syscall	
	li		$v0, 4
	la		$a0, _space
	syscall	
	li		$v0, 4
	la		$a0, L15
	syscall	
	lw		$t0, j
	li		$t1, 1
	add		$t3, $t0, $t1
	sw		$t3, j
	j		L21
L22:
	li		$v0, 4
	la		$a0, L18
	syscall	
	li		$v0, 10
	syscall	
	.data	
rowSums:	.space		20
colSums:	.space		16
twoD:	.space		80
	.align		4
_nl:	.asciiz		"\n"
_space:	.asciiz		" "
_true:	.asciiz		"true"
_false:	.asciiz		"false"
L14:	.asciiz		":\t"
L18:	.asciiz		"\n"
L15:	.asciiz		"\t"
L1:	.asciiz		"Enter 20 ints: "
i:	.word		0
j:	.word		0
k:	.word		0
