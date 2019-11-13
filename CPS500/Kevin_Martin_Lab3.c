/*===============================================================*\
**
**  File Name     : Kevin_Martin_Lab3.c (corrections to Lab2)
**  Creation Date : 10-23-2019
**  Last Modified : Thu 24 Oct 2019 09:31:24 PM PDT
**  Compiler      : gcc -march=native -Wall -werror -std=gnu99 -lm
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==============================================================*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// MAX constant for static array initialization
#define MAX 35

// Global variable for question 2
int globalVariable = 50;

// Point structure for question 4
struct Point {
  int b, c;
} p1, p2;

// Prototyped function declarations, based on suggestions in Lab 2 assignment
int power(int a, int b);
void reAssign(int **ptr);
int secondLargest(int arr[], int Num);
double distance(struct Point p1, struct Point p2);
int *createArray(int size);

// Switch statement to allow user to select question 1 - 5
int question_select(int i) {
  int x = 0, y = 0, N = 0, a_size = 0;
  int *ptr = NULL, *A = NULL;

  switch (i) {
    case 1:
      printf("Please enter two integers, a base x and a power y\n");
      scanf("%d", &x);
      scanf("%d", &y);
      power(x, y);
      break;
    case 2:
      reAssign(&ptr);
      printf("Pointer ptr points to the value of the globalVariable = %d\n",
             *ptr);
      break;
    case 3:
      printf("Please enter the size of the array\n");
      scanf("%d", &N);
      A = (int *)malloc(sizeof(int) * N);
      printf("Please enter the integers for the array followed by Enter\n");
      for (int j = 0; j < N; j++) {
        scanf("%d", &A[j]);
      }
      secondLargest(A, N);
      break;
    case 4:
      printf("Please enter the coordinates for the first point\n");
      scanf("%d", &p1.b);
      scanf("%d", &p1.c);
      printf("Please enter the coordinates for the second point\n");
      scanf("%d", &p2.b);
      scanf("%d", &p2.c);
      double get_dist = distance(p1, p2);
      printf("The distance between p1 and p2 is %.2f\n", get_dist);
      break;
    case 5:
      printf("Please enter the size of the array\n");
      scanf("%d", &a_size);
      createArray(a_size);
      break;
    default:
      printf("Please enter a number 1-5 to test that question\n");
      return (0);
  }
  return (1);
}

// Question 1: function takes two integers and returns x to the power of y
// *UPDATE* added checks for y=0, x=0, and y<0
int power(int x, int y) {
  int result = x;
  if (y == 0) {
    result = 1;
  } else if (x == 0 && y > 0) {
    result = 0;
  } else if (y < 0) {
    float resultf = 1 / (float)x;
    int z = abs(y);
    for (int j = 1; j < z; j++) {
      resultf *= (float)1 / x;
    }
    printf("%d to the power of %d = %f\n", x, z, (float)resultf);
    return (resultf);
  } else {
    for (int i = 1; i < y; i++) {
      result *= x;
    }
  }
  printf("%d to the power of %d = %d\n", x, y, result);
  return (result);
}

// Question 2: function to reassign pointer to a global variable
// The pointer variable ptr was initialized to NULL in question_select
// *UPDATE* moved print line out function, added double pointer argument type
void reAssign(int **ptr) { *ptr = &globalVariable; }

// Question 3: function to determine second largest value in array A[]
// Function comp to allow qsort to sort in ascending order
int comp(const void *a, const void *b) {
  int *x = (int *)a;
  int *y = (int *)b;
  return *x - *y;
}

int secondLargest(int A[], int N) {
  qsort(A, N, sizeof(A[0]), comp);
  int result = A[N - 2];
  printf("The second largest value in the array is %d\n", result);
  return (result);
}

// Question 4: compute the distance between two points x and y
double distance(struct Point p1, struct Point p2) {
  double dist_result = sqrt(pow(p1.b - p2.b, 2) + pow(p1.c - p2.c, 2));
  return (dist_result);
}

// Question 5: create array of given integer size
int *createArray(int a_size) {
  int *d_array = NULL;
  d_array = (int *)malloc(sizeof(int) * a_size);
  printf("There are %d elements in the array: ", a_size);
  for (int i = 0; i < a_size; i++) {
    printf("%d ", d_array[i]);
  }
  printf("\n");
  return (0);
}

// Main function prompts user for input to determine which question to run
int main() {
  int N = 0, check = 0;
  while (check == 0) {
    printf("Please enter the question number you would like to see (1-5)\n");
    scanf("%d", &N);
    check = question_select(N);
  }
  return (0);
}

