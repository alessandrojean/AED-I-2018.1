# Estruturas Lineares: Pilhas e Filas

## Introdução

<img align="right" src="https://user-images.githubusercontent.com/14254807/37260020-28438538-256d-11e8-8543-cecea80eca0a.png" width="170" height="115">

### Aulas Anteriores: Estruturas Lineares - Lista

#### Tipos de Listas

- Sequencial (i.e. usando vetores) ou encadeada/ligada/enlaçada (i.e. usando
referências);
- Com encadeamento simples ou duplo, com/sem nó cabeça, circulares ou não.

#### Operações Básicas sobre Listas

- Buscar o elemento <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.03.12/svgs/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode" align=middle width=9.395100000000005pt height=14.155350000000013pt/>: <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.03.12/svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.647755pt height=24.65759999999998pt/>;
- Inserir em uma posição <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.03.12/svgs/63bb9849783d01d91403bc9a5fea12a2.svg?invert_in_darkmode" align=middle width=9.075495000000004pt height=22.831379999999992pt/>: <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.03.12/svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.647755pt height=24.65759999999998pt/>;
- Remover o elemento <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.03.12/svgs/332cc365a4987aacce0ead01b8bdcc0b.svg?invert_in_darkmode" align=middle width=9.395100000000005pt height=14.155350000000013pt/>: <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.03.12/svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.647755pt height=24.65759999999998pt/>.

**Outras operações:** criar, copiar, ordenar, unir, dividir...

### Outros tipos de Listas Lineares: Pilhas e Filas

Duas importantes variantes de menor complexidade que resultam de restringir
as operações de inserção e remoção.

**Pilha:** Tipo abstrato de dados que inclui duas operações fundamentais:
a inserção (*push* - empilhar) e a remoção (*pop* - desempilhar)
- Ambas operações são sempre realizadas por um único extremo (início/final
= topo - *top*). Sempre é removido o elemento **mais** recentemente inserido;
- Também conhecidas como listas LIFO - *last in first out*.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37260094-e3b80c4e-256d-11e8-9e1c-5ada3fbcce50.png">
</p>

**Fila:** Tipo abstrato de dados que inclui duas operações fundamentais:
a inserção (*enqueue* - enfileirar) e a remoção (*dequeue* - desenfileiras)
- A inserção é sempre realizada pelo final enquanto a remoção é sempre
realizada pelo início. Sempre é removido o elemento **menos** recentemente
inserido;
- Também conhecidas como listas FIFO - *first in first out*.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37260271-f67bb586-256f-11e8-8d8e-108030c5e6f7.png">
</p>

## Pilhas

### Exemplo de Pilhas

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37260284-19a9c0a2-2570-11e8-93d8-a38e0356bd04.png">
</p>

- Nos compiladores: análise sintática, semântica, para lidar com funções recursivas;
- Balanceamento de símbolos auxiliares em expressões, tags em HTML e XML;
- Intepreta botões de avançar/voltar dos navegadores, desfazer/refazer dos editores.

### Implementação de pilha usando vetores

- Mesma estrutura de dados de um vetor; por isso é preciso armazenar a capacidade
e uma variável `first` que indica a posição do topo da pilha (coincide com o 
tamanho!)

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37260673-c8c3d628-2574-11e8-8517-1e252bb38bbc.png">
</p>

#### Alguns cuidados

- O Tipo base do vetor deve ser um ponteiro aos dados caso o tamanho deles
for maior do que o `sizeof(* void)`;
- Ao desempilhar, considerar o caso da pilha estar vazia;
- Ao empilhar, considerar o caso da pilha estar cheia;
- Liberar toda a memória ao terminar.

### Exemplo de implementação de pilha usando vetores

```c
#include <stdio.h>
#include <stdlib.h>

#define MINCAPACITY 15

typedef struct arrStack arrStack;

struct arrStack {
  int top;
  int capacity;
  int * data;
};

arrStack * createArrStack () {
  arrStack * temp = malloc(sizeof(arrStack));
  if (!temp)
    return NULL;
  temp->data = malloc(MINCAPACITY * sizeof(int));
  if (!temp->data) {
    free(temp);
    return NULL;
  }
  temp->top = 0;
  temp->capacity = MINCAPACITY;
  return temp;
}

int isEmpty (arrStack * stack) {
  return !stack || !stack->top;
}

int isFull (arrStack * stack) {
  return stack->top == stack->capacity;
}

int push (arrStack * stack, int elem) {
  if (isFull(stack))
    return 0;                      // return 0 if full
  stack->data[stack->top] = elem;
  return ++stack->top;             // returns the new size
}

int pop (arrStack * stack, int * elem) {
  if (isEmpty(stack))
    return -1;                     // return -1 if empty
  *elem = stack->data[--stack->top];
  return stack->top;               // returns the new size
}

void deleteStack (arrStack * stack) {
  if (!stack) {
    free(stack->data);
    free(stack);
  }
}

int main (int argc, char ** argv) {
  arrStack * stack = createArrStack();
  int i;

  printf("%d\n", push(stack, 1));
  printf("%d\n", push(stack, 145));
  printf("%d\n", pop(stack, &i));
  printf("%d\n", i);

  // Teste o código.

  return EXIT_SUCCESS;
}
```

O custo de todas as operações é constante <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.03.12/svgs/1e2f931ee6c0b8e7a51a7b0d123d514f.svg?invert_in_darkmode" align=middle width=34.000065pt height=24.65759999999998pt/>.

### O quê fazer quando a pilha está cheia?

**Solução 1:** Reportar um erro ou lançar uma exceção.

**Solução 2:** Em muitos casos há memória disponível no sistema; por que
não auto-ajustar?

Quanto e quando ajustar? Como garantir que o auto-ajuste não aconteça
frequentemente? Como evitar ter muita memória sem usar?

- *push*: dobrar o tamanho do vetor se a pilha está na capacidade máxima;
- *pop*: reduzir à metade o tamanho do vetor se a pilha está em um
quarto da capacidade.

**Exercício para casa:** Implementação de uma pilha auto-ajustável.

### Implementação básica de pilha enlaçada

- Mesma estrutura de dados de uma lista simplesmente ligada.

![image](https://user-images.githubusercontent.com/14254807/37260901-ce97dc96-2576-11e8-99b4-76a157b06b85.png)

#### `push(1)`

![image](https://user-images.githubusercontent.com/14254807/37260948-0a1f512c-2577-11e8-8c8a-7361cf9b0315.png)

#### `push(2)`

![image](https://user-images.githubusercontent.com/14254807/37260987-714ac1f6-2577-11e8-9493-3017874714ea.png)

#### `push(3)`: 

![image](https://user-images.githubusercontent.com/14254807/37260995-8e3ccbba-2577-11e8-888b-e65fda6751fa.png)

#### `pop()`

![image](https://user-images.githubusercontent.com/14254807/37261040-dfc613f6-2577-11e8-9f6d-ea72f8abd550.png)

#### `push(4)`

![image](https://user-images.githubusercontent.com/14254807/37261051-fa79f4ce-2577-11e8-8cae-b0e6cc36bf65.png)

- Ao empilhar, considerar se não há memória disponível;
- Ao desempilhar, considerar o caso da pilha estar vazia retornar booleano ou
valor apropriado, lançar exceção etc. Em linguagens sem coleta automática
de lixo, **importante** não esquecer de liberar o nó.

### Análise das operações

- **Implementação enlaçada:** O custo das operações é constante <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.03.12/svgs/1e2f931ee6c0b8e7a51a7b0d123d514f.svg?invert_in_darkmode" align=middle width=34.000065pt height=24.65759999999998pt/>. Precisa
de memória extra para os ponteiros.
- **Implementação usando vetor:** O custo das operações é constante <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.03.12/svgs/1e2f931ee6c0b8e7a51a7b0d123d514f.svg?invert_in_darkmode" align=middle width=34.000065pt height=24.65759999999998pt/>.
Capacidade máxima é um valor fixo.
- **Implementação usando vetor auto-ajustável:** Menos espaço desperdiçado.
No pior caso, o custo das operações é linear <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.03.12/svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.647755pt height=24.65759999999998pt/>.

**Análise amortizado:** Cálculo do custo médio por operação ao longo de uma
sequência de operações no pior caso.

> A partir de uma pilha autoajustável vazia, qualquer sequência de <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.03.12/svgs/fb97d38bcc19230b0acd442e17db879c.svg?invert_in_darkmode" align=middle width=17.739810000000002pt height=22.46574pt/> 
> operações *push* e *pop* tem um custo proporcional a <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.03.12/svgs/fb97d38bcc19230b0acd442e17db879c.svg?invert_in_darkmode" align=middle width=17.739810000000002pt height=22.46574pt/>. Portanto,
> cada operação tem custo amortizado constante.
>
> Robert Sedgewick. Algorithms, 4th Edition. Addison-Wesley, 2011.

## Filas

### Exemplo de Filas

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37261111-9f38d9e4-2578-11e8-82d9-b95a3113d70e.png">
</p>

Nos sistemas operacionais são usadas, por ex., para armazenar tarefas ainda
não processadas ou concluídas.
- Os caracteres lidos do teclado;
- Documentos esperando para serem impressos;
- Processos esperando para usar um recurso;
- Instruções para serem executadas na CPU;
- Pacotes para serem encaminhados.

### Fila: Implementação enlaçada

- Mesma estrutura de dados de uma lista simplesmente ligada com ponteiros ao
primeiro e último elementos.

```c
typedef struct LinkedNode LinkedNode;

struct LinkedNode {
  int data;
  LinkedNode * next;
};

struct Queue {
  LinkedNode * first, * last;
};
```

- Em linguagens sem coleta automática de lixo, ao desenfileirar não
esquecer de liberar o nó.

![image](https://user-images.githubusercontent.com/14254807/37261177-3556ca76-2579-11e8-8ce0-aa485db24597.png)

#### `enqueue(1)`

![image](https://user-images.githubusercontent.com/14254807/37261187-4dfad324-2579-11e8-8b43-c1e8e8581124.png)

#### `enqueue(2)`

![image](https://user-images.githubusercontent.com/14254807/37261198-77efde2c-2579-11e8-89f3-15c8fd524043.png)

#### `enqueue(3)`

![image](https://user-images.githubusercontent.com/14254807/37261206-8b1cbe84-2579-11e8-996b-a8f7b2262bcb.png)

#### `dequeue()`

![image](https://user-images.githubusercontent.com/14254807/37261218-9ea7d77c-2579-11e8-81b1-1432e05cb4d6.png)

#### `enqueue(4)`

![image](https://user-images.githubusercontent.com/14254807/37261244-c040899c-2579-11e8-9665-d50106d90043.png)

### Fila: Implementação usando vetores

- Da mesma forma que as pilhas, as filas podem ser implementadas usando um
único cursor dentro do vetor.

**Exemplo:** após enfileirar os inteiros 1, 2, 3, 4, 5.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37261269-fa2477d6-2579-11e8-9acf-3d04d50f3abd.png">
</p>

- Isso faz com que uma das operações tenha custo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.03.12/svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.647755pt height=24.65759999999998pt/>. É melhor usar dois
cursores e deixar a fila deslocar pelo vetor.

**Exemplo:** após desenfileirar 1.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37261299-2ee242b4-257a-11e8-8caa-d2a2609b5268.png">
</p>

**Exemplo:** após desenfileirar 1, 2, 3 e enfileirar 6, 7, 8.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37261317-4a5164da-257a-11e8-877b-619b97c83842.png">
</p>

- Além disso, para garantir tempo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/laboratory/2018.03.12/svgs/1e2f931ee6c0b8e7a51a7b0d123d514f.svg?invert_in_darkmode" align=middle width=34.000065pt height=24.65759999999998pt/>, o deslocamento deve ser circular.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37261366-9c3f7174-257a-11e8-929b-95e3f2d0362d.png">
</p>

**Exemplo:** antes.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37261317-4a5164da-257a-11e8-877b-619b97c83842.png">
</p>

Após enfileirar 4, 5 e enfileirar 9, 10, 11.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37261388-cc4dd2d4-257a-11e8-828d-4ce9d7644011.png">
</p>

### Fila: Implementação usando vetores, alguns cuidados

- Incrementar os cursores de forma apropriada i.e. se estiverem na última posição
do vetor, a nova posição é 0;
- Onde colocar o cursor `last`: na posição do último elemento ou na seguinte vazia?

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37261411-052784a6-257b-11e8-910c-fdc25b08a670.png">
</p>

- Verificar se a lista está vazia ou cheia: verificar os índices ou usar
um contador auxiliar para o tamanho?
- Igualmente válidas as considerações sobre implementação de pilhas usando
vetores.

**Exercício para casa:** Implementação de uma fila auto-ajustável.

## Conclusões

- As pilhas e filas são casos especiais de listas lineares amplamente
usadas na computação;
- O custo das operações é constante. Nas versões autoajustáveis o custo
do redimensionamento é amortizado nas operações seguintes;
- Outras variantes de filas: 
  - **Fila simétrica** (*Deque*, *Dequeue*, *Double-Ended Queues*), 
  inserções e remoções por ambos os extremos;
  - **Fila de prioridades** (*Priority Queue*), insere em qualquer posição,
  remove o elemento de maior prioridade.

## Referências Bibliográficas

- Thomas H. Cormen; Charles E. Leiserson; Ronald L. Rivest; Clifford Stein.
**Introduction to Algorithms, 3rd Edition**. 2009;
- Robert Sedgewick; Kevin Wayne. **Algorithms, 4th Edition**. 2011.
Slides: http://algs4.cs.princeton.edu/lectures/
- Donald Knuth. **The Art of Computer Programming, 3rd Edition**.
Section 6.1: Sequential Searching. 1997;
- Nivio Ziviani. **Projeto de Algoritmos, 2ª Edição**. 2007;
- Jayme L. Szwarcfiter; Lilian Markezon. **Estruturas de Dados
e seus Algoritmos, 3ª Edição**. 2010.