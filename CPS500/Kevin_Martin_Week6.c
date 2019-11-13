/*===========================================================*\
**
**  File Name     : Kevin_Martin_Week6.c
**  Creation Date : 11-07-2019
**  Last Modified : Mon 11 Nov 2019 07:48:22 PM PST
**  Compiler      : gcc -march=native -Wall -werror -std=gnu99
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***==========================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Question1: replace each integer with the product of every other element
int product(int lhs, int count, int size, int arr[]) {
  int temp = arr[count];

  // Base case, check if at end of array.
  // If so, set index to the prior elements
  if (count >= size - 1) {
    arr[count] = lhs;
    return temp;
  }
  // Update left side to include current index
  int left_prod = lhs * arr[count];

  // Move one past index, find product of all numbers to the right
  int rhs = product(left_prod, count + 1, size, arr);

  // Current index of array is set to product of all other elements, excluding itself
  arr[count] = lhs * rhs;

  // Inlclude current index in remaining values
  return rhs * temp;
}

// Question 2: given an number and power, find the result of raising the given
// number to the given power
int power(int x, int pow) {
  // Base case, no more powers to multiply by
  if (pow == 1) {
    return (x);
  }
  // Recursive call
  return x * power(x, pow - 1);
}

// Question 3: print all permuations of string containing unique chars
void stringPerm(char* input, int beg, int end) {
  // Base case, traversed entire input array
  if (beg == end) {
    printf("%s\n", input);
  } else {
    for (int i = beg; i <= end; i++) {
      // Move up the array and swap the next pair of chars
      
      char temp1 = *(input + beg);
      *(input + beg) = *(input + i);
      *(input + i) = temp1;

      // Recursive call
      stringPerm(input, beg + 1, end);

      // Swap the two chars back to where they were and continue
      temp1 = *(input + beg);
      *(input + beg) = *(input + i);
      *(input + i) = temp1;
    }
  }
}

int main() {
  // Question 1 variables
  int arr[] = {1, 2, 3, 4, 5};  // EDIT HERE TO TEST
  int size = sizeof(arr) / sizeof(arr[0]);
  int start = 1, count = 0;
  // int* result = malloc(size);

  // Question 2 variables
  int x = 5, y = 4;  // EDIT HERE TO TEST

  // Question 3 variable
  char input[] = "ABC";  // EDIT HERE TO TEST
  int input_length = strlen(input) - 1;

  // Function calls
  printf("Question 1:\n");
  printf("Input: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\nOutput: ");
  product(start, count, size, arr);
  for (int j = 0; j < size; j++) {
    printf("%d ", arr[j]);
  }

  printf("\n\nQuestion 2:\n");
  printf("%d raised to the power of %d is %d", x, y, power(x, y));

  printf("\n\nQuestion 3:\n");
  printf("Input: %s\n", input);
  printf("Output:\n");
  stringPerm(input, 0, input_length);
  return 0;
}
