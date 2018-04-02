# RAs e Notas

O professor ABC guarda os RAs (número de registro do aluno) e nota de cada aluno em
um sistema. Esse sistema usa uma árvore binária de busca. O sistema possui funções
para incluir e remover dados. Para avaliar o desempenho do sistema, o professor ABC
resolveu adicionar alguns indicadores: altura da árvore e quantidade de comparações
realizadas na busca.

## Exercício

Escreva um programa em linguagem C que receba uma sequência de operações (inserção,
remoção, busca e obter altura). Quando for feita uma **operação de busca**, o
programa deve imprimir a quantidade de comparações realizadas na **árvore binária
de busca**. Salve o código no arquivo: `arvorenotas.c`. O programa deverá utilizar
uma **árvore binária de busca**.

**Atenção:** libere a árvore da memória ao final do programa.

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
      <td><code>I [RA] [Nota</code></td>
      <td><code>I 90 8</code></td>
      <td>
        <b>Insere</b> um item na árvore, com o RA e a nota informados. RA e nota
        <br>
        são números inteiros (<code>int</code>). <i>Caso o RA informado já exista na
        <br>
        árvore, apenas a nota é atualizada (e não é inserido um novo nó).
        <br>
        Portanto, não haverá nós com RAs repetidos na árvore.</i>
      </td>
    </tr>
    <tr>
      <td><code>R [RA]</code></td>
      <td><code>R 90</code></td>
      <td>
        <b>Remove</b> o nó com o RA informado. Para a remoção, use a remoção
        <br>
        por cópia de T. Hibbard e D. Knuth. Considere a versão que usa o
        <br>
        <b>sucessor</b> quando um elemento que possui duas subárvores não
        <br>
        nulas é removido.
      </td>
    </tr>
    <tr>
      <td><code>B [RA]</code></td>
      <td><code>B 90</code></td>
      <td>
        <b>Busca</b> o nó com o RA informado. Após realizar a busca, mostre a
        <br>
        <b>quantidade de comparações realizadas</b> até o fim da busca e a <b>nota</b>
        <br>
        <b>do aluno</b> no seguinte formato: <code>C=[NumComparações] Nota=[Nota]</code>.
        <br>
        Por exemplo, <code>C=2 Nota=9</code>. Quando o RA não for encontrado,
        <br>
        assuma nota = -1. Por exemplo, <code>C=2 Nota=-1</code>.
      </td>
    </tr>
    <tr>
      <td><code>A</code></td>
      <td><code>A</code></td>
      <td>
        Mostra a <b>altura</b> da árvore no formato <code>A = [Altura]</code>.
        <br>
        Por exemplo, <code>A=3</code>.
      </td>
    </tr>
    <tr>
      <td><code>P</code></td>
      <td><code>P</code></td>
      <td>O programa finaliza.</td>
    </tr>
  </tbody>
</table>

## Exemplos

### Exemplo 1

Para a entrada

    I 8 10
    I 4 7
    I 7 2
    I 2 5
    A
    R 4
    B 7
    I 1 2
    I 19 2
    B 1
    R 1
    A
    P

a saída deve ser:

    A=2
    C=2 Nota=2
    C=4 Nota=2
    A=2

### Exemplo 2

Para a entrada

    I 8 5
    I 4 6
    I 16 10
    I 1 9
    A
    I 5 1
    I 18 0
    B 8
    B 18
    B 1
    B 5
    B 16
    B 78
    B -9
    B 15
    I 15 9
    B 15
    R 8
    B 8
    B 15
    B 18
    I 8 7
    I 8 10
    I 8 8
    B 8
    A
    P

a saída deve ser:

    A=2
    C=1 Nota=5
    C=3 Nota=0
    C=3 Nota=9
    C=3 Nota=1
    C=2 Nota=10
    C=3 Nota=-1
    C=3 Nota=-1
    C=2 Nota=-1
    C=3 Nota=9
    C=3 Nota=-1
    C=1 Nota=9
    C=3 Nota=0
    C=4 Nota=8
    A=3