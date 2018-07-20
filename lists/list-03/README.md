# Lista de Exercícios 3: Listas Ligadas
*Lista de exercícios da Prof. Mirtha Lina, CMCC/UFABC.*

## Operações sobre listas simplesmente enlaçadas

Escreva funções C para realizar as seguintes operações sobre listas simplesmente
enlaçadas. Defina outras funções auxiliares se achar conveniente.

1. Inserir/remover um elemento na posição `i` da lista.
1. Concatenar duas listas.
1. Inverter uma lista sobre ela mesma (i.e. sem criar uma nova).
1. Dividir uma lista em duas metades. Se o tamanho da lista é ímpar, a segunda
metade terá tamanho ímpar.
1. Eliminar o último nó de uma lista circular.

## Matrizes esparsas v.1

Uma matriz esparsa é uma matriz que contém pouquíssimos elementos que não são
zero (ver Figura 1). Dessa forma, a matriz pode ser representada de forma 
eficiente armazenando somente os elementos não nulos.

Existem várias representações para uma matriz esparsa. Na representação
enlaçada, são usados dois tipos diferentes de nós: um nó cabeça que armazena a
informação da linha ou coluna e o nó do elemento. Por exemplo, a seguinte matriz
pode ser representada em memória como mostra a Figura 2.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/36739667-43e7aba0-1bbf-11e8-9eed-527d910f3eb3.png"><br/>
  Figura 1: Exemplo de uma matriz esparsa.
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/36740176-6de31c86-1bc0-11e8-981c-d50cef3ebeb7.png"><br/>
  Figura 2: Representação enlaçada da matriz na Figura 1.
</p>

1. Defina uma estrutura de dados para armazenar uma matriz esparsa usando a 
representação enlaçada acima. Escreva uma função para criar a matriz.
1. Escreva uma função para inserir (ou atualizar) um elemento na matriz.
1. Escreva funções para ler e imprimir uma matriz esparsa.