#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  double data;
  LinkedNode * next;
};

typedef struct Stack Stack;
struct Stack {
  LinkedNode * top;
};

Stack * createStack () {
  Stack * stack = malloc(sizeof(stack));
  if (stack == NULL)
    return NULL;

  stack->top = NULL;

  return stack;
}

int isEmpty (Stack * stack) {
  return stack == NULL || stack->top == NULL;
}

LinkedNode * push (Stack * stack, double data) {
  LinkedNode * node = malloc(sizeof(node));
  if (node == NULL)
    return NULL;

  node->data = data;

  if (isEmpty(stack)) {
    stack->top = node;
    node->next = NULL;
  } else {
    node->next = stack->top;
    stack->top = node;
  }

  return node;
}

double pop (Stack * stack) {
  if (isEmpty(stack))
    return -1;

  LinkedNode * top = stack->top;
  stack->top = top->next;

  top->next = NULL;

  double data = top->data;
  free(top);

  return data;
}

void freeStack (Stack * stack) {
  if (stack == NULL)
    return;

  LinkedNode * current, * next;
  for (current = stack->top; current != NULL; current = next) {
    next = current->next;
    free(current);
  }

  free(stack);
}

void printError (Stack * stack) {
  freeStack(stack);
  printf("ERRO\n");
  exit(0);
}

void operationH (Stack * stack) {
  double n1 = pop(stack);

  if (n1 == -1)
    printError(stack);

  push(stack, n1 * 3);
}

void operationSum (Stack * stack) {
  double n2 = pop(stack), n1 = pop(stack);

  if (n1 == -1 || n2 == -1)
    printError(stack);

  push(stack, n1 + n2);
}

void operationSubtract (Stack * stack) {
  double n2 = pop(stack), n1 = pop(stack);

  if (n1 == -1 || n2 == -1)
    printError(stack);

  push(stack, n1 - n2);
}

void operationF (Stack * stack) {
  double n3 = pop(stack), n2 = pop(stack), n1 = pop(stack);

  if (n1 == -1 || n2 == -1 || n3 == -1)
    printError(stack);

  push(stack, (n1 * n1) - (n2 / 2) + n3);
}

void operationG (Stack * stack) {
  double n3 = pop(stack), n2 = pop(stack), n1 = pop(stack);

  if (n1 == -1 || n2 == -1 || n3 == -1)
    printError(stack);

  push(stack, (n1 * n2) + n3);
}

Stack * calculate (char * input, double * result) {
  Stack * stack = createStack();

  int i;
  char curr;
  for (i = 0; input[i] != '\0'; i++) {
    curr = input[i];

    if (curr >= '0' && curr <= '9') {
      push(stack, (double) curr - '0');
    } else if (curr == 'h') {
      operationH(stack);
    } else if (curr == '+') {
      operationSum(stack);
    } else if (curr == '-') {
      operationSubtract(stack);
    } else if (curr == 'f') {
      operationF(stack);
    } else if (curr == 'g') {
      operationG(stack);
    }
  }

  if(stack->top == NULL || stack->top->next != NULL)
    printError(stack);

  *result = stack->top->data;

  return stack;
} 

int main (int argc, char ** argv) {
  char input[100];
  scanf("%100s", input);

  double result;
  Stack * stack = calculate(input, &result);

  printf("%.2lf\n", result);

  freeStack(stack);

  return EXIT_SUCCESS;
}