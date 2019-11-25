/*================================================================*\
**
**  File Name     : Kevin_Martin_Week7.c
**  Creation Date : 11-17-2019
**  Last Modified : Tue 19 Nov 2019 08:50:15 PM PST
**  Compiler      : gcc -march=native -Wall -Werror -std=gnu99 -lm
**  Author        : Kevin Martin, kmarti44@syr.edu
**  Organization  : Syracuse University
***================================================================*/

#include <stdio.h>
#include <stdlib.h>

// Define the listNode struct and initialize the head
typedef struct listNode {
  char value;
  struct listNode* next;
} Node;

typedef struct list {
  Node* head;
} List;

// Function to push each element of array onto list
void push(struct listNode** Node, char letter) {
  struct listNode* tmp = (struct listNode*)malloc(sizeof(struct listNode));
  tmp->next = *Node;
  tmp->value = letter;
  *Node = tmp;
}

// Get array of chars into list format, starting with end and working back
struct listNode* initializeList(char* input) {
  struct listNode* List = NULL;
  for (int i = sizeof(input) - 1; i >= 0; i--) {
    push(&List, input[i]);
  }
  return List;
}

// Function to print for lists (before and after modification)
void printList(struct listNode* Node) {
  printf("head-");
  while (Node != NULL) {
    printf(">%c-", Node->value);
    Node = Node->next;
  }
  printf("/\n");
}

// Function to remove every other item off list
void removeEveryOther(struct listNode* Node) {
  if (Node == NULL) {
    return;
  }

  struct listNode* curr = Node->next;
  if (curr == NULL) {
    return;
  }
  Node->next = curr->next;
  free(curr);

  removeEveryOther(Node->next);
}

// Function to pop items off a list (LIFO)
void pop(struct listNode* Node) {
  char pop_char = '\0';
  struct listNode* new_node = NULL;
  while (Node != NULL) {
    new_node = Node->next;
    pop_char = Node->value;
    Node = new_node;
    printf("%c\n", pop_char);
  }
}

// Function to add items to queue, to be used with deque
void enque(struct listNode** Node, char letter) {
  struct listNode* tmp = (struct listNode*)malloc(sizeof(struct listNode));
  tmp->next = *Node;
  tmp->value = letter;
  *Node = tmp;
}

// Get array of chars into list format, starting with end and working back
struct listNode* initializeQueue(char* input) {
  struct listNode* List = NULL;
  for (int i = sizeof(input) - 1; i >= 0; i--) {
    enque(&List, input[i]);
  }
  return List;
}

// Function to deque items from list (FIFO)
void deque(struct listNode* Node) {
  char deq = '\0';
  if (Node->next == NULL) {
    deq = Node->value;
    printf("%c\n", deq);
    exit(0);
  }

  struct listNode* curr = Node;
  // Second to last node
  while (curr->next->next != NULL) {
    curr = curr->next;
  }
  // New curr node points to second to last, so remove the last
  deq = curr->next->value;
  curr->next = NULL;
  printf("%c\n", deq);
  // Recursive call for remaining nodes
  deque(Node);
}

void printArr(char* arr) {
  for (int i = 0; i < sizeof(arr); i++) {
    printf("%c ", arr[i]);
  }
  printf("\n");
}

void popArr(char* arr) {
  for (int i = 0; i < sizeof(arr); i++) {
    printf("%c\n", arr[i]);
    arr[i] = '\0';
  }
}

int main() {
  // Initialize the list and print the elements
  char input_list[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

  // Question 1: Remove every other item from list
  printf("*******Question 1*******\n");
  struct listNode* List = initializeList(input_list);
  printf("Initial list: ");
  printList(List);
  printf("New list: ");
  removeEveryOther(List);
  printList(List);

  // Question 2: Implement stack, using arry from Question 1
  printf("*******Question 2*******\n");
  printf("Initial array: ");
  printArr(input_list);
  printf("Popped:\n");
  popArr(input_list);

  // Question 3: Implement stack, using same list from Question 1
  char input_stack[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
  printf("*******Question 3*******\n");
  List = initializeList(input_stack);
  printf("Initial stack: ");
  printList(List);
  printf("Popped:\n");
  pop(List);

  // Question 4: Implement que, using a list
  printf("*******Question 4*******\n");
  char input_queue[] = {'1', '2', '3', '4', '5', '6', '7'};
  List = initializeQueue(input_queue);
  printf("Initial queue: ");
  printList(List);
  printf("Dequed:\n");
  deque(List);
  return 0;
}

