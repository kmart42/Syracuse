/*=================================================*\
**
**  File Name     : CPS500.Lab1.Q3.c
**  Creation Date : 10-05-2019
**  Last Modified : Sat 05 Oct 2019 09:01:12 PM PDT
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

// Function to get number for sequence from user, ensures whole numbers
// Programmer note: limiting the max number to 46 as the 47th Fibonacci
// number is greater than the max unsigned long integer

int getnum(void) {
  char check[MAX];
  int n = 0;
  char *ptr;
  printf("Please enter the number of Fibonacci numbers you wish to see\n");
  scanf("%[^\n]d", check);
  getchar();
  for (int i = 0; check[i] != '\0'; i++) {
    if (isalpha(check[i]) != 0 || strchr(check, '.') != NULL) {
      printf("Please enter an integer\n");
      return (n = getnum());
    }
  }

  n = strtol(check, &ptr, 10);
  if (n <= 0) {
    printf("please enter an integer\n");
    return (n = getnum());
  } else if (n >= 47) {
    printf(
        "Please enter a number smaller than 47 to avoid incorrect results\n");
    return (n = getnum());
  } else
    return (n);
}

void fibonacci(int k) {
  int fib_list[k];

  // force first two numbers of sequence
  fib_list[0] = 1;
  fib_list[1] = 1;

  // create fibonacci list
  for (int i = 2; i < k; i++) {
    fib_list[i] = fib_list[i - 1] + fib_list[i - 2];
  }
  // print each element of the fibonacci list
  for (int j = 0; j < k; j++) {
    printf("%d ", fib_list[j]);
  }
  printf("\n");
}

// main function gets integer from user and calls fibonacci function

int main() {
  unsigned long int k = getnum();
  fibonacci(k);
  return (0);
}
