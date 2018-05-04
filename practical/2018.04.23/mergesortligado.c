#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int ra;
  int nota;
  LinkedNode * next;
};

LinkedNode * insert (LinkedNode * last, int ra, int nota);
void printLinkedList (LinkedNode * first);
void freeLinkedList (LinkedNode * first);

int compare (int raA, int raB, int asc);
LinkedNode * mergeSort (LinkedNode * first, LinkedNode ** last, int asc);
LinkedNode * findMiddle (LinkedNode * first);
LinkedNode * merge (LinkedNode * a, LinkedNode * b, LinkedNode ** last, int asc);

int main (int argc, char ** argv) {
  LinkedNode * first = NULL, * last = NULL;
  int op, ra, nota;
  scanf("%d", &op);

  while (op != 0) {
    if (op == 1) {
      scanf("%d %d", &ra, &nota);
      last = insert(last, ra, nota);
      if (!first)
        first = last;
    } else if (op == 2) {
      printLinkedList(first);
    } else if (op == 6) {
      first = mergeSort(first, &last, 1);
      printLinkedList(first);
    } else if (op == 9) {
      first = mergeSort(first, &last, 0);
      printLinkedList(first);
    }

    scanf("%d", &op);
  }

  freeLinkedList(first);

  return EXIT_SUCCESS;
}

/**
 * Insere um novo elemento com os valores
 * de ra e nota ao fim da lista.
 * Retorna o novo final.
 **/
LinkedNode * insert (LinkedNode * last, int ra, int nota) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (!tmp) return NULL;

  tmp->ra = ra;
  tmp->nota = nota;
  tmp->next = NULL;
  if (last) {
    last->next = tmp;
  }

  return tmp;
}

/**
 * Imprime a lista ligada no formato proposto.
 **/
void printLinkedList (LinkedNode * first) {
  printf("[LISTA]\n");
  for (; first != NULL; first = first->next)
    printf("[%d %d]\n", first->ra, first->nota);
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
 * Retorna a comparação entre raA e raB.
 * Se asc for verdadeiro, compara raA com raB,
 * caso contrário, compara raB com raA.
 **/
int compare (int raA, int raB, int asc) {
  return (asc) ? raA - raB : raB - raA;
}

/**
 * Efetua o algoritmo de ordenação
 * MergeSort na lista ligada, atualizando
 * o ponteiro para o novo último elemento.
 * 
 * Se asc for verdadeiro, ordena em ordem
 * crescente, caso contrário, ordena em
 * ordem decrescente.
 **/
LinkedNode * mergeSort (LinkedNode * first, LinkedNode ** last, int asc) {
  if (!first || !first->next)
    return first;

  LinkedNode * mid, * second, * a, * b;

  // Acha o meio da lista.
  mid = findMiddle(first);
  // Define o inicio da segunda metade.
  second = mid->next;
  // Define o fim da primeira metade.
  mid->next = NULL;

  a = mergeSort(first, &mid, asc);
  b = mergeSort(second, last, asc);
  return merge(a, b, last, asc);
}

/**
 * Acha o meio da lista ligada e retorna-o.
 **/
LinkedNode * findMiddle (LinkedNode * first) {
  if (!first)
    return NULL;

  // O i percorre na velocidade normal,
  // enquanto j percorre com o dobro.
  // Assim, quando j chegar ao fim,
  // i estará exatamente na metade da lista.
  LinkedNode * i = first, * j = first;
  while (i->next && j->next && j->next->next) {
    i = i->next;
    j = j->next->next;
  }

  return i;
}

/**
 * Junta duas listas ligadas a e b,
 * atualizando o ponteiro para o novo último elemento,
 * e retorna a nova lista.
 * 
 * Se asc for verdadeiro, junta em ordem
 * crescente, caso contrário, junta em
 * ordem decrescente.
 **/
LinkedNode * merge (LinkedNode * a, LinkedNode * b, LinkedNode ** last, int asc) {
  LinkedNode * result = NULL, * curr;
  // Inicia o primeiro nó da lista.
  if (compare(a->ra, b->ra, asc) <= 0) {
    result = curr = a;
    a = a->next;
  } else {
    result = curr = b;
    b = b->next;
  }

  // Itera até o fim da lista menor.
  while (a && b) {
    if (compare(a->ra, b->ra, asc) <= 0) {
      curr->next = a;
      a = a->next;
    } else {
      curr->next = b;
      b = b->next;
    }
    // Avança para a próxima posição.
    curr = curr->next;
  }

  // Junta com o possível restante da lista maior.
  curr->next = (!a) ? b : a;

  // Acha o fim da lista.
  LinkedNode * c = curr->next;
  for (; c && c->next; c = c->next);

  // Define o fim apropriado.
  *last = (!c) ? curr : c;

  return result;
}
