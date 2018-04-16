# Algoritmos de Ordenação Simples

## Introdução

### O problema da Ordenação (Sorting)

O problema de ordenar uma sequência de <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/f9c4988898e7f532b9f826a75014ed3c.svg?invert_in_darkmode" align=middle width=14.999985000000004pt height=22.46574pt/> elementos de dados
<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/7f87882c32a8644b5ee7bcd81d136217.svg?invert_in_darkmode" align=middle width=112.33661999999998pt height=22.831379999999992pt/> consiste em obter uma permutação dos elementos
tal que <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/0c5d7113e1b354239746f818a2b83a5c.svg?invert_in_darkmode" align=middle width=188.145705pt height=22.831379999999992pt/> onde <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/c85a67d18322c7784f40a29a9fd19c86.svg?invert_in_darkmode" align=middle width=12.785520000000004pt height=20.908799999999992pt/> é uma
**ordem** total definida para uma parte do registro de dado (*chave*).

<p align="center">
  <img src="img/img1.png">
</p>

### O problema de embaralhar (Shuffling)

Operação contrária a ordenar que consiste em obter uma permutação
aleatória de uma sequência de dados.

```c
void shufflingArr (int * v, int n) {
  for (int i = n - 1; i > 0; i--) {
    int r = rand() % (i + 1);  // Random int between 0...i
    int aux = v[i];            // Swap
    v[i] = v[r];
    v[r] = aux;
  }
}
```

### Vantagens de ordenar

- Melhora a visualização dos dados;
- Após ordenar a busca (elemento, mínimo, máximo) é mais eficiente;
- Permite remover elementos repetidos, checar se não há repetições,
calcular a distribuição de frequências com facilidade;
- Passo inicial para resolver de forma mais simples/eficiente um problema
ex. calcular a mediana e a moda, obter uma árvore geradora mínima,
construir uma árvore B+;
- Usada em muitas áreas da Computação, ex. banco de dados, sistemas
operacionais, recuperação de informação etc.

### Tipos de Ordenação

<p align="center">
  <img src="img/img2.png">
</p>

### Características dos Algoritmos de Ordenação

- **In-place:** se a quantidade de memória auxiliar utilizada
pelo algoritmo é <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/9cf64727487f57b15f4c7a257f1dbaca.svg?invert_in_darkmode" align=middle width=69.66613500000001pt height=24.65759999999998pt/>.

  Exemplo: Mergesort não é um algoritmo in-place.
- **Estável:** se a ordem relativa dos itens com chaves iguais
mantém-se inalterada.

  Exemplo: Quicksort não é um algoritmo estável.
- **Adaptativo:** se o fato da sequência já estar ordenada
afeta a complexidade do algoritmo.

  Exemplo: Insertionsort.
- **Híbrido:** se usa vários métodos.

  Exemplo: Timsort.
- **Paralelo:** se usa múltiplos processadores para ordenar.

  Exemplo: Spaghetti sort, Bitonic mergesort.
- **Ordenação Parcial:** se ordena somente os <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/63bb9849783d01d91403bc9a5fea12a2.svg?invert_in_darkmode" align=middle width=9.075495000000004pt height=22.831379999999992pt/> primeiros elementos.

  Exemplo: Quickselect.

## Algoritmos de ordenação simples: Insertion Sort e Selection Sort

### Ordenação por seleção - Selection Sort

    repeat (numOfElements - 1) times
      set the first unsorted element as the minimum
      for each of the unsorted elements
        if element < currentMinimum
          set element as new minimum
      swap minimum with first unsorted position

**Funcionamento:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/7438fba87b414f019f8f961deccdb574.svg?invert_in_darkmode" align=middle width=107.76711pt height=22.831379999999992pt/>

- selecione o mínimo da parte não ordenada;
- coloque o mínimo na posição <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/77a3b857d53fb44e33b53e4c8b68351a.svg?invert_in_darkmode" align=middle width=5.663295000000005pt height=21.683310000000006pt/>.

### Ordenação por inserção - Insertion Sort

<p align="center">
  <img src="img/img4.png">
</p>

    mark first element as sorted
    for each unsorted element X
      'extract' the element X
      for j = lastSortedIndex down to 0
        if current element j > X
          move sorted element to the right by 1
        break loop and insert X here

**Funcionamento:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/6f4848aec060e6a7fedab930cd6cfc5e.svg?invert_in_darkmode" align=middle width=79.45674pt height=22.831379999999992pt/>

- insira o elemento <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/77a3b857d53fb44e33b53e4c8b68351a.svg?invert_in_darkmode" align=middle width=5.663295000000005pt height=21.683310000000006pt/> na posição correta da parte ordenada.

### Implementação

#### Selection sort

```c
int selectionSort (int * v, int n) {
  int i, j, min, aux;
  long int comp = 0;

  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (v[min] > v[j])
        min = j;
      comp++;
    }

    if (min != i) {
      aux = v[min];
      v[min] = v[i];
      v[i] = aux;
    }
  }

  return comp;
}
```

#### Insertion sort

```c
int insertionSort (int * v, int n) {
  int i, j, key;
  long int comp = 0;

  for (i = 1; i < n; i++) {
    key = v[i];
    j = i - 1;
    while (j >= 0 && ++comp && v[j] > key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }

  return comp;
}
```

Ver código completo [aqui](basic-sorting.c).

### Análise Selection Sort

|                                  | Comparações          | Movimentações |
| -------------------------------- | -------------------- | ------------- |
| Caso melhor (sequência em ordem) | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/084046dbf113a7e22863c6df7d642f7a.svg?invert_in_darkmode" align=middle width=43.352759999999996pt height=33.20559pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/29632a9bf827ce0200454dd32fc3be82.svg?invert_in_darkmode" align=middle width=8.219277000000005pt height=21.18732pt/>           |
| Caso pior                        | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/084046dbf113a7e22863c6df7d642f7a.svg?invert_in_darkmode" align=middle width=43.352759999999996pt height=33.20559pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/c08d70993ad73e9a2a21ba3e69382175.svg?invert_in_darkmode" align=middle width=59.182035000000006pt height=24.65759999999998pt/>    |

- Melhor algoritmo para sequências pequenas com registros muito grandes;
- In-place, não adaptativo, não estável.

**Qual o caso pior do selection sort? Por que não é estável?**

### Análise Insertion Sort

|                                        | Comparações          | Movimentações |
| -------------------------------------- | -------------------- | ----------------------- |
| Caso melhor (sequência em ordem)       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/3eeee545b1fbecf1f5a508b7304d7d5c.svg?invert_in_darkmode" align=middle width=38.17737pt height=21.18732pt/>              | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/e99c1ddba901290ecfa9a7a74788b495.svg?invert_in_darkmode" align=middle width=59.182035000000006pt height=24.65759999999998pt/>                         |
| Caso pior (sequência em ordem reversa) | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/19596a4474d46270353bb2e8ea8fbe77.svg?invert_in_darkmode" align=middle width=43.352759999999996pt height=33.20559pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.04.16/svgs/1388a119c053b4782241cb099ea3755b.svg?invert_in_darkmode" align=middle width=83.539665pt height=33.459689999999995pt/> |

- Algoritmo apropriado para sequências pequenas ou quando se deseja
adicionar poucos registros a uma sequência ordenada;
- In-place, adaptativo e estável.

## Referências Bibliográficas

- Algorithms, Robert Sedgewick and Kevin Wayne, 4th Edition, 2011.

  Slides: http://algs4.cs.princeton.edu/lectures/
- Introduction to Algorithms, 3rd Edition. Thomas H. Cormen, Charles E. 
Leiserson, Ronald L. Rivest and Clifford Stein, 2009.
- The Art of Computer Programming 3rd Edition, Donald Knuth, 1997.
- Projeto de Algoritmos, 2ª Edição, Nivio Ziviani, 2007.
- Estruturas de Dados e seus Algoritmos, 3ra edição, Jayme L.
Szwarcfiter and Lilian Markezon, 2010.
- Wikipedia: https://en.wikipedia.org/wiki/Sorting_algorithm