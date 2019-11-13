/*================================================================*\
**
**  File Name     : Kevin_Martin_Lab4.c
**  Creation Date : 11-11-2019
**  Last Modified : Tue 12 Nov 2019 11:01:52 PM PST
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

char *getReg(char *registerStr);

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

// Converts binary 'string' to int
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

// Substring helper function
char *subString(char *str, int start, int lng) {
  char *outStr = malloc(lng + 1);
  memcpy(outStr, &str[start], lng);
  outStr[lng] = '\0';
  return outStr;
  free(outStr);
}

void r_type(char *inst) {
  char *rs = getReg(subString(inst, 6, 5));
  char *rt = getReg(subString(inst, 11, 5));
  char *rd = getReg(subString(inst, 16, 5));
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

void jump(char *inst) {}

void addi(char *inst) {
  char *rs = getReg(subString(inst, 6, 5));
  char *rt = getReg(subString(inst, 11, 5));
  int addConst = binconv(subString(inst, 16, 16));
  printf("addi %s, %s, %d\n", rt, rs, addConst);
}

void i_type(char *inst) {}

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
  // char *test = subString(instruction, 6, 5);
  // printf("%s\n%s\n", test, getReg(test));
  int opcode = binconv(opc);
  switch (opcode) {
    case 0:
      r_type(instruction);
      break;
    case 2:
      jump(instruction);
      break;
    case 8:
      addi(instruction);
      break;
    case 4:
    case 35:
    case 43:
      i_type(instruction);
      break;
    default:
      printf("Enter one of the valid operations\n");
  }
  // char *regg = getReg(opc);
  // printf("%s\n", regg);
  return 0;
}

// Switch case to return appropriate register, using int conversion
char *getReg(char *regStr) {
  int n = binconv(regStr);
  switch (n) {
    case 0:
      return "$zero";
      break;
    case 1:
      return "$at";
      break;
    case 2:
      return "$v0";
      break;
    case 3:
      return "$v1";
      break;
    case 4:
      return "$a0";
      break;
    case 5:
      return "$a1";
      break;
    case 6:
      return "$a2";
      break;
    case 7:
      return "$a3";
      break;
    case 8:
      return "$t0";
      break;
    case 9:
      return "$t1";
      break;
    case 10:
      return "$t2";
      break;
    case 11:
      return "$t3";
      break;
    case 12:
      return "$t4";
      break;
    case 13:
      return "$t5";
      break;
    case 14:
      return "$t6";
      break;
    case 15:
      return "$t7";
      break;
    case 16:
      return "$s0";
      break;
    case 17:
      return "$s1";
      break;
    case 18:
      return "$s2";
      break;
    case 19:
      return "$s3";
      break;
    case 20:
      return "$s4";
      break;
    case 21:
      return "$s5";
      break;
    case 22:
      return "$s6";
      break;
    case 23:
      return "$s7";
      break;
    case 24:
      return "$t8";
      break;
    case 25:
      return "$t9";
      break;
    case 26:
      return "$k0";
      break;
    case 27:
      return "$k1";
      break;
    case 28:
      return "$gp";
      break;
    case 29:
      return "$sp";
      break;
    case 30:
      return "$fp";
      break;
    case 31:
      return "$ra";
      break;
    default:
      printf("Enter a valid register 0-31\n");
      return NULL;
  }
}
