/*================================================================*\
**
**  File Name     : Kevin_Martin_Lab4.c
**  Creation Date : 11-11-2019
**  Last Modified : Sat 16 Nov 2019 04:21:12 PM PST
**  Compiler      : gcc -march=native -Wall -Werror -std=gnu99 -lm
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 32
#define ACTUAL_LENGTH 32 + 1
#define false 0
#define true 1

char *register_list[32] = {"$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2",
                           "$a3",   "$t0", "$t1", "$t2", "$t3", "$t4", "$t5",
                           "$t6",   "$t7", "$s0", "$s1", "$s2", "$s3", "$s4",
                           "$s5",   "$s6", "$s7", "$t8", "$t9", "$k0", "$k1",
                           "$gp",   "$sp", "$fp", "$ra"};

// Protypte of subString for use in multiple functions
char *subString(char *Sstring, int Sstart, int Slng);

// Checks that the char array is 32 bits long
// and only has 0 and 1 in it.
int check(char *bits) {
  if (strlen(bits) != LENGTH) {
    return false;
  }
  for (int i = 0; i < LENGTH; i++) {
    if (bits[i] != '0' && bits[i] != '1') {
      return false;
    }
  }
  return true;
}

// Converts binary 'string' to int (positive numbers)
int binconv(char *binary) {
  int out = 0, i = 0;
  while (binary[i] != '\0') {
    if (binary[i] == '1')
      out = (out << 1) + 1;
    else if (binary[i] == '0')
      out = out << 1;
    i++;
  }
  return out;
}

// 2's compliment binary conversion
int constbin(char *signbin) {
  // If positive number, use regugular binary conversion function
  if (signbin[0] == '0') {
    return binconv(signbin);
  }
  // First flip all the bits
  else {
    for (int i = 0; i <= strlen(signbin); i++) {
      if (signbin[i] == '0') {
        signbin[i] = '1';
      } else if (signbin[i] == '1') {
        signbin[i] = '0';
      }
    }
  }

  // Add 1
  int end = strlen(signbin) - 1;
  for (int j = end; j > 0; j--) {
    if (signbin[j] == '0') {
      signbin[j] = '1';
      break;
    } else {
      signbin[j] = '0';
    }
  }
  int negInt = -(binconv(subString(signbin, 0, strlen(signbin))));
  return negInt;
}

// Substring helper function
char *subString(char *str, int start, int lng) {
  char *outStr = malloc(lng + 1);
  memcpy(outStr, &str[start], lng);
  outStr[lng] = '\0';
  return outStr;
  free(outStr);
}

// Function for the three given r-type instructions
void r_type(char *inst) {
  char *rs = register_list[binconv(subString(inst, 6, 5))];
  char *rt = register_list[binconv(subString(inst, 11, 5))];
  char *rd = register_list[binconv(subString(inst, 16, 5))];
  int typePrint = binconv(subString(inst, 26, 6));
  switch (typePrint) {
    case 32:
      printf("add ");
      break;
    case 34:
      printf("sub ");
      break;
    case 42:
      printf("slt ");
      break;
    default:
      printf("Enter one of the three valid R-Format instructions\n");
      exit(0);
  }
  printf("%s, %s, %s\n", rd, rs, rt);
}

// Print notes on original bit string, shifted bit strings, and assumptions (00
// at end, and PC counter first four are 0)
void jump(char *inst) {
  char tmpStr[33];
  for (int i = 4; i < 30; i++) {
    tmpStr[i] = inst[i + 2];
  }

  tmpStr[0] = '0';
  tmpStr[1] = '0';
  tmpStr[2] = '0';
  tmpStr[3] = '0';
  tmpStr[30] = '0';
  tmpStr[31] = '0';
  tmpStr[32] = '\0';
  int addr = binconv(subString(tmpStr, 0, 32));
  printf("j 0x%08x\n", addr);
  printf(
      "\nNOTE: full address of jump instruction includes shifting the 26-bit "
      "target address by two places and making the lower order two bits '00'. "
      "The four highest order bits are represented by '0000', which assumes "
      "the PC counter is at 0000. Fully shifted address:\n");
  printf("%s\n", tmpStr);
}

// Function for the four i-type instructions (all involving constants)
void i_type(char *inst, int op) {
  char *rs = register_list[binconv(subString(inst, 6, 5))];
  char *rt = register_list[binconv(subString(inst, 11, 5))];
  // int offConst = binconv(subString(inst, 16, 16));
  int offConst = constbin(subString(inst, 16, 16));
  switch (op) {
    case 8:
      printf("addi %s, %s, %d\n", rt, rs, offConst);
      break;
    case 4:
      printf("beq %s, %s, %d\n", rs, rt, offConst);
      break;
    case 35:
      printf("lw %s, %d(%s)\n", rt, offConst, rs);
      break;
    case 43:
      printf("sw %s, %d(%s)\n", rt, offConst, rs);
      break;
    default:
      printf("Enter one of the four valid I-Format instructions\n");
      exit(0);
  }
}

// We will take the bitstring as a command line argument.
int main(int argc, char **argv) {
  // Make sure we have at least one argument.
  if (argc < 2) {
    fprintf(stderr, "No argument found\n");
    return -1;
  }
  // Get a pointer to the argument.
  char *instruction = argv[1];
  if (!check(instruction)) {
    fprintf(stderr, "Invalid bit string\n");
    return -2;
  }

  char opc[6] = "";
  memcpy(opc, instruction, 6);
  int opcode = binconv(opc);
  switch (opcode) {
    case 0:
      r_type(instruction);
      break;
    case 2:
      jump(instruction);
      break;
    case 8:
    case 4:
    case 35:
    case 43:
      i_type(instruction, opcode);
      break;
    default:
      printf("Enter one of the valid operations\n");
  }
  return 0;
}

