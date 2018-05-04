# Discos Voadores (Ordenação)

Nos últimos anos, com a maior necessidade de os seres humanos irem ao
espaço,a demanda por transporte espacial tem crescido. Os alienígenas,
de olho nesse novo mercado, decidiram oferecer uma série de discos
voadores para nós. Entretanto, os discos possuem diversas características
diferentes, o que torna complexa a escolha dos modelos.

Um estudante sugeriu elaborar um sistema que pudesse ordenar os discos
voadores oferecidos de acordo com as características que possuem. Como
os alienígenas sempre lançam novos modelos, o sistema precisa ser
implementado com uma **lista ligada**.


## Exercício

Escreva um programa em linguagem C que receba uma sequência de operações 
(inserção, ordenação e impressão de discos voadores).

Salve o código no arquivo: `discosvoadores.c`. 

O programa deverá utilizar uma **lista ligada**.
**Não utilize array/arranjo!**

**Atenção:** libere a lista da memória ao final do programa.

## Entrada e saída

O sistema receberá diversas entradas e, dependendo da operação, pode haver
parâmetros adicionais:

<table>
  <thead>
    <th>Operação</th>
    <th>Exemplo</th>
    <th>Descrição</th>
  </thead>
  <tbody>
    <tr>
      <td><code>1 [M] [V] [K] [C] [P]</code></td>
      <td><code>1 ABC 10 5.5 2 30</code></td>
      <td>
        <b>Insere</b> um disco voador <b>no final da lista</b>
        <br>
        <b>ligada</b>, com o modelo (M), velocidade em
        <br>
        Km/h (V), eficiência em Km/Litro (K),
        <br>
        capacidade (C) e prazo de entrega em dias
        <br>
        marcianos (P). Os tipos dos campos são
        <br>
        especificados em tabela a seguir.
      </td>
    </tr>
    <tr>
      <td><code>2</code></td>
      <td><code>2</code></td>
      <td>
        <b>Imprime</b> a lista de discos voadores.
      </td>
    </tr>
    <tr>
      <td><code>8 [modo]</code></td>
      <td><code>8 10</code></td>
      <td>
        <b>Ordena (com <i>quicksort</i>)</b> a lista de discos
        <br>
        voadores de acordo com o modo
        <br>
        especificado (os modos de ordenação são
        <br>
        especificados em outra tabela a seguir). No
        <br>
        exemplo, a lista de discos será ordenada por
        <br>
        modelo (ordem crescente). Imprima a lista
        <br>
        após a ordenação.
      </td>
    </tr>
    <tr>
      <td><code>0</code></td>
      <td><code>0</code></td>
      <td>
        <b>Libera</b> a lista ligada da memória e <b>encerra</b> o
        <br>
        programa.
      </td>
    </tr>
  </tbody>
</table>

### Tipos dos campos

<table>
  <thead>
    <th>Campo</th>
    <th>Tipo</th>
    <th>Comentário</th>
  </thead>
  <tbody>
    <tr>
      <td>Modelo (M)</td>
      <td><code>string</code></td>
      <td>
        A <code>string</code> contém apenas letras
        <br>
        maiúsculas e tem no máximo
        <br>
        50 caracteres.
      </td>
    </tr>
    <tr>
      <td>Velocidade em Km/h (V)</td>
      <td><code>int</code></td>
      <td>-</td>
    </tr>
    <tr>
      <td>Eficiência em Km/h (V)</td>
      <td><code>double</code></td>
      <td>
        Use ponto para separar as
        <br>
        casas decimais. Na
        <br>
        impressão da eficiência, use
        <br>
        sempre duas casas decimais.
      </td>
    </tr>
    <tr>
      <td>Capacidade (C)</td>
      <td><code>int</code></td>
      <td>-</td>
    </tr>
    <tr>
      <td>
        Prazo de entrega em dias
        <br>
        marcianos (P)
      </td>
      <td><code>int</code></td>
      <td>-</td>
    </tr>
  </tbody>
</table>

### Modos de ordenação

<table>
  <thead>
    <th>Modo</th>
    <th>Descrição</th>
  </thead>
  <tbody>
    <tr>
      <td>10</td>
      <td>Ordena por modelo (<b>crescente</b>)</td>
    </tr>
    <tr>
      <td>11</td>
      <td>Ordena por modelo (<b>decrescente</b>)</td>
    </tr>
    <tr>
      <td>20</td>
      <td>Ordena por capacidade (<b>crescente</b>)</td>
    </tr>
    <tr>
      <td>21</td>
      <td>Ordena por capacidade (<b>decrescente</b>)</td>
    </tr>
    <tr>
      <td>50</td>
      <td>
        Ordena por velocidade (<b>decrescente</b>),
        em caso de empate na velocidade,
        <br>
        ordena por Km/Litro (<b>decrescente</b>)
      </td>
    </tr>
    <tr>
      <td>51</td>
      <td>
        Ordena por velocidade (<b>decrescente</b>),
        em caso de empate na velocidade,
        <br>
        ordena por Km/Litro (<b>crescente</b>)
      </td>
    </tr>
    <tr>
      <td>60</td>
      <td>Ordena por prazo de entrega (<b>crescente</b>)</td>
    </tr>
    <tr>
      <td>61</td>
      <td>Ordena por prazo de entrega (<b>decrescente</b>)</td>
    </tr>
  </tbody>
</table>

### Observações

- **Não faça cópias dos algoritmos de ordenação!** Ou seja, implemente
apenas uma vez o algoritmo de ordenação *quicksort*, que pode ordenar
por todos os modos especificados no exercício;
- **Após a ordenação, não inverta ordem da lista**. Por exemplo, para
ordenação decrescente, não ordene de forma crescente e depois inverta
a lista;
- Sempre que uma lista é impressa (operação=2), imprima uma linha com
o texto `[DISCOS]`;
- Quando a lista é impressa após uma ordenação, imprima `[O=n]`,
em que `n` é o modo de ordenação;
- **Libere a lista da memória ao final do programa**.

## Exemplo

Para a entrada

    1 ABC 100 90 55 1
    1 DEF 50 9.5 6 60
    1 GHI 10 9.6 3 360
    1 JKL 50 6.7 80 20
    1 MNO 50 5 40 14
    1 PQR 10 7.7 56 90
    2
    8 60
    8 61
    1 STU 10 4.5 50 5
    2
    8 50
    8 10
    8 20
    8 11
    8 21
    1 VWX 20 8.55 38 45
    1 YZ 90 2.50 8 120
    2
    8 51
    0

a saída deve ser:

    [DISCOS]
    [M=ABC V=100 KM-L=90.00 C=55 E=1]
    [M=DEF V=50 KM-L=9.50 C=6 E=60]
    [M=GHI V=10 KM-L=9.60 C=3 E=360]
    [M=JKL V=50 KM-L=6.70 C=80 E=20]
    [M=MNO V=50 KM-L=5.00 C=40 E=14]
    [M=PQR V=10 KM-L=7.70 C=56 E=90]
    [O=60]
    [M=ABC V=100 KM-L=90.00 C=55 E=1]
    [M=MNO V=50 KM-L=5.00 C=40 E=14]
    [M=JKL V=50 KM-L=6.70 C=80 E=20]
    [M=DEF V=50 KM-L=9.50 C=6 E=60]
    [M=PQR V=10 KM-L=7.70 C=56 E=90]
    [M=GHI V=10 KM-L=9.60 C=3 E=360]
    [O=61]
    [M=GHI V=10 KM-L=9.60 C=3 E=360]
    [M=PQR V=10 KM-L=7.70 C=56 E=90]
    [M=DEF V=50 KM-L=9.50 C=6 E=60]
    [M=JKL V=50 KM-L=6.70 C=80 E=20]
    [M=MNO V=50 KM-L=5.00 C=40 E=14]
    [M=ABC V=100 KM-L=90.00 C=55 E=1]
    [DISCOS]
    [M=GHI V=10 KM-L=9.60 C=3 E=360]
    [M=PQR V=10 KM-L=7.70 C=56 E=90]
    [M=DEF V=50 KM-L=9.50 C=6 E=60]
    [M=JKL V=50 KM-L=6.70 C=80 E=20]
    [M=MNO V=50 KM-L=5.00 C=40 E=14]
    [M=ABC V=100 KM-L=90.00 C=55 E=1]
    [M=STU V=10 KM-L=4.50 C=50 E=5]
    [O=50]
    [M=ABC V=100 KM-L=90.00 C=55 E=1]
    [M=DEF V=50 KM-L=9.50 C=6 E=60]
    [M=JKL V=50 KM-L=6.70 C=80 E=20]
    [M=MNO V=50 KM-L=5.00 C=40 E=14]
    [M=GHI V=10 KM-L=9.60 C=3 E=360]
    [M=PQR V=10 KM-L=7.70 C=56 E=90]
    [M=STU V=10 KM-L=4.50 C=50 E=5]
    [O=10]
    [M=ABC V=100 KM-L=90.00 C=55 E=1]
    [M=DEF V=50 KM-L=9.50 C=6 E=60]
    [M=GHI V=10 KM-L=9.60 C=3 E=360]
    [M=JKL V=50 KM-L=6.70 C=80 E=20]
    [M=MNO V=50 KM-L=5.00 C=40 E=14]
    [M=PQR V=10 KM-L=7.70 C=56 E=90]
    [M=STU V=10 KM-L=4.50 C=50 E=5]
    [O=20]
    [M=GHI V=10 KM-L=9.60 C=3 E=360]
    [M=DEF V=50 KM-L=9.50 C=6 E=60]
    [M=MNO V=50 KM-L=5.00 C=40 E=14]
    [M=STU V=10 KM-L=4.50 C=50 E=5]
    [M=ABC V=100 KM-L=90.00 C=55 E=1]
    [M=PQR V=10 KM-L=7.70 C=56 E=90]
    [M=JKL V=50 KM-L=6.70 C=80 E=20]
    [O=11]
    [M=STU V=10 KM-L=4.50 C=50 E=5]
    [M=PQR V=10 KM-L=7.70 C=56 E=90]
    [M=MNO V=50 KM-L=5.00 C=40 E=14]
    [M=JKL V=50 KM-L=6.70 C=80 E=20]
    [M=GHI V=10 KM-L=9.60 C=3 E=360]
    [M=DEF V=50 KM-L=9.50 C=6 E=60]
    [M=ABC V=100 KM-L=90.00 C=55 E=1]
    [O=21]
    [M=JKL V=50 KM-L=6.70 C=80 E=20]
    [M=PQR V=10 KM-L=7.70 C=56 E=90]
    [M=ABC V=100 KM-L=90.00 C=55 E=1]
    [M=STU V=10 KM-L=4.50 C=50 E=5]
    [M=MNO V=50 KM-L=5.00 C=40 E=14]
    [M=DEF V=50 KM-L=9.50 C=6 E=60]
    [M=GHI V=10 KM-L=9.60 C=3 E=360]
    [DISCOS]
    [M=JKL V=50 KM-L=6.70 C=80 E=20]
    [M=PQR V=10 KM-L=7.70 C=56 E=90]
    [M=ABC V=100 KM-L=90.00 C=55 E=1]
    [M=STU V=10 KM-L=4.50 C=50 E=5]
    [M=MNO V=50 KM-L=5.00 C=40 E=14]
    [M=DEF V=50 KM-L=9.50 C=6 E=60]
    [M=GHI V=10 KM-L=9.60 C=3 E=360]
    [M=VWX V=20 KM-L=8.55 C=38 E=45]
    [M=YZ V=90 KM-L=2.50 C=8 E=120]
    [O=51]
    [M=ABC V=100 KM-L=90.00 C=55 E=1]
    [M=YZ V=90 KM-L=2.50 C=8 E=120]
    [M=MNO V=50 KM-L=5.00 C=40 E=14]
    [M=JKL V=50 KM-L=6.70 C=80 E=20]
    [M=DEF V=50 KM-L=9.50 C=6 E=60]
    [M=VWX V=20 KM-L=8.55 C=38 E=45]
    [M=STU V=10 KM-L=4.50 C=50 E=5]
    [M=PQR V=10 KM-L=7.70 C=56 E=90]
    [M=GHI V=10 KM-L=9.60 C=3 E=360]

