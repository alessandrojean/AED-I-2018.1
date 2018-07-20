# Lista de dúvidas
*Exercício do Prof. Paulo H. Pisani, CMCC/UFABC.*

Muitos alunos procuram o professor ABC para tirar dúvidas ao longo do quadrimestre.
Recentemente, o professor foi alocado para dez turmas, o que implicou em um grande 
aumento na quantidade de dúvidas que precisa responder. Diante deste cenário, ele 
resolveu criar um sistema com uma lista de dúvidas. Como a quantidade de dúvidas é 
desconhecida e ele deseja agrupar as dúvidas de cada aluno, o professor escolheu 
implementar o sistema utilizando uma **lista simplesmente ligada**. Dessa forma, ele
pode inserir novas dúvidas no interior na lista sem precisar mover (na memória) as 
dúvidas que estão à frente na lista.

Você pode ajudar o professor ABC a implementar este sistema?

## 1. Sistema sem agrupamento de dúvidas

> Salva na mesma ordem em que recebe.

### Código

Escrever o programa em linguagem C, salve o código no arquivo: `duvidasimples.c`.

O programa deverá utilizar apenas uma **lista simplesmente ligada** para armazenar 
as dúvidas. As operações de inserção de dúvidas devem ser realizadas sobre esta 
lista ligada (não crie uma nova lista a cada nova inserção).

### Entrada

O sistema receberá diversas entradas no formato `RA CodTopico`. Quando o sistema 
receber a entrada `-1 -1`, ele para de receber dúvidas. Observe que a entrada 
`-1 -1` não é armazenada.

Tanto `RA` (registro do aluno) quanto `CodTopico` são números inteiros. O professor 
criou uma tabela, de forma que os alunos devem escolher um `CodTopico` para cada 
dúvida.

### Saída

Assim que o sistema receber a entrada `-1 -1`, deverá ser impressa a lista 
armazenada em memória. A lista deverá ser impressa na mesma ordem em que foi lida.

### Exemplo 1

#### Entrada

    10 700
    50 230
    10 80
    50 91
    20 507
    10 85
    -1 -1

#### Saída

    10 700
    50 230
    10 80
    50 91
    20 507

### Exemplo 2

#### Entrada

    66 1
    66 2
    88 3
    99 5
    88 1
    88 7
    10 400
    -1 -1

#### Saída

    66 1
    66 2
    88 3
    99 5
    88 1
    88 7
    10 400

## 2. Sistema com agrupamento de dúvidas

> Agrupa as dúvidas de cada aluno.

### Código

Escrever o programa em linguagem C, salve o código no arquivo: 
`duvidagrupos.c`.

O programa deverá utilizar apenas uma **lista simplesmente ligada**
para armazenar as dúvidas. As operações de inserção de dúvidas devem 
ser realizadas sobre esta lista ligada (não crie uma nova lista a cada 
nova inserção).

### Entrada

O sistema receberá diversas entradas no formato `RA CodTopico`. Quando 
o sistema receber a entrada `-1 -1`, ele para de receber dúvidas. 
Observe que a entrada `-1 -1` não é armazenada.

Nesta versão do programa, sempre que uma dúvida de um RA é recebida, 
ela deve ser inserida na lista juntamente com as dúvidas do mesmo RA, 
ao final da sequência de dúvidas daquele RA. Veja como o agrupamento 
funciona nos exemplos de entrada/saída (Exemplo 1 e Exemplo 2).

Tanto `RA` (registro do aluno) quanto `CodTopico` são números inteiros. 
O professor criou uma tabela, de forma que os alunos devem escolher um 
`CodTopico` para cada dúvida.

### Saída

Assim que o sistema receber a entrada `-1 -1`, deverá ser impressa a 
lista armazenada em memória. A lista deverá ser impressa na mesma ordem 
em que foi lida, mas seguindo a regra de agrupamento mencionada no 
enunciado.

### Exemplo 1

#### Entrada

    10 700
    50 230
    10 80
    50 91
    20 507
    10 85
    -1 -1

#### Saída

Observe que as dúvidas foram agrupadas por RA e que as dúvidas de um
mesmo RA estão na ordem que foram recebidas.

    10 700
    10 80
    10 85
    50 230
    50 91
    20 507

### Exemplo 2

#### Entrada

    66 1
    66 2
    88 3
    99 5
    88 1
    88 7
    10 400
    -1 -1

#### Saída

Observe que as dúvidas foram agrupadas por RA e que as dúvidas de um 
mesmo RA estão na ordem que foram recebidas.

    66 1
    66 2
    88 3
    88 1
    88 7
    99 5
    10 400
