/*=================================================*\
**
**  File Name     : CPS500.Lab1.Q2.c
**  Creation Date : 10-05-2019
**  Last Modified : Sat 05 Oct 2019 06:41:53 PM PDT
**  Compiler      : gcc -march=native -Wall -Werror -std=gnu99
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***=================================================*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

// function to get number of lines from user, ensures whole numbers

int getlines(void) {
  char check[MAX];
  int n = 0;
  char *ptr;
  printf("Please enter the number of lines you wish to see\n");
  scanf("%[^\n]d", check);
  getchar();
  for (int i = 0; check[i] != '\0'; i++) {
    if (isalpha(check[i]) != 0 || strchr(check, '.') != NULL) {
      printf("Please enter an integer\n");
      return (n = getlines());
    }
  }

  n = strtol(check, &ptr, 10);
  if (n < 0) {
    printf("please enter an integer\n");
    return (n = getlines());
  } else
    return (n);
}

// main function prints as many '*' characters as prompted by user

int main() {
  int x = getlines();
  int count = 0;
  for (int i = 0; i < x; i++) {
    printf("\n");
    count++;
    for (int j = 0; j < count; j++) {
      printf("*");
    }
  }

  printf("\n");
  return (0);
}
