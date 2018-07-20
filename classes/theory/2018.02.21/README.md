# Breve revisão de ponteiros e estruturas dinâmicas
*Retirado dos slides da Prof. Mirtha Lina, CMCC/UFABC.*

## Introdução

### Exercício aula

Escreva um programa em C que leia duas sequências de números inteiros. Cada sequência tem tamanho
arbitrário e termina com três zeros consecutivos que não formam parte da sequência. O programa
deve determinar se a primeira sequência é `>`, `<` ou `==` que o **reverso** da segunda.

**Como saber quanta memória reservar para armazenar os dados?** Não dá pra saber! Precisamos reservar
memória dinamicamente.

**Estratégia 1:** Começar com um tamanho de vetor mínimo (ex. 10) e, se não for suficiente, dobrar
o tamanho.

### Ponteiros

C permite o acesso e o gerenciamento dinâmico da memória do programa, usando o tipo de dado ponteiro.

- Uma variável ponteiro armazena um endereço de memória. Para declarar um ponteiro usa-se o operador
`*` após o tipo dos dados cujos endereços ele vai armazenar (tipo base).
  ```c
  int * ip;
  char * cp = "Hello world";
  ```
- Para obter o enderço de uma variável usa-se o operador `&`.
  ```c
  int i = 100;
  pi = &i;
  ```
- Para obter o dado apontado pelo ponteiro (dereferenciar) também usa-se o operador `*`.
  ```c
  printf("*ip = %d *cp = %c", *ip, *cp);
  ```
  
  ![image](https://user-images.githubusercontent.com/14254807/36484998-c382450c-16f9-11e8-9bd2-9efd52595196.png)

#### Exemplo

```c
#include <stdio.h>

int main () {
  int  i = 20; 
  char c='A';  
  int *ip;                    /* pointer  declaration */
  ip = &i;                    /* stores address of i in pointer */

  printf("Addresses of ip, c and i:%p - %p - %p\n", &ip,&c,&i);
  printf("Sizes of ip, c, i: %d - %d - %d\n", 
          sizeof(ip), sizeof(i), sizeof(c));
   
  printf("Values stored in pi, c, i : %p - %x - %x\n", ip, c, i );

  /* access the value using the pointer */
  printf("Value of *ip variable: %X\n", *ip );

  return 0;
}
```

<table>
	<thead>
		<tr>
			<th>Variável</th>
			<td><code>ip</code></td>
			<th></th>
			<th></th>
			<th></th>
			<th></th>
			<td><code>c</code></td>
			<td><code>i</code></td>
			<th></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<th>Valor</th>
			<td>0x00007ffe</td>
			<td>0x22bc368c</td>
			<td colspan="4">0x00000041</td>
			<td>0x00000014</td>
			<td>0x????????</td>
		</tr>
		<tr>
			<th>Endereço</th>
			<td>0x7ffe22bc3680</td>
			<td>0x7ffe22bc3684</td>
			<td colspan="4">0x7ffe22bc3688</td>
			<td>0x7ffe22bc368c</td>
			<td>0x7ffe22bc3690</td>
		</tr>
	</tbody>
</table>

### Ponteiros e alocação dinâmica de memória

- É possível alocar e liberar memória em tempo de execução usando as funções `malloc`, `calloc`, 
`realloc` e `free`;
- A constante `NULL` (que representa um ponteiro nulo `==0`) é retornada caso não houver memória
disponível para ser alocada.

```c
#include <stdio.h>
#include <stdlib.h>

int main (void) {
  int * p1 = malloc(4 * sizeof(int)); // Allocates an array of 4 int.
  int * p2 = malloc(sizeof(int[4]));  // Same, naming the type.
  
  if (p1) {
    for (int i = 0; i < 4; i++) {
      p1[i] = i * i;
    }
  }
  
  free(p1);
  free(p2);
  
  return 0;
}
```

### Ponteiros e Vetores

Os ponteiros podem ser usados para acessar os elementos de um vetor. Para isso, C permite usar
os operadores `++`, `--`, `+` e `-`.

```c
#include<stdio.h>

int main (void) {
  double arr[5] = {1000.0, 2.0, 3.4, 17.0, 50.0}; 
  int i;
   
  printf("\nArray values using arr as address\n");
  for (i = 0; i < 5; i++) {
    printf("arr[%d] = %f =  %f\n",  i, *(arr + i), arr[i]);
  }

  double * p = arr, *q = p;

  printf("\nArray values using pointer\n");
  for (i = 0; i < 5; i++) {
    printf("\nAddress of arr[%d] = %x\n", i, q);
    printf("*(p + %d) = %f =  %f\n",  i, *(p + i), (*q));
    q++;
  }
}
```


### Erros comuns com ponteiros

- Não inicializar ponteiros ou criar alias. Dereferenciar ponteiros nulos ou com referências não
válidas (*dangling references*);
- Não liberar memória que não vai ser mais usada. Quando não puder mais ser acessada vira **lixo**
(*garbage* ou *memory leak*);
  ```c
  int * p1 = malloc(sizeof(int));
  *p1 = 4;
  int * p2 = p1;                    // Alias of p1.
  int * p3 = malloc(sizeof(int));
  
  free(p1);                         // p2 is now dangling.
  
  printf("%d\n", *p2);              // Print ????
  
  p3 = malloc(sizeof(int));         // Former p3 is now garbage.
  ```
- Abusar da aritmética de ponteiros e acessar memória fora dos limites de um vetor ou estrutura;
- Liberar memória que não foi alocada ou já foi liberada.

### Ponteiros e Funções

**Relembrando:** A transferência de parâmetros em C é por valor, i.e. somente o valor do argumento
na chamada é transferido para o parâmetro formal da função e esse valor não pode ser mudado.

- Os ponteiros permitem modificar o conteúdo de um parâmetro. Como argumento deve ser transferido
o endereço de uma variável.
- Os ponteiros podem ser retornados. Isso, permite criar um vetor ou estrutura dentro de uma função
e retornar seu endereço.

```c
int * swapAlloc (int * xa, int * ya) {
  int temp = *xa;
  *xa = *ya;
  *ya = temp;
  return malloc(*xa * sizeof(int));
}

int main () {
  int x, y;
  scanf("%d", &x);
  scanf("%d", &y);
  int * arr = swapAlloc(&x, &y);
  printf("x = %d, y = %d", x, y);
  
  return 0;
}
```

### Exercício aula

Escreva um programa em C que leia duas sequências de números inteiros. Cada sequência tem tamanho
arbitrário e termina com três zeros consecutivos que não formam parte da sequência. O programa
deve determinar se a primeira sequência é `>`, `<` ou `==` que o **reverso** da segunda.

**Como saber quanta memória reservar para armazenar os dados?** Não dá pra saber! Precisamos reservar
memória dinamicamente.

**Estratégia 1:** Começar com um tamanho de vetor mínimo (ex. 10) e, se não for suficiente, dobrar
o tamanho. **Desvantagem?**

## Estudo independente

### Função `main` e seus argumentos

- Não pode ser usada em nenhum lugar do programa;
- Pode retornar `void` ou `int`; não precisa ter `return` no corpo;
- Pode ter ou não parâmetros, os argumentos fornecidos quando o programa é chamado na linha
de comando são cadeias.

```c
#include <stdio.h>

int main (int argc, char ** argv) {
  printf("Program name %s\n", argv[0]);
  
  if (argc == 2) {
    printf("The argument supplied is %s\n", argv[1]);
  } else if (argc > 2) {
    printf("Too many arguments supplied.\n");
  } else {
    printf("One argument expected.\n");
  }
}
```

## Bibliografia

- **C How to Program**, Paul J. Deitel & Harvey Deitel, 8th ed. 2015
- **Beginning C**, Ivor Horton, 5th ed. 2013
- **C Programming Language**, Brian W. Kernighan & Dennis Ritchie. 1988
- **Essential C**, Nick Parlante. 2003
  http://cslibrary.stanford.edu/101/EssentialC.pdf
- https://www.tutorialspoint.com/cprogramming/index.htm