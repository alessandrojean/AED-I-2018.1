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

// Conta quantos elementos a lista possui.
int listSize (LinkedNode * first) {
  int n;
  for (n = 0; first != NULL; first = first->next, n++);

  return n;
}

// Divide a lista em duas metades.
void divideList(LinkedNode * list, LinkedNode ** l1, LinkedNode ** l2) {
  if (list == NULL)
    return;

  int n = listSize(list);
  // Arredonda a divisão para cima.
  int n1 = (n + 2 - 1) / 2;

  // O início da primeira sublista é a própria lista.
  *l1 = list;

  // Itera até o fim da primeira sublista.
  int i;
  LinkedNode * curr;
  for (i = 1, curr = list; i < n1; curr = curr->next, i++);

  // curr->next é o início da segunda sublista.
  *l2 = curr->next;
  // Define o fim da primeira sublista.
  curr->next = NULL;
}


int main (int argc, char **argv) {
  LinkedNode * list = malloc(sizeof(LinkedNode));
  LinkedNode * last = list;

  list->data = 1;
  list->next = NULL;
  
  for (int i = 1; i < 11; i++) {
    // TODO: Verificar se o retorno não é NULL.
    last = appendNode(last, i + 1);
  }

  printList(list);

  LinkedNode * list1 = NULL, * list2 = NULL;
  divideList(list, &list1, &list2);

  printList(list1);
  printList(list2);

  return EXIT_SUCCESS;
}
