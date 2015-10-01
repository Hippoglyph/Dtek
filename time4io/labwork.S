  # labwork.S
  # Written 2015 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1 2015-2016.
  # The macros PUSH and POP are in the public domain.

.global hexasc
.global delay
.global time2string
.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
.text
  # You can add your own code here
  #
hexasc:
	andi	$t0,$a0,15
	slti 	$t1,$t0,0x000a
	bne		$t1,$0,number
	nop
character:	
	addi	$t0,$t0,0x0007
number:
	addi	$v0,$t0,0x0030
	jr	$ra
	nop
	
delay:  
	add	$t0,$a0,$0	#t0 = ms
loopms:
	beq	$t0,$0,endms
	nop
	addi	$t0,$t0,-1
	addi	$t1,$0,26500
loopdelay:
	addi	$t1,$t1,-1
	bne	$t1,$0,loopdelay
	nop
	j	loopms
	nop
endms:
	jr $ra  
	nop

time2string:
	PUSH	$s0
	PUSH	$s1
	PUSH	$s2
	PUSH	$ra
	addi 	$s0,$0,0	#Init loop
	addi	$s1,$0,4	#number of loops
	add	$s2,$a0,$0	#Save memory pointer
loop1:
	addi	$s0,$s0,1
	add 	$a0,$a1,$0
	jal	hexasc
	nop
	PUSH	$v0
	srl	$a1,$a1,4
	bne	$s0,$s1,loop1
	nop
	
	add	$a0,$s2,$0 	#Get the memory pointer back to $a0
	
	POP	$t1
	sw 	$t1,0($a0)
	POP	$t2
	sll	$t2,$t2,8
	add	$t1,$t1,$t2
	addi 	$t2,$0,0x3A
	sll	$t2,$t2,16	
	add	$t1,$t1,$t2
	sw 	$t1,0($a0)
	POP	$t2
	sll	$t2,$t2,24
	add	$t1,$t1,$t2
	sw 	$t1,0($a0)
	
	POP	$t1
	add	$v0,$t1,$0
	addi	$t2,$0,0x00
	sll	$t2,$t2,8
	add	$t1,$t1,$t2
	sw 	$t1,4($a0)
	
	POP	$ra
	POP	$s2
	POP	$s1
	POP	$s0
	jr	$ra
	nop
