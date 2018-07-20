# RAs, Nomes e Notas (Ordenação)
*Exercício do Prof. Paulo H. Pisani, CMCC/UFABC.*

O professor ABC guarda os RAs (número de registro do aluno) e nota de cada
aluno em um sistema. Esse sistema usa uma **lista ligada**. O sistema possui 
funções para incluir, ordenar e buscar dados. Para avaliar o desempenho do 
sistema, o professor ABC resolveu adicionar um indicador: quantidade de 
comparações realizadas na ordenação.

## Exercício

Escreva um programa em linguagem C que receba uma sequência de operações 
(inserção, ordenação, busca e imprimir lista). Quando for feita uma 
**operação de ordenação**, o programa deve imprimir a quantidade de comparações realizadas na durante a ordenação. Nas operações de busca, o 
programa deve mostrar a posição do item na lista ligada
(a posição do primeiro item é zero).

Salve o código no arquivo: `ordenanotasligada.c`. 

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
      <td><code>I [RA] [Nome] [Nota]</code></td>
      <td><code>I 200 TESTE 10</code></td>
      <td>
        <b>Insere</b> um item <b>no final da lista ligada</b>, com o
        <br>
        RA, Nome e a Nota informados. RA e Nota são
        <br>
        números inteiros (<code>int</code>), Nome é uma string de no
        <br>
        máximo <i>50 caracteres maiúsculus sem espaços</i>.
      </td>
    </tr>
    <tr>
      <td><code>O [Algoritmo] [Campo]</code></td>
      <td><code>O 1 1</code></td>
      <td>
        <b>Ordena</b> a lista ligada utilizando o Algoritmo
        <br>
        especificado sobre o Campo chave informado.
        <br>
        <ul>
          <li>Algoritmos:</li>
          <ul>
            <li>1: Ordenação por seleção;</li>
            <li>2: Ordenação por inserção.</li>
          </ul>
          <li>Campo chave:</li>
          <ul>
            <li>1: RA;</li>
            <li>2: Nome.</li>
          </ul>
        </ul>
        No exemplo, <code>O 1 1</code>, será realizada a
        <br>
        ordenação com ordenação por seleção no
        <br>
        campo chave RA. Após a ordenação, o
        <br>
        programa deve imprimir a quantidade de
        <br>
        comparações realizadas no formato
        <br>
        <code>Comparacoes=x</code>. Por exemplo,
        <br>
        <code>Comparacoes=12</code>.
      </td>
    </tr>
    <tr>
      <td><code>B [RA]</code></td>
      <td><code>B 200</code></td>
      <td>
        <b>Busca</b> o aluno pelo RA e retorna sua posição
        <br>
        na lista ligada no formato <code>Pos=x</code>. Por exemplo,
        <br>
        <code>Pos=4</code>. O primeiro elemento está na posição 0
        <br>
        (zero). Retornar <code>Pos=-1</code> se o elemento não
        <br>
        estiver na lista.
      </td>
    </tr>
    <tr>
      <td><code>M</code></td>
      <td><code>M</code></td>
      <td>
        <b>Mostra</b> a lista ligada atual, um aluno abaixo do
        <br>
        outro. Por exemplo:
        <pre><code>[200 TESTE 10]
[320 ABC 10]
[500 ABCD 5]</code></pre>
      </td>
    </tr>
    <tr>
      <td><code>P</code></td>
      <td><code>P</code></td>
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
apenas uma função para ordenação por seleção, que pode ordenar tanto
por RA quanto por Nome. O mesmo vale para o caso da ordenação por
inserção;
- Não há acentos nas palavras impressas;
- Pode utilizar `strcmp` de `string.h` para comparar duas strings;
- **Libere a lista da memória ao final do programa**.

## Exemplos

### Exemplo 1

Para a entrada

    I 10 ABC 10
    I 18 DEF 2
    I 15 GHI 6
    I 60 JKL 5
    B 15
    B 16
    M
    O 1 1
    B 18
    O 2 1
    B 10
    P

a saída deve ser:

    Pos=2
    Pos=-1
    [10 ABC 10]
    [18 DEF 2]
    [15 GHI 6]
    [60 JKL 5]
    Comparacoes=6
    Pos=2
    Comparacoes=3
    Pos=0

### Exemplo 2

Para a entrada

    I 10 ABC 10
    I 18 DEF 2
    I 15 GHI 6
    I 60 JKL 5
    B 15
    B 16
    M
    O 1 1
    B 18
    I 57 PQR 10
    I 80 MNO 9
    O 2 2
    O 2 1
    O 2 1
    O 1 2
    O 2 2
    B 10
    M
    P

a saída deve ser:

    Pos=2
    Pos=-1
    [10 ABC 10]
    [18 DEF 2]
    [15 GHI 6]
    [60 JKL 5]
    Comparacoes=6
    Pos=2
    Comparacoes=7
    Comparacoes=8
    Comparacoes=5
    Comparacoes=15
    Comparacoes=5
    Pos=0
    [10 ABC 10]
    [18 DEF 2]
    [15 GHI 6]
    [60 JKL 5]
    [80 MNO 9]
    [57 PQR 10]
