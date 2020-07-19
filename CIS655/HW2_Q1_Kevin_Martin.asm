.data
#array: .word 1,3,5,7,9,11 #change array elements here
array: .word 0,4,900,5,3,2 #change array elements here
.text
main:
la $t0, array # address of array into t0
add $t0, $t0, 24 # length of array, 6 elements at 4 bytes each
loop1: # check if the entire array has been visited
add $t1, $0, $0 # set i = 0
la $a0, array # a0 has first element of array
loop2: # sorting
lw $t2, 0($a0) # t1 to current element, array[i]
lw $t3, 4($a0) # next element in array, move by 4 bytes
slt $t4, $t2, $t3 # check if t1 < t0
beq $t4, $0, next # if so, switch elements, if not go to next element
add $t1, $0, 1 # if so, check next element of array
sw $t2, 4($a0) # store the newly found higher number in next position
sw $t3, 0($a0) # newly found lower number in first position
next:
addi $a0, $a0, 4 # next element of array
bne $a0, $t0, loop2 # if all elemnts have not been examined, continue sort
bne $t1, $0, loop1 # check loop1 flag, continue

jal print #call print routine
li $v0, 10 #10 is syscall for exit
syscall

.data
buff:		.asciiz "buff\n"
max_text:	.asciiz "\nThe max value is:\n"
min_text:	.asciiz "\nThe min value is:\n"
.text
print: 
li $v0, 4 #syscall 4 is print string
la $a0, buff # needed a buffer to print correctly
syscall

li $v0, 4 #syscall 4 for print string
la $a0, max_text # identify max value
syscall

li $v0, 1 # syscall for integer
la $a0, array # load sorted array into a0
lw $t1, 4($a0) # first element in array
add $a0, $t1, $zero # load element into a0 for print
syscall

li $v0, 4 # syscall 4 for print string
la $a0, min_text # identify min value
syscall

li $v0, 1 # syscall for integer
la $a0, array # load sorted array into a0
lw $t2, 24($a0) # last element in array
add $a0, $t2, $zero # load element into a0 for print
syscall

jr $ra #jump back to main part of function, ready to exit
