#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int ra;
  int cod;
  LinkedNode * next;
};

LinkedNode * appendNode (LinkedNode * last, int ra, int cod) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (tmp == NULL) return NULL;

  tmp->ra = ra;
  tmp->cod = cod;
  tmp->next = NULL;

  if (last != NULL)
    last->next = tmp;

  return tmp;
}

LinkedNode * insertNode (LinkedNode * curr, int ra, int cod) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (tmp == NULL) return NULL;

  tmp->ra = ra;
  tmp->cod = cod;

  if (curr == NULL) {
    tmp->next = NULL;
  } else {
    tmp->next = curr->next;
    curr->next = tmp;
  }

  return tmp;
}

LinkedNode * findLastByRa (LinkedNode * list, int ra) {
  if (list == NULL)
    return NULL;

  LinkedNode * curr, * prev, * found = NULL;
  for (curr = list; curr != NULL; prev = curr, curr = curr->next) {
    if (curr->ra == ra)
      found = curr;
  }

  if (found != NULL)
    return found;

  return prev;
}

LinkedNode * lerLista () {
  int ra, cod;
  LinkedNode * list = NULL, * last = NULL, * tmp = NULL;

  while (1) {
    scanf("%d", &ra);
    scanf("%d", &cod);

    if (ra == -1 && cod == -1)
      return list;

    tmp = findLastByRa(list, ra);
    last = insertNode(tmp, ra, cod);

    if (list == NULL) 
      list = last;
  }
}

void printList (LinkedNode * list) {
  LinkedNode * curr;
  for (curr = list; curr != NULL; curr = curr->next) {
    printf("%d %d\n", curr->ra, curr->cod);
  }
}

void freeList (LinkedNode * list) {
  LinkedNode * curr, * next;
  for (curr = list; curr != NULL; curr = next) {
    next = curr->next;
    free(curr);
  }
}

int main (int argc, char ** argv) {
  LinkedNode * list = NULL;
  list = lerLista();

  printList(list);

  freeList(list);

  return EXIT_SUCCESS;
}