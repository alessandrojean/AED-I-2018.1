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

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/cdb888f0383e1618870d7abf1b88ed5d.svg?invert_in_darkmode" align=middle width=262.70475pt height=16.438356pt/></p>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/579f7dac24d61c0ccc33c6b8c317867b.svg?invert_in_darkmode" align=middle width=375.05819999999994pt height=16.438356pt/></p>

- Número de chamadas recursivas:

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/9a3793ccf6c9a0fb2806f0c60ccd212a.svg?invert_in_darkmode" align=middle width=226.54335pt height=16.438356pt/></p>

- Tempo de execução:

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/31952505575e08138392506c9fb5a0ad.svg?invert_in_darkmode" align=middle width=235.1547pt height=16.438356pt/></p>

### Relações de recorrência e seus tipos

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/cdb888f0383e1618870d7abf1b88ed5d.svg?invert_in_darkmode" align=middle width=262.70475pt height=16.438356pt/></p>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/579f7dac24d61c0ccc33c6b8c317867b.svg?invert_in_darkmode" align=middle width=375.05819999999994pt height=16.438356pt/></p>

- **Linear:** se não há produtos ou potências de termos recursivos, ex. 
<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/5975ac523ab622dcec72894c64d61768.svg?invert_in_darkmode" align=middle width=174.906105pt height=24.99551999999999pt/>;
- **Não linear:** ex. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/2f96203c559492ac370144c82e77bd44.svg?invert_in_darkmode" align=middle width=281.11990499999996pt height=24.65759999999998pt/>;
- **Homogênea:** se não há um termo não recursivo;
- De **segundo/terceiro/quarto grau** (em geral de ordem ou grau fixo),
dependendo do menor termo recursivo, ex. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/a274baafc0cb07ccd912c1b655075cb1.svg?invert_in_darkmode" align=middle width=257.186655pt height=24.65759999999998pt/>
é de ordem 4;
- **Com coeficientes constantes ou não**;
- **Divisão e conquista:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/fed82c11d89ba4f1a6ab0a1ad23b71c3.svg?invert_in_darkmode" align=middle width=226.458705pt height=37.80842999999999pt/>.

### Exemplos de recorrências simples

- Linear, homogênea, de ordem 1 e coeficiente constante.

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/07983433331c3279b5b8abd457c3440a.svg?invert_in_darkmode" align=middle width=216.53775000000002pt height=16.438356pt/></p>

- Linear, homogênea, de ordem 1 e coeficiente variável.

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/2b5d48e2e9eb01ea7de2c909b4b997e9.svg?invert_in_darkmode" align=middle width=221.07854999999998pt height=16.438356pt/></p>

- Linear, não homogênea, de ordem 1.

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/9a3793ccf6c9a0fb2806f0c60ccd212a.svg?invert_in_darkmode" align=middle width=226.54335pt height=16.438356pt/></p>

- Linear, homogênea, de ordem 2.

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/c5c4d35946373fa7e23d1c6ee0260c99.svg?invert_in_darkmode" align=middle width=358.71pt height=16.438356pt/></p>

### Como obter a solução de uma recorrência, i.e. uma função não recursiva equivalente?

```c
double powerR (float base, int n) {
  if (n == 0)
    return 1;
  else
    return base * powerR(base, n-1);
}
```

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/586635c78657c7efe2d0117bc0b89dea.svg?invert_in_darkmode" align=middle width=288.76484999999997pt height=16.438356pt/></p>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/20380491379478d1614c84569583d1db.svg?invert_in_darkmode" align=middle width=496.419pt height=41.09589pt/></p>

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

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/f66a4ca9627d79e615fe492bfdc5eca0.svg?invert_in_darkmode" align=middle width=165.78539999999998pt height=30.180149999999998pt/></p>

- <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/cc33f2d43f77dd8957bcdb6a0afc605a.svg?invert_in_darkmode" align=middle width=38.825985pt height=21.18732pt/> é o número de sub-problemas de tamanho <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/b0d608abbdaaf83496cdc80639d16f9c.svg?invert_in_darkmode" align=middle width=8.126084999999998pt height=22.853489999999976pt/>.
- <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/bb7940a01548a7a4db973e55d2e5b1b5.svg?invert_in_darkmode" align=middle width=37.19166pt height=22.831379999999992pt/> e <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/3d425a215e8eeb2a056f553633aaae4a.svg?invert_in_darkmode" align=middle width=32.469855pt height=24.65759999999998pt/> é o custo de dividir e combinar as sub-soluções.

### Árvore de recursividade (Recursion Tree)

Usada para visualizar recorrências de divisão e conquista.

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/f66a4ca9627d79e615fe492bfdc5eca0.svg?invert_in_darkmode" align=middle width=165.78539999999998pt height=30.180149999999998pt/></p>

- <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/cc33f2d43f77dd8957bcdb6a0afc605a.svg?invert_in_darkmode" align=middle width=38.825985pt height=21.18732pt/> é o número de sub-problemas de tamanho <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/b0d608abbdaaf83496cdc80639d16f9c.svg?invert_in_darkmode" align=middle width=8.126084999999998pt height=22.853489999999976pt/>.
- <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/bb7940a01548a7a4db973e55d2e5b1b5.svg?invert_in_darkmode" align=middle width=37.19166pt height=22.831379999999992pt/> e <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/3d425a215e8eeb2a056f553633aaae4a.svg?invert_in_darkmode" align=middle width=32.469855pt height=24.65759999999998pt/> é o custo de dividir e combinar as sub-soluções.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37098165-f9ba7dd0-21fb-11e8-9ba1-eebdf37164e1.png">
</p>

### Árvore de recursividade - <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/59003bff7924bf5ba0dd158e2684e30e.svg?invert_in_darkmode" align=middle width=159.47860500000002pt height=27.94572000000001pt/>

- Consiste em desenhar a árvore das chamadas recursivas.
- Cada nó é rotulado com o custo de resolver o sub-problema individual. A soma
por níveis é calculada e depois a soma total.

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37098325-62790f1c-21fc-11e8-8270-1e6efa3e427e.png">
</p>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/70ac6f41aba1025a57b2c710a46cf860.svg?invert_in_darkmode" align=middle width=200.08724999999998pt height=50.54808pt/></p>

## Teorema Mestre - <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/59003bff7924bf5ba0dd158e2684e30e.svg?invert_in_darkmode" align=middle width=159.47860500000002pt height=27.94572000000001pt/>

### Teorema Mestre

- É uma receita para recorrências de divisão e conquista onde o problema é
dividido em sub-problemas do mesmo tamanho.
- Permite obter uma aproximação assintótica, não a solução exata.

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/1b0ef644784145074502b409cdfa2b82.svg?invert_in_darkmode" align=middle width=256.72844999999995pt height=50.54808pt/></p>

**Ideia:** Comparar <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/03a246f2e648cf3249ba8f671e965064.svg?invert_in_darkmode" align=middle width=50.30223pt height=29.19113999999999pt/> e <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/3d425a215e8eeb2a056f553633aaae4a.svg?invert_in_darkmode" align=middle width=32.469855pt height=24.65759999999998pt/> para determinar
- Se <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/3d425a215e8eeb2a056f553633aaae4a.svg?invert_in_darkmode" align=middle width=32.469855pt height=24.65759999999998pt/> é assintoticamente menor ou maior que <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/03a246f2e648cf3249ba8f671e965064.svg?invert_in_darkmode" align=middle width=50.30223pt height=29.19113999999999pt/> por um
fator polinomial <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/2e1a4eee0cc71a236217ae3828919d32.svg?invert_in_darkmode" align=middle width=65.762235pt height=21.839399999999983pt/>.
- Se <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/3d425a215e8eeb2a056f553633aaae4a.svg?invert_in_darkmode" align=middle width=32.469855pt height=24.65759999999998pt/> é assintóticamente igual a <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/03a246f2e648cf3249ba8f671e965064.svg?invert_in_darkmode" align=middle width=50.30223pt height=29.19113999999999pt/>.

Pode ser limitado assintoticamente usando 3 casos:
1. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/5abcaf24f5bfc11afb31c163d5e81f94.svg?invert_in_darkmode" align=middle width=290.01670499999994pt height=29.19113999999999pt/>
1. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/ca26f8fd3fe2d119262b050724417ce2.svg?invert_in_darkmode" align=middle width=336.43285499999996pt height=29.19113999999999pt/>
1. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/73cb0fc4e6dbffe303972edaf1df18da.svg?invert_in_darkmode" align=middle width=145.73938499999997pt height=29.19113999999999pt/> e existe <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/3cf02e03a84b8072989808b36ad361de.svg?invert_in_darkmode" align=middle width=37.250730000000004pt height=21.18732pt/> tal que para
todo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> suficientemente grande <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/51170af96089fdc62d2ba2fa64012cc6.svg?invert_in_darkmode" align=middle width=249.95800499999999pt height=27.94572000000001pt/>

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37098325-62790f1c-21fc-11e8-8270-1e6efa3e427e.png">
</p>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/70ac6f41aba1025a57b2c710a46cf860.svg?invert_in_darkmode" align=middle width=200.08724999999998pt height=50.54808pt/></p>

### Caso 1 do Teorema Mestre

1. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/5abcaf24f5bfc11afb31c163d5e81f94.svg?invert_in_darkmode" align=middle width=290.01670499999994pt height=29.19113999999999pt/>

O custo é dominado pelo trabalho feito nas folhas.

### Caso 2 do Teorema Mestre

2. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/ca26f8fd3fe2d119262b050724417ce2.svg?invert_in_darkmode" align=middle width=336.43285499999996pt height=29.19113999999999pt/>

O trabalho está distribuído em todos os níveis.

### Caso 3 do Teorema Mestre

3. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/73cb0fc4e6dbffe303972edaf1df18da.svg?invert_in_darkmode" align=middle width=145.73938499999997pt height=29.19113999999999pt/> e existe <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/3cf02e03a84b8072989808b36ad361de.svg?invert_in_darkmode" align=middle width=37.250730000000004pt height=21.18732pt/> tal que para
todo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> suficientemente grande <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/51170af96089fdc62d2ba2fa64012cc6.svg?invert_in_darkmode" align=middle width=249.95800499999999pt height=27.94572000000001pt/>

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

1. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/5abcaf24f5bfc11afb31c163d5e81f94.svg?invert_in_darkmode" align=middle width=290.01670499999994pt height=29.19113999999999pt/>

**Exemplo:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/77a8fc0d94abe97bcb059be0eb2f2f0b.svg?invert_in_darkmode" align=middle width=226.10395499999998pt height=27.94572000000001pt/>

<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/47e1df81161202a38c876348f6a9c4b9.svg?invert_in_darkmode" align=middle width=248.015955pt height=29.19113999999999pt/> para <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/7d064005e144808707a773a44d3d0529.svg?invert_in_darkmode" align=middle width=36.809355000000004pt height=21.18732pt/>.
Logo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/597dc347bb9d0ed7828cf9ec324061ae.svg?invert_in_darkmode" align=middle width=99.27158999999999pt height=26.76201000000001pt/>

**Exemplo:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/aefcd0349cc1b53acdc102da5180fa89.svg?invert_in_darkmode" align=middle width=251.69215499999996pt height=27.94572000000001pt/>

<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/7e89e612aa3356b41a642632c7ff8399.svg?invert_in_darkmode" align=middle width=254.340405pt height=29.19113999999999pt/> para <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/feef4414bf0517a29510bbeb5a6af76d.svg?invert_in_darkmode" align=middle width=37.115265pt height=27.775769999999994pt/>. Logo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/ed8fdef951657df1b0c428867c403a89.svg?invert_in_darkmode" align=middle width=91.89707999999999pt height=24.65759999999998pt/>.

### Exemplos Caso 2 do Teorema Mestre

2. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/ca26f8fd3fe2d119262b050724417ce2.svg?invert_in_darkmode" align=middle width=336.43285499999996pt height=29.19113999999999pt/>

**Exemplo:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/fd8a97cce3a04b102bd1c25a4156fd36.svg?invert_in_darkmode" align=middle width=233.479455pt height=27.94572000000001pt/>

<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/1d39738d7ea201f96cb4e816ff0b37b8.svg?invert_in_darkmode" align=middle width=239.42770499999997pt height=29.19113999999999pt/>. Logo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/57adee37f4d84c26501682a6453cc8a2.svg?invert_in_darkmode" align=middle width=155.02872000000002pt height=26.76201000000001pt/>

**Exemplo:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/63efa884300caf9bb67f2e368c738298.svg?invert_in_darkmode" align=middle width=233.479455pt height=27.94572000000001pt/>

<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/904a4262cc8b53461778affc9df058c1.svg?invert_in_darkmode" align=middle width=233.74180499999997pt height=29.19113999999999pt/>. Logo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/5f34ffad49a12f2b87fba2533068909a.svg?invert_in_darkmode" align=middle width=138.521955pt height=24.65759999999998pt/>.

### Exemplos Caso 3 do Teorema Mestre

3. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/73cb0fc4e6dbffe303972edaf1df18da.svg?invert_in_darkmode" align=middle width=145.73938499999997pt height=29.19113999999999pt/> e existe <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/3cf02e03a84b8072989808b36ad361de.svg?invert_in_darkmode" align=middle width=37.250730000000004pt height=21.18732pt/> tal que para
todo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> suficientemente grande <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/51170af96089fdc62d2ba2fa64012cc6.svg?invert_in_darkmode" align=middle width=249.95800499999999pt height=27.94572000000001pt/>

**Exemplo:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/e9403951c3b9158d744b169770fd7300.svg?invert_in_darkmode" align=middle width=233.479455pt height=27.94572000000001pt/>

<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/13fc0c7df6f8c92d25c00fa7bc6364f1.svg?invert_in_darkmode" align=middle width=254.084655pt height=29.19113999999999pt/> para <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/7d064005e144808707a773a44d3d0529.svg?invert_in_darkmode" align=middle width=36.809355000000004pt height=21.18732pt/>.
Além disso, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/54225d9823f621fe82a45f9a0b80bb2c.svg?invert_in_darkmode" align=middle width=90.92407499999999pt height=34.64868pt/> para <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/a6c5955c0270a44bf1b8fc880f9e99fd.svg?invert_in_darkmode" align=middle width=37.55664pt height=27.775769999999994pt/>. Logo
<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/ff88a4fdd4fd9d2547a97a6099313844.svg?invert_in_darkmode" align=middle width=99.27158999999999pt height=26.76201000000001pt/>.

**Exemplo:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/c4e188f88b546eebb1f968e09fd2b33d.svg?invert_in_darkmode" align=middle width=288.322155pt height=27.94572000000001pt/>

<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/4f183f1cd4ad723a25d3d9bc1f960a8b.svg?invert_in_darkmode" align=middle width=347.642955pt height=29.19113999999999pt/> para
<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/682ac5553bf5a250648921ee35002314.svg?invert_in_darkmode" align=middle width=66.033165pt height=21.18732pt/>, i.e. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/6aac845940a194dc57bd4d600260101e.svg?invert_in_darkmode" align=middle width=120.30842999999999pt height=24.65759999999998pt/>. Além disso, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/34c84dc75a34adf55c35929503926941.svg?invert_in_darkmode" align=middle width=192.222855pt height=27.94572000000001pt/>, ex. para <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/f49f4ef692681e9171f486c43b602a30.svg?invert_in_darkmode" align=middle width=37.55664pt height=27.775769999999994pt/>.
Logo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/5f34ffad49a12f2b87fba2533068909a.svg?invert_in_darkmode" align=middle width=138.521955pt height=24.65759999999998pt/>.

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

- O comportamento assintotico de <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/cc4152a1ba8a0ec113e9f2062a489b7d.svg?invert_in_darkmode" align=middle width=34.541760000000004pt height=24.65759999999998pt/> não muda se <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/8b0e862411b93d9281b31d08f4fb1194.svg?invert_in_darkmode" align=middle width=41.76876pt height=27.94572000000001pt/>
é substituido por <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/6c79fd18d14d2691d69e0d3c674db56e.svg?invert_in_darkmode" align=middle width=57.293940000000006pt height=27.94572000000001pt/> ou
<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/8e9070dfc75cdd785ba51c06adee10c4.svg?invert_in_darkmode" align=middle width=57.293940000000006pt height=27.94572000000001pt/>
- Nem sempre pode ser aplicado
  - <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/d1daa928f8f5a679d7d8c97f15ecf2f8.svg?invert_in_darkmode" align=middle width=152.750565pt height=27.94572000000001pt/>
  - <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/60c4ec0dca3c26433d601a1bce7c3ca0.svg?invert_in_darkmode" align=middle width=138.68382pt height=27.94572000000001pt/>
  - <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/e0751f1c058bf973bbee8b858b370f2c.svg?invert_in_darkmode" align=middle width=183.030705pt height=27.94572000000001pt/>
  - <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/84283ea76b9792caa048109bb2cde35e.svg?invert_in_darkmode" align=middle width=196.59865499999998pt height=27.94572000000001pt/>
- Tem variantes mais gerais.
  
  **Forma geral do caso 2:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/5e18fc290acaf1f2df0fe23b5c7dd355.svg?invert_in_darkmode" align=middle width=195.84130499999998pt height=29.19113999999999pt/> para certo
  <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/9844df5631898f9abd3b4eb9a5a0bd23.svg?invert_in_darkmode" align=middle width=279.33955499999996pt height=29.19113999999999pt/>.

  **Exemplo:** <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/dd457a0c88491df93ae3c86e2e4abbc3.svg?invert_in_darkmode" align=middle width=183.030705pt height=27.94572000000001pt/>, caso 3 não se
  aplica porque <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/409e56362ae6eccb1f477429b55a2962.svg?invert_in_darkmode" align=middle width=56.49187500000001pt height=24.65759999999998pt/> não é polinomialmente maior do que <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>.

#### Forma geral do Teorema Mestre (Akra-Bazzi, 1998)

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/7b803e369b12c1c035e8b2c83c105731.svg?invert_in_darkmode" align=middle width=311.19329999999997pt height=47.93398499999999pt/></p>

- Sufficient base cases are provided;
- <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/dc2670f4f37f05a6b7e0d9eef1cd6781.svg?invert_in_darkmode" align=middle width=44.29887pt height=21.18732pt/> and <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/90c2fc6a688a5499ffbc9bc6763576f9.svg?invert_in_darkmode" align=middle width=72.8013pt height=22.831379999999992pt/> are constants for all <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/77a3b857d53fb44e33b53e4c8b68351a.svg?invert_in_darkmode" align=middle width=5.663295000000005pt height=21.683310000000006pt/>;
- <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/aa6a9c63ebf6922316d824ef7fe20026.svg?invert_in_darkmode" align=middle width=101.70682499999998pt height=24.65759999999998pt/>, where <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/3e18a4a28fdee1744e5e3f79d13b9ff6.svg?invert_in_darkmode" align=middle width=7.113876000000004pt height=14.155350000000013pt/> is a constant;
- <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/fd859318f00cc333eaf1798b41b5a76d.svg?invert_in_darkmode" align=middle width=173.80225499999997pt height=47.67147000000001pt/> for all <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/77a3b857d53fb44e33b53e4c8b68351a.svg?invert_in_darkmode" align=middle width=5.663295000000005pt height=21.683310000000006pt/>.

https://en.wikipedia.org/wiki/Akra-Bazzi_method

#### Variantes Simples do Teorema Mestre

- <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/989e862b4495137dd388106b066d507c.svg?invert_in_darkmode" align=middle width=295.196055pt height=27.94572000000001pt/>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/bb887b682d44574d1f1f539054556b50.svg?invert_in_darkmode" align=middle width=279.02160000000003pt height=69.041775pt/></p>

- <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/4b07dbf5be4b63373b8a8559b0a96476.svg?invert_in_darkmode" align=middle width=315.114855pt height=24.65759999999998pt/>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/35db9b74ada86b8be1cf02f8533bbc21.svg?invert_in_darkmode" align=middle width=203.07375pt height=49.31553pt/></p>

#### Variantes do Teorema Mestre - <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/ac72f72c7136b6d770d747d44d104b45.svg?invert_in_darkmode" align=middle width=162.668055pt height=24.65759999999998pt/>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/35db9b74ada86b8be1cf02f8533bbc21.svg?invert_in_darkmode" align=middle width=203.07375pt height=49.31553pt/></p>

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

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/e8fc118dca039fc63ce9f85fd747d548.svg?invert_in_darkmode" align=middle width=220.70729999999998pt height=16.438356pt/></p>

### Método da substituição

1. Substituir iterativamente até achar uma soma geral e resolver

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/58b57ef967df9aa62192faeed953376f.svg?invert_in_darkmode" align=middle width=398.80665pt height=189.49425pt/></p>

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

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/be0d186fc21789fb85360bbe7a27eec0.svg?invert_in_darkmode" align=middle width=409.65375pt height=30.180149999999998pt/></p>

**Caso Base:**

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/13fb744fbf350733a12bc70e1af19740.svg?invert_in_darkmode" align=middle width=343.01849999999996pt height=16.438356pt/></p>

**Hipótese da Indução:**

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/0bad0644841621c6f5f8f63d89fab1c8.svg?invert_in_darkmode" align=middle width=320.81115pt height=16.438356pt/></p>

**Passo de Indução:**

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/332aa6c80725293613b31c16e3e251ab.svg?invert_in_darkmode" align=middle width=388.1031pt height=103.98828pt/></p>

Como "adivinhar" a solução?

- Resolver para valores pequenos e chutar um termo geral;
- Adaptar a solução de um caso similar;
- Para recorrências de divisão e conquista, usar a árvore de recursividade.

### Outros exemplos de Árvore de Recursividade

#### Exemplo de Árvore de Recursividade

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/97de8f2d5a18c2fd7c58b1b5c70aa9a2.svg?invert_in_darkmode" align=middle width=225.08145000000002pt height=30.180149999999998pt/></p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37104246-fd5664ae-220a-11e8-90b6-0279a90fdfc9.png">
</p>

- Soma: <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/5abce081b7319a93cfb4228c5c79031b.svg?invert_in_darkmode" align=middle width=308.49175499999996pt height=34.70313pt/>
- Chutar que <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/b709622bab0ac130fa70878a67aad839.svg?invert_in_darkmode" align=middle width=79.99249499999999pt height=26.76201000000001pt/> e provar por indução!

#### Árvore de Recursividade - <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/fed82c11d89ba4f1a6ab0a1ad23b71c3.svg?invert_in_darkmode" align=middle width=226.458705pt height=37.80842999999999pt/>

- <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/dc2670f4f37f05a6b7e0d9eef1cd6781.svg?invert_in_darkmode" align=middle width=44.29887pt height=21.18732pt/> é o número de sub-problemas de tamanho <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/d1a8bd1dc0fdc88f3a91bcf5f35c1218.svg?invert_in_darkmode" align=middle width=10.988339999999999pt height=22.853489999999976pt/>.

**Exemplo:** Resolvendo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/84283ea76b9792caa048109bb2cde35e.svg?invert_in_darkmode" align=middle width=196.59865499999998pt height=27.94572000000001pt/>

<p align="center">
  <img src="https://user-images.githubusercontent.com/14254807/37104509-aa3d5ab0-220b-11e8-86db-be0ba6ae3c40.png">
</p>

- Chutar <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/ea70ca223e40dfeefd3000fa242cf7d2.svg?invert_in_darkmode" align=middle width=148.44357pt height=24.65759999999998pt/> e provar por indução!

### Outras Técnicas: Mudança de Variáveis

#### Resolvendo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/ad4988f21faffbb271bbedf9031c86e8.svg?invert_in_darkmode" align=middle width=184.26985499999998pt height=24.99551999999999pt/>

- Mudando a variável:

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/43b45ebebc9dd54509698f788d2c8a24.svg?invert_in_darkmode" align=middle width=338.99249999999995pt height=18.85323pt/></p>

- Mudando a função:

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/790894dbe04b92482266eb15c3f20354.svg?invert_in_darkmode" align=middle width=285.80145pt height=30.180149999999998pt/></p>

- Aplicando o Teorema Mestre, caso 2:

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/eab20637680b9f6cb1c38ba0924590fb.svg?invert_in_darkmode" align=middle width=160.70092499999998pt height=16.438356pt/></p>

Logo:

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/65d3e168582f3e47b21ee7e99b1bff50.svg?invert_in_darkmode" align=middle width=465.8181pt height=16.438356pt/></p>

#### Resolvendo Fibonacci

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/162b04d50473871249947000df8b13c4.svg?invert_in_darkmode" align=middle width=299.33309999999994pt height=14.429217pt/></p>

- Postulate that <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/94cf96c7a4066dae843f7047c04c23d1.svg?invert_in_darkmode" align=middle width=57.07581pt height=21.839399999999983pt/>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/a42327ea92f955d0f1510db89124dd7b.svg?invert_in_darkmode" align=middle width=129.86885999999998pt height=15.572667pt/></p>

- Divide by <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/bccb73c653d2496156a176ce39fa529e.svg?invert_in_darkmode" align=middle width=34.34772pt height=26.76201000000001pt/>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/8aaf0c191af9f51077064c8def812ad4.svg?invert_in_darkmode" align=middle width=104.702895pt height=15.572667pt/></p>

- Factor <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/5ce8a3665ecdba972d5b12406f0d74d7.svg?invert_in_darkmode" align=middle width=171.908055pt height=37.80842999999999pt/>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/42cf236827c76adda8fcb762545c86b8.svg?invert_in_darkmode" align=middle width=134.26908pt height=19.86303pt/></p>

- Form of solution must be

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/8fe16a63ea04ea30b30d4acbd2232a40.svg?invert_in_darkmode" align=middle width=125.28549pt height=18.949755pt/></p>

- Use initial conditions to solve for coefficients

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/07334253a954c02110776d8e786a0caf.svg?invert_in_darkmode" align=middle width=116.36394pt height=13.059337499999998pt/></p>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/21e86aef07ccb13a1486ff076937b282.svg?invert_in_darkmode" align=middle width=135.952905pt height=18.949755pt/></p>

- Solution

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.07/svgs/5a7f780ff3150b21947a6cafda912ad8.svg?invert_in_darkmode" align=middle width=109.399455pt height=42.161624999999994pt/></p>