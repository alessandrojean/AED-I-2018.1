#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

/* Métodos para a estrutura heap */
int left (int i);
int right (int i);
int parent (int i);
void maxHeapify (int * v, int m, int i);
void minHeapify (int * v, int m, int i);
void buildMaxHeap (int * v, int n);
void buildMinHeap (int * v, int n);
void heapSort (int * v, int n, bool desc);

/* Métodos auxiliares para os vetores */
void printArray (int * v, int n);
void orderedArray (int * v, int n);
void shuffleArray (int * v, int n);

int main (int argc, char **argv) {
  // Define a semente para o gerador
  // de números randômicos baseado
  // no tempo atual do computador.
  srand(time(NULL));

  int n = 30;
  int v[n];
  clock_t start, stop;
  double elapsed;

  orderedArray(v, n);
  shuffleArray(v, n);

  printf("Vetor gerado:\n");
  printArray(v, n);

  printf("\nAplicando heap sort:\n");
  start = clock();
  heapSort(v, n, false);
  stop = clock();

  printArray(v, n);
  elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Tempo passado em ms: %lf\n", elapsed);

  printf("\nAplicando heap sort em ordem decrescente:\n");
  start = clock();
  heapSort(v, n, true);
  stop = clock();

  printArray(v, n);
  elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Tempo passado em ms: %lf\n", elapsed);

  return EXIT_SUCCESS;
}

/**
 * Retorna a posição do nó
 * esquerdo do elemento i
 * em um heap de tamanho
 * qualquer.
 **/
int left (int i) {
  // Alternativamente, poderia
  // ser calculado usando operadores
  // bitwise para uma maior eficiência.
  // 2 * i + 1 = i << 1 | 1
  return 2 * i + 1;
}

/**
 * Retorna a posição do nó
 * direito do elemento i
 * em um heap de tamanho
 * qualquer.
 **/
int right (int i) {
  return 2 * i + 2;
}

/**
 * Retorna a posição do nó
 * parente do elemento i
 * em um heap de tamanho
 * qualquer.
 **/
int parent (int i) {
  return floor((i - 1) / 2);
}

/**
 * Dado um max-heap v[1..m],
 * rearranja-o de modo que a sub-árvore
 * i seja max-heap.
 * Custo proporcional a altura da
 * árvore, ou seja, log(m).
 **/
void maxHeapify (int * v, int m, int i) {
  int l = left(i), r = right(i), max = i;

  // Se a sub-árvore da esquerda é
  // maior que o nó i, defina o 
  // maior como a posição da esquerda.
  if (l < m && v[l] > v[max])
    max = l;

  // Se a sub-árvore da direita é
  // maior que o nó i, defina o
  // maior como a posição da direita.
  if (r < m && v[r] > v[max])
    max = r;

  // Se o maior for diferente
  // do índice do nó i.
  if (max != i) {
    // Troca o item maior com
    // o nó i, para balancear
    // e obedecer a ordem.
    int aux = v[i];
    v[i] = v[max];
    v[max] = aux;

    // Recursivamente aplica o
    // maxHeapify na sub-árvore afetada.
    maxHeapify(v, m, max);
  }
}

/**
 * Dado um min-heap v[1..m],
 * rearranja-o de modo que a sub-árvore
 * i seja min-heap.
 * Custo proporcional a altura da
 * árvore, ou seja, log(m).
 **/
void minHeapify (int * v, int m, int i) {
  int l = left(i), r = right(i), min = i;

  // Se a sub-árvore da esquerda é
  // maior que o nó i, defina o 
  // maior como a posição da esquerda.
  if (l < m && v[l] < v[min])
    min = l;

  // Se a sub-árvore da direita é
  // maior que o nó i, defina o
  // maior como a posição da direita.
  if (r < m && v[r] < v[min])
    min = r;

  // Se o maior for diferente
  // do índice do nó i.
  if (min != i) {
    // Troca o item maior com
    // o nó i, para balancear
    // e obedecer a ordem.
    int aux = v[i];
    v[i] = v[min];
    v[min] = aux;

    // Recursivamente aplica o
    // minHeapify na sub-árvore afetada.
    minHeapify(v, m, min);
  }
}

/**
 * Dado um vetor v, transforma-o
 * em um max-heap.
 * Tem custo O(n).
 **/
void buildMaxHeap (int * v, int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    maxHeapify(v, n, i);
}

/**
 * Dado um vetor v, transforma-o
 * em um min-heap.
 * Tem custo O(n).
 **/
void buildMinHeap (int * v, int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    minHeapify(v, n, i);
}

/**
 * Aplica o algoritmo de
 * ordenação heap sort no
 * vetor v[0..n - 1].
 * 
 * Se desc for true, ordena
 * em ordem decrescente.
 * 
 * Tem custo de O(n * log(n))
 * no pior e melhor caso.
 **/
void heapSort (int * v, int n, bool desc) {
  // Pré-processamento:
  // cria o min-heap do vetor v
  // se desc for verdadeiro.
  if (desc)
    buildMinHeap(v, n);
  // Senão, cria o max-heap.
  else
    buildMaxHeap(v, n);

  // Itera em todos os items do heap,
  // de traz pra frente.
  for (int i = n - 1; i >= 0; i--) {
    // Troca o maior elemento, que
    // está sempre na primeira posição
    // com o elemento na posição i.
    int aux = v[0];
    v[0] = v[i];
    v[i] = aux;

    // Aplica o minHeapify para
    // corrigir e ordenar o min-heap.
    if (desc)
      minHeapify(v, i, 0);
    // Senão, aplica o maxHeapify.
    else
      maxHeapify(v, i, 0);
  }
}

/**
 * Gera um vetor v[0..n - 1], com
 * elementos em ordem crescente.
 **/
void orderedArray (int * v, int n) {
  for (int i = 0; i < n; i++)
    v[i] = i;
}

/**
 * Embaralha um vetor v[0..n - 1]
 **/
void shuffleArray (int * v, int n) {
  for (int i = n - 1; i > 0; i--) {
    // Gera um número randômico entre 0...i
    int r = rand() % (i + 1);
    // Efetua a troca entre r e i.
    int aux = v[i];
    v[i] = v[r];
    v[r] = aux;
  }
}

/**
 * Imprime um vetor de inteiros
 * v[0..n - 1].
 **/
void printArray (int * v, int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
}
