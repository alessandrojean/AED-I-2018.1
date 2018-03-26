#include <stdlib.h>
#include <stdio.h>

typedef char Data;

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  Data data;
  LinkedNode * next;
};

typedef struct Stack Stack;
struct Stack {
  LinkedNode * top;
};

Stack * createStack ();
Stack * readStack ();
LinkedNode * push (Stack * stack, Data data);
Data pop (Stack * stack);
void printStack (Stack * stack);
void freeStack (Stack * stack);

int isSufixe (Stack * textA, Stack * textB);

int main (int argc, char ** argv) {
  // Leitura da primeira cadeia de entrada.
  Stack * textA = readStack();

  // Leitura da segunda cadeia de entrada.
  Stack * textB = readStack();

  // Verifica se a texto B é sufixo de texto A.
  int sufixe = isSufixe(textA, textB);
  printf("%s\n", sufixe ? "SIM" : "NAO");

  // Libera as estruturas da memória após o uso.
  freeStack(textA);
  freeStack(textB);

  return EXIT_SUCCESS;
}

Stack * createStack () {
  Stack * stack = malloc(sizeof(Stack));
  if (stack == NULL)
    return NULL;

  stack->top = NULL;

  return stack;
}

Stack * readStack () {
  Stack * stack = createStack();
  if (stack == NULL)
    return NULL;

  char atual = getchar();
  while (atual != '\n') {
    push(stack, atual);
    atual = getchar();
  }

  return stack;
}

LinkedNode * push (Stack * stack, Data data) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (tmp == NULL)
    return NULL;

  tmp->data = data;
  tmp->next = stack->top;
  stack->top = tmp;

  return tmp;
}

Data pop (Stack * stack) {
  if (stack == NULL || stack->top == NULL)
    return '\0';

  LinkedNode * tmp = stack->top;
  stack->top = tmp->next;

  Data data = tmp->data;
  free(tmp);

  return data;
}

void printStack (Stack * stack) {
  LinkedNode * curr = stack->top;
  for (; curr != NULL; curr = curr->next)
    printf("%c ", curr->data);

  printf("\n");
}

void freeStack (Stack * stack) {
  if (stack == NULL)
    return;

  LinkedNode * curr = stack->top, * next;
  for (; curr != NULL; curr = next) {
    next = curr->next;
    free(curr);
  }

  free(stack);
}

// Função que verifica se o texto B é
// sufixo de texto A. Caso verdade, retorna
// 1, caso falso, retorna 0.
int isSufixe (Stack * textA, Stack * textB) {
  if (textA == NULL || textA->top == NULL)
    return 0;
  if (textB == NULL || textB->top == NULL)
    return 0;

  Data tmp1 = pop(textA), tmp2 = pop(textB);
  int oneTime = 0;
  while (tmp1 != '\0' && tmp2 != '\0') {
    // Se o texto A diferir do texto B,
    // não é um sufixo.
    if (tmp1 != tmp2)
      return 0;

    tmp1 = pop(textA);
    tmp2 = pop(textB);
    oneTime = 1;
  }

  // Se não executou nenhuma vez, significa
  // que alguma das entradas é inválida,
  // e, consequentemente, não é um sufixo.
  if (!oneTime)
    return 0;

  return 1;
}
