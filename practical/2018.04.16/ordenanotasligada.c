/**
 * Developed by @alessandrojean and @IsabellaLima
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int ra;
  char * nome;
  int nota;
  LinkedNode * prev, * next;
};

LinkedNode * insert (LinkedNode * last, int ra, char * nome, int nota);
int searchByRA (LinkedNode * first, int ra);
int selectionSort (LinkedNode ** first, LinkedNode ** last, int option);
int insertionSort (LinkedNode ** first, LinkedNode ** last, int option);
void swapLinkedNodes (LinkedNode ** first, LinkedNode * x, LinkedNode * y);
void printLinkedList (LinkedNode * first);
void freeLinkedList (LinkedNode * first);

int main (int argc, char ** argv) {
  LinkedNode * first = NULL, * last = NULL;
  char o;
  scanf("\n%c", &o);

  while (o != 'P') {
    if (o == 'I') {
      int ra, nota;
      char * nome = malloc(50 * sizeof(char));
      scanf("%d %s %d", &ra, nome, &nota);
      last = insert(last, ra, nome, nota);
      if (first == NULL)
        first = last;
    } else if (o == 'O') {
      int alg, op, comp;
      scanf("%d %d", &alg, &op);
      comp = (alg == 1)
        ? selectionSort(&first, &last, op)
        : insertionSort(&first, &last, op);
      printf("Comparacoes=%d\n", comp);
    } else if (o == 'B') {
      int ra, pos;
      scanf("%d", &ra);
      pos = searchByRA(first, ra);
      printf("Pos=%d\n", pos);
    } else if (o == 'M') {
      printLinkedList(first);
    }

    scanf("\n%c", &o);
  }

  freeLinkedList(first);

  return EXIT_SUCCESS;
}

/**
 * Insere no final da lista ligada
 * um novo nó com os valores de ra,
 * nome e nota especificados.
 **/
LinkedNode * insert (LinkedNode * last, int ra, char * nome, int nota) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (tmp == NULL) return NULL;

  tmp->ra = ra;
  tmp->nome = nome;
  tmp->nota = nota;
  tmp->next = NULL;
  tmp->prev = last;
  if (last != NULL) {
    last->next = tmp;
  }

  return tmp;
}

/**
 * Busca na lista ligada pelo nó
 * com o ra igual ao especificado.
 * Caso não exista, retorna -1,
 * senão, retorna a posição.
 **/
int searchByRA (LinkedNode * first, int ra) {
  for (int i = 0; first != NULL; first = first->next, i++) {
    if (first->ra == ra)
      return i;
  }
  return -1;
}

/**
 * Ordena a lista ligada com o algoritmo
 * Selection Sort, atualizando o nó cabeça
 * e o no final caso necessário.
 * O campo chave é especificado através de option,
 * podendo assumir:
 * 
 * 1) RA;
 * 2) Nome.
 *
 * Retorna a quantidade de comparações realizadas.
 **/
int selectionSort (LinkedNode ** first, LinkedNode ** last, int option) {
  long int count = 0;
  LinkedNode * i, * j, * min;

  // Iterar de i até n - 1.
  for (i = *first; i->next != NULL; i = i->next) {
    // Tomar o item em i como o mínimo.
    min = i;
    // Iterar de j = i + 1 até n.
    for (j = i->next; j != NULL; j = j->next) {
      // É menor que o mínimo?
      if ((option == 1 && min->ra > j->ra) ||
          (option == 2 && strcmp(min->nome, j->nome) > 0)) {
        // Armazena a posição do novo mínimo.
        min = j;
      }
      // Incrementa o contador de comparações.
      count++;
    }

    // Se é necessário trocar.
    if (min != i) {
      // Troca os nós i com o min.
      swapLinkedNodes(first, i, min);
      // Estabelece i como min, pois o
      // valor mudou e o laço precisa
      // continuar sem intereferências.
      i = min;
    }
  }

  // Atualiza o nó final.
  *last = i;

  return count;
}

/**
 * Ordena a lista ligada com o algoritmo
 * Insertion Sort, atualizando o nó cabeça
 * e o final caso necessário.
 * O campo chave é especificado através de option,
 * podendo assumir:
 * 
 * 1) RA;
 * 2) Nome.
 * 
 * Retorna a quantidade de comparações realizadas.
 **/
int insertionSort (LinkedNode ** first, LinkedNode ** last, int option) {
  LinkedNode * i, * nextI, * j, * key;
  long int comp = 0;

  // Itera de 1 até n.
  for (i = (*first)->next; i != NULL; i = nextI) {
    // Armazena o nó com a chave a comparar.
    key = j = i;
    // Armazena o próximo a i,
    // pois este pode ser modificado.
    nextI = i->next;
    // Enquanto j não está na posição correta.
    while (j->prev != NULL && ++comp &&
           ((option == 1 && j->prev->ra > key->ra) ||
            (option == 2 && strcmp(j->prev->nome, key->nome) > 0))) {
      
      // Armazena o anterior a j para modificar o final.
      LinkedNode * prevJ = j->prev;
      // Troca j - 1 com j.
      swapLinkedNodes(first, prevJ, j);

      // Se o j anteriormente era o
      // fim da lista, mude-o para o
      // novo fim, prevJ.
      if (*last == j)
        *last = prevJ;
    }
  }

  return comp;
}

/**
 * Troca na lista ligada os nós x e y de posição,
 * corrigindo o nó cabeça caso necessário.
 **/
void swapLinkedNodes (LinkedNode ** first, LinkedNode * x, LinkedNode * y) {
  // Troca os next de x com y.
  LinkedNode * tmp = x->next;
  x->next = y->next;
  y->next = tmp;

  // Atualiza o prev do novo next de x.
  if (x->next != NULL)
    x->next->prev = x;
  // Atualiza o prev do novo next de y.
  if (y->next != NULL)
    y->next->prev = y;

  // Troca os prev de x com y.
  tmp = x->prev;
  x->prev = y->prev;
  y->prev = tmp;

  // Atualiza o next do novo prev de x.
  if (x->prev != NULL)
    x->prev->next = x;
  // Senão, x deve virar o novo nó cabeça.
  else *first = x;

  // Atualiza o next do novo prev de y.
  if (y->prev != NULL)
    y->prev->next = y;
  // Senão, y deve virar o novo nó cabeça.
  else *first = y;
}

/**
 * Imprime a lista ligada no
 * formato proposto:
 * 
 * [[ra] [nome] [nota]]
 **/
void printLinkedList (LinkedNode * first) {
  for (; first != NULL; first = first->next)
    printf("[%d %s %d]\n", first->ra, first->nome, first->nota);
}

/**
 * Libera a lista ligada da memória,
 * juntamente com o vetor nome que
 * também foi alocado dinamicamente.
 **/
void freeLinkedList (LinkedNode * first) {
  LinkedNode * next;
  for (; first != NULL; first = next) {
    next = first->next;
    free(first->nome);
    free(first);
  }
}
