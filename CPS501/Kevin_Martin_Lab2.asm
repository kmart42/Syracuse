.data
array: .word 1,3,5,7,9,11 #change array elements here
.text
main:
la $s0, array
lw $s1, 0($s0) #temp = array[0]
lw $s2, 20($s0) #second temp = array[5]
lw $s3, 0($s0) #third temp, as copy, before modificatition
add $s1, $s2, 1 #array[0] = array[5] +1
add $s2, $s3, -1 #array[5] = array[0] - 1
sw $s1, 0($s0) #stores result into array[0]
sw $s2, 20($s0) #stores result of second operation into array[5]
lw $s1, 4($s0) #temp = array[1]
lw $s2, 16($s0) #second temp = array[4]
lw $s3, 4($s0) #third temp, as copy, before modification
add $s1, $s2, 5 #array[1] = array[4] + 5
add $s2, $s3, -5 #array[4] = array[1] - 5
sw $s1, 4($s0) #store result of third operation into array[1]
sw $s2, 16($s0) #store result of fourth operatoin into array[4]
lw $s1, 8($s0) #temp = array[2]
lw $s2, 12($s0) #second temp = array[3]
lw $s3, 8($s0) #third temp, as copy, before modification
sll $s1, $s2, 1 #array[2] = array[3] * 2
srl $s2, $s3, 1 #array[3] = array[2] /2 (original array[2])
sw $s1, 8($s0) #store result of fith operation into array[2]
sw $s2, 12($s0) #store result of sixth operation into array[3]


#print function below, used help from MARS example program
la $a0, array #array argument for print funciton
jal print #call print routine

li $v0, 10 #10 is syscall for exit
syscall


.data
space:.asciiz " " #spaces to insert between printed numters
head:.asciiz " The modified array is:\n" #header line for print
.text
print: add $t0, $zero, $a0 #starting address of array
add $t1, $zero, 6 #initialize loop, known size of 6 elements
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
