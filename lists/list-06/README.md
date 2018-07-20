# Lista de Exercícios 6: Árvores Binárias de Busca
*Lista de exercícios da Prof. Mirtha Lina, CMCC/UFABC.*

## 1. Remoção por cópia nas ABBs (T. Hibbard e D. Knuth)

O algoritmo para remover um nó de uma ABB é chamado de remoção por cópia
e foi proposto por T. Hibbard em 1962. Essa remoção tem dois casos:

**Caso fácil:** Se o nó a remover `n` tem zero ou um filho `f`, atualizar o
link do pai do nó com `NULL` ou `f` respectivo.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37375381-15089246-26fe-11e8-8ff0-def8efc538a4.png">
</p>

**Caso difícil:** Se o nó a remover `n` tem dois filhos, reduzir ao caso anterior.

1. Colocar em `n` seu sucessor (menor nó à direita): `succ(n) = s = min(n.right)`.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37375426-4f7b20ce-26fe-11e8-9beb-7416c79c6d3d.png">
</p>

2. Remover `s` (note que `S` cumpre que `s.left == NULL`).

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37375466-80f5bb14-26fe-11e8-9fbe-760cc1403af7.png">
</p>

### Exercícios

1. Desenhe a árvore resultante de remover os seguintes nós (nessa ordem) da ABB
abaixo: D, P, A, M, T.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37375509-b068ed1c-26fe-11e8-81de-e8a8dc65efd0.png">
</p>

2. Escreva uma função para remover um elemento de uma ABB.
3. Escreva um programa e funções auxiliares apropriadas para testar sua
implementação da função de remoção.

## 2. Outras operações sobre árvores binárias de busca

Implemente as seguintes operações de ordem sobre uma ABB:

1. Funções para o cálculo do máximo e o mínimo.
1. Funções para o cálculo do sucessor e antecessor de um elemento. As suas funções
devem retornar `NULL` caso o elemento não estiver na árvore ou não existir sucessor
(caso do máximo) ou antecessor (caso do mínimo).

   **Exemplo:** Na árvore do exercício 1.1 acima, o mínimo é A, o máximo é Y,
   o sucessor de O é P, o antecessor de I é H.

Explique qual é a complexidade das suas funções no caso pior e melhor.