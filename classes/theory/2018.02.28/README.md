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
- O custo de tempo é uma função <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/cc4152a1ba8a0ec113e9f2062a489b7d.svg?invert_in_darkmode" align=middle width=34.541760000000004pt height=24.65759999999998pt/> onde <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> representa o tamanho da entrada. **Exemplo:** Insertion-Sort, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/14ebbd324f2b3e723b57f79088e851b0.svg?invert_in_darkmode" align=middle width=95.26654500000001pt height=22.831379999999992pt/>

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/36647924-214921dc-1a6b-11e8-879a-65aadb6a66be.png">
</p>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/3df7a9dcbec933bb76259139e556f27c.svg?invert_in_darkmode" align=middle width=538.3158pt height=47.13489pt/></p>

- **Caso melhor:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/53d147e7f3fe6e47ee05b88b166bd3f6.svg?invert_in_darkmode" align=middle width=12.328800000000005pt height=22.46574pt/> já ordenado <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/92cb1c946ad41d5a9294d107f0d6a4b8.svg?invert_in_darkmode" align=middle width=152.81375999999997pt height=22.831379999999992pt/>
  
  <p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/4fd0ddd607884ececda9d0ff5aee26df.svg?invert_in_darkmode" align=middle width=383.02109999999993pt height=16.438356pt/></p>
- **Caso pior:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/53d147e7f3fe6e47ee05b88b166bd3f6.svg?invert_in_darkmode" align=middle width=12.328800000000005pt height=22.46574pt/> em ordem decrescente <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/bc8dd7e9bdab0c833af029a203744f13.svg?invert_in_darkmode" align=middle width=152.3049pt height=22.831379999999992pt/>

  <p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/fd564934c8de922b63c99ae763f4984c.svg?invert_in_darkmode" align=middle width=475.86495pt height=54.673245pt/></p>
  
### Notações assintóticas ou de Bachmann-Landau (*O*)

Permitem descrever o comportamento assintótico de uma função quando o argumento tende a infinito.

- **Notação *O*:** expressa um limite superior para o comportamento assintótico de uma função, de forma
aproximada.

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/a20c71f24382c024c1cfb211c4f9bea9.svg?invert_in_darkmode" align=middle width=405.9825pt height=16.438356pt/></p>

Informalmente, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/ea839fa247a13cf65b099b2d9d5c3071.svg?invert_in_darkmode" align=middle width=109.42437pt height=24.65759999999998pt/> (se escreve
<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/6e28871a6a32a516e600da6b46683a1f.svg?invert_in_darkmode" align=middle width=110.30712pt height=24.65759999999998pt/>), significa que <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/3d425a215e8eeb2a056f553633aaae4a.svg?invert_in_darkmode" align=middle width=32.469855pt height=24.65759999999998pt/> não cresce mais rapidamente que <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/f010a0fda7cdcc04209d9381ef5fca27.svg?invert_in_darkmode" align=middle width=31.0827pt height=24.65759999999998pt/>, para valores de <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> suficientemente grandes (como se <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/58d9dae7c4c1dd14ba69f8f098766abb.svg?invert_in_darkmode" align=middle width=84.526365pt height=24.65759999999998pt/>).

**Exemplo:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/a876233248b9eb8f9ef34ef5245de4cd.svg?invert_in_darkmode" align=middle width=344.012955pt height=26.76201000000001pt/>

### Notações assintóticas ou de Bachmann-Landau (&Omega;)

Permitem descrever o comportamento assintótico de uma função quando o argumento tende a infinito.

- **Notação &Omega;:** expressa um limite inferior para o comportamento assintótico de uma função, de forma aproximada.

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/f33f061867b5b65aa6a73cc876b57979.svg?invert_in_darkmode" align=middle width=405.9825pt height=16.438356pt/></p>

Informalmente, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/3ed5f1006d103ed7aa4d053507d8e9af.svg?invert_in_darkmode" align=middle width=108.301215pt height=24.65759999999998pt/> (se escreve
<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/23fd4d3560bb2304d695d73d6188e644.svg?invert_in_darkmode" align=middle width=109.183965pt height=24.65759999999998pt/>), significa que <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/3d425a215e8eeb2a056f553633aaae4a.svg?invert_in_darkmode" align=middle width=32.469855pt height=24.65759999999998pt/> cresce mais rapidamente que <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/f010a0fda7cdcc04209d9381ef5fca27.svg?invert_in_darkmode" align=middle width=31.0827pt height=24.65759999999998pt/>, para valores de <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> suficientemente grandes (como se <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/0b5535aabea43ea8af796d2d67c2df52.svg?invert_in_darkmode" align=middle width=84.526365pt height=24.65759999999998pt/>).

**Exemplo:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/e50ab616884e9028374b5ca1a20c68a0.svg?invert_in_darkmode" align=middle width=299.76820499999997pt height=26.76201000000001pt/>

### Notações assintóticas ou de Bachmann-Landau (&Theta;)

Permitem descrever o comportamento assintótico de uma função quando o argumento tende a infinito.

- **Notação &Theta;:** expressa um limite fireme ou restrito para o comportamento
assintótico de uma função, de forma aproximada.

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/23f4c42ae5d2dec2c40b914b423223a0.svg?invert_in_darkmode" align=middle width=555.67545pt height=16.438356pt/></p>

Informalmente, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/fde550ecd8b9c3a9c3ecf991eedbbe4a.svg?invert_in_darkmode" align=middle width=109.21448999999997pt height=24.65759999999998pt/> (se escreve
<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/8a35aa25793467088290d4677a4cd64f.svg?invert_in_darkmode" align=middle width=110.09724000000001pt height=24.65759999999998pt/>), significa que <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/3d425a215e8eeb2a056f553633aaae4a.svg?invert_in_darkmode" align=middle width=32.469855pt height=24.65759999999998pt/> cresce tão rapidamente quanto <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/f010a0fda7cdcc04209d9381ef5fca27.svg?invert_in_darkmode" align=middle width=31.0827pt height=24.65759999999998pt/>
dentro de um fator, para valores de <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> suficientemente grandes.

**Exemplo:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/12b6625ac06a442e8a10907bf88114d3.svg?invert_in_darkmode" align=middle width=335.164005pt height=26.76201000000001pt/>

### Algumas propriedades das notações *O*, &Omega;, &Theta;

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/36792274-e93b255a-1c78-11e8-8a98-1a0e36ed2eeb.png">
</p>

1. Todas reflexivas e transitivas; <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/b35e24d8a08c0ab01195f2ad2a78fab7.svg?invert_in_darkmode" align=middle width=12.785520000000004pt height=22.46574pt/> é simétrica;
2. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/7637253b9d918359ef3cbfb6f46b31d1.svg?invert_in_darkmode" align=middle width=245.06080499999996pt height=24.65759999999998pt/>
3. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/7586be124aa49c975459d072698d8c7f.svg?invert_in_darkmode" align=middle width=245.97490499999995pt height=24.65759999999998pt/> e <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/23fd4d3560bb2304d695d73d6188e644.svg?invert_in_darkmode" align=middle width=109.183965pt height=24.65759999999998pt/>
4. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/3179131260b4e17f1bc07655205b6ea4.svg?invert_in_darkmode" align=middle width=208.59415499999997pt height=24.65759999999998pt/>
5. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/d5f5097ad05e636a6a1884a8f73201f7.svg?invert_in_darkmode" align=middle width=297.17770499999995pt height=24.65759999999998pt/>

### Propriedades das notações *O*, &Omega;, &Theta;

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/36647924-214921dc-1a6b-11e8-879a-65aadb6a66be.png">
</p>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/3df7a9dcbec933bb76259139e556f27c.svg?invert_in_darkmode" align=middle width=538.3158pt height=47.13489pt/></p>

Aqui, pelo caso pior <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/3a1fa25e6805485bf103f59e8db4b1cd.svg?invert_in_darkmode" align=middle width=99.48147pt height=26.76201000000001pt/>. Porém, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/5a5274f11b034e1cbca86b8e9cc21717.svg?invert_in_darkmode" align=middle width=99.27158999999999pt height=26.76201000000001pt/> pois no caso
melhor <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/7c43bfcf52b69eaa46129f6986d46676.svg?invert_in_darkmode" align=middle width=98.35831499999999pt height=26.76201000000001pt/>, e sim <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/8e1fecc54c46b5290f19d15ec793cef3.svg?invert_in_darkmode" align=middle width=90.98380499999999pt height=24.65759999999998pt/>.

## Complexidade de Algoritmos não Recursivos

### Pequeno guia para a análise do caso pior

- Operações sobre tipos básicos: <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/1e2f931ee6c0b8e7a51a7b0d123d514f.svg?invert_in_darkmode" align=middle width=34.000065pt height=24.65759999999998pt/>
- Sequência de instruções: <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/5959778e0fda3fd2719e0d0114dcfe8d.svg?invert_in_darkmode" align=middle width=160.29370500000002pt height=24.65759999999998pt/>
- Condicional **if**: <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/39ebcabf9952b483af40aae2223d4d2a.svg?invert_in_darkmode" align=middle width=234.205455pt height=24.65759999999998pt/>
- Laços: <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/efa718d4b8134937cf482d3b5278f68a.svg?invert_in_darkmode" align=middle width=199.273305pt height=37.80842999999999pt/>

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

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/6644ba6ba70e812e8f4508308cc70d0a.svg?invert_in_darkmode" align=middle width=116.867025pt height=44.897324999999995pt/></p>

```c
for (i = 1; i <= n; i *= 2)
  for (j = 0; j < i; j++)
    count++;
```

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/svgs/55fc71b3c68083208f0382d7114a17fb.svg?invert_in_darkmode" align=middle width=175.98569999999998pt height=44.897324999999995pt/></p>

## Bibliografia

- **Introduction to Algorithms**, 3rd Edition. Thomas H. Cormen, Charles E. 
Leiserson, Ronald L. Rivest and Clifford Stein, 2009, caps 2-4.
- **An Introduction to the Analysis of Algorithms**, 2nd Edition. Robert
Sedgewick and Philippe Flajolet, 2013.
- **Algorithms Design: Foundation, Analysis and Internet Examples**. Michael
T. Goodrich and Roberto Tamassia, 2002.
- **Projeto de Algoritmos**, 2ª edição. Nivio Ziviani, 2007.
- Wikipédia: [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation), 
[Master theorem](https://en.wikipedia.org/wiki/Master_theorem).