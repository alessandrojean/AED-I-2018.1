#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Métodos para a estrutura heap. */
int left (int i);
int right (int i);
int parent (int i);
int lastParent (int n);
int hasLeftChild (int i, int n);
int hasRightChild (int i, int n);
int isLeaf (int i, int n);
int maxHeapify (int * v, int n, int i);
int buildMaxHeap (int * v, int n);
int heapSort (int * v, int n);

/* Métodos auxiliares para os vetores */
void printArray (int * v, int n);
void orderedArray (int * v, int n);
void unorderedArray (int * v, int n);
void shuffleArray (int * v, int n);
void copyArray (int * from, int * to, int n);

int main (int argc, char **argv) {
  // Define a semente para o gerador
  // de números randômicos baseado
  // no tempo atual do computador.
  srand(time(NULL));

  int n = 30, comp;
  int v1[n], v2[n];
  clock_t start, stop;
  double elapsed;

  orderedArray(v1, n);
  shuffleArray(v1, n);
  unorderedArray(v2, n);

  printf("Vetor gerado:\n");
  printArray(v1, n);

  printf("\nAplicando heap sort:\n");
  start = clock();
  comp = heapSort(v1, n);
  stop = clock();

  printArray(v1, n);
  elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Tempo passado em ms: %lf\n", elapsed);
  printf("Comparações realizadas: %d\n", comp);

  printf("\nAplicando heap sort em um vetor já ordenado:\n");
  start = clock();
  comp = heapSort(v1, n);
  stop = clock();

  printArray(v1, n);
  elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Tempo passado em ms: %lf\n", elapsed);
  printf("Comparações realizadas: %d\n", comp);

  printf("\nAplicando heap sort em um vetor ordenado ao contrário:\n");
  start = clock();
  comp = heapSort(v2, n);
  stop = clock();

  printArray(v2, n);
  elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
  printf("Tempo passado em ms: %lf\n", elapsed);
  printf("Comparações realizadas: %d\n", comp);

  return EXIT_SUCCESS;
}

/**
 * Retorna a posição do nó esquerdo do 
 * elemento i em um heap de tamanho qualquer.
 **/
int left (int i) {
  // Alternativamente, poderiaser calculado usando
  // operadores bitwise para uma maior eficiência.
  // 2 * i + 1 = i << 1 | 1
  return 2 * i + 1;
}

/**
 * Retorna a posição do nó direito do
 * elemento i em um heap de tamanho qualquer.
 **/
int right (int i) {
  return 2 * i + 2;
}

/**
 * Retorna a posição do nó parente do 
 * elemento i em um heap de tamanho qualquer.
 **/
int parent (int i) {
  // No C, a divisão de inteiros tem o
  // comportamento natural da função floor,
  // portanto não é necessário usá-la.
  return (i - 1) / 2;
}

/**
 * Retorna a posição do último nó pai,
 * ou seja, que possui filhos.
 **/
int lastParent (int n) {
  return (n / 2) - 1;
}

/**
 * Retorna se dado elemento i possui
 * filhos em sua esquerda.
 **/
int hasLeftChild (int i, int n) {
  return left(i) < n;
}

/**
 * Retorna se dado elemento i possui
 * filhos em sua direita.
 **/
int hasRightChild (int i, int n) {
  return right(i) < n;
}

/**
 * Retorna se dado elemento i é uma folha,
 * ou seja, não possui filhos.
 **/
int isLeaf (int i, int n) {
  return left(i) >= n;
}

/**
 * Dado um heap v[1..m], rearranja-o de modo 
 * que a sub-árvore i seja max-heap.
 * 
 * Custo proporcional a altura da árvore,
 * ou seja, log(n).
 **/
int maxHeapify (int * v, int n, int i) {
  int l = left(i), r = right(i), max = i, comp = 1;

  // Se a sub-árvore da esquerda é maior que 
  // o nó i, defina o maior como a posição da esquerda.
  if (hasLeftChild(i, n) && v[l] > v[max])
    max = l;

  // Se a sub-árvore da direita é maior que
  // o nó i, defina o maior como a posição da direita.
  if (hasRightChild(i, n) && v[r] > v[max])
    max = r;

  // Se o maior for diferente do índice do nó i.
  if (max != i) {
    // Troca o item maior com o nó i, 
    // para balancear e obedecer a ordem.
    int aux = v[i];
    v[i] = v[max];
    v[max] = aux;

    // Recursivamente aplica o maxHeapify
    // na sub-árvore afetada.
    comp += maxHeapify(v, n, max);
  }

  return comp;
}

/**
 * Dado um vetor v, transforma-o em um max-heap.
 * 
 * Em uma análise grosseira, tem custo O(n log(n)).
 * Porém, em uma análise refinada, pode-se deduzir
 * que o custo é O(n).
 **/
int buildMaxHeap (int * v, int n) {
  int lp = lastParent(n), comp = 0;

  for (int i = lp; i >= 0; i--)
    comp += maxHeapify(v, n, i);

  return comp;
}

/**
 * Aplica o algoritmo de ordenação 
 * heap sort no vetor v[0..n - 1].
 *
 * Tem custo de O(n log(n)) no pior caso.
 **/
int heapSort (int * v, int n) {
  int comp = 0;

  // Pré-processamento: cria o max-heap do vetor v.
  comp += buildMaxHeap(v, n);

  // Itera em todos os items do heap,
  // de traz pra frente.
  for (int i = n - 1; i > 0; i--) {
    // Troca o maior elemento, que
    // está sempre na primeira posição
    // com o elemento na posição i.
    int aux = v[0];
    v[0] = v[i];
    v[i] = aux;

    // Aplica o maxHeapify para
    // corrigir e ordenar o max-heap.
    comp += maxHeapify(v, i, 0);
  }

  return comp;
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
 * Gera um vetor v[0..n - 1], com
 * elementos em ordem decrescente.
 **/
void unorderedArray (int * v, int n) {
  for (int i = 0; i < n; i++)
    v[i] = n - i - 1;
}

/**
 * Embaralha um vetor v[0..n - 1].
 **/
void shuffleArray (int * v, int n) {
  for (int i = n - 1; i > 0; i--) {
    // Gera um número randômico entre 0..i.
    int r = rand() % (i + 1);
    // Efetua a troca entre r e i.
    int aux = v[i];
    v[i] = v[r];
    v[r] = aux;
  }
}

/**
 * Imprime um vetor de inteiros v[0..n - 1].
 **/
void printArray (int * v, int n) {
  printf("[");
  for (int i = 0; i < n; i++)
    printf("%d%s", v[i], i < n - 1 ? ", ": "]\n");
}

/**
 * Copia o vetor from para to.
 **/
void copyArray (int * from, int * to, int n) {
  for (int i = 0; i < n; i++)
    to[i] = from[i];
}
