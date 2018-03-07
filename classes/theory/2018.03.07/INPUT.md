# Noções básicas de complexidade de algoritmos

## Complexidade de algoritmos recursivos

### Análise de Algoritmos recursivos

Recursividade é um recurso de programação de grande importância.

```c
double powerR (float base, int n) {
  if (n == 0)
    return 1;
  else
    return base * powerR(base, n-1);
}

double powerI (float base, int n) {
  double pow = 1;
  for (int i = 0; i < n; i++)
    pow *= base;
  return pow;
}
```

#### Vantagens

- Fornece uma forma natural, simples e elegante de resolver um problema;
- Facilidade para analisar as propriedades de um algoritmo.

**Como analisar a complexidade de um algoritmo recursivo?**

### Algoritmos recursivos e Recorrências

A propriedades de um programa recursivo podem ser analisadas usando uma função
recursiva, chamada **relação de recorrência**.

```c
double powerR (float base, int n) {
  if (n == 0)
    return 1;
  else
    return base * powerR(base, n-1);
}
```

Em matemática, uma **relação de recorrência** é definida para um conjunto de
valores iniciais e em termos de ela mesma.

$$f(0) = c_0,\ f(1) = c_1,\ \dots,\ f(k) = c_k$$

$$f(n) = g\left(f(n - 1),\ f(n - 2),\ \dots,\ f(n - t)\right),\ n > k$$

- Número de chamadas recursivas:

$$C(0) = 0,\ C(n) = C(n - 1) + 1$$

- Tempo de execução:

$$T(0) = c_1,\ T(n) = T(n - 1) + c_2$$

### Relações de recorrência e seus tipos

$$f(0) = c_0,\ f(1) = c_1,\ \dots,\ f(k) = c_k$$

$$f(n) = g\left(f(n - 1),\ f(n - 2),\ \dots,\ f(n - t)\right),\ n > k$$

- **Linear:** se não há produtos ou potências de termos recursivos, ex. 
$C(n) - \sqrt{n}C(n - 1) = n$;
- **Não linear:** ex. $C(n) = C(n - 1) \cdot C(n - 2) + C(n - 3)$;
- **Homogênea:** se não há um termo não recursivo;
- De **segundo/terceiro/quarto grau** (em geral de ordem ou grau fixo),
dependendo do menor termo recursivo, ex. $D(n) - 3 \cdot D(n - 2) + D(n - 4) = 1$
é de ordem 4;
- **Com coeficientes constantes ou não**;
- **Divisão e conquista:** $T(n) = \sum_{i = 1}^{k} a_i \cdot T\left(\frac{n}{b_i}\right) + f(n)$.

### Exemplos de recorrências simples

- Linear, homogênea, de ordem 1 e coeficiente constante.

$$A(0) = 1,\ A(n) = 2 \cdot A(n - 1)$$

- Linear, homogênea, de ordem 1 e coeficiente variável.

$$B(0) = 1,\ B(n) = n \cdot B(n - 1)$$

- Linear, não homogênea, de ordem 1.

$$C(0) = 0,\ C(n) = C(n - 1) + 1$$

- Linear, homogênea, de ordem 2.

$$F(0) = 1,\ F(1) = 1,\ F(n) = F(n - 1) + F(n - 2)$$

### Como obter a solução de uma recorrência, i.e. uma função não recursiva equivalente?

```c
double powerR (float base, int n) {
  if (n == 0)
    return 1;
  else
    return base * powerR(base, n-1);
}
```

$$T(0) = c_1,\ T(n) = T(n - 1) + c_2,\ n > 0$$

\begin{align*}
T(n) =&\ T(n - 1) + c_2 = T(n - 2) + c_2 + c_2 = T(n - 3) + c_2 + c_2 + c_2 \\
      &\ T(n - k) + k \cdot c_2 = T(0) + c_2 \cdot n = c_1 + c_2 \cdot n 
\end{align*}

### Recorrências

- Não existe procedimento geral para resolver recorrências;
- Recorrências lineares de ordem fixa com coeficientes constantes sempre
podem ser resolvidas (Mathematica, WolframAlpha);

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37097901-52693594-21fb-11e8-907c-87b963b1ef00.png">
</p>

- Vários casos especiais podem ser resolvidos facilmente;
- A **análise de algoritmos** não precisa de uma solução exata; **basta uma
aproximação assintótica**.
  - **Método de substituição**;
  - **Árvore de recursividade**;
  - **Teorema Mestre**.

## Complexidade de Algoritmos de Divisão e Conquista

### Algoritmos de Divisão e Conquista

```c
double powerDC (float base, unsigned int n) {
  if (n == 0)
    return 1;
  else
    return powerDC(base * base, n / 2) * ((n % 2) ? base : 1);
}
```

As recorrências mais simples de divisão e conquista tem a forma

$$T(n) = aT\left(\frac{n}{b}\right) + f(n)$$

- $a > 0$ é o número de sub-problemas de tamanho $\frac{n}{b}$.
- $b > 1$ e $f(n)$ é o custo de dividir e combinar as sub-soluções.

### Árvore de recursividade (Recursion Tree)

Usada para visualizar recorrências de divisão e conquista.

$$T(n) = aT\left(\frac{n}{b}\right) + f(n)$$

- $a > 0$ é o número de sub-problemas de tamanho $\frac{n}{b}$.
- $b > 1$ e $f(n)$ é o custo de dividir e combinar as sub-soluções.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37098165-f9ba7dd0-21fb-11e8-9ba1-eebdf37164e1.png">
</p>

### Árvore de recursividade - $T(n) = aT\left(\frac{n}{b}\right) + f(n)$

- Consiste em desenhar a árvore das chamadas recursivas.
- Cada nó é rotulado com o custo de resolver o sub-problema individual. A soma
por níveis é calculada e depois a soma total.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37098325-62790f1c-21fc-11e8-8270-1e6efa3e427e.png">
</p>

$$a^{\log_b(n)} + \sum_{k = 0}^{\log_b(n) - 1} a^kf\left(\frac{n}{b^k}\right)$$

## Teorema Mestre - $T(n) = aT\left(\frac{n}{b}\right) + f(n)$

### Teorema Mestre

- É uma receita para recorrências de divisão e conquista onde o problema é
dividido em sub-problemas do mesmo tamanho.
- Permite obter uma aproximação assintótica, não a solução exata.

$$T(n) = n^{\log_b(a)} + \sum_{k = 0}^{\log_b(n) - 1} a^kf\left(\frac{n}{b^k}\right)$$

**Ideia:** Comparar $n^{\log_b(a)}$ e $f(n)$ para determinar
- Se $f(n)$ é assintoticamente menor ou maior que $n^{\log_b(a)}$ por um
fator polinomial $n^\epsilon,\ \epsilon > 0$.
- Se $f(n)$ é assintóticamente igual a $n^{\log_b(a)}$.

Pode ser limitado assintoticamente usando 3 casos:
1. $f(n) = O(n^{\log_b(a)}) \Rightarrow T(n) = \Theta(n^{\log_b(a)})$
1. $f(n) = \Theta(n^{\log_b(a)}) \Rightarrow T(n) = \Theta(n^{\log_b(a)} \log(n))$
1. $f(n) = \Omega(n^{\log_b(a) + \epsilon})$ e existe $c < 1$ tal que para
todo $n$ suficientemente grande $af\left(\frac{n}{b}\right) \leq cf(n) \Rightarrow T(n) = \Theta(f(n))$

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37098325-62790f1c-21fc-11e8-8270-1e6efa3e427e.png">
</p>

$$a^{\log_b(n)} + \sum_{k = 0}^{\log_b(n) - 1} a^kf\left(\frac{n}{b^k}\right)$$

### Caso 1 do Teorema Mestre

1. $f(n) = O(n^{\log_b(a)}) \Rightarrow T(n) = \Theta(n^{\log_b(a)})$

O custo é dominado pelo trabalho feito nas folhas.

### Caso 2 do Teorema Mestre

2. $f(n) = \Theta(n^{\log_b(a)}) \Rightarrow T(n) = \Theta(n^{\log_b(a)} \log(n))$

O trabalho está distribuído em todos os níveis.

### Caso 3 do Teorema Mestre

3. $f(n) = \Omega(n^{\log_b(a) + \epsilon})$ e existe $c < 1$ tal que para
todo $n$ suficientemente grande $af\left(\frac{n}{b}\right) \leq cf(n) \Rightarrow T(n) = \Theta(f(n))$

O custo é dominado pelo trabalho feito na raiz.

### Quais casos de Teorema Mestre se aplicam?

```c
double powerR (float base, int n) {
  if (n == 0)
    return 1;
  else
    return base * powerR(base, n - 1);
}

double powerDC (float base, unsigned int n) {
  if (n == 0)
    return 1;
  else
    return powerDC(base * base, n / 2) * ((n % 2) ? base : 1);
}
```

### Exemplos Caso 1 do Teorema Mestre

1. $f(n) = O(n^{\log_b(a)}) \Rightarrow T(n) = \Theta(n^{\log_b(a)})$

**Exemplo:** $T(n) = 4\left(\frac{n}{2}\right) + n,\ a = 4,\ b = 2$

$n^{\log_b(a)} = n^2,\ f(n) = n = O(n^{2 - \epsilon})$ para $\epsilon = 1$.
Logo $T(n) = \Theta(n^2)$

**Exemplo:** $T(n) = 2T\left(\frac{n}{2}\right) + \sqrt{n},\ a = 2,\ b = 2$

$n^{\log_b(a)} = n,\ f(n) = \sqrt{n} = O(n^{1 - \epsilon})$ para $\epsilon = \frac{1}{2}$. Logo $T(n) = \Theta(n)$.

### Exemplos Caso 2 do Teorema Mestre

2. $f(n) = \Theta(n^{\log_b(a)}) \Rightarrow T(n) = \Theta(n^{\log_b(a)} \log(n))$

**Exemplo:** $T(n) = 4\left(\frac{n}{2}\right) + n^2,\ a = 4,\ b = 2$

$n^{\log_b(a)} = n^2,\ f(n) = n^2 = \Theta(n^2)$. Logo $T(n) = \Theta(n^2 \cdot \log(n))$

**Exemplo:** $T(n) = 2\left(\frac{n}{2}\right) + n^2,\ a = 2,\ b = 2$

$n^{\log_b(a)} = n,\ f(n) = 10n = \Theta(n)$. Logo $T(n) = \Theta(n\log(n))$.

### Exemplos Caso 3 do Teorema Mestre

3. $f(n) = \Omega(n^{\log_b(a) + \epsilon})$ e existe $c < 1$ tal que para
todo $n$ suficientemente grande $af\left(\frac{n}{b}\right) \leq cf(n) \Rightarrow T(n) = \Theta(f(n))$

**Exemplo:** $T(n) = 4\left(\frac{n}{2}\right) + n^3,\ a = 4,\ b = 2$

$n^{\log_b(a)} = n^2,\ f(n) = n^3 = \Omega(n^{2 + \epsilon})$ para $\epsilon = 1$.
Além disso, $4\left(\frac{n}{2}\right)^3 \leq cn^3$ para $c = \frac{1}{2}$. Logo
$T(n) = \Theta(n^3)$.

**Exemplo:** $T(n) = 43\left(\frac{n}{4}\right) + n\log_2(n),\ a = 4,\ b = 4$

$n^{\log_3(4)} = n^{0.793},\ f(n) = n\log_2(n) = \Omega(n^{0.793 + \epsilon})$ para
$\epsilon = 0.207$, i.e. $n\log_2(n) = \Omega(n)$. Além disso, $3\left(\frac{n}{4}\right)\log_2\left(\frac{n}{4}\right) \leq cn\log_2(n)$, ex. para $c = \frac{3}{4}$.
Logo $T(n) = \Theta(n\log(n))$.

## Referências Bibliográficas

- **Introduction to Algorithms**, 3rd Edition. Thomas H. Cormen, Charles E. 
Leiserson, Ronald L. Rivest and Clifford Stein, 2009, caps 2,3,4
- **An Introduction to the Analysis of Algorithms**, 2nd Edition. Robert
Sedgewick and Philippe Flajolet, 2013
- **Algorithm Design: Foundation, Analysis, and Internet Examples**. Michael T. 
Goodrich and Roberto Tamassia, 2002
- **Projeto de Algoritmos**, 2ª Edição, Nivio Ziviani, 2007
- Wikipedia: [Master theorem](https://en.wikipedia.org/wiki/Master_theorem)

## Apêndice: Para saber mais

### Mais sobre o Teorema Mestre

#### Considerações sobre o Teorema Mestre apresentado

- O comportamento assintotico de $T(n)$ não muda se $T\left(\frac{n}{b}\right)$
é substituido por $T\left(\left\lceil\frac{n}{b}\right\rceil\right)$ ou $T\left(\left\lfloor\frac{n}{b}\right\rfloor\right)$
- Nem sempre pode ser aplicado
  - $T(n) = 4nT\left(\frac{n}{2}\right) + 3^n$
  - $T(n) = \frac{1}{2} T\left(\frac{n}{2}\right) + n$
  - $T(n) = 3T\left(\frac{n}{2}\right) - n\log(n)$
  - $T(n) = T\left(\frac{n}{3}\right) + T\left(\frac{2n}{3}\right) + n$
- Tem variantes mais gerais.
  
  **Forma geral do caso 2:** $f(n) = \Theta(n^{\log_b(a)}(\log(n))^k)$ para certo
  $k \geq 0 \Rightarrow T(n) = \Theta(n^{\log_b(a)}(\log(n))^{k + 1})$.

  **Exemplo:** $T(n) = 3T\left(\frac{n}{3}\right) + n\log(n)$, caso 3 não se
  aplica porque $n\log(n)$ não é polinomialmente maior do que $n$.

#### Forma geral do Teorema Mestre (Akra-Bazzi, 1998)

$$T(x) = g(x) + \sum_{i = 1}^{k} a_iT(b_ix + h_i(x)),\ x \geq x_0$$

- Sufficient base cases are provided;
- $a_i > 0$ and $0 < b_i < 1$ are constants for all $i$;
- $\left|g(x)\right| \in O(x^c)$, where $c$ is a constant;
- $\displaystyle\left|h_i(x)\right| \in O\left(\frac{x}{(\log(x))^2}\right)$ for all $i$.

https://en.wikipedia.org/wiki/Akra-Bazzi_method

#### Variantes Simples do Teorema Mestre

- $T(n) = aT\left(\frac{n}{b}\right) + n^c,\ a > 0,\ b > 0,\ c \geq 0$

$$T(n) = \begin{cases} 
\Theta(n^{\log_b(a)}) & \mbox{if } \log_b(a) > c \\
\Theta(n^c\log_b(n)) & \mbox{if } \log_b(a) = c \\
\Theta(n^c) & \mbox{if } \log_b(a) < c
\end{cases}$$

- $T(n) = aT(n - b) + n^c,\ a > 0,\ b > 0,\ c \geq 0$

$$T(n) = \begin{cases}
O(n^{c + 1}) & \mbox{if } a = 1 \\
O(n^ca^{\frac{n}{b}}) & \mbox{if } a > 1
\end{cases}$$

#### Variantes do Teorema Mestre - $T(n) = aT(n - b) + n^c$

$$T(n) = \begin{cases}
O(n^{c + 1}) & \mbox{if } a = 1 \\
O(n^ca^{\frac{n}{b}}) & \mbox{if } a > 1
\end{cases}$$

**Exemplo:** Torres de Hanoi, solução recursiva

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37102919-c1ce9634-2207-11e8-95fc-b539a0d53ccb.png">
</p>

```c
// dir == -1 -> left; dir == 1 -> right
// (move in a circular way)
void HanoiTower (int disksNum, int dir) {
  if (disksNum == 0)
    return;
  HanoiTower(disksNum - 1, -dir);
  moveDisk(disksNum, dir);
  HanoiTower(disksNum - 1, -dir);
}
```

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37103138-4b64e97a-2208-11e8-86b2-99e3738c81ab.png">
</p>

$$T(n) = 2T(n - 1) + 1 = O(2^n)$$

### Método da substituição

1. Substituir iterativamente até achar uma soma geral e resolver

$$\begin{array}{lcl}
\displaystyle\sum_{i = 0}^{n} i = \sum_{i = 1}^{n} i = \frac{n(n + 1)}{2} &&
\displaystyle\sum_{i = 1}^{n} i^c \in \Theta(n^{c + 1}),\ c > -1 \\
\displaystyle\sum_{i = 0}^{n} i^2 = \frac{n(n + 1)(2n + 1)}{6} &&
\displaystyle\sum_{i = 1}^{n} \frac{1}{i} \in \Theta(\log(n)) \\
\displaystyle\sum_{i = 0}^{n} i^3 = \left(\frac{n(n + 1)}{2}\right)^2 &&
\displaystyle\sum_{i = 1}^{n} c^i \in \Theta(c^n),\ c > 1 \\
\displaystyle\sum_{i = 0}^{n} c^i = \frac{c^{n + 1} - 1}{c - 1},\ c \neq 1 &&
\displaystyle\sum_{i = 1}^{n} \log(i) \in \Theta(n \cdot log(n))
\end{array}$$

2. Adivinhar a forma geral da solução e provar usando indução que é correta.
3. Transformar a recorrência num caso conhecido.

#### 2. Adivinhar a forma geral e provar por indução

```c
double powerDC (float base, unsigned int n) {
  if (n == 0)
    return 1;
  else
    return powerDC(base * base, n / 2) * ((n % 2) ? base : 1);
}
```

$$T(0) = c_1,\ T(n) = T\left(\frac{n}{2}\right) + c_2 = c_1 + c_2 \cdot (\log_2(n) + 1)\ ?$$

**Caso Base:**

$$n = 1 \Rightarrow T(1) = c_1 + c_2 = c_1 + c_2 \cdot (\log_2(1) + 1)$$

**Hipótese da Indução:**

$$1 < m < n \Rightarrow T(m) = c_1 + c_2 \cdot (\log_2(m) + 1)$$

**Passo de Indução:**

\begin{align*}
T(n) &= T\left(\frac{n}{2}\right) + c_2 = \left(c_1 + c_2 \cdot \left(\log_2\left(\frac{n}{2}\right) + 1\right)\right) + c_2 \\
     &= \left(c_1 + c_2 \cdot \left(\log_2(n) - \log_2(2) + 1\right)\right) + c_2 \\
     &= c_1 + c_2 \cdot \log_2(n) + c_2 \\
     &= c_1 + c_2 \cdot (\log_2(n) + 1)
\end{align*}

Como "adivinhar" a solução?

- Resolver para valores pequenos e chutar um termo geral;
- Adaptar a solução de um caso similar;
- Para recorrências de divisão e conquista, usar a árvore de recursividade.

### Outros exemplos de Árvore de Recursividade

#### Exemplo de Árvore de Recursividade

$$T(1) = 1,\ T(n) = 2T\left(\frac{n}{2}\right) + n^2$$

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37104246-fd5664ae-220a-11e8-90b6-0279a90fdfc9.png">
</p>

- Soma: $n^2 \cdot \sum_{k = 0}^{\log_2(n)} \frac{1}{2^k} = n^2\left(1 + \frac{1}{2} + \frac{1}{4} + \frac{1}{8} + \cdots\right)$
- Chutar que $T(n) \leq cn^2$ e provar por indução!

#### Árvore de Recursividade - $T(n) = \sum_{i = 1}^{k} a_i \cdot T\left(\frac{n}{b_i}\right) + f(n)$

- $a_i > 0$ é o número de sub-problemas de tamanho $\frac{n}{b_i}$.

**Exemplo:** Resolvendo $T(n) = T\left(\frac{n}{3}\right) + T\left(\frac{2n}{3}\right) + n$

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37104509-aa3d5ab0-220b-11e8-86db-be0ba6ae3c40.png">
</p>

- Chutar $T(n) \leq c \cdot n \cdot \log_2(n)$ e provar por indução!

### Outras Técnicas: Mudança de Variáveis

#### Resolvendo $T(n) = 2T(\sqrt{n}) + \log_2(n)$

- Mudando a variável:

$$m = \log_2{n} \Rightarrow n = 2^m \Rightarrow T(2^m) = 2T(2^{\frac{m}{2}}) + m$$

- Mudando a função:

$$S(m) = T(2^m) \Rightarrow S(m) = 2S\left(\frac{m}{2}\right) + m$$

- Aplicando o Teorema Mestre, caso 2:

$$S(m) = O(m \cdot \log(m))$$

Logo:

$$T(n) = T(2^m) = S(m) = O(m \cdot \log(m)) = O(\log(n) \cdot \log(\log(n)))$$

#### Resolvendo Fibonacci

$$a_n = a_{n - 1} + a_{n - 2},\ n \geq 2,\ a_0 = 0,\ a_1 = 1$$

- Postulate that $a_n = x^n$

$$x^n = x^{n - 1} + x^{n - 2}$$

- Divide by $x^{n - 2}$

$$x^2 - x - 1 = 0$$

- Factor $\left(\phi = \frac{1 + \sqrt{5}}{2},\ \hat{\phi} = \frac{1 - \sqrt{5}}{2}\right)$

$$(x - \phi)(x - \hat{\phi}) = 0$$

- Form of solution must be

$$a_n = c_0\phi^n + c_1\hat{\phi}^n$$

- Use initial conditions to solve for coefficients

$$a_0 = 0 = c_0 + c_1$$

$$a_1 = 1 = \phi c_0 + \hat{\phi}c_1$$

- Solution

$$a_n = \frac{\phi^n}{\sqrt{5}} - \frac{\hat{\phi}^n}{\sqrt{5}}$$