# Noções básicas de complexidade de algoritmos

## Introdução

### Aula anterior: Vetores vs. Listas enlaçadas?

- Dado um problema, como saber que estrutura de dados escolher? 
  
  Depende das operações a serem realizadas e o custo ou complexidade delas.

- Custo do quê? 
  
  Dos recursos que serão consumidos pelo algoritmo que implementa a operação.

  - Tempo de execução e quantidade de memória interna/externa: depende do 
  computador;
  - Dificuldade de implementação (?), numero de linhas de código: depende da 
  linguagem e o programador.

Como medir o custo ou complexidade de tempo e espaço, de um algoritmo 
independentemente de hardware de computador, linguagem de programação, compilador,
estilo de codificação etc?

### Objetivos da Análise da Complexidade de Algoritmos

- Ajudar a determinar qual algoritmo é mais eficiente para resolver um problema;
- Medir como o tempo ou espaço aumenta com relação ao **tamanho de entrada**.

**Tamanho da entrada:** número de elementos de dados que são entrada para o algoritmo. Varia 
dependendo do problema.

- Número de elementos de um conjunto/sequência;
- Dimensões de uma matriz;
- Quantidade de bits na representação de um número;
- Número de vértices e/ou arestas de um grafo.

### Tipos de Análise da Complexidade de Algoritmos

- **Análise de caso pior:** considera as entradas para a qual o algoritmo tem o maior custo;
- **Análise de caso melhor:** considera as entradas para as quais o algoritmo tem o menor custo;
- **Análise de caso médio&ast;:** calcula a média do custo sobre todas as entradas, assumindo
uma distribuição.

**Importante**

1. **O custo exato do algoritmo é irrelevante.** O importante é obter uma boa aproximação
ou limite (*tigh bound*).
1. **Entradas pequenas são irrelevantes.** O importante é o comportamento do algoritmo
quando o tamanho da entrada é grande (*asymphotic efficiency*).

**&ast;** Não é objetivo da matéria. Será estudado na disciplina Análise de Algoritmos.

## Análise Assintótica e Notações O, &Omega;, &Theta;

### Análise Assintótica de Algoritmos

- Assume um modelo abstrato de computador com um conjunto **básico** de operações e seus custos;
- O custo de tempo é uma função $T(n)$ onde $n$ representa o tamanho da entrada. **Exemplo:** Insertion-Sort, $n = A.length$

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/36647924-214921dc-1a6b-11e8-879a-65aadb6a66be.png">
</p>

$$T(n) = c_1n + (c_2 + c_4)(n - 1) + c_5\sum_{j = 2}^{n}t_j + (c_6 + c_7)\sum_{j = 2}^{n}(t_j - 1) + c_8(n - 1)$$

- **Caso melhor:** $A$ já ordenado $\Rightarrow \forall j = 2 \dots n, t_j = 1$
  
  $$T(n) = (c_1 + c_2 + c_4 + c_5 + c_8)n - (c_2 + c_4 + c_5 + c_8)$$
- **Caso pior:** $A$ em ordem decrescente $\Rightarrow \forall j = 2 \dots n, t_j = j$

  $$
  \begin{align*}
  T(n) =& \left(\frac{c_5}{2} + \frac{c_6}{2} + \frac{c_7}{2}\right)n^2 + \left(c_1 + c_2 + c_4 + \frac{c_5}{2} - \frac{c_6}{2} - \frac{c_7}{2} + c_8\right)n\\
        & - (c_2 + c_4 + c_5 + c_8)
  \end{align*}
  $$
  
### Notações assintóticas ou de Bachmann-Landau (*O*)

Permitem descrever o comportamento assintótico de uma função quando o argumento tende a infinito.

- **Notação *O*:** expressa um limite superior para o comportamento assintótico de uma função, de forma
aproximada.

$$O(g(n)) = \left\{\ f(n)\ |\ \exists c > 0, n_0, \forall n > n_0, f(n) \leq c * g(n) \ \right\}$$

Informalmente, $f(n) \in O(g(n))$ (se escreve
$f(x) = O(g(x))$), significa que $f(n)$ não cresce mais rapidamente que $g(n)$, para valores de $n$ suficientemente grandes (como se $f(x) \leq g(x)$).

**Exemplo:** $5n = O(n^2),\ 10n^2 + 5n = O(n^2),\ n^3 \neq O(10n^2)$

### Notações assintóticas ou de Bachmann-Landau (&Omega;)

Permitem descrever o comportamento assintótico de uma função quando o argumento tende a infinito.

- **Notação &Omega;:** expressa um limite inferior para o comportamento assintótico de uma função, de forma aproximada.

$$O(g(n)) = \left\{\ f(n)\ |\ \exists c > 0, n_0, \forall n > n_0, f(n) \geq c * g(n) \ \right\}$$

Informalmente, $f(n) \in \Omega(g(n))$ (se escreve
$f(x) = \Omega(g(x))$), significa que $f(n)$ cresce mais rapidamente que $g(n)$, para valores de $n$ suficientemente grandes (como se $f(x) \geq g(x)$).

**Exemplo:** $n^2 = \Omega(300n + 1000),\ 10n^2 + 5n = \Omega(n^2)$

### Notações assintóticas ou de Bachmann-Landau (&Theta;)

Permitem descrever o comportamento assintótico de uma função quando o argumento tende a infinito.

- **Notação &Theta;:** expressa um limite fireme ou restrito para o comportamento
assintótico de uma função, de forma aproximada.

$$O(g(n)) = \left\{\ f(n)\ |\ \exists c_1 > 0, c_2 > 0, n_0, \forall n > n_0, c_1 * g(n) \leq f(n) \leq c_2 * g(n) \ \right\}$$

Informalmente, $f(n) \in \Theta(g(n))$ (se escreve
$f(x) = \Theta(g(x))$), significa que $f(n)$ cresce tão rapidamente quanto $g(n)$
dentro de um fator, para valores de $n$ suficientemente grandes.

**Exemplo:** $10n^2 + 5n = \Theta(n^2),\ n \neq \Theta(n^2),\ n^3 \neq \Theta(10n^2)$

### Algumas propriedades das notações *O*, &Omega;, &Theta;

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/36792274-e93b255a-1c78-11e8-8a98-1a0e36ed2eeb.png">
</p>

1. Todas reflexivas e transitivas; $\Theta$ é simétrica;
2. $f(x) = O(g(x)) \Leftrightarrow g(x) = \Omega(f(x))$
3. $f(x) = \Theta(g(x)) \Leftrightarrow f(x) = O(g(x))$ e $f(x) = \Omega(g(x))$
4. $O(kf(x)) = O(f(x)), \forall k \neq 0)$
5. $O(f(x)) + O(g(x)) = O(max(f(x), g(x)))$

### Propriedades das notações *O*, &Omega;, &Theta;

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/36647924-214921dc-1a6b-11e8-879a-65aadb6a66be.png">
</p>

$$T(n) = c_1n + (c_2 + c_4)(n - 1) + c_5\sum_{j = 2}^{n}t_j + (c_6 + c_7)\sum_{j = 2}^{n}(t_j - 1) + c_8(n - 1)$$

Aqui, pelo caso pior $T(n) = O(n^2)$. Porém, $T(n) \neq \Theta(n^2)$ pois no caso
melhor $T(n) \neq \Omega(n^2)$, e sim $T(n) = \Omega(n)$.

## Complexidade de Algoritmos não Recursivos

### Pequeno guia para a análise do caso pior

- Operações sobre tipos básicos: $O(1)$
- Sequência de instruções: $O(max(I_1, I_2, \dots, I_n))$
- Condicional **if**: $O(max(test + then, test + else))$
- Laços: $O\left(\sum_{i = 1}^{iterNum}(test + body)\right)$

```c
if (a + b % c) {                // Test.
  i = 0;                        // Assignment operator
  while (i < n)                 // Test, iterations?
    d[i++] = a + b;             // Body.
} else {
  for (i = 0; i < n; i++)       // Test, iterations?
    for (j = 0; j < n; j++)     // Test, iterations?
      f[i][j] = c;              // Body.
  for(i = 1; i <= n; i *= 2)    // Iterations?
    count++;
}                               // T(if)?
```

```c
for (i = 0; i < n; i++)
  for (j = 0; j < n; j++)
    for (k = 0; k <= j; j++)
      f[i][j][k] = c;
```

$$\sum_{i = 1}^{n} i = \frac{n(n+1)}{2}$$

```c
for (i = 1; i <= n; i *= 2)
  for (j = 0; j < i; j++)
    count++;
```

$$\sum_{i = 0}^{n} c^i = \frac{c^{n+1} - 1}{c - 1},\ c \neq 1$$

### Classes de Complexidades

Permite definir uma hierarquia na complexidade dos algoritmos.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37095690-5fa4f62c-21f5-11e8-8d04-f2b5cd3445d7.png">
</p>

$$O(1) \subset O(\log(n)) \subset O(n) \subset O(n^2) \subset O(2^n) \subset O(n!) \subset O(n^n)$$

- $\forall a, b, a > 0, O((\log(n))^b) \subset O(n^a)$
- $\forall a, b, a > 1, O(n^b) \subset O(a^n)$

| Complexidade                | Nome         | Exemplo                                   |
| --------------------------- | ------------ | ----------------------------------------- |
| $O(1)$                      | Constante    | Expressões e atribuições inteiras e reais | 
| $O(\log(\log(n)))$          | Logarítmica  | Busca por interpolação                    |
| $O(\log(n))$                | Logarítmica  | Busca binária                             |
| $O(n)$                      | Linear       | Busca sequencial                          |
| $O(n\log(n)) = O(\log(n!))$ | Quase linear | Métodos de ordenação eficientes           |
| $O(n^c)$                    | Polinomial   | Métodos de ordenação simples              |
| $O(c^n), c>1$               | Exponencial  | Todas as combinações de elementos         |
| $O(n!)$                     | Fatorial     | Todas as permutações de elementos         |

## Bibliografia

- **Introduction to Algorithms**, 3rd Edition. Thomas H. Cormen, Charles E. 
Leiserson, Ronald L. Rivest and Clifford Stein, 2009, caps 2-4.
- **An Introduction to the Analysis of Algorithms**, 2nd Edition. Robert
Sedgewick and Philippe Flajolet, 2013.
- **Algorithms Design: Foundation, Analysis and Internet Examples**. Michael
T. Goodrich and Roberto Tamassia, 2002.
- **Projeto de Algoritmos**, 2ª edição. Nivio Ziviani, 2007.
- Wikipédia: [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation)