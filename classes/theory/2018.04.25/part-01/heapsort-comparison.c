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

/* Métodos para o Merge Sort. */
int merge (int * v, int lo, int mid, int hi);
int MergeSort (int * v, int lo, int hi);
int mergeSort (int * v, int n);

/* Métodos para o Quick Sort. */
int partition (int * v, int lo, int hi, int * comp);
int QuickSort (int * v, int lo, int hi);
int quickSort (int * v, int n);

/* Métodos auxiliares para os vetores. */
void printArray (int * v, int n);
void orderedArray (int * v, int n);
void unorderedArray (int * v, int n);
void shuffleArray (int * v, int n);
void copyArray (int * from, int * to, int n);

/* Métodos auxiliares para o tempo. */
double timeDifference (clock_t start, clock_t stop);

int main (int argc, char **argv) {
  // Define a semente para o gerador
  // de números randômicos baseado
  // no tempo atual do computador.
  srand(time(NULL));
  
  printf("\n-------------------------------------------------------------\n");
  printf("%29s%16s%16s\n", "HeapSort", "QuickSort", "MergeSort");
  printf("%-13s  --------------  --------------  --------------\n", "Elementos");
  printf("%19s%10s%6s%10s%6s%10s\n", "Comp", "T (ms)", "Comp", "T (ms)", "Comp", "T (ms)");
  printf("-------------------------------------------------------------\n");

  int min = 15, max = 35, step = 5, c;
  double d;
  clock_t start, stop;
  char modo[3][12] = { "Random\0", "Ordenado\0", "Desordenado\0" };
  // Vetor de ponteiros pra funções.
  int (* sortFunction[3])(int *, int) = { heapSort, quickSort, mergeSort };
  
  // Armazenamento das médias.
  int medC[3][3] = {0};
  double medT[3][3] = {0};
  
  for (int i = min; i <= max; i += step) {
    int v[i], v1[i];
    
    printf("n = %d\n", i);
    
    for (int j = 0; j < 3; j++) {
      if (j == 0) {
        orderedArray(v, i);
        shuffleArray(v, i);
      } else if (j == 1) {
        orderedArray(v, i);
      } else {
        unorderedArray(v, i);
      }
      
      for (int k = 0; k < 3; k++) {
        copyArray(v, v1, i);
        start = clock();
        c = (*sortFunction[k])(v1, i);
        stop = clock();
        d = timeDifference(start, stop);
        medT[j][k] += d;
        medC[j][k] += c;
      }
      
      printf("  %-11s%6d%10f%6d%10f%6d%10f\n", modo[j], medC[j][0], medT[j][0], medC[j][1], medT[j][1], medC[j][2], medT[j][2]);
    }
  }
  
  int n = (max - min + step) / step;
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      medC[i][j] /= n;
      medT[i][j] /= n;
    }
  }
  
  printf("-------------------------------------------------------------\n");
  printf("Média\n");
  for (int i = 0; i < 3; i++) {
    printf("  %-11s%6d%10f%6d%10f%6d%10f\n", modo[i], medC[i][0], medT[i][0], medC[i][1], medT[i][1], medC[i][2], medT[i][2]);
  }
  printf("-------------------------------------------------------------\n\n");

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
 * Junta dois sub-vetores [lo..mid] e [mid + 1..hi]
 * em um único vetor, ordenado.
 **/
int merge (int * v, int lo, int mid, int hi) {
  int i = lo, j = mid + 1, k = 0;
	int aux[hi - lo + 1];
	int comp = 0;

	while (i <= mid && j <= hi) {
		aux[k++] = v[i] <= v[j] ? v[i++] : v[j++];
		comp++;
	}

	while (i <= mid)
		aux[k++] = v[i++];

	while (j <= hi)
		aux[k++] = v[j++];

	for (i = lo, k = 0; i <= hi; i++)
		v[i] = aux[k++];

	return comp;
}

/**
 * Efetua o MergeSort em um vetor v,
 * limitado por lo e hi.
 **/
int MergeSort (int * v, int lo, int hi) {
  int comp = 0;

	if (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		comp += MergeSort(v, lo, mid);
		comp += MergeSort(v, mid + 1, hi);
		comp += merge(v, lo, mid, hi);
	}

	return comp;
}

/**
 * Aplica o método de ordenação
 * Merge Sort em um vetor v de n elementos.
 **/
int mergeSort (int * v, int n) {
  return MergeSort(v, 0, n - 1);
}

/**
 * Particiona o vetor v em dois sub-vetores,
 * tal que: [lo..mid - 1], mid, [mid + 1..hi].
 **/
int partition (int * v, int lo, int hi, int * comp) {
  int key = v[lo], mid = lo, i = lo + 1, aux;

	for (; i <= hi; i++) {
		if (v[i] < key) {
			mid++;
			aux = v[mid];
			v[mid] = v[i];
			v[i] = aux;
		}
		(*comp)++;
	}

	v[lo] = v[mid];
	v[mid] = key; // put the key in its place

	return mid;
}

/**
 * Efetua o QuickSort em um vetor v,
 * limitado por lo e hi.
 **/
int QuickSort (int * v, int lo, int hi) {
  int comp = 0;
	if (lo < hi) {
		int mid = partition(v, lo, hi, &comp);
		comp += QuickSort(v, lo, mid - 1);
		comp += QuickSort(v, mid + 1, hi);
	}
	return comp;
}

/**
 * Aplica o método de ordenação
 * Quick Sort em um vetor v de n elementos.
 **/
int quickSort (int * v, int n) {
  return QuickSort(v, 0, n - 1);
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

/**
 * Calcula a diferença de tempo entre
 * stop e start, em milisegundos.
 **/
double timeDifference (clock_t start, clock_t stop) {
  return (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
}
