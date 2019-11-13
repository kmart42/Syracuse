/*===================================================================*\
**
**  File Name     : Kevin_Martin_Lab4.c
**  Creation Date : 10-24-2019
**  Last Modified : Tue 29 Oct 2019 08:00:11 PM PDT
**  Compiler      : gcc -march=native -Wall -werror -std=gnu99 -lm
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==================================================================*/

#include <stdio.h>
#include <stdlib.h>

// Q1: Determine if the sum of a subset within the given set is equal to a given
// sum. Returns 0 for False 1 for True
int subsetSum(int* set, int count, int sum) {
  // Check base cases for success or failure
  if (sum == 0) return (1);
  if (count == 0 && sum != 0) return (0);

  // If the last element of current subset is greater than sum, do not include
  // Recursive call, excluding current last element
  if (set[count - 1] > sum) return subsetSum(set, count - 1, sum);

  // Check to see if current last element should be included OR excluded
  // Recursive call with updated parameters
  return subsetSum(set, count - 1, sum) ||
         subsetSum(set, count - 1, sum - set[count - 1]);
}

// Q2: Function to find difference between two given sets
// Includes helper function to check if unique number has already been added

int checkNum(int* R, int N, int countR) {
  if (countR == 0) return 0;
  for (int i = 0; i <= countR; i++) {
    if (N == R[i]) return (1);
  }
  return (0);
}

void setDifference(int* S, int countS, int* T, int count, int* R, int countR) {
  // j defined outside of loop to check if entire second loop completed
  int j = 0;
  for (int i = 0; i < countS; i++) {
    for (j = 0; j < count; j++) {
      if (S[i] == T[j]) {
        break;
      }
    }
    // If no elements were equal, check to see if already in results
    // If not, add to results
    if (j == count) {
      if (!checkNum(R, S[i], countR)) {
        R[countR] = S[i];
        countR++;
      }
    }
  }

  if (countR == 0) {
    printf("There were no common elements between the sets\n");
  } else {
    printf("The difference between set S and set T is: \n");
    for (int k = 0; k < countR; k++) {
      printf("%d ", R[k]);
    }
  }
  printf("\n");
}

// Q3: Determine if subset s is a proper subset of T
// Double loop, increase counter if subset is present in Set
int properSubset(int* s, int counts, int* T, int countT) {
  int s_check = 0;
  if (counts >= countT) return (0);
  for (int i = 0; i < counts; i++) {
    for (int j = 0; j < countT; j++) {
      if (s[i] == T[j]) {
        s_check++;
      }
    }
  }
  if (s_check == counts) return (1);
  return (0);
}

// Switch case to choose problem. Each case holds relevant parameters
int question_select(int i) {
  // Variables for Q1
  int count = 0, sum = 0;
  int* set = NULL;

  // Variables for Q2
  int countS = 0, countR = 0;
  int* S = NULL;
  int* T = NULL;
  int* R = NULL;

  // Variables for Q3
  int counts = 0, countT = 0;
  int* s = NULL;

  switch (i) {
    case 1:
      printf("Enter the size of the array\n");
      scanf("%d", &count);
      set = (int*)malloc(sizeof(int) * count);
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
      break;
    case 2:
      printf("Enter the size of the first array S\n");
      scanf("%d", &countS);
      S = (int*)malloc(sizeof(int) * countS);
      printf("Enter the elements of the first array\n");
      for (int i = 0; i < countS; i++) {
        scanf("%d", &S[i]);
      }
      printf("Enter the size of the second array T\n");
      scanf("%d", &count);
      T = (int*)malloc(sizeof(int) * count);
      R = (int*)malloc(sizeof(int) * count);
      printf("Enter the elements of the second array\n");
      for (int j = 0; j < count; j++) {
        scanf("%d", &T[j]);
      }
      setDifference(S, countS, T, count, R, countR);
      return (1);
      break;
    case 3:
      printf("Enter the size of the first array s\n");
      scanf("%d", &counts);
      s = (int*)malloc(sizeof(int) * counts);
      printf("Enter the elements of the first array\n");
      for (int i = 0; i < counts; i++) {
        scanf("%d", &s[i]);
      }
      printf("Enter the size of the second array T\n");
      scanf("%d", &countT);
      T = (int*)malloc(sizeof(int) * countT);
      printf("Enter the elements of the second array\n");
      for (int j = 0; j < countT; j++) {
        scanf("%d", &T[j]);
      }
      if (!properSubset(s, counts, T, countT)) {
        printf("No proper subset found\n");
      } else {
        printf("Success, s is a proper subset of T\n");
      }
      break;
    default:
      printf("Enter a valid number 1 - 3 to test question\n");
      return (0);
  }
  return (1);
}

int main() {
  int N = 0, check = 0;
  while (check == 0) {
    printf("Please enter the question number you would like to see (1-3)\n");
    scanf("%d", &N);
    check = question_select(N);
  }
  return (0);
}
