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

// Deleta o item na posição i.
void removeNodeAt (LinkedNode ** first, int i) {
  // Se a lista é vazia, não há nada a se fazer.
  if (*first == NULL)
    return;

  // Se a posição é zero, remover o primeiro
  // item e mudar o início para o próximo.
  if (i == 0) {
    LinkedNode * next = (*first)->next;
    free(*first);
    *first = next;
    return;
  }

  int j = 0;
  LinkedNode * curr = *first, * prev = NULL;
  for (; j < i && curr != NULL; prev = curr, curr = curr->next, j++);

  // Se a posição for maior que o tamanho,
  // não há nada a se deletar.
  if (curr == NULL)
    return;

  // Faz a distribuição e remove o item.
  prev->next = curr->next;
  free(curr);
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

  removeNodeAt(&list, 0);

  printList(list);

  removeNodeAt(&list, 5);

  printList(list);

  return EXIT_SUCCESS;
}
