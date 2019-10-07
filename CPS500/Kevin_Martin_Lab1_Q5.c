/*=================================================*\
**
**  File Name     : CPS500.Lab1.Q5.c
**  Creation Date : 10-06-2019
**  Last Modified : Sun 06 Oct 2019 04:44:25 PM PDT
**  Compiler      : gcc -march=native -Wall -werror -std=gnu99
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***=================================================*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

// Switch statement to handle each of the 5 operands that could be passed
void calculate(int lh, int rh, char oper) {
  switch (oper) {
    case '+':
      printf("%d + %d = %d\n", lh, rh, lh + rh);
      break;
    case '-':
      printf("%d - %d = %d\n", lh, rh, lh - rh);
      break;
    case '/':
      printf("%f / %f = %f\n", (float)lh, (float)rh, (float)lh / (float)rh);
      break;
    case '*':
      printf("%d * %d = %d\n", lh, rh, lh * rh);
      break;
    case '%':
      printf("%d %% %d = %d\n", lh, rh, lh % rh);
      break;
    default:
      printf("Please enter a valid equation\n");
      break;
  }
}

// Function which prompts the user to enter an equation, and identify the
// operand Allows for format 'x+y' as well as 'x + y'
// Function does not allow for floats as inputs, but casts to float for division
// Function will not work with negative numbers
int getequation(void) {
  char eq[MAX];
  char op;
  char *ope = eq;
  int lh, rh;
  printf("Please enter your equation\n");
  scanf("%[^\n]d", eq);
  getchar();

  // Loop to check for each of the 5 options, store as 'op' and replace with ' '
  for (int i = 0; eq[i] != '\0'; i++) {
    if (eq[i] == '+' || eq[i] == '-' || eq[i] == '/' || eq[i] == '*' ||
        eq[i] == '%') {
      op = eq[i];
      eq[i] = ' ';
    }
  }
  lh = strtol(eq, &ope, 10);
  rh = strtol(ope, &ope, 10);

  // Check for integers only, after operand character has been switched out
  for (int j = 0; eq[j] != '\0'; j++) {
    if (isalpha(eq[j]) != 0 || strchr(eq, '.') != NULL) {
      printf("Please enter positive integers only\n");
      return (lh = getequation());
    }
  }

  calculate(lh, rh, op);
  return (0);
}

// Main just initializes program, all variables and equations tracked elsewhere
int main() {
  getequation();
  return (0);
}

