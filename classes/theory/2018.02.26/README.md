# Estruturas lineares dinâmicas (listas)
*Retirado dos slides do Prof. Paulo H. Pisani, CMCC/UFABC.*

## Introdução

### Listas com arranjos (revisão)

- Itens dispostos em um arranjo sequencial;

![image](https://user-images.githubusercontent.com/14254807/36679106-2b2ba482-1af1-11e8-903d-86f1e7daf0bd.png)

**Problemas?**

## Listas ligadas/encadeadas

- Estrutura de dados que armazena os itens de forma não consecutiva na
memória:
  - Usa ponteiros para "ligar" um item no próximo.

![image](https://user-images.githubusercontent.com/14254807/36679244-812296e8-1af1-11e8-8b6e-5a4a4960e1f2.png)

- Vários tipos:
  - Listas simplesmente ligadas (com e sem nó cabeça);
  - Listas duplamente ligadas (com e sem nó cabeça);
  - Listas circulares.

## Listas simplesmente ligadas

- Cada item é ligado somente ao próximo item;

![image](https://user-images.githubusercontent.com/14254807/36679386-d533d9e0-1af1-11e8-83e6-99c948171da9.png)

### Implementação

```c
typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int data;
  LinkedNode * next;
};
```

O ponteiro para o primeiro item deve ser salvo.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int data;
  LinkedNode * next;
};

int main () {
  LinkedNode * first = malloc(sizeof(LinkedNode));

  // ...
}
```

### Adicionar ao final

```c
LinkedNode * appendNode (LinkedNode * last, int num) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (tmp == NULL)
    return NULL;

  tmp->data = num;
  tmp->next = NULL;

  if (last != NULL)
    last->next = tmp;

  return tmp;
}
```

E se usar essa função em um item no meio da lista? Como evitar esse
problema?

### Inserir no meio

```c
LinkedNode * insertNode (LinkedNode * current, int num) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (tmp == NULL)
    return NULL:
  
  tmp->data = num;

  if (current == NULL) {
    tmp->next = NULL;
  } else {
    tmp->next = current->next;
    current->next = tmp;
  }

  return tmp;
}
```

### Impressão

```c
void printList (LinkedNode * first) {
  LinkedNode * curr = first;
  while (curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}
```

Versão recursiva:

```c
void printListRecursive (LinkedNode * curr) {
  if (curr != NULL) {
    printf("%d ", curr->data);
    printListRecursive(curr->next);
  }
}
```

### Remoção

```c
void removeFirstNode (LinkedNode * first) {
  free(first);
}
```

Lembrar de guardar o ponteiro do segundo item antes de remover!

```c
void removeNextNode (LinkedNode * current) {
  LinkedNode * nextnext = current->next->next;

  free(current->next);

  current->next = nextnext;
}
```

### Exercícios

1. Escreva um programa em C que leia duas sequências de números inteiros.
Cada sequência tem tamanho arbitrário e termina com três zeros 
consecutivos que não formam parte da sequência. O programa deve
determinar se a primeira sequência é `>`, `<` ou `==` que a segunda
(comparação lexicográfica).

   Utilizar **listas simplesmente ligadas**.

1. Escreva um programa em C que leia duas sequências de números inteiros.
Cada sequência tem tamanho arbitrário e termina com três zeros 
consecutivos que não formam parte da sequência. O programa deve
determinar se a primeira sequência é `>`, `<` ou `==` que **o reverso** da
segunda (comparação lexicográfica).

   Utilizar **listas simplesmente ligadas**.

## Listas duplamente ligadas

- Cada item é ligado ao próximo item e também ao anterior;
- **Vantagem:** a lista pode ser percorrida em ambas as direções.

![image](https://user-images.githubusercontent.com/14254807/36680475-a3955da2-1af4-11e8-9b02-bc781009f87f.png)

### Implementação

```c
typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
  int data;
  DLinkedNode * prev;
  DLinkedNode * next;
}
```

### Adicionar ao final

```c
DLinkedNode * appendNodeD (DLinkedNode * last, int num) {
  DLinkedNode * tmp = malloc(sizeof(DLinkedNode));
  if (tmp == NULL)
    return NULL;

  tmp->data = num;
  tmp->prev = last;
  tmp->next = NULL;

  if (last != NULL)
    last->next = tmp;

  return tmp;
}
```

### Inserir no meio

```c
DLinkedNode * insertNodeD (DLinkedNode * current, int num) {
  DLinkedNode * tmp = malloc(sizeof(DLinkedNode));
  if (tmp == NULL)
    return NULL;

  tmp->data = num;
  tmp->prev = current;
  if (current == NULL) {
    tmp->next = NULL;
    return tmp;
  } else {
    tmp->next = current->next;
    if (current->next != NULL)
      current->next->prev = tmp;
    current->next = tmp;
  }

  return tmp;
}
```

### Exercício

Escreva um programa em C que leia duas sequências de números inteiros.
Cada sequência tem tamanho arbitrário e termina com três zeros 
consecutivos que não formam parte da sequência. O programa deve
determinar se a primeira sequência é `>`, `<` ou `==` que **o reverso** da
segunda (comparação lexicográfica).

Utilizar **listas duplamente ligadas**.

## Listas simplesmente ligadas com nó cabeça

- Cada item é ligado somente ao próximo item;
- O primeiro item não armazena dados da lista (e nunca é excluído);
- **Vantagem:** não é necessário verificar se a lista está vazia (o item cabeça
nunca é removido).

![image](https://user-images.githubusercontent.com/14254807/36680828-a0a000f6-1af5-11e8-94ee-c84617839ed3.png)

### Adicionar ao final

```c
LinkedNode * appendNode (LinkedNode * last, int num) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (tmp == NULL)
    return NULL;

  tmp->data = num;
  tmp->next = NULL;

  last->next = tmp;

  return tmp;
}
```

### Inserir no meio

```c
LinkedNode * insertNode (LinkedNode * current, int num) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (tmp == NULL)
    return NULL:
  
  tmp->data = num;

  tmp->next = current->next;
  current->next = tmp;

  return tmp;
}
```

## Listas circulares

- Cada item é ligado somente ao próximo item e **o último item é ligado
ao primeiro**.

![image](https://user-images.githubusercontent.com/14254807/36680949-f7e0f5b4-1af5-11e8-8c46-19652a389223.png)


### Implementação

```c
typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int data;
  LinkedNode * next;
}
```

## Resumo

![image](https://user-images.githubusercontent.com/14254807/36681180-a8f7fe6a-1af6-11e8-9fbd-12f1b3651efb.png)


### Listas com arranjos

```diff
+ Simples para usar;
+ Alocação em bloco contínuo;
+ Acesso a um item em tempo constante;
- Requer saber a quantidade de itens previamente (para alocação);
- Inserção/remoção requer deslocamentos;
- Expansão custosa (realocar e copiar).
```

### Listas ligadas/encadeadas/enlaçadas

```diff
+ Não requer conhecer a quantidade de itens previamente;
+ Inserção e remoção não requer deslocamentos;
- Acesso a uma posição necessita percorrer a lista;
- Memória extra para os ponteiros.
```

## Exercícios

Escreva funções em C para realizar as seguintes operações com listas 
simplesmente ligadas:

1. Concatenar duas listas.
1. Inverter uma lista sobre ela mesma (sem criar uma nova);
1. Dividir uma lista em duas metades. Se o tamanho da lista é ímpar, a segunda
metade terá tamanho ímpar.
1. Eliminar o primeiro item de uma lista.
1. Eliminar o último item de uma lista.
1. Inserir um item na posição `i` da lista.
1. Remover o item da posição `i` da lista.

## Referências

- Nivio Ziviani. **Projeto de Algoritmos: com implementações em Pascal e C**.
Cengage Learning, 2015.
- Robert Sedgewick. **Algorithms in C/C++/Java, Parts 1-4 (Fundamental Algorithms,
Data Structures, Sorting, Searching)**. Addison-Wesley Professional.
- Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein. 
**Algoritmos: Teoria e Prática**. Elsevier, 2012.