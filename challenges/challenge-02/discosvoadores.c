#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Opções disponíveis. */
#define INSERT 1
#define PRINT 2
#define SORT 8

/* Ordenações. */
#define MODEL_ASC 10
#define MODEL_DESC 11
#define CAPACITY_ASC 20
#define CAPACITY_DESC 21
#define VELOCITY_DESC_EFFICIENCY_DESC 50
#define VELOCITY_DESC_EFFICIENCY_ASC 51
#define DELIVERY_TIME_ASC 60
#define DELIVERY_TIME_DESC 61

/* Outras constantes. */
#define MODEL_SIZE 50
#define PRINT_NORMAL 0

/* Estrutura do disco voador. */
typedef struct FlyingSaucer FlyingSaucer;
struct FlyingSaucer {
  char * model;
  int velocity;
  double efficiency;
  int capacity;
  int deliveryTime;
};

/* Estrutura da lista ligada. */
typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  FlyingSaucer * flyingSaucer;
  LinkedNode * prev, * next;
};

/* Métodos para os discos voadores. */
FlyingSaucer * newFlyingSaucer (char * m, int v, double e, int c, int d);
void printFlyingSaucer (FlyingSaucer * flyingSaucer);
int compareFlyingSaucer (FlyingSaucer * a, FlyingSaucer * b, int mode);

/* Métodos para a lista ligada. */
LinkedNode * insert (LinkedNode * last, FlyingSaucer * value);
void printLinkedList (LinkedNode * first, int mode);
void freeLinkedList (LinkedNode * first);

/* Métodos para o QuickSort. */
void quickSort (LinkedNode * lo, LinkedNode * hi, int mode);
LinkedNode * partition (LinkedNode * lo, LinkedNode * hi, int mode);

int main (int argc, char **argv) {
  int op;
  scanf("%d", &op);

  LinkedNode * first = NULL, * last = NULL;

  while (op) {
    if (op == INSERT) {
      // Aloca dinamicamente uma string para
      // o modelo do disco voador.
      char * m = malloc(MODEL_SIZE * sizeof(char));
      int v, c, d;
      double e;
      scanf("%s %d %lf %d %d", m, &v, &e, &c, &d);

      // Cria um disco voador novo.
      FlyingSaucer * flyingSaucer = newFlyingSaucer(m, v, e, c, d);

      // Adiciona no fim da lista ligada.
      last = insert(last, flyingSaucer);
      if (!first) first = last;
    } else if (op == SORT) {
      int mode;
      scanf("%d", &mode);
      quickSort(first, last, mode);
      printLinkedList(first, mode);
    } else if (op == PRINT) {
      printLinkedList(first, PRINT_NORMAL);
    }

    scanf("%d", &op);
  }

  freeLinkedList(first);

  return EXIT_SUCCESS;
}

/**
 * Cria e retorna um novo disco voador com 
 * os valores especificados nos parâmetros da função.
 * 
 * Caso haja falta de memória, retorna NULL.
 **/
FlyingSaucer * newFlyingSaucer (char * m, int v, double e, int c, int d) {
  FlyingSaucer * flyingSaucer = malloc(sizeof(FlyingSaucer));
  if (!flyingSaucer) return NULL;

  flyingSaucer->model = m;
  flyingSaucer->velocity = v;
  flyingSaucer->efficiency = e;
  flyingSaucer->capacity = c;
  flyingSaucer->deliveryTime = d;

  return flyingSaucer;
}

/**
 * Imprime um disco voador no formato especificado.
 * 
 * Formato:
 * [M=model V=velocity KM-L=efficiency C=capacity E=deliveryTime]
 **/
void printFlyingSaucer (FlyingSaucer * flyingSaucer) {
  printf(
    "[M=%s V=%d KM-L=%.2lf C=%d E=%d]\n",
    flyingSaucer->model,
    flyingSaucer->velocity,
    flyingSaucer->efficiency,
    flyingSaucer->capacity,
    flyingSaucer->deliveryTime
  );
}

/**
 * Retorna a comparação entre o disco voador a e b,
 * de acordo com o modo especificado.
 **/
int compareFlyingSaucer (FlyingSaucer * a, FlyingSaucer * b, int mode) {
  int v = b->velocity - a->velocity;

  switch (mode) {
    case MODEL_ASC:
      return strcmp(a->model, b->model);
    case MODEL_DESC:
      return strcmp(b->model, a->model);
    case CAPACITY_ASC:
      return a->capacity - b->capacity;
    case CAPACITY_DESC:
      return b->capacity - a->capacity;
    case VELOCITY_DESC_EFFICIENCY_DESC:
      return (!v) ? b->efficiency - a->efficiency : v;
    case VELOCITY_DESC_EFFICIENCY_ASC:
      return (!v) ? a->efficiency - b->efficiency : v;
    case DELIVERY_TIME_ASC:
      return a->deliveryTime - b->deliveryTime;
    case DELIVERY_TIME_DESC:
      return b->deliveryTime - a->deliveryTime;
  }

  return 0;
}

/**
 * Insere um nó no final da lista ligada,
 * com o valor de value, e retorna o
 * último nó, ou seja, o nó criado.
 **/
LinkedNode * insert (LinkedNode * last, FlyingSaucer * value) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (!tmp) return NULL;

  tmp->flyingSaucer = value;
  tmp->next = NULL;
  tmp->prev = last;
  if (last) {
    last->next = tmp;
  }

  return tmp;
}

/**
 * Imprime a lista ligada no formato
 * especificado. Caso mode seja 0,
 * imprime [DISCOS] antes, caso contrário,
 * imprime o método de ordenação especificado.
 **/
void printLinkedList (LinkedNode * first, int mode) {
  if (mode == PRINT_NORMAL) printf("[DISCOS]\n");
  else printf("[O=%d]\n", mode);

  for (; first != NULL; first = first->next) {
    printFlyingSaucer(first->flyingSaucer);
  }
}

/**
 * Libera da memória a lista ligada.
 **/
void freeLinkedList (LinkedNode * first) {
  LinkedNode * next;
  for (; first != NULL; first = next) {
    next = first->next;
    free(first);
  }
}

/**
 * Efetua o algoritmo de ordenação QuickSort
 * na lista ligada delimitada por lo e hi,
 * utilizando como comparação o modo especificado.
 **/
void quickSort (LinkedNode * lo, LinkedNode * hi, int mode) {
  if (hi && lo != hi && lo != hi->next) {
    LinkedNode * mid = partition(lo, hi, mode);
    quickSort(lo, mid->prev, mode);
    quickSort(mid->next, hi, mode);
  }
}

/**
 * Particiona a lista ligada, separando os
 * elementos menores que o pivô e os maiores e
 * retornando o elemento pivô.
 **/
LinkedNode * partition (LinkedNode * lo, LinkedNode * hi, int mode) {
  // Elemento pivô.
  FlyingSaucer * key = lo->flyingSaucer, * aux;
  LinkedNode * mid = lo, * i = lo->next;

  for (; i != hi->next; i = i->next) {
    if (compareFlyingSaucer(i->flyingSaucer, key, mode) <= 0) {
      // Incrementa o mid.
      mid = mid->next;
      // Troca os valores de mid com i.
      aux = mid->flyingSaucer;
      mid->flyingSaucer = i->flyingSaucer;
      i->flyingSaucer = aux;
    }
  }

  // Coloca o pivô no lugar correto.
  lo->flyingSaucer = mid->flyingSaucer;
  mid->flyingSaucer = key;

  return mid;
}
