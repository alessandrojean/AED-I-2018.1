# Breve revisão da linguagem C

## Introdução

### Linguagem C desenvolvida por Dennis Ritchie, 1969-73

[![image](https://user-images.githubusercontent.com/14254807/36386976-59a81924-1576-11e8-87c4-0edbcbaadab9.png)](https://www.tiobe.com/tiobe-index/)

> "C is quirky, flawed, and an enormous success. C++ and Java, say, are presumably growing faster
> than plain C, but I bet C will still be around."
>
> **Dennis Ritchie's quotes**

### Algumas características da linguagem C

- Linguagem estruturada, flexível, modular, de propósito geral, combina características de alto
e baixo nível, referência para outras linguagens ex. C++, Java, C#, Go, Arduino, Verilog;
- Variedade de tipos de dados, operadores e funções predefinidas;
- Linguagem portável, com compiladores para todos os sistemas operacionais e plataformas de hardware;
- Programas compilados e executados de forma **muito** eficiente;
- *Língua franca*: autores de livros didáticos, ..., desenvolvedores;
- Ponteiros e funções para o gerenciamento de memória;
- Não é orientada a objetos (classes, encapsulation, data hiding, inheritane, polymorphism,
constructors/destructors, genericity, overloading, exceptions, runtime type checking).

> "Anybody who comes to you and says he has a perfect language is either naive or a salesman.""
>
> **Bjarne Stroutrup's quote**

## Elementos básicos da linguagem

### Tipos de Dados Básicos: Inteiros e Reais

| Type              | Storage size | Value range                                          |
| ----------------- | :----------: | :--------------------------------------------------: |
| `char`            | 1 byte       | -128 to 127 or 0 to 255                              |
| `unsigned char`   | 1 byte       | 0 to 255                                             |
| `signed char`     | 1 byte       | -128 to 127                                          |
| `int`             | 2 or 4 bytes | -32,768 to 32,767 or -2,147,488,648 to 2,147,483,647 |
| `unsigned int`    | 2 or 4 bytes | 0 to 65,535 or 0 to 4,294,967,295                    |
| `short`           | 2 bytes      | -32,768 to 32,767                                    |
| `unsigned short`  | 2 bytes      | 0 to 65,535                                          |
| `long`            | 4 bytes      | -2,147,483,648 to 2,147,483,647                      |
| `unsigned long`   | 4 bytes      | 0 to 4,294,967,295                                   |
| `float`           | 4 bytes      | 1.2E-38 to 3.4E+38                                   |
| `double`          | 8 bytes      | 2.3E-308 to 1.7E+308                                 |
| `long double`     | 10 bytes     | 3.4E-4932 to 1.1E+4932                               |

### Tipos de dados, constantes e declaração de variáveis

- Básicos: inclui o tipo `char`; não existe tipo bool: qualquer valor diferente de zero é `true`
enquanto zero representa `false`; `void` indica nenhum valor disponível; tipos enumerativos;
- Tipos derivados: arrays, pointers, unions, structures, functions;
- Uma `string` é um array de caractéres terminados por um caractere nulo `'\0'`.

**Declaração de váriaveis:** 1) Tipo 2) Identificadores 3) Inicialização.

```c
#define MPI 3.14             // Constant declaration

int main (void) {
  const int LENGHT = 10;     // Constant declaration
  int i, j = 2, k;           // Variable declaration
  float minSalary = 954.0;
  char s1[] = {'H', 'e', 'l', 'l', 'o', '\0'}, s2[] = "Hello", *s3 = "Hello;
}
```

### Identificadores e Palavras reservadas

As palavras reservadas de C não podem ser usadas como identificadores; as funções predefinidas
também não.

|            |          |            |            |
| :--------: | :------: | :--------: | :--------: |
| `auto`     | `else`   | `long`     | `switch`   |
| `break`    | `enum`   | `register` | `typedef`  |
| `case`     | `extern` | `return`   | `union`    |
| `char`     | `float`  | `short`    | `unsigned` |
| `const`    | `for`    | `signed`   | `void`     |
| `continue` | `goto`   | `sizeof`   | `volatile` |
| `default`  | `if`     | `static`   | `while`    |
| `do`       | `int`    | `struct`   | `_Packed`  |
| `double`   |          |            |            |

Use identificadores descritivos nem muito curtos nem muito longos, começando por minúscula.
Sinta-se a vontade de usar um estilo próprio porém consistente que ajude na legibilidade
do seu código!

### Saída e Entrada de dados

```c
// Defined in header <stdio.h>
int printf( const char *format, ... );
int printf( const char *restrict format, ... );
int fprintf( FILE *stream, const char *format, ... );
int fprintf(FILE *restrict stream, const char *restrict format, ... );
int sprintf( char *buffer, const char *format, ... );
int sprintf( char *restrict buffer, const char *restrict format, ... );

int scanf( const char *format, ... );
int scanf( const char *restrict format, ... );
int fscanf( FILE *stream, const char *format, ... );
int fscanf(FILE *restrict stream, const char *restrict format, ... );
int sscanf( char *buffer, const char *format, ... );
int sscanf( char *restrict buffer, const char *restrict format, ... );
```

### Exemplo de Entrada e Saída de dados

```c
#include <stdio.h>

int main(void) { 
    int i, j;  float x, y; char str1[10], str2[4]; char carr[2];

    char input[] = "25 54.32E-1 Thompson 56789 0123 56ab";

    int ret = sscanf(input, "%d%f   %9s   %2d  %f  %*d  %3[0-9]  %2c",
                             &i,&x, str1,  &j, &y,      str2,    carr);
    /* parse as follows:
            %d: an integer                                              => i
            %f: a floating-point value                                  => x
           %9s: a string of at most 9 non-whitespace characters         => str1
           %2d: two-digit integer (digits 5 and 6)                      => j
            %f:  a floating-point value (digits 7, 8, 9)                => y
           %*d: an integer which isn't stored anywhere
       %3[0-9]: a string of at most 3 decimal digits (digits 5 and 6)   => str2
           %2c: two characters                                          => carr
           ' ': all consecutive whitespace  */
       
    printf("Converted %d fields:\ni = %d\nx = %f\nstr1 = %s\n"
           "j = %d\ny = %f\nstr2 = %s\n"
           "carr[0] = U+%x\ncarr[1] = U+%x\n",
           ret, i, x, str1, j, y, str2, carr[0], carr[1]);
           
}   // Adapted from http://en.cppreference.com/w/c/io/fscanf
```

### Operadores

| Category       | Operator                            | Associativity |
| :------------: | :---------------------------------: | :-----------: |
| Postfix        |	`() [] -> . ++ --`                 | Left to right |
| Unary          |	`+ - ! ~ ++ - - (type)* & sizeof`  | Right to left |
| Multiplicative |	`* / %`                            | Left to right |
| Additive       |	`+ -`	                           | Left to right |
| Shift          |	`<< >>`	                           | Left to right |
| Relational     |	`< <= > >=`	                       | Left to right |
| Equality       |	`== !=`	                           | Left to right |
| Bitwise AND    |	`&`	                               | Left to right |
| Bitwise XOR    |	`^`	                               | Left to right |
| Bitwise OR     |	`|`	                               | Left to right |
| Logical AND    |	`&&`	                           | Left to right |
| Logical OR     |	`||`	                           | Left to right |
| Conditional    |	`?:`	                           | Right to left |
| Assignment     |	`= += -= *= /= %=>>= <<= &= ^= |=` | Right to left |
| Comma          |	`,`	                               | Left to right |

Para usar outras funções matemáticas incluir as bibliotecas `math.h` e `stdlib.h`. 
Ver mais informação [aqui](http://en.cppreference.com/w/c/numeric/math).

### Condicionais

```c
if (boolean_expression) {
  /* statement(s) will execute if the boolean expression is true */
} else {
  /* statement(s) will execute if the boolean expression is false */
}
```

```c
switch (expression) {
  case constant-expression:
    statement(s);
    break; // Optional
  case constant-expression:
    statement(s);
    break; // Optional
  // You can have any number of case statements.
  default:
    statement(s);
}
```

### Laços

```c
while (condition) {
  statement(s);
}

do {
  statement(s);
} while (condition);

for (init; condition; increment) {
  statement(s);
}
```

```c
#include <stdio.h>               // headers

int main(void){
  int i, j, n;                   // local variables definition 
  scanf("%d", &n);
  for( i = 3; i < n;  i+= 2 ){
    j = 2;
    while( j <= (i / j) ) {      // how to avoid the division?
      if( !( i % j ) ) break;
      j++;
    }
    if( j > i / j ) printf("%d\n", i);
  }
  return 0;
}
```

O que faz esse programa?

### Exercício 1

Escreva um programa em C que compare lexicograficamente duas sequências de números
inteiros de tamanho `N` e determine se a primeira é maior, menor ou igual que a segunda.

**Exemplo:** Para `N = 5`:

- A sequência `2, 4.5, 345, 5, 89` é maior do que a sequência `2, 4.5, 345, -1, 259`;
- A sequência `2, 4.5, 345, -5, -8` é menor do que `2, 4.5, 345, -5, -2`.

### Ambiente de trabalho

- Ambiente de desenvolvimento integrado (IDE):
  - Netbeans para C/C++;
  - CodeBlocks, [Tutorial de instalação](http://linguagemc.com.br/tutorial-para-instalacao-do-code-blocks/);
  - [AWS Cloud9](https://aws.amazon.com/pt/cloud9/?origin=c9io).
- Plataforma de desenvolvimento online
  - https://repl.it/languages/c
  - https://www.tutorialspoint.com/compile_c_online.php
- Editor de texto + gcc na linha de comando, ex. em Linux
  ```bash
  $ gcc hello.c -o hello.exe
  $ ./hello.exe
  ```

### Exercício 2

Escreva um programa em C que compare lexicograficamente duas sequências de números
inteiros de tamanho `N` e `M` e determine se a primeira é maior, menor ou igual que a segunda.

**Exemplo:** Para `N = 8` e `M = 4`:

- A sequência `2, 4.5, 345, 55, 89, 2, 5, 9` é maior do que a sequência `2, 4.5, 345, -1`;
- A sequência `2, 4.5, 345, 55, 89, 2, 5, 9` é menor do que `2, 4, 345, 55`;
- A sequência `2, 4.5, 345, 55, 89, 2, 5, 9` é maior do que `2, 4.5, 345, 55`.

Além disso, o programa deve calcular o produto dos elementos da menor sequência e a soma dos
elementos da maior. Caso sejam iguais, a soma e produto de ambas.

## Arrays

### Arrays (Vetores ou Arranjos)

Tipo de dados que permite armazenar um número fixo de valores de um mesmo tipo base e que podem
ser referenciados usando um identificador de variável.

- Declaração: 
  ```c
  TipoBase identificadorVar[NumElem];
  int v1[3]; int n = 3; float v2[n];
  ```
- Declaração com Inicialização:
  ```c
  int v3[100] = {0, 1, 2, 3};
  float v4[2] = {1.5, 2, 3}; // Instrução não válida
  ```
- Após a criação, não é possível mudar o número de elementos;
- Acesso aos elementos (índices `0 .. NumElem - 1`):
  ```c
  v1[0] = 1; v2[n - 1] = v2[n - 2];
  // Instruções válidas porém semanticamente erradas.
  v1[-1] = 65; v2[n] = 12.3;
  ```
  
```c
#include <stdio.h>

void  main() {
  int n;
  printf("Array size: "); scanf("%d", &n);
  int v[n];
  for(int i = 0; i < n; i++){
    printf("v[%d] = \n", i);
    scanf("%d", &v[i]);
    if ( v[i] & 1 ) 
      printf("\n%d -> B\n", v[i]); 
    else 
      printf("\n%d -> A\n", v[i]); 
        
    // Can we otimize this code?
  } 
}
```

O que faz esse programa?

## Funções

```c
returnType functionName (parameters) { inst }
```

- Somente podem devolver um valor de tipo básico ou ponteiro;
- A instrução `return` pode estar em qualquer lugar do corpo;
- A chamada `functionName(parameters)` deve ter correspondência com a declaração. A transferência
entre os parâmetros e os argumentos da chamada é **sempre** por valor.

```c
#include<stdio.h>

void readIntArr (int n, int arr[]);
void writeIntArr (int n, int arr[]);

int  main() {
  int numEl, n;
  printf("Digite o número de elementos do vetor: ");
  scanf("%d", &numEl);
  int v[numEl];
  readIntArr(numEl, v);
  writeIntArr(numEl, v);
  return 0;
}
```

### Exercício no laboratório

Escreva um programa em C que compare lexicograficamente duas sequências de números
inteiros de tamanho `N` e `M` e determine se a primeira é maior, menor ou igual que a segunda.

**Exemplo:** Para `N = 8` e `M = 4`:

- A sequência `2, 4.5, 345, 55, 89, 2, 5, 9` é maior do que a sequência `2, 4.5, 345, -1`;
- A sequência `2, 4.5, 345, 55, 89, 2, 5, 9` é menor do que `2, 4, 345, 55`;
- A sequência `2, 4.5, 345, 55, 89, 2, 5, 9` é maior do que `2, 4.5, 345, 55`.

Além disso, o programa deve calcular o produto dos elementos da menor sequência e a soma dos
elementos da maior. Caso sejam iguais, a soma e produto de ambas.

## Estudo independente

### Estruturas

Enquanto os vetores permitem armazenar vários elementos de dados de um único tipo usando só
um identificador de variável, as estruturas permitem armazenar elementos de dados de tipos
diferentes.

Para acessar cada elemento de dado de uma estrutura (*campo-field*) é usado o operador ponto (`.`).

```c
struct [sctructure tag] {
  member definition;
  ...
  member definition;
} [one or more structure variables];
```

```c
#include <stdio.h>

struct Books {
  char title[50];
  char author[50];
  char subject[100];
  int book_id;
}

void printBook (struct Books book) {
  printf("Book title: %s\n", book.title);
  printf("Book author: %s\n", book.author);
  printf("Book subject: %s\n", book.subject);
  printf("Book book_id: %s\n", book.book_id);
}
```

### Números (pseudo-) aleatórios

Para gerar números aleatórios deve ser usada a função `rand()`. No entando, antes deve ser
usada a função `srand()`, uma vez no início do programa. Ver mais informações [aqui](https://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c).

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
  srand(time(NULL)); // Use current time as seed for random generator.
  int random_variable = rand();
  printf("Random value on [0, %d]: %d\n", RAND_MAX, random_variable);
}
```

Possível saída:

    Random value on [0, 2147483647]: 1373858591
    
## Exercícios para casa

Escreva programas em C (definindo funções apropriadas) para:

1. Dado um inteiro `k > 1` e uma sequência de `M` números inteiros, determinar se a sequência
contem pelo menus uma sub-sequência de até `k` números consecutivos. Faça o programa imprimir
todas as sub-sequências máximas.
  **Exemplo:** Para `k = 4` a sequência `8, -10, 4, -2, -1, 0, 1, 2, 50, 51, 54` contém as
sub-sequências `-2, -1, 0, 1`; `-1, 0, 1, 2` e `50, 51`.
1. Gerenciar uma agenda de contatos. Para cada contato deve-se armazenar **Nome**, **Telefone** e **Email**. Seu programa deve dar as seguintes opções ao usuário: **Inserir um contato** no final da agenda, **Buscar dados pelo Nome**, **Buscar dados pelo Telefone**, **Mostrar Agenda** e **Sair**.

## Bibliografia e Links úteis

- **Beginning C**, Ivor Horton, 5th ed. 2013
  https://github.com/apress/beg-c-5th-edition
- **C How to Program**, Paul J. Deitel & Harvey Deitel, 8th ed. 2015
- **C Programming Language**, Brian W. Kernighan & Dennis Ritchie. 1988
- **Essential C**, Nick Parlante. 2003
  http://cslibrary.stanford.edu/101/EssentialC.pdf
- https://www.tutorialspoint.com/cprogramming/index.htm