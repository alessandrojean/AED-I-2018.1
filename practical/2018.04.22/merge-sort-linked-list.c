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

/* MergeSort. */
int compare (Value a, Value b);
LinkedNode * mergeSort (LinkedNode * first, int * comp);
LinkedNode * findMiddle (LinkedNode * first);
LinkedNode * merge (LinkedNode * a, LinkedNode * b, int * comp);

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

  first = mergeSort(first, &comp);

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
 * Efetua o algoritmo de ordenação
 * MergeSort em uma lista ligada.
 **/
LinkedNode * mergeSort (LinkedNode * first, int * comp) {
  if (first == NULL || first->next == NULL) {
    return first;
  }

  LinkedNode * mid, * second, * a, * b, * c;
  int ct = 0;

  // Acha o meio da lista.
  mid = findMiddle(first);
  // Ínicio da segunda metade.
  second = mid->next;
  second->prev = NULL;
  // Define o fim da primeira metade.
  mid->next = NULL;

  a = mergeSort(first, &ct);
  b = mergeSort(second, &ct);
  c = merge(a, b, &ct);

  *comp += ct;

  return c;
}

/**
 * Acha o meio da lista ligada, utilizando
 * o algoritmo lento-rápido. Uma das variáveis
 * é incrementada em uma (i->next), enquanto
 * a segunda é incrementada em duas (j->next->next).
 **/
LinkedNode * findMiddle (LinkedNode * first) {
  if (!first)
    return NULL;

  LinkedNode * i = first, * j = first;
  while (i->next && j->next && j->next->next) {
    i = i->next;
    j = j->next->next;
  }

  return i;
}

LinkedNode * merge (LinkedNode * a, LinkedNode * b, int * comp) {
  LinkedNode * result = NULL, * curr;
  // Inicia o primeiro nó da lista.
  if (compare(a->value, b->value) <= 0) {
    result = a;
    a = a->next;
  } else {
    result = b;
    b = b->next;
  }
  result->prev = NULL;
  curr = result;
  (*comp)++;

  // Itera até o fim de uma das listas.
  while (a != NULL && b != NULL) {
    if (compare(a->value, b->value) <= 0) {
      curr->next = a;
      curr->next->prev = curr;
      a = a->next;
    } else {
      curr->next = b;
      curr->next->prev = curr;
      b = b->next;
    }
    // Incrementa a lista nova.
    curr = curr->next;
    (*comp)++;
  }

  // Caso alguma das listas tenha acabado,
  // junta com o que restou da outra.
  curr->next = (!a) ? b : a;
  curr->next->prev = curr;

  return result;
}
