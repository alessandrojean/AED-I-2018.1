#include <stdio.h>
#include <stdlib.h>

#define MINCAPACITY 10

typedef struct Stack Stack;
struct Stack {
  int top;
  int capacity;
  int * data;
};

Stack * createStack ();
int isEmpty (Stack * stack);
int isFull (Stack * stack);
int isAtQuarterOfCapacity (Stack * stack);
int push (Stack * stack, int element);
int pop (Stack * stack, int * element);
int increase (Stack * stack);
int decrease (Stack * stack);
void printStack (Stack * stack);
void freeStack (Stack * stack);

int main (int argc, char **argv) {
  Stack * stack = createStack();

  printf("\nPushing %d elements.\n", MINCAPACITY);

  for (int i = 0; i < MINCAPACITY; i++) {
    push(stack, i + 1);
  }

  printStack(stack);
  printf("Capacity: %d; Top: %d\n", stack->capacity, stack->top);
  printf("\nPushing %d more elements.\n", MINCAPACITY);

  for (int i = 0; i < MINCAPACITY; i++) {
    push(stack, i + MINCAPACITY + 1);
  }

  printStack(stack);
  printf("Capacity: %d; Top: %d\n", stack->capacity, stack->top);
  printf("\nPopping %d elements.\n", (MINCAPACITY * 6) / 4);

  int elem;
  for (int i = 0; i < (MINCAPACITY * 6) / 4; i++) {
    pop(stack, &elem);
  }

  printStack(stack);
  printf("Capacity: %d; Top: %d\n", stack->capacity, stack->top);

  freeStack(stack);

  return EXIT_SUCCESS;
}

Stack * createStack () {
  Stack * stack = malloc(sizeof(Stack));
  if (stack == NULL)
    return NULL;

  stack->data = malloc(MINCAPACITY * sizeof(int));
  if (stack->data == NULL) {
    free(stack);
    return NULL;
  }

  stack->top = 0;
  stack->capacity = MINCAPACITY;
  return stack;
}

int isEmpty (Stack * stack) {
  return !stack || !stack->top;
}

int isFull (Stack * stack) {
  return stack->top == stack->capacity;
}

int isAtQuarterOfCapacity (Stack * stack) {
  return ((double) stack->top / stack->capacity) == 0.25;
}

int push (Stack * stack, int element) {
  if (isFull(stack)) {
    if (increase(stack) == 0)
      return 0;
  }
  stack->data[stack->top] = element;
  return ++stack->top;
}

int pop (Stack * stack, int * element) {
  if (isEmpty(stack))
    return -1;

  *element = stack->data[--stack->top];

  if (isAtQuarterOfCapacity(stack)) {
    if (decrease(stack) == 0)
      return 0;
  }

  return stack->top;
}

int increase (Stack * stack) {
  int * newData = malloc(stack->capacity * 2 * sizeof(int));
  if (newData == NULL)
    return 0;

  // Copy the old elements to the new array.
  for (int i = 0; i < stack->top; i++)
    newData[i] = stack->data[i];

  stack->capacity *= 2;
  free(stack->data);
  stack->data = newData;

  return stack->capacity;
}

int decrease (Stack * stack) {
  int * newData = malloc((stack->capacity / 2) * sizeof(int));
  if (newData == NULL)
    return 0;

  // Copy the old elements to the new array.
  for (int i = 0; i < stack->top; i++)
    newData[i] = stack->data[i];

  stack->capacity /= 2;
  free(stack->data);
  stack->data = newData;

  return stack->capacity;
}

void printStack (Stack * stack) {
  for (int i = 0; i < stack->top; i++)
    printf("%d%s", stack->data[i], (i == stack->top - 1) ? "\n" : ", ");
}

void freeStack (Stack * stack) {
  if (stack == NULL)
    return;

  free(stack->data);
  free(stack);
}