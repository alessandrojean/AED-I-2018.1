#include <stdio.h>
#include <stdlib.h>

typedef int Value;

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  Value value;
  LinkedNode * prev, * next;
};

/* Linked list. */
LinkedNode * insert (LinkedNode * last, Value value);
int search (LinkedNode * first, Value value);
void printLinkedList (LinkedNode * first);
void freeLinkedList (LinkedNode * first);

/* QuickSort. */
int compare (Value a, Value b);
LinkedNode * findLast (LinkedNode * first);
LinkedNode * partition (LinkedNode * lo, LinkedNode * hi, int * comp);
int QuickSort (LinkedNode * lo, LinkedNode * hi);
int quickSort (LinkedNode * first);

int main (int argc, char **argv) {
  int v[] = { 8, 4, 9, 1, 5, 7, 2, 3 };
  int n = sizeof(v) / sizeof(v[0]), comp = 0;

  LinkedNode * first = NULL, * last = NULL;

  for (int i = 0; i < n; i++) {
    last = insert(last, v[i]);
    if (!first)
      first = last;
  }

  printLinkedList(first);

  comp = quickSort(first);

  printLinkedList(first);

  printf("Comparisons: %d\n", comp);

  freeLinkedList(first);

  return EXIT_SUCCESS;
}

/**
 * Insere um nó no final da lista ligada,
 * com valor value.
 **/
LinkedNode * insert (LinkedNode * last, Value value) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (!tmp) return NULL;

  tmp->value = value;
  tmp->next = NULL;
  tmp->prev = last;
  if (last) {
    last->next = tmp;
  }

  return tmp;
}

/**
 * Busca na lista ligada por um nó com
 * valor igual a value e retorna seu índice.
 * Caso não exista, retorna -1.
 **/
int search (LinkedNode * first, Value value) {
  for (int i = 0; first != NULL; first = first->next, i++) {
    if (first->value == value)
      return i;
  }
  return -1;
}

/**
 * Imprime a lista ligada.
 **/
void printLinkedList (LinkedNode * first) {
  for (; first != NULL; first = first->next)
    printf("%d ", first->value);
  printf("\n");
}

/**
 * Libera da memória a lista ligada.
 **/
void freeLinkedList (LinkedNode * first) {
  for (LinkedNode * next; first != NULL; first = next) {
    next = first->next;
    free(first);
  }
}

/**
 * Retorna a comparação entre a e b.
 **/
int compare (Value a, Value b) {
  return a - b;
}

/**
 * Acha o fim da lista ligada.
 **/
LinkedNode * findLast (LinkedNode * first) {
  for (; first != NULL && first->next != NULL; first = first->next);
  return first;
}

/**
 * Efetua o algoritmo de ordenação
 * QuickSort em uma lista ligada.
 **/
int quickSort (LinkedNode * first) {
  LinkedNode * last = findLast(first);
  return QuickSort(first, last);
}

/**
 * Função recursiva que efetua o QuickSort 
 * na lista ligada, limitada por lo e hi.
 **/
int QuickSort (LinkedNode * lo, LinkedNode * hi) {
  int comp = 0;
  if (hi && lo != hi && lo != hi->next) {
    LinkedNode * mid = partition(lo, hi, &comp);
    comp += QuickSort(lo, mid->prev);
    comp += QuickSort(mid->next, hi);
  }
  return comp;
}

LinkedNode * partition (LinkedNode * lo, LinkedNode * hi, int * comp) {
  // Elemento pivô.
  Value key = lo->value, aux;
  LinkedNode * mid = lo, * i = lo->next;

  for (; i != hi->next; i = i->next) {
    if (compare(i->value, key) <= 0) {
      // Incrementa o mid.
      mid = mid->next;
      // Troca os valores de mid com i.
      aux = mid->value;
      mid->value = i->value;
      i->value = aux;
    }
    (*comp)++;
  }

  // Coloca o pivô no lugar correto.
  lo->value = mid->value;
  mid->value = key;

  return mid;
}
