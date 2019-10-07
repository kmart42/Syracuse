/*=================================================*\
**
**  File Name     : CPS500.Lab1.Q1.c
**  Creation Date : 10-05-2019
**  Last Modified : Sat 05 Oct 2019 03:22:39 PM PDT
**  Compiler      : gcc -march=native -Wall -Werror -std=gnu99
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***=================================================*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

// function to get radius from user, checks to make sure it is a valid number

float getrad(void) {
  char rad[MAX];
  float r = 0.0;
  printf("Please enter the radius: ");
  if (fgets(rad, MAX, stdin) && sscanf(rad, "%f", &r) != 1) {
    printf("Please enter a valid number\n");
    return (r = getrad());
  } else
    return (r);
}

// main gets radius, prints diamter and circumference, rounded to 4 decimals

int main() {
  float x = 0.0;
  x = getrad();
  printf("The diameter of a circle with radius %.4f is %.4f\n", x, 2 * x);
  printf("The circumference of a circle with radius %.4f is %.4f\n", x,
         2 * M_PI * x);

  return (0);
}
