# Algoritmos de Busca

## Introdução

**Busca:** Operação de recuperar uma informação específica em um conjunto
de dados.

- Os dados estão organizados em **registros**;
- Cada registro inclui um campo **chave** que é usada na busca;
- As chaves sempre podem ser comparadas (**ordem total**);
- A busca pode terminar com êxito (*hit*, *match*) ou não (*miss*). Pode
retornar a posição do registro ou seu valor (i.e. registro sem a chave);
- Usada antes da inserção (se as chaves são únicas) e a remoção.

**Exemplos de busca:** livros (seção), dicionários (palavra), sistema de
arquivos (arquivo), web (página), banco de dados (registro), ADN (sequencia
de bases) etc.

## Busca sequencial

### Dados não ordenados

Busca em uma coleção de registros não ordenados.

- Percorrer estrutura de dados (vetores ou listas) até acharmos
a chave ou chegarmos no final. 

  Custo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.647755pt height=24.65759999999998pt/>. Dá para melhorar?

```c
typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  Key key;
  Value value;
  LinkedNode * next;
};

LinkedNode * search (LinkedNode * first, Key key) {
  while (first != NULL && first->key != key)
    first = first->next;
  return first;
}
```

- Para **vetores** pode ser usada uma sentinela que evita o teste 
de fim de lista

```c
typedef struct Node Node;
struct Node {
  Key key;
  Value * value;
};

int searchArr (Node * arr, int n, Key key) {
  int i = 0;
  arr[n].key = key;
  while (arr[i].key != key)
    i++;
  if (i < n)
    return i;
  return -1;
}
```

### Dados ordenados

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37377482-f05dd6d0-2708-11e8-93b6-6fa68630d845.png">
</p>

- Percorrer a estrutura de dados (vetor ou lista) até acharmos a chave
**ou uma maior do que ela** ou chegarmos no final;
- O que muda no código anterior? Custo no caso pior? <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.647755pt height=24.65759999999998pt/>. Dá para melhorar?

**Se as chaves estão ordenadas, por que começar no início? Por que não pular
algumas chaves?**

### Busca em um dicionário

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37377554-60df9e84-2709-11e8-88e9-509eccdf6822.png">
</p>

- Abrir em uma página qualquer (posição aleatória);
- Se achamos o que procuramos, pronto!
- Se o que procuramos está antes então descartar o restante;
- Se o que procuramos está depois então descartar o anterior;
- Até acharmos o que procuramos ou perceber que não está.

## Busca binária

Aplica o princípio da **dicotomia**.

- Começar na metade do arranjo;
- Se achamos a chave procurada `k`, pronto!
- Se `k` é menor que o elemento do meio, descartar metade superior;
- Se `k` é maior que o elemento do meio, descartar metade inferior;
- Aplicar recursivamente até acharmos `k` ou o arranjo ficar vazio.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37377626-c5268d9e-2709-11e8-96bd-30870d438007.png">
</p>

Searching Sorted List Visualization: https://www.cs.usfca.edu/~galles/visualization/Search.html

### Variante recursiva

```c
int binarySearch (Node * arr, int l, int r, Key key) {
  if (l < r)
    return -1;

  int mid = l + (r - l) / 2;

  if (arr[mid].key == key)
    return mid;

  // Key is smaller than element in the middle?
  if (arr[mid].key > key)
    return binarySearch(arr, l, mid - 1, key);

  // Key must be in right subarray.
  return binarySearch(arr, mid + 1, r, key);
}
```

Ver considerações sobre a corretude da versão interativa em [Requiem for a
Bug - Verifying Software, Part 2: Formal Verification through SPARK, 2014,
Johannes Kanig, Electronic Design, 2015](http://electronicdesign.com/test-measurement/requiem-bug-verifying-software-part-2-formal-verification-through-spark-2014).

### Análise do algoritmo - Caso pior

Sempre descarta metade do arranjo até `l > r`, i.e. a chave procurada não
está no vetor.

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/8d6c5364e7fd65491fec657320c190f0.svg?invert_in_darkmode" align=middle width=158.626215pt height=30.180149999999998pt/></p>

Relembrando o Teorema Mestre: <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/59003bff7924bf5ba0dd158e2684e30e.svg?invert_in_darkmode" align=middle width=159.47860500000002pt height=27.94572000000001pt/>.

Neste caso <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/f0ab30e11910c2d2688aac5ed2ced758.svg?invert_in_darkmode" align=middle width=38.825985pt height=21.18732pt/>, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/d9437a17ba5a0df9089e53386bb19c86.svg?invert_in_darkmode" align=middle width=37.19166pt height=22.831379999999992pt/>, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/858cbec36c83e2c26e1f0da95c0b7a61.svg?invert_in_darkmode" align=middle width=120.41996999999998pt height=29.19113999999999pt/>, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/9753fd8027513ffcef9f797fa96183fe.svg?invert_in_darkmode" align=middle width=88.38753pt height=24.65759999999998pt/>. Logo, 
aplica-se o caso 2:

2. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/7dfa16d78fb29643a060e61e154acbb0.svg?invert_in_darkmode" align=middle width=346.478055pt height=29.19113999999999pt/>.

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/e2e8f4765770515b40e8b7f57f6b471f.svg?invert_in_darkmode" align=middle width=125.91529499999999pt height=16.438356pt/></p>

### Busca sequencial vs Busca binária

| Técnica          | Ordem | Busca     | Inserção | Remoção |
| ---------------- | :---: | :-------: | :------: | :-----: |
| Busca Sequencial | Não   | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>      | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>     |
| Busca Binária    | Sim   | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/79badfc8340e83b5f4e91765c36fd4fe.svg?invert_in_darkmode" align=middle width=43.885215pt height=24.65759999999998pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>      | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>     |

- Busca sequencial é simples porém ineficiente;
- A busca binária tem custo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/9cf64727487f57b15f4c7a257f1dbaca.svg?invert_in_darkmode" align=middle width=69.66613500000001pt height=24.65759999999998pt/> porém o vetor precisa estar
ordenado. Sua eficiência da busca binária está baseada na indexação
em tempo constante de qualquer elemento;
- Se o vetor é pequeno a busca linear pode ser mais eficiente que
ordenar e usar busca binária;
- Inserções e remoções arbitrárias têm custo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.647755pt height=24.65759999999998pt/>.

**Existem estruturas não lineares que permitem a busca em tempo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/9cf64727487f57b15f4c7a257f1dbaca.svg?invert_in_darkmode" align=middle width=69.66613500000001pt height=24.65759999999998pt/>
e inserções/remoções mais eficientes?**

## Árvores Binárias de Busca

### Árvore binária

1. Um nó raiz com duas sub-árvores binárias disjuntas.
2. Um único nó (folha).

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37377915-906cd782-270b-11e8-9e59-46edc72fd2a1.png">
</p>

### Árvore binária em Computação

1. Árvore vazia.
2. Um nó com duas sub-árvores binárias disjuntas.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37377952-d3afd904-270b-11e8-9926-bc70102ca7b8.png">
</p>

```c
typedef struct TreeNode TreeNode;
struct TreeNode {
  Key key;
  Value value;
  TreeNode * pLeft, * pRight;
};
```

### Árvore Binária de Busca (ABB)

Inventada por P. F. Windley, A. D. Booth, A. J. T. Colin e T. N. Hibbard
em 1960, é uma árvore na qual a chave de cada nó é

- maior que qualquer chave na sub-árvore da esquerda;
- menor que qualquer chave na sub-árvore da direita.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37378009-225cfbf4-270c-11e8-8d7c-233dda918dc8.png">
</p>

### Ordem linear Árvore Binária de Busca

- Percorrer recursivamente a sub-árvore da esquerda;
- Imprimir a chave e/ou o valor da raiz;
- Percorrer recursivamente a sub-árvore da direita.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37378057-5ccd2412-270c-11e8-9a76-dd4bc601eaa9.png">
</p>

```c
void inOrder (TreeNode * t) {
  if (t == NULL)
    return;

  inOrder(t->pLeft);
  printf("%d", t->key);
  inOrder(t->pRight);
}
```

## Busca nas ABBs

- Começar na raiz da árvore;
- Se a chave procurada `k` está na raiz `r`, pronto!
- Se `k` é menor que `r`, procurar continuar a busca só na sub-árvore da 
esquerda. Se `k` é maior que `r`, procurar continuar a busca só na sub-árvore
da direita;
- Aplicar recursivamente até acharmos `k` ou a árvore ficar vazia.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37378156-c9138260-270c-11e8-8930-6d34a3f293fa.png">
</p>

### Exemplo: buscar `M`

- Começar na raiz da árvore.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37378199-f2975e04-270c-11e8-9c62-5ab3f34fb5a3.png">
</p>

- `M < P`: buscar à esquerda.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37378249-3408b5fe-270d-11e8-9659-d21221d2b11e.png">
</p>

- `M > H`: buscar à direita.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37378275-4e773e2e-270d-11e8-81d4-0be619d9a3c8.png">
</p>

- `M < O`: buscar à esquerda.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37378306-72c2b312-270d-11e8-88fd-5c38b39bdbb0.png">
</p>

- `M > I`: buscar à direita.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37378345-923aa0d8-270d-11e8-9874-2c446021582d.png">
</p>

- Chave encontrada!

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37378372-a8710888-270d-11e8-9d4a-2e839166cb67.png">
</p>

### Exemplo: buscar `N`

- `N > M`: buscar à direita.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37378411-d0b3fdaa-270d-11e8-8536-3403168bf20b.png">
</p>

- Chave não encontrada!

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37378440-e991efda-270d-11e8-9148-b2445e58809f.png">
</p>

## Inserção nas ABBs

- A forma de uma ABB depende da ordem das inserções e remoções. A nova
chave é sempre inserida em uma folha.

### Exemplo: inserir `N`

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37378488-28a1edec-270e-11e8-87f4-3ba1818c1db1.png">
</p>

**Exercício:** Desenhe a árvore que resulta de inserir os seguintes nós
em uma árvore de busca binária: 15, 4, 20, 17, 19, 1, 8, 25, 12, 28, 2.

Binary Search Tree Visualization: https://www.cs.usfca.edu/~galles/visualization/BST.html

```c
TreeNode * insert (TreeNode * t, Key key, Value value) {
  if (t == NULL) {
    TreeNode * tmp = malloc(sizeof(TreeNode));
    if (tmp != NULL) {
      tmp->key = key;
      tmp->value = value;
      tmp->pRight = tmp->pLeft = NULL;
    }
    return tmp;
  }

  if (key < t->key)
    t->pLeft = insert(t->pLeft, key, value);
  else if (key > t->key)
    t->pRight = insert(t->pRight, key, value);
  else
    t->value = value;
  return t;
}
```

### Análise da Busca e Inserção nas ABBs

- A forma de uma ABB depende da ordem das inserções e remoções. A nova
chave é sempre inserida em uma folha;
- Se `n` chaves distintas são inseridas em uma ABB em ordem aleatória,
o custo da busca é <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/9cf64727487f57b15f4c7a257f1dbaca.svg?invert_in_darkmode" align=middle width=69.66613500000001pt height=24.65759999999998pt/>.
- O caso pior é quando as chaves são inseridas ordenadas (crescente ou
decrescente). Neste caso, a árvore tem a forma de uma lista linear; logo
o custo da busca é <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.647755pt height=24.65759999999998pt/>.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37379089-c1b21776-2710-11e8-88cb-4c6dfae30493.png">
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37379164-0f62455e-2711-11e8-919e-ac15f78da0e4.png">
</p>

### Conclusões

| Técnica          | Ordem | Busca     | Inserção  | Remoção   |
| ---------------- | :---: | :-------: | :-------: | :-------: |
| Busca sequencial | Não   | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       |
| Busca Binária    | Sim   | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/79badfc8340e83b5f4e91765c36fd4fe.svg?invert_in_darkmode" align=middle width=43.885215pt height=24.65759999999998pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       |
| ABB              | Sim   | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/>       |
| ???              | Sim   | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/79badfc8340e83b5f4e91765c36fd4fe.svg?invert_in_darkmode" align=middle width=43.885215pt height=24.65759999999998pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/79badfc8340e83b5f4e91765c36fd4fe.svg?invert_in_darkmode" align=middle width=43.885215pt height=24.65759999999998pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.14/svgs/79badfc8340e83b5f4e91765c36fd4fe.svg?invert_in_darkmode" align=middle width=43.885215pt height=24.65759999999998pt/> |

[The Height of a Random Binary Search Tree](http://cgm.cs.mcgill.ca/~reedbook/papers/2003_R_1.pdf),
Bruce Reed, Journal of the ACM, v 50, No. 3, 2003, pp. 306-332.

## Referências Bibliográficas

- Robert Sedgewick. **Algorithms, 4th Edition**. Addison-Wesley, 2011,
Slides http://algs4.cs.princeton.edu/lectures/
- Thomas H. Cormen; Charles E. Leiserson; Ronald L. Rivest; Clifford Stein.
**Introduction to Algorithms, 3rd Edition**. 2009;
- Donald Knuth. **The Art of Computer Programming, 3rd Edition**. Section
6.1: Sequential Searching, 1997;
- Nivio Ziviani. **Projeto de Algoritmos, 2ª Edição**. 2007;
- Johannes Kanig. [**Requiem for a Bug - Verifying Software: Testing and
Staatic Analysis**](http://electronicdesign.com/test-measurement/requiem-bug-verifying-software-testing-and-static-analysis). Electronic Design (ED), 2014;
- Johannes Kanig. [**Requiem for a Bug - Verifying Software, Part 2:
Formal Verification through SPARK 2014**](http://electronicdesign.com/test-measurement/requiem-bug-verifying-software-part-2-formal-verification-through-spark-2014). Electronic Design (ED), 2015;