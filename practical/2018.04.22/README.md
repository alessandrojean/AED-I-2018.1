# RAs e Notas (Ordenação)

O professor ABC guarda os RAs (número de registro do aluno) e nota de cada
aluno em um sistema. Esse sistema usa uma **lista ligada**. O sistema possui 
funções para incluir e ordenar dados.

## Exercício

Escreva um programa em linguagem C que receba uma sequência de operações 
(inserção, ordenação crescente por RA, ordenação decrescente por RA
e imprimir lista).

Salve o código no arquivo: `mergesorligado.c`. 

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
      <td><code>1 [RA] [Nota]</code></td>
      <td><code>1 200 10</code></td>
      <td>
        <b>Insere</b> um item <b>no final da lista ligada</b>, com o
        <br>
        RA e a Nota informados. RA e Nota são
        <br>
        números inteiros (<code>int</code>).
      </td>
    </tr>
    <tr>
      <td><code>2</code></td>
      <td><code>2</code></td>
      <td>
        <b>Imprime</b> a lista.
      </td>
    </tr>
    <tr>
      <td><code>6</code></td>
      <td><code>6</code></td>
      <td>
        <b>Ordena (com mergesort)</b> a lista em ordem
        <br>
        crescente de RA.
      </td>
    </tr>
    <tr>
      <td><code>9</code></td>
      <td><code>9</code></td>
      <td>
        <b>Ordena (com mergesort)</b> a lista em ordem
        <br>
        decrescente de RA.
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

### Observações

- **Não faça cópias dos algoritmos de ordenação!** Ou seja, implemente
apenas uma função para ordenação por intercalação (*mergesort*), que pode
ordenar tanto em ordem crescente como decrescente;
- Sempre que uma lista é impressa, imprima uma linha com o texto `[LISTA]`;
- **Libere a lista da memória ao final do programa**.

## Exemplos

### Exemplo 1

Para a entrada

    1 5 8
    1 50 6
    1 20 8
    1 30 10
    1 10 10
    2
    6
    9
    1 100 4
    1 25 10
    2
    6
    0

a saída deve ser:

    [LISTA]
    [5 8]
    [50 6]
    [20 8]
    [30 10]
    [10 10]
    [LISTA]
    [5 8]
    [10 10]
    [20 8]
    [30 10]
    [50 6]
    [LISTA]
    [50 6]
    [30 10]
    [20 8]
    [10 10]
    [5 8]
    [LISTA]
    [50 6]
    [30 10]
    [20 8]
    [10 10]
    [5 8]
    [100 4]
    [25 10]
    [LISTA]
    [5 8]
    [10 10]
    [20 8]
    [25 10]
    [30 10]
    [50 6]
    [100 4]


### Exemplo 2

Para a entrada

    1 700 0
    2
    6
    9
    1 500 10
    1 800 5
    9
    1 850 8
    2
    6
    0

a saída deve ser:

    [LISTA]
    [700 0]
    [LISTA]
    [700 0]
    [LISTA]
    [700 0]
    [LISTA]
    [800 5]
    [700 0]
    [500 10]
    [LISTA]
    [800 5]
    [700 0]
    [500 10]
    [850 8]
    [LISTA]
    [500 10]
    [700 0]
    [800 5]
    [850 8]
