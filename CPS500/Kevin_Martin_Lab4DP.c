/*===================================================================*\
**
**  File Name     : Kevin_Martin_Lab4.c
**  Creation Date : 10-24-2019
**  Last Modified : Fri 25 Oct 2019 05:07:52 PM PDT
**  Compiler      : gcc -march=native -Wall -werror -std=gnu99 -lm
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==================================================================*/

#include <stdio.h>
#include <stdlib.h>

int subsetSum(int *set, int count, int sum) {
  int subset[count + 1][sum + 1];

  for (int i = 0; i <= count; i++) subset[i][0] = 1;
  for (int j = 1; j <= sum; j++) subset[0][j] = 0;
  for (int k = 1; k <= count; k++) {
    for (int m = 1; m <= sum; m++) {
      if (m < set[k - 1]) {
        subset[k][m] = subset[k - 1][m];
      }
      if (m >= set[k - 1]) {
        subset[k][m] = subset[k - 1][m] || subset[k - 1][m - set[k - 1]];
      }
    }
  }
  printf("subset is %d\n", subset[count][sum]);
  return (subset[count][sum]);
}

int main() {
  int count = 0, sum = 0;
  int *set = NULL;
  printf("Enter the size of the array\n");
  scanf("%d", &count);
  set = (int *)malloc(sizeof(int) * count);
  printf("Enter the elements of the array\n");
  for (int i = 0; i < count; i++) {
    scanf("%d", &set[i]);
  }
  printf("Enter the desired sum\n");
  scanf("%d", &sum);
  int output = subsetSum(set, count, sum);
  if (output != 0) {
    printf("Success, a subset of sum %d exists\n", sum);
  } else {
    printf("No such subset of sum %d exists\n", sum);
  }
  return (0);
}
