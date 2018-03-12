#include <stdio.h>
#include <stdlib.h>

#define MINCAPACITY 15

typedef struct arrStack arrStack;

struct arrStack {
  int top;
  int capacity;
  int * data;
};

arrStack * createArrStack () {
  arrStack * temp = malloc(sizeof(arrStack));
  if (!temp)
    return NULL;
  temp->data = malloc(MINCAPACITY * sizeof(int));
  if (!temp->data) {
    free(temp);
    return NULL;
  }
  temp->top = 0;
  temp->capacity = MINCAPACITY;
  return temp;
}

int isEmpty (arrStack * stack) {
  return !stack || !stack->top;
}

int isFull (arrStack * stack) {
  return stack->top == stack->capacity;
}

int push (arrStack * stack, int elem) {
  if (isFull(stack))
    return 0;                      // return 0 if full
  stack->data[stack->top] = elem;
  return ++stack->top;             // returns the new size
}

int pop (arrStack * stack, int * elem) {
  if (isEmpty(stack))
    return -1;                     // return -1 if empty
  *elem = stack->data[--stack->top];
  return stack->top;               // returns the new size
}

void deleteStack (arrStack * stack) {
  if (!stack) {
    free(stack->data);
    free(stack);
  }
}

int main (int argc, char ** argv) {
  arrStack * stack = createArrStack();
  int i;

  printf("%d\n", push(stack, 1));
  printf("%d\n", push(stack, 145));
  printf("%d\n", pop(stack, &i));
  printf("%d\n", i);

  // Teste o código.

  return EXIT_SUCCESS;
}