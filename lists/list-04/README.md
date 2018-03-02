# Lista de Exercícios 4: Complexidade de algoritmos

## Notações assintóticas

1. Ordene as seguintes funções por ordem de crescimento assintótico de forma não
decrescente. Preencha a tabela com os números correspondentes à ordem de 
crescimento. Use o mesmo número caso duas funções tenham a mesma ordem de 
crescimento, i.e. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/1fbce93542e8f17dc1d3a148dde2a325.svg?invert_in_darkmode" align=middle width=111.04087500000001pt height=24.65759999999998pt/>. Justifique de forma apropriada
sua ordenação.

   | Função | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/dcca91a3a77c6055fef6c77fdf4b44c5.svg?invert_in_darkmode" align=middle width=16.34523pt height=21.839399999999983pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/b0cfd2abfaffc29bb397536441842532.svg?invert_in_darkmode" align=middle width=56.49187500000001pt height=24.65759999999998pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/88ae1e7d87608a5ea339db7350692c67.svg?invert_in_darkmode" align=middle width=16.34523pt height=21.839399999999983pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/387c646a307de8023b04bffb886f24ee.svg?invert_in_darkmode" align=middle width=50.038395pt height=29.19113999999999pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/a9f328d5a2bf4c15e050611fa6a39c28.svg?invert_in_darkmode" align=middle width=29.707260000000005pt height=29.19113999999999pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/a4dae61405b4eb1ccecbcc5700b25f03.svg?invert_in_darkmode" align=middle width=32.87691pt height=21.18732pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/38770a8d9227f63841ed3c92db3d7e51.svg?invert_in_darkmode" align=middle width=53.771025pt height=26.76201000000001pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/2d12bf257d5566a2e9a51e2dbbf0b0cf.svg?invert_in_darkmode" align=middle width=55.528935pt height=24.65759999999998pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/ebcbccbc670c95a08bb5121f73b0b80f.svg?invert_in_darkmode" align=middle width=26.21223pt height=21.839399999999983pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/cc8777dc41169b621abb9344d4935585.svg?invert_in_darkmode" align=middle width=22.332750000000004pt height=26.76201000000001pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/124ea1296f906499daca48407c9fee04.svg?invert_in_darkmode" align=middle width=51.259725pt height=29.534339999999986pt/> |
   | ------ | - | - | - | - | - | - | - | - | - | - | - |
   | Ordem  | | | | | | | | | | | | |


1. Responda se as seguintes afirmações são verdadeiras ou falsas. Justifique de
forma apropriada sua resposta.

   1. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/0b5335df487410f1447ace499a130d4d.svg?invert_in_darkmode" align=middle width=160.331655pt height=26.76201000000001pt/>
   1. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/19563bd6d18a7da7faed2723818a6e91.svg?invert_in_darkmode" align=middle width=88.58536500000001pt height=26.76201000000001pt/>
   1. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/f0959f73043032993e43707287161075.svg?invert_in_darkmode" align=middle width=92.83197pt height=29.64951000000001pt/>
   1. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/4d81425447d9cee969b4d01354a6cab8.svg?invert_in_darkmode" align=middle width=142.633425pt height=26.76201000000001pt/>
   1. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/998ae4f4d9dbba674264dbece9af6102.svg?invert_in_darkmode" align=middle width=104.322735pt height=29.19113999999999pt/>
   1. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/610dd2bc8fa40e7dbef7c09ccd14ef61.svg?invert_in_darkmode" align=middle width=244.948605pt height=24.65759999999998pt/>
   1. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/89dd0bfc1473f1b3ba5338176c92815f.svg?invert_in_darkmode" align=middle width=161.301855pt height=24.65759999999998pt/>
   1. <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/lists/list-04/svgs/6dce598f99862511cf9425f5ce48459d.svg?invert_in_darkmode" align=middle width=128.86648499999998pt height=24.65759999999998pt/>

## Complexidade de algoritmos

1. Qual a complexidade assintótica das seguintes funções?

   ```c
   int a (int n) {
     int i, j, count = 0;
     for (i = n; i >= 1; i /= 2)
       for (j = 1; j <= n * n; j++)
         count++
     return count;
   }

   int b (int n) {
     int i, j, k, count = 0;
     for (i = n / 2; i <= n; i++)
       for (j = 1; j <= n; j *= 2)
         for (k = 1; k <= n; k *= 2)
           count++;
     return count;
   }
   ```

1. Qual a complexidade assintótica no caso pior do programa que você usou para
resolver o Exercício 1 da Lista 1?

1. Preencha a seguinte tabela com a complexidade no caso pior das seguintes
operações sobre **conjuntos** (não há repetições de elementos).

   | Operação                   | Tamanho Entrada | Vetores | Listas enlaçadas |
   | -------------------------- | --------------- | ------- | ---------------- |
   | Pertinencia de um elemento |                 |         |                  |
   | União                      |                 |         |                  |
   | Interseção                 |                 |         |                  |
   | Diferença                  |                 |         |                  |
   | Inserir elemento no final  |                 |         |                  |
   | Eliminar um elemento       |                 |         |                  |
   | Produto cartesiano         |                 |         |                  |
   | Conjunto potência          |                 |         |                  |