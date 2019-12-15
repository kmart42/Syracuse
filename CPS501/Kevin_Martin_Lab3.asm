.data 
#array: .word 0, 5, 15, 3, 18, 7, 20, 2, 16, 1 
array: .word 10, 9, 90, 8, 7, 6, 5, 4, 3, 2, 1
.text 
.globl main
main:
la $t0, array 
addi $a0, $t0, 0 # start address of array
addi $a1, $zero, 11 # a1 = n
jal shellSort
end:jal print #call print routine
li $v0, 10 
syscall 

shellSort:
addi $sp, $sp, -4 # make room for new variable gap
sw $ra 4($sp) # save register for jump back
srl $a2, $a1, 1 # gap = n / 2, a2 = gap
while: jal insertShell #start of while loop
li $t1, 0 # set up check register
beq $a2, $t1, shellSort  # branch if result does not = 1
srl $a2, $a2, 1 # gap /2
j while #continue loop

insertShell:
addi $sp, $sp, -28 # 7 registers
sw $ra, 24($sp) # ra to stack
sw $s5, 20($sp) # s5 to stack
sw $s4, 16($sp) # s4 to stack
sw $s3, 12($sp) # s3 to stack
sw $s2, 8($sp) # s2 to stack
sw $s1, 4($sp) # s1 to stack
sw $s0, 0($sp) # s0 to stack
move $s2, $a0 # copy a0 (array) into s2
move $s3, $a1 # a1 (N) into s3
move $s4, $a2 # a2 (gap) into s4

addi $s0, $s4, 0# i = s4 (gap), s0 = i
forOuter: slt $t0, $s0, $s3 # t0=0 if s0<s3 (i<n)
beq $t0, $zero, exit1 # go to exit1 if s0<s3 (i<n)
addi $s1, $s0, 0 # j = i
forInner: slt $t0, $s1, $s4 # t0=1 if s1<s4(keeps j>=gap)
bne $t0, $zero, exit2 # go to exit2 if s1<0
sll $t1, $s1, 2 # j * 4
add $t2, $s2, $t1
lw $t3, 0($t2) # t3 = arr[j]
sub $s5, $s1, $s4 # s5 = j - gap
sll $t1, $s5, 2 # (j - gap) * 4
add $t2, $s2, $t1 # t2 = arr + (j - gap)
lw $t5, 0($t2) # t5 = arr[j - gap]
slt $t0, $t3, $t5, # t0=0 if t3 < t5 (array[j] < array[j - gap])
beq $t0, $zero, exit2 # go to exit2 if t4 < t3
move $a0, $s2 # a0 gets s2 (array) for swap
move $a3, $s1 # a1 gets s1 (j) for swap
move $a2, $s5 # a2 gets s5 (j - gap) for swap
jal swap # jump to swap
sub $s1, $s1, $s4 # j -= gap
j forInner # jump to inner loop

exit2: addi $s0, $s0, 1 # i ++
j forOuter # jump to outer loop

exit1: lw $s0, 0($sp) #restoring s0-s5 from stack
lw $s1, 4($sp)
lw $s2, 8($sp)
lw $s3, 12($sp)
lw $s4, 16($sp)
lw $s5, 20($sp)
lw $ra, 24($sp)
addi $sp, $sp, 28
j end


swap:
move $s2, $a0 # a0; array
move $s1, $a3 # a1: j
move $s5, $a2 # a2: j - gap
sll $t1, $a2, 2 # t1 =  (j - gap) * 4
add $t1, $a0, $t1 # t1 = arr[j - gap]
sll $t2, $a3, 2 # $t2 = j * 4
add $t2, $a0, $t2 # t2 = arr[j]
lw $t0, 0($t1) # t0 = arr[j - gap]
lw $t3, 0($t2) # t3 = arr[j]
sw $t3, 0($t1) # t3 = arr[var - gap]
sw $t0, 0($t2) # t0 = arr[j]
move $a0, $s2 # a0; array
move $a3, $s1 # a1: j
move $a2, $s5 # a2: j - gap
jr $ra # end of swap 

.data
space:.asciiz " " #spaces to insert between printed numters
head:.asciiz " The modified array is:\n" #header line for print
.text
print: add $t0, $zero, $a0 #starting address of array
add $t1, $zero, 11 #initialize loop, known size of 10 elements
la $a0, head #load address of the print heading, defined above
li $v0, 4 #syscall 4 is print string
syscall

out: lw $a0, 0($t0) #load integer to be printed from array
li $v0, 1 #1 is print integer syscall
syscall

la $a0, space #load address for space, defined above
li $v0, 4 #syscall 4 for print string
syscall

addi $t0, $t0, 4 #increment address for next element of array
addi $t1, $t1, -1 #decrease loop counter by 1
bgtz $t1, out #repeat until finished

jr $ra #jump back to main part of function, ready to exit
