/*================================================================*\
**
**  File Name     : Kevin_Martin_Lab5.c
**  Creation Date : 11-24-2019
**  Last Modified : Sun 01 Dec 2019 03:25:21 PM PST
**  Compiler      : gcc -march=native -Wall -Werror -std=gnu99 -lm
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***================================================================*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
int x = 5;
int y = 0;

void handler(int signum) {
  printf("You divided by zero! Bad programmer!\n");
  y = 5;

  // Divide step is at main+70 (relative offset, in hex)
  // This is 112 in decimal. Divide by 4 for instruction = 22
  // Need to create full instruction buffer
  // Add 22 to skip division step
  int buffer[24];
  int *ret;
  ret = buffer + 40;
  (*ret) += 22;

  /* 
  My first thought, but the modification does not stick
  Essentially the same as setting "y=5;' on line 19

  asm("mov %ebp,64(%ebx)");
  asm("add $0x5, %ebp");
  asm("mov 64(%ebx), %ebp");
  printf("%d\n", y);
  */
  return;
}

int main(int argc, char **argv) {
  signal(SIGFPE, handler);
  printf("x=%d\n", x);
  printf("y=%d\n", y);

  int z = x / y;
  printf("Statement skipped!\n");
  return 0;
}
