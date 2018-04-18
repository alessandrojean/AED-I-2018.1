# Algoritmos de Ordenação Ótimos

## Introdução

### Aula anterior: Introdução aos Algoritmos de ordenação

**Algoritmos elementares de ordenação**, baseados em comparações, de custo
<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/3987120c67ed5a9162aa9841b531c3a9.svg?invert_in_darkmode" align=middle width=43.022265pt height=26.76201000000001pt/> no caso pior.
- Ordenação por troca (*bubble sort*);
- Ordenação por seleção (*selection sort*);
- Ordenação por inserção (*insertion sort*).

**Algoritmos de ordenação bons**
- Shellsort

**Limite assintótico da ordenação baseada em comparações** é 
<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/34b25858c1d4e42626ad67082bc85089.svg?invert_in_darkmode" align=middle width=81.149475pt height=24.65759999999998pt/>, i.e. qualquer algoritmo de ordenação baseado em 
comparações usa no mínimo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/409e56362ae6eccb1f477429b55a2962.svg?invert_in_darkmode" align=middle width=56.49187500000001pt height=24.65759999999998pt/> comparações no caso pior.

**Hoje:** Algoritmos de ordenação ótimos.

## Mergesort

### Mergesort - Ordenação por intercalação

- Inventado por John von Neumann em 1945;
- Algoritmo simples, de propósito geral, ótimo, estável;
- Exemplo clássico de algoritmo recursivo de divisão e conquista;
- A conquista é feita usando intercalação.

<p align="center">
  <img src="img/img1.png">
</p>

<p align="center">
  <img src="img/img2.png">
</p>

### Intercalação - Merge

Combinação de dois ou mais arranjos (arquivos, listas) de entrada
ordenados em um único arranjo ordenado.

<p align="center">
  <img src="img/img3.png">
</p>

- Comparar os primeiros de cada arranjo de entrada e copiar o menor
para o arranjo de saída.

### Algoritmo de Intercalação

- Simples usando memória auxiliar;
- Uma das duas listas vai acabar primeiro; passar diretamente os restantes.
Ao intercalar elementos iguais dar prioridade ao primeiro arranjo; isto
garante a estabilidade da ordenação;
- A memória auxiliar pode ser de tamanho <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/f11950293b5756c0367d21fb42f57c99.svg?invert_in_darkmode" align=middle width=8.126084999999998pt height=22.853489999999976pt/> 
(**Exercício independente**);
- Existem variantes que usam memória auxiliar <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/1e2f931ee6c0b8e7a51a7b0d123d514f.svg?invert_in_darkmode" align=middle width=34.000065pt height=24.65759999999998pt/> (*in-place*); porém
ou são mais complexas e/ou menos ineficientes.


### Algoritmo de Ordenação por Intercalação (Mergesort)

- Dividir o vetor em duas partes de tamanhos similares e ordenar
recursivamente;
- Intercalar os sub-vetores ordenados.

```c
long int MergeSort (int * v, int lo, int hi) {
  long int comp = 0;

  if (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    comp += MergeSort(v, lo, mid);
    comp += MergeSort(v, mid + 1, hi);
    comp += merge(v, lo, mid, hi);
  }

  return comp;
}
```

### Análise do Mergesort

O arranjo é sempre dividido na metade. No caso pior, o tamanho do
arranjo inicial é potência de 2. Para a intercalação temos,
- **Caso pior:** Todos os elementos são comparados no mínimo uma vez
(os dois maiores não estão no mesmo sub-vetor);
- **Caso melhor:** Quando metade dos elementos são comparados
(o maior de um vetor é menor que o primeiro do outro).

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/1eafd25615a8ab3e257794d68cbbba5f.svg?invert_in_darkmode" align=middle width=168.49305pt height=30.180149999999998pt/></p>

Relembrando o Teorema Mestre: <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/59003bff7924bf5ba0dd158e2684e30e.svg?invert_in_darkmode" align=middle width=159.47860500000002pt height=27.94572000000001pt/>

1. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/0634ca2934e8825901d5042c271b1601.svg?invert_in_darkmode" align=middle width=305.769255pt height=29.19113999999999pt/>
2. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/5a5caec03648d0f983e4f7929cbe8286.svg?invert_in_darkmode" align=middle width=336.43285499999996pt height=29.19113999999999pt/>
3. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/a236c5c5ea6439b6d10f619bd6ba31c7.svg?invert_in_darkmode" align=middle width=146.47116pt height=29.19113999999999pt/> e existe <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/3cf02e03a84b8072989808b36ad361de.svg?invert_in_darkmode" align=middle width=37.250730000000004pt height=21.18732pt/> tal que para todo
<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> suficientemente grande <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/dc08e73ebb08390e5471027b9b1c1609.svg?invert_in_darkmode" align=middle width=249.95800499999999pt height=27.94572000000001pt/>

Neste caso <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/cf34371d316f136e859347be44d26b44.svg?invert_in_darkmode" align=middle width=38.825985pt height=21.18732pt/>, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/d9437a17ba5a0df9089e53386bb19c86.svg?invert_in_darkmode" align=middle width=37.19166pt height=22.831379999999992pt/>, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/14e86d5c7ec986cea40feff32f819c4d.svg?invert_in_darkmode" align=middle width=122.06766pt height=29.19113999999999pt/>, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/2d029fd6089cbbc06bc2cf83169e937b.svg?invert_in_darkmode" align=middle width=90.03522pt height=24.65759999999998pt/>.
Logo, pelo caso 2, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/5f34ffad49a12f2b87fba2533068909a.svg?invert_in_darkmode" align=middle width=138.521955pt height=24.65759999999998pt/>.

A recorrência geral tem a forma <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/27494d81948c5a4cb5adfd7cb91b6773.svg?invert_in_darkmode" align=middle width=236.83225499999998pt height=27.94572000000001pt/>. A mesma solução é obtida usando
indução.

### Aprimorando o algoritmo

O mergesort não é sensível aos dados de entrada.

http://www.sorting-algorithms.com/merge-sort

- Antes de intercalar testar se o vetor já está ordenado. Isso evita a 
intercalação mas não as chamadas recursivas (**como?**);
- Usar inserção para arranhos pequenos (ex. `tamanho < 25`);
- É possível eliminar a cópia ao vetor auxiliar durante a intercalação
(reduz o tempo mas não o espaço).

### Mergesort iterativo

#### Árvore de Partições

<p align="center">
  <img src="img/img4.png">
</p>

A recursividade é usada para definir as partições do vetor que
precisam ser intercaladas e a ordem das intercalações.

O mergesort recursivo faz um percurso em post-ordem da árvore.
No entanto, qualquer outro percurso que visite primeiro os filhos
e depois o nó pode ser usado.

**É possível fazer um percurso por níveis, de baixo para cima!**

#### Bottom-Up Mergesort

<p align="center">
  <img src="img/img5.png">
</p>

### Top-Down vs Bottom-Up Mergesort

- Se <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> não é uma potência de 2, então o conjunto de intercalações das
duas variantes é diferente;

<p align="center">
  <img src="img/img6.png"><br>
  Robert Sedgewick, Algorithms, 4th Edition, Addison-Wesley, 2011
</p>

- O número de comparações é menor na variante recursiva;

  |           | best case                      | average case        | worst case |
  | --------- | ------------------------------ | ------------------- | ---------- |
  | top-down  | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/799bd94170a38c8d8b2da278b398d46d.svg?invert_in_darkmode" align=middle width=132.41810999999998pt height=27.775769999999994pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/d4c90d2c1946ffba45bda6c8ed246461.svg?invert_in_darkmode" align=middle width=123.89289pt height=24.65759999999998pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/a2a834cafdd619b582343994dd0812b9.svg?invert_in_darkmode" align=middle width=123.89289pt height=24.65759999999998pt/> |
  | bottom-up | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/799bd94170a38c8d8b2da278b398d46d.svg?invert_in_darkmode" align=middle width=132.41810999999998pt height=27.775769999999994pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/a616b93fa3ee5aa8e3b5e39486a0bc8d.svg?invert_in_darkmode" align=middle width=123.89289pt height=24.65759999999998pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/362292d8e9ba65e75deb8303420862ef.svg?invert_in_darkmode" align=middle width=123.89289pt height=24.65759999999998pt/> |

  Bottom-up mergesort - A detailed analysis. W. Panny, H. Prodinger, Algorithmica,
  14 (4): 340-354, 1995.

- A versão recursiva é mais rápida;

  | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       | 100000 | 200000 | 400000 | 800000 |
  | --------- | :----: | :----: | :----: | :----: |
  | top-down  | 53     | 111    | 237    | 524    |
  | bottom-up | 59     | 127    | 267    | 568    |

  Robert Sedgewick, Algorithms, 4th Edition, Addison-Wesley, 2011.

- Existe uma variante não recursiva que aproveita as sequencias ordenadas
do arranjo de entrada (*natural mergesort*).

## Quicksort

- Inventado por Tony Hoare em 1959 sendo estudante e publicado em 1961;
- Refinado e analisado por Robert Sedgewick em 1976;
- Exemplo clássico de algoritmo recursivo de divisão e conquista;
- A conquista é feita de forma inteligente particionando a sequência
antes de dividir sem precisar de memória auxiliar.

<p align="center">
  <img src="img/img7.png">
</p>

### Particionamento

- Escolher um elemento pivô de forma tal que no final ele seja colocado
na posição certa;
- Separar os elementos menores e maiores ou iguais ao pivô usando
trocas;

<p align="center">
  <img src="img/img8.png">
</p>

- A parte mais importante do Quicksort, tem custo linear;
- A escolha do elemento pivô influencia como é feito o particionamento
e o desempenho do Quicksort;
- Pode ser usado um elemento aleatório, ou a mediana de uma amostra
do vetor (ex. primeiro, último, meio);
- Pode mudar a ordem relatia de registros com a mesma chave.

### O algoritmo

```c
int QuickSort (int * v, int lo, int hi) {
  int comp = 0;

  if (lo < hi) {
    int mid = partition(v, lo, hi, &comp);
    comp += QuickSort(v, lo, mid - 1);
    comp += QuickSort(v, mid + 1, hi);
  }

  return comp;
}
```

Ver exemplo completo [aqui](optimal-sorting-algorithms.c).

### Análise do Quicksort

- **Caso melhor:** o vetor é sempre particionado na metade.

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/0092831b27ec0a616bf5b18729b8376b.svg?invert_in_darkmode" align=middle width=272.47274999999996pt height=30.180149999999998pt/></p>

- **Caso pior:** a sequência já está ordenada (crescente ou decrescente).

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/6c8ce81cfbd75d91673f583aa4a34691.svg?invert_in_darkmode" align=middle width=239.77964999999998pt height=18.312359999999998pt/></p>

**Como evitar o caso pior?** Inicialmente embaralhar o vetor.

- Para sub-vetores pequenos, usar ordenação por inserção. Nesses casos
também é possível ignorar a chamada e ordenar por inserção somente uma
vez no final;
- Primeiro ordenar a partição menor para garantir que o algoritmo seja
in-place, i.e. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/9cf64727487f57b15f4c7a257f1dbaca.svg?invert_in_darkmode" align=middle width=69.66613500000001pt height=24.65759999999998pt/> chamadas na pilha.

## Conclusões

### Mergesort

- Implementação elegante tanto de forma recursiva como iterativa;
tanto em vetores quanto em listas ligadas; tanto em memória itnerna
como externa;
- Único ótimo (<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/ad9999ab03750a426e034fd75f8dbd2c.svg?invert_in_darkmode" align=middle width=82.06275pt height=24.65759999999998pt/>) e estável porém não adaptativo;
- Usa memória auxiliar <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.647755pt height=24.65759999999998pt/>. As variantes in-place usam mais comparações
e movimentações ou não são estáveis. A versão para listas ligadas usa
memória auxiliar <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.04.18/svgs/1e2f931ee6c0b8e7a51a7b0d123d514f.svg?invert_in_darkmode" align=middle width=34.000065pt height=24.65759999999998pt/>.

### Quicksort

- Algoritmo ótimo in-place muito eficiente (se implementado de
maneira correta);
- Não é estável nem adaptativo; porém existe uma versão adaptativa
(3-way Quicksort);
- Há variantes para ordenação por distribuição, parcial e externa.

## Referências Bibliográficas

- Algorithms, Robert Sedgewick and Kevin Wayne, 4th Edition, 2011.
  
  Slides: http://algs4.cs.princeton.edu/lectures/
- Introduction to Algorithms, 3rd Edition. Thomas H. Cormen, Charles
E. Leiserson, Ronald L. Rivest and Clifford Stein, 2009.
- The Art of Computer Programming 3rd Edition, Donald Knuth, Section
5.2.4: Sorting by Merging, 1997.
- Projeto de Algoritmos, 2ª Edição, Nivio Ziviani, 2007.
- Estruturas de Dados e seus Algoritmos, 3ª Edição, Jayme L. Szwarcfiter and
Lilian Markezon, 2010.
- Comparison Sorting Algorithms

  https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html
- Sorting Algorithms Animation

  http://www.sorting-algorithms.com/