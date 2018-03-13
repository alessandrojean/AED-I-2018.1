#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int data;
  LinkedNode * next;
};

typedef struct Stack Stack;
struct Stack {
  LinkedNode * top;
};

typedef struct SevenSegmentsDisplay SevenSegmentsDisplay;
struct SevenSegmentsDisplay {
  int a;
  int b;
  int c;
  int d;
  int e;
  int f;
  int g;
  char digit;
};

typedef struct Digit Digit;
struct Digit {
  SevenSegmentsDisplay * display;
  Digit * next;
};

SevenSegmentsDisplay DIGITS[] = {
  { 1, 1, 1, 1, 1, 1, 0 }, // 0 (i =  0)
  { 0, 1, 1, 0, 0, 0, 0 }, // 1 (i =  1)
  { 1, 1, 0, 1, 1, 0, 1 }, // 2 (i =  2)
  { 1, 1, 1, 1, 0, 0, 1 }, // 3 (i =  3)
  { 0, 1, 1, 0, 0, 1, 1 }, // 4 (i =  4)
  { 1, 0, 1, 1, 0, 1, 1 }, // 5 (i =  5)
  { 1, 0, 1, 1, 1, 1, 1 }, // 6 (i =  6)
  { 1, 1, 1, 0, 0, 0, 0 }, // 7 (i =  7)
  { 1, 1, 1, 1, 1, 1, 1 }, // 8 (i =  8)
  { 1, 1, 1, 1, 0, 1, 1 }, // 9 (i =  9)
  { 1, 1, 1, 0, 1, 1, 1 }, // A (i = 10)
  { 0, 0, 1, 1, 1, 1, 1 }, // b (i = 11)
  { 1, 0, 0, 1, 1, 1, 0 }, // C (i = 12)
  { 0, 1, 1, 1, 1, 0, 1 }, // d (i = 13)
  { 1, 0, 0, 1, 1, 1, 1 }, // E (i = 14)
  { 1, 0, 0, 0, 1, 1, 1 }, // F (i = 15)
};

Stack * createStack ();
int isEmpty (Stack * stack);
LinkedNode * push (Stack * stack, int element);
int pop (Stack * stack);
void printStack (Stack * stack);
void freeStack (Stack * stack);

Stack * readNumber ();
Digit * binaryStackToHex (Stack * stack);
int fourBitArrayIsEnd (int * array);
int fourBitArrayToDecimal (int * array);
void printRepresentation (Digit * digits);
void freeDigits (Digit * digits);

int main (int argc, char **argv) {
  Stack * stack = readNumber();

  // printStack(stack);

  Digit * digits = binaryStackToHex(stack);

  printRepresentation(digits);

  freeStack(stack);
  freeDigits(digits);

  return EXIT_SUCCESS;
}

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

LinkedNode * push (Stack * stack, int element) {
  LinkedNode * node = malloc(sizeof(node));
  if (node == NULL)
    return NULL;

  node->data = element;

  if (isEmpty(stack)) {
    stack->top = node;
    node->next = NULL;
  } else {
    node->next = stack->top;
    stack->top = node;
  }

  return node;
}

int pop (Stack * stack) {
  if (isEmpty(stack))
    return -1;

  LinkedNode * top = stack->top;
  stack->top = top->next;

  top->next = NULL;

  int data = top->data;
  free(top);

  return data;
}

void printStack (Stack * stack) {
  for (LinkedNode * curr = stack->top; curr != NULL; curr = curr->next) {
    printf("%d", curr->data);
  }
  printf("\n");
}

void freeStack (Stack * stack) {
  for (LinkedNode * curr = stack->top, * next; curr != NULL; curr = next) {
    next = curr->next;
    free(curr);
  }
  free(stack);
}

Stack * readNumber () {
  Stack * stack = createStack();

  char c;
  while (1) {
    scanf("%c", &c);
    if (c == 'b')
      break;

    push(stack, c - '0');
  }

  return stack;
}

int fourBitArrayIsEnd (int * array) {
  return array[0] == -1 || array[1] == -1 || array[2] == -1 || array[4] == -1;
}

Digit * binaryStackToHex (Stack * stack) {
  int n = 0;
  int fourBitNumber[4] = {1,1,1,1};
  Digit * digits = NULL, * tmp;
  while (1) {
    for (int i = 0; i < 4; i++)
      fourBitNumber[i] = pop(stack);

    n = fourBitArrayToDecimal(fourBitNumber);
    tmp = malloc(sizeof(Digit));
    tmp->display = &(DIGITS[n]);
    if (digits == NULL) {
      digits = tmp;
      digits->next = NULL;
    } else {
      tmp->next = digits;
      digits = tmp;
    }

    if (fourBitArrayIsEnd(fourBitNumber)) {
      break;
    }

    n = 0;
  }

  // Remove the landing zeros.
  Digit * c, * next;
  for (c = digits; c != NULL && c->display == &(DIGITS[0]); c = next) {
    next = c->next;
    free(c);
  }

  digits = next;

  return digits;
}

int fourBitArrayToDecimal (int * array) {
  int n = 0;
  for (int i = 0, m = 1; i < 4; i++, m *= 2)
    n += array[i] == -1 ? 0 : m * array[i];
  return n;
}

void printRepresentation (Digit * digits) {
  // Laço que cuida das 3 linhas.
  for (int i = 0; i < 3; i++) {
    // Laço que cuida de cada segmento na lista ligada.
    for (Digit * c = digits; c != NULL; c = c->next) {
      if (i == 0) {
        printf(c->display->a ? " _ " : "   ");
      }else if (i == 1) {
        printf("%c%c%c", 
          c->display->f ? '|' : ' ',
          c->display->g ? '_' : ' ',
          c->display->b ? '|' : ' '
        );
      } else {
        printf("%c%c%c", 
          c->display->e ? '|' : ' ',
          c->display->d ? '_' : ' ',
          c->display->c ? '|' : ' '
        );
      }
      printf(" ");
    }
    printf("\n");
  }
}

void freeDigits (Digit * digits) {
  for (Digit * c = digits, * n; c != NULL; c = n) {
    n = c->next;
    free(c);
  }
}