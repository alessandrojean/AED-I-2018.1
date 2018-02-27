#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int data;
  LinkedNode * next;
};

LinkedNode * appendNode (LinkedNode * last, int num) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (tmp == NULL)
    return NULL;

  tmp->data = num;
  tmp->next = NULL;

  if (last != NULL)
    last->next = tmp;

  return tmp;
}

void printList (LinkedNode * first) {
  LinkedNode * curr = first;
  while (curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

// Insere um item na posição i.
void insertNodeAt (LinkedNode ** first, int num, int i) {
  // Se a lista está vazia e a posição for diferente
  // de zero, não há nada a se fazer.
  if (*first == NULL && i != 0)
    return;

  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (tmp == NULL)
    return;

  tmp->data = num;
  tmp->next = NULL;

  // Se a lista está vazia, mas a posição é zero,
  // insira-a no início.
  if (*first == NULL && i == 0) {
    *first = tmp;
    return;
  }

  // Se a lista não é vazia, mas a posição é zero,
  // mude o início para tmp, e defina seu next como
  // o início da lista.
  if (i == 0) {
    tmp->next = *first;
    *first = tmp;
    return;
  }

  // Se não for nenhum dos casos anteriores,
  // itere a lista até achar o elemento de posição i.
  int j = 0;
  LinkedNode * curr = *first, * prev = NULL;
  for (; j < i && curr != NULL; prev = curr, curr = curr->next, j++);

  // No fim, se a posição i for maior que o tamanho
  // da lista, o elemento será inserido no final,
  // se for o caso.
  tmp->next = curr;
  prev->next = tmp;
}

int main (int argc, char **argv) {
  LinkedNode * list = malloc(sizeof(LinkedNode));
  LinkedNode * last = list;

  list->data = 1;
  list->next = NULL;
  
  for (int i = 1; i < 10; i++) {
    // TODO: Verificar se o retorno não é NULL.
    last = appendNode(last, i + 1);
  }

  printList(list);

  insertNodeAt(&list, 11, 11);

  printList(list);

  return EXIT_SUCCESS;
}
