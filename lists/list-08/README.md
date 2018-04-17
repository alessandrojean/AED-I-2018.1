# Lista de Exercícios 8: Ordenação

1. Adapte o algoritmo de ordenação por inserção de forma tal que
utilize a busca binária para achar a posição onde o elemento deve
ser inserido. Analise a complexidade do algoritmo.

2. Dada a sequência de números: `3 4 9 2 5 8 2 1 7 4`, ordene-a
em ordem não decrescente segundo os seguintes algoritmos, apresentando
a sequência obtida após cada passo do algoritmo: InsertionSort,
MergeSort e QuickSort.

3. Modifique a função de intercalação do MergeSort para usar memória
auxiliar de tamanho `n / 2`.

4. Escreva uma função baseada no QuickSort que dado um inteiro `k > 0`
e um vetor de `n > k` de números reais retorne os `k` maiores elementos
do vetor, não necessariamente em ordem. Por exemplo, suponha que os 
elementos `k = 3` e `V = 7, 1, 3, 10, 17, 2, 21, 9`. Então, sua função
deverá retornar os números `10, 17, 21` em alguma ordem.

5. Escreva um programa de complexidade **linear** (no caso pior)
que dados `n` números reais encontre todos os elementos que se
repetem pelo menos `n / 3` vezes. Justifique de forma apropriada
a complexidade do seu programa.

## Soma de quadrados

6. Escreva um programa que imprima todos os conjuntos de seis
inteiros positivos, `a1`, `a2`, `a3`, `a4`, `a5` e `a6`, tais que:
`a1 <= a2 <= a3 <= 30` e `a1 < a4 <= a5 <= a6 <= 20` e a soma dos
quadrados de `a1`, `a2` e `a3` seja igual à soma dos quadrados
de `a4`, `a5` e `a6`.

   **Dica:** Gere todas as somas possíveis de três quadrados e use
um procedimento de ordenação para localizar repetições.

7. Discorra sobre a complexidade no caso pior do seu programa.