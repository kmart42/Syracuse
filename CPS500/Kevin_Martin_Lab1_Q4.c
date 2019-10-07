/*=================================================*\
**
**  File Name     : CPS500.Lab1.Q4.c
**  Creation Date : 10-05-2019
**  Last Modified : Sun 06 Oct 2019 01:10:01 PM PDT
**  Compiler      : gcc -march=native -Wall -werror -std=gnu99
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***=================================================*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// takes both arrays, the size of the array, and sums each respective element
void arrayAddition(int A[], int B[], int N, int output[]) {
  for (int i = 0; i < N; i++) {
    output[i] = A[i] + B[i];
  }
  printf("The summed array is: ");
  for (int j = 0; j < N; j++) {
    printf("%d ", output[j]);
  }
  printf("\n");
}

// user is promted for total number of elements, then populates each array
int main() {
  int A[MAX];
  int B[MAX];
  int N = 0;
  printf("Please enter the total elements for each array\n");
  scanf("%d", &N);
  getchar();
  printf("Please enter %d elements for the first array\n", N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  printf("Please enter %d elements of the second array\n", N);
  for (int j = 0; j < N; j++) {
    scanf("%d", &B[j]);
  }
  int output[N];
  arrayAddition(A, B, N, output);
  return (0);
}
