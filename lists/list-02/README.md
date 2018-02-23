# Lista de Exercícios 2: Ponteiros e estruturas dinâmicas

## Vetores, Ponteiros e Strings

1. Quais são os valores de `x`, `y`, `z`, `p` e `pp` ao final da função abaixo?
   ```c
   void f () {
     int x, y, z, * p, * pp;
     y = 0;
     p = &y;
     pp = &p;
     x = *p;
     x += 4;
     (*p)++;
     --x;
     (*p) += x;
     p--;
     (*p) += x;
     p++;
     (**pp) += 3 * x;
   }
   ```
1. Identifique e corrija os erros nas funções abaixo.
   ```c
   // Item a)
   void trocaMin (int * i, int * j) {
     if (i < j) return;
     int * temp;
     *i = *j;
     *j = *temp;
   }
   
   // Item b)
   void main () {
     char * a = "trem", * b = "carro";
     if (a < b)
       printf("%s vem antes de %s no dicionário\n", a, b);
     else
       printf("%s vem depois de %s no dicionário\n", a, b);
   }
   
   // Item c)
   void xxx (char * v, int n, int k) {
     char * c;
     for (c = v; c < v + n; v += k)
       printf("%c", *c);
   }
   ```
1. Reflita sobre os erros do seguinte problema e como poderiam ser corrigidos.
   ```c
   #include <stdio.h>
   
   int main () {
     char * s1  = "Linguagem C";
     char s2[ ] = "Linguagem C";
     printf("%s\n", s1);
     printf("%s\n", s2);
     printf(s1);
     printf(s2);
     printf(s1 + 2);
     printf(*(s1 + 2));
     printf(&s2[2]);
     printf(s2 + 2);
     printf(s2[2]);
     printf(s1[1]);
     s1 += 4;
     s1++;
     s2 += 4;
     s2++;
     
     char * s3 = "Linguagem", s4[ ], s5[20];
     s3 = s4;
     s2 = s5;
     s5 = "Linguagem C";
     s5 = s3;
     
     return 0;
   }
   ```
   
## Operações sobre vetores dinâmicos e strings

Escreva funções C para realizar as seguintes operações. Pense cuidadosamente quais os parâmetros
de entrada-saída e o retorno de cada função. Escreva um programa para testar suas funções.

1. Inverter um vetor (i.e. sem criar um novo).
1. Inserir um elemento na posição `i` do vetor. Caso o valor de `i` exceda o número de elementos do
vetor (porém não o tamanho) insira na posição `i`, preencha com zero os elementos intermediários e
atualize o número de elementos. Caso o valor de `i` exceda o tamanho do vetor, crie (se possível)
um novo vetor com tamanho apropriado e insira como explicado anteriormente.
1. Dividir um vetor em dois vetores contendo os elementos negativos e positivos (não incluir os zeros).
1. Concatenar duas strings.
1. Dada uma string contendo uma frase (palavras separadas por espaço), obter outra com a conversão a
maiúsculas, minúsculas ou título dependendo de um parâmetro de entrada.
1. Dada uma string e uma letra, retornar um vetor de inteiros contendo as posições das ocorrências da
letra.