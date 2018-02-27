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

// Concatena duas listas ligadas, ligando o final de list1
// ao inicio de list2, modificando list1.
LinkedNode * concatenate (LinkedNode * list1, LinkedNode * list2) {
  // Se a primeira lista for vazia, basta apenas 
  // retornar a segunda lista.
  if (list1 == NULL)
    return list2;

  // Percorre toda a primeira lista até o final.
  LinkedNode * curr;
  for (curr = list1; curr->next != NULL; curr = curr->next);

  // Como curr é o último elemento da primeira lista,
  // basta ligá-lo ao início da segunda lista, mesmo
  // ela sendo vazia.
  curr->next = list2;

  return list1;
}

int main (int argc, char **argv) {
  LinkedNode * list1 = malloc(sizeof(LinkedNode));
  LinkedNode * list2 = malloc(sizeof(LinkedNode));
  LinkedNode * last1 = list1, * last2 = list2;

  list1->data = 1;
  list1->next = NULL;
  // TODO: Verificar se o retorno não é NULL.
  last1 = appendNode(last1, 2);
  last1 = appendNode(last1, 3);

  printList(list1);

  list2->data = 4;
  list2->next = NULL;
  // TODO: Verificar se o retorno não é NULL.
  last2 = appendNode(last2, 5);
  last2 = appendNode(last2, 6);

  printList(list2);

  LinkedNode * listC = concatenate(list1, list2);

  printList(listC);

  return EXIT_SUCCESS;
}
