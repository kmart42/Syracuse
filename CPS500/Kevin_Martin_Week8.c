/*================================================================*\
**
**  File Name     : Kevin_Martin_Week8.c
**  Creation Date : 11-23-2019
**  Last Modified : Thu 28 Nov 2019 09:35:47 PM PST
**  Compiler      : gcc -march=native -Wall -Werror -std=gnu99 -lm
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
  int value;
  struct TreeNode* left;
  struct TreeNode* right;
} TreeNode;

typedef struct Tree {
  TreeNode* root;
} Tree;

typedef struct Heap {
  int* array;
  int capacity;
  int size;
} Heap;

struct TreeNode* newNode(int data) {
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  node->value = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Heap* minHeap(int capacity) {
  Heap* h = (Heap*)malloc(sizeof(Heap));
  h->array = malloc(capacity * sizeof(int));
  h->capacity = capacity;
  h->size = 0;
  return h;
}

int search(TreeNode* node, int check) {
  if (node == NULL) {
    return 1;
  }
  if (!(search(node->left, check))) {
    return 0;
  }
  if (node->value < check) {
    return 0;
  }
  check = node->value;
  return search(node->right, check);
}

struct TreeNode* create(char* input) {
  struct TreeNode* root = newNode(input[0]);
  root->left = newNode(input[1]);
  root->right = newNode(input[2]);
  root->right->right = newNode(input[3]);
  root->right->right->left = newNode(input[4]);
  root->left->left = newNode(input[5]);
  root->left->right = newNode(input[6]);
  root->left->right->left = newNode(input[7]);
  root->left->right->right = newNode(input[8]);

  return root;
}

struct TreeNode* create2(char* input) {
  struct TreeNode* root = newNode(input[0]);
  root->left = newNode(input[1]);
  root->right = newNode(input[2]);
  root->right->right = newNode(input[3]);
  root->right->right->right = newNode(input[4]);  // Moved branch
  root->left->left = newNode(input[5]);
  root->left->right = newNode(input[6]);
  root->left->right->left = newNode(input[7]);
  root->left->right->right = newNode(input[8]);

  return root;
}

struct TreeNode* BSTCheck(char* input, int num) {
  printf("Tree %d  inputs: ", num);
  for (int i = 0; i < sizeof(input); i++) {
    printf("%d ", input[i]);
  }
  struct TreeNode* root = create(input);
  if (search(root, -10000)) {
    printf("\nTree is a BST\n");
  } else {
    printf("\nTree is NOT a BST\n");
  }
  return root;
}

struct TreeNode* BSTCheck2(char* input, int num) {
  printf("Tree %d  inputs: ", num);
  for (int i = 0; i < sizeof(input); i++) {
    printf("%d ", input[i]);
  }
  struct TreeNode* root = create2(input);
  if (search(root, -10000)) {
    printf("\nTree is a BST\n");
  } else {
    printf("\nTree is NOT a BST\n");
  }
  return root;
}

int isomorphic(struct TreeNode* tree1, struct TreeNode* tree2) {
  if (tree1 == NULL && tree2 == NULL) {
    return 1;
  }
  if (tree1 != NULL && tree2 != NULL) {
    return (isomorphic(tree1->left, tree2->left) &&
            isomorphic(tree1->right, tree2->right));
  }
  return 0;
}

void swap(struct Heap* input, int first, int second) {
  int tmp = input->array[first];
  input->array[first] = input->array[second];
  input->array[second] = tmp;
}

void heapify(struct Heap* input, int i) {
  /*
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int tmp = i;
  if (left < input->size && input->array[left] > input->array[i]) tmp = left;
  if (right < input->size && input->array[right] > input->array[tmp])
    tmp = right;
  if (tmp != i) {
    swap(input, input->array[i], input->array[tmp]);
    heapify(input, tmp);
  }
  */
  int tmp, start = (i - 1) / 2;
  if (input->array[start] > input->array[i]) {
    tmp = input->array[start];
    input->array[start] = input->array[i];
    input->array[i] = tmp;
    heapify(input, start);
  }
}

void heapAdd(Heap* h, int value) {
  if (h->size < h->capacity) {
    h->array[h->size] = value;
    heapify(h, h->size);
    h->size++;
  }
}

void heapPrint(struct Heap* input) {
  for (int i = 0; i < input->size; i++) {
    printf("%d ", input->array[i]);
  }
  printf("\n");
}


Heap* removeMin(struct Heap* input) {
  input->array[0] = input->array[input->size - 1];
  int new_size = input->size - 1;
  input->size = 0;
  for (int i = 0;i<new_size;i++){
  heapAdd(input, input->array[i]);
  }

  return input;
}

int main() {
  char notBST_arr[] = {2, 7, 5, 9, 4, 2, 6, 5, 11};  // is not a BST
  char BST_arr[] = {8, 3, 10, 14, 13, 1, 6, 4, 7};   // BST

  // Question 2
  struct TreeNode* tree1 =
      BSTCheck(notBST_arr, 1);  // first array, first tree mapping
  struct TreeNode* tree2 =
      BSTCheck(BST_arr, 2);  // second array, first tree mapping
  struct TreeNode* tree3 =
      BSTCheck2(BST_arr, 3);  // second array, second tree mapping

  // Question 1

  // should be isomorphic, same tree mappings (but different numbers)
  printf("\n");
  if (isomorphic(tree1, tree2) == 1) {
    printf("The first two trees are isomorphic\n");
  } else {
    printf("The first two trees are NOT isomorphic\n");
  }
  // should not be isomorphic, different tre mappings (even though same numbers)
  if (isomorphic(tree2, tree3) == 1) {
    printf("The second two trees are isomorphic\n");
  } else {
    printf("The second two trees are NOT isomorphic\n");
  }

  // Question 3
  //int heap_arr[] = {3, 2, 1, 5, 4};
  int heap_arr[] = {5, 8, 13, 2, 19};
  int heap_size = sizeof(heap_arr) / sizeof(int);
  Heap* input = minHeap(heap_size );
  for (int i = 0; i < heap_size; i++) {
    heapAdd(input, heap_arr[i]);

  }
  printf("\nIntial Heap: ");
  heapPrint(input);
  printf("Heap after min removal: ");
  input = removeMin(input);
  heapPrint(input);

  return 0;
}

