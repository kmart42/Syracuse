/*================================================================*\
**
**  File Name     : Kevin_Martin_Lab5.c
**  Creation Date : 11-24-2019
**  Last Modified : Tue 26 Nov 2019 12:36:27 AM PST
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
  //sigaction(
 // asm("jmp main+0x7f");
  //return;
}

int main(int argc, char **argv) {
  signal(SIGFPE, handler);
  printf("x=%d\n", x);
  printf("y=%d\n", y);
  int z = x / y;
  printf("Statement skipped!\n");
  return 0;
}
