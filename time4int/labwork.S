  # labwork.S
  # Written 2015 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1 2015-2016.
  # The macros PUSH and POP are in the public domain.

.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm

.data
.text
.globl hexasc
.globl delay
.globl time2string
.globl enable_interrupt
  # You can add your own code here
  #

hexasc:
	andi	$v0, $a0, 15
	slti	$t0, $v0, 10
	beq	$t0, $0, letter
	addi	$v0, $v0, 0x30
	jr $ra
	nop
letter:
	addi	$v0, $v0, 0x37
	jr $ra
	nop

delay:
	add 	$t0, $a0, $0	#Save argument to t0
MainLoop:
	addi	$t0, $t0, -1
	slti	$t3,$t0,0	
	bne	$t3,$0, end
	nop
	add 	$t1, $0, $0	#Inner loop index
	addi 	$t2, $0, 26500	#Loop roof
InnerLoop:
	addi 	$t1, $t1, 1
	bne	$t1, $t2, InnerLoop
	nop
	
	j	MainLoop	#While (t0 > 0)
	nop
end:
	jr $ra
	nop
	
time2string:
	PUSH	$s0
	PUSH	$s1
	PUSH	$s2
	PUSH	$s3
	PUSH	$ra		#Store jump location
	add	$s0, $a0, $0	#Store memory adress
	add 	$s1, $0, $0	#Loop index
	addi	$s2, $0, 4 	#Upper loop limit
PushLoop:
	add	$a0, $a1, $0
	jal	hexasc
	nop
	PUSH	$v0		#Push word on stack
	srl	$a1, $a1, 4	#Remove last word
	addi	$s1, $s1, 1	#t1++
	bne	$s1, $s2, PushLoop
	nop
	
	add	$a0, $s0, $0	#Load back memory adress
	POP	$t0		#First minute
	POP	$t1		#Second minute
	sll	$t1,$t1,8	#Move one byte left
	add	$t0, $t0, $t1	#Merge
	addi	$t1, $0, 0x3A	#Colon
	sll	$t1, $t1, 16	#Move two bytes
	add	$t0, $t0, $t1	#Merge
	POP	$t1		#First second
	POP	$t2		#Second second
	addi	$t3, $0, 0x0030
	bne	$t1, $t3, notDing
	nop
	bne	$t2, $t3, notDing
	nop
	j	ding
	nop
notDing:
	sll	$t1,$t1,24	#Move three bytes
	add	$t0, $t0, $t1	#Merge
	sw	$t0, 0($a0)	#Store result in first word
	add	$t0, $t2, $0
	addi	$t1, $0, 0x00	#Null byte
	sll	$t1,$t1,8	#Move one byte
	add	$t0, $t1, $t0	#Merge
	sw	$t0, 4($a0)	#Store result in second word

dingEnd:	
	POP	$ra
	POP	$s3
	POP	$s2
	POP	$s1
	POP	$s0
	
	jr	$ra
	nop
ding:
	addi	$t0, $0, 0x44
	sb	$t0, 0($a0)
	addi	$t0, $0, 0x49
	sb	$t0, 1($a0)
	addi	$t0, $0, 0x4e
	sb	$t0, 2($a0)
	addi	$t0, $0, 0x47
	sb	$t0, 3($a0)
	sb	$0, 4($a0)
	
	j	dingEnd
	nop

enable_interrupt:
	ei
	jr $ra
	nop