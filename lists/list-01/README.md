# Lista de Exercícios 1: Revisão da Linguagem C

Escreva programas em C para resolver os seguintes problemas definindo funções apropriadas.

## 1. Intervalo inteiro de tamanho `k`

Dado um inteiro `k > 1` e uma sequência de `M` números inteiros, determinar se a sequência
contém pelo menos uma sub-sequência de até `k` números consecutivos. Faça o programa
imprimir todas as sub-sequências máximas.

**Exemplo 1:** Para `k = 4`, a sequência `8, -10, 4, -2, -1, 0, 1, 2, 50, 51, 54` contém as
sub-sequências

- `-2, 1, 0, 1`
- `1, 0, 1, 2`
- `50, 51`

**Exemplo 2:** Para `k = 7`, a sequência `5, 20, -9, 51, 52, 53 -1, -4, -3, -2, -1, 0, 1, 2, 3`
contém as sub-sequências

- `51, 52, 53`
- `-4, -3, -2, -1, 0, 1, 2`
- `-3, -2, -1, 0, 1, 2, 3`

## 2. Agenda de Contatos

Escreva um programa para gerenciar uma agenda de contatos. Para cada contato deve-se armazenar **Nome**, **Telefone** e **Email**. Seu programa deve dar as seguintes opções ao usuário: **Inserir um contato** no final da agenda, **Buscar dados pelo Nome**, **Buscar dados pelo Telefone**, **Mostrar Agenda** e **Sair**.

## 3. Conversão inteiro 🡪 sete segmentos

Um "display" de sete segmentos é constitúido por sete LEDs dispostos de forma retangular como mostra
na Figura 1. Cada LED é chamado de segmento porque, quando iluminado, o segmento faz parte de um dígito
numérico hexadecimal. Os dígitos hexadecimais maiores do que nove são mostrados usando letras maiúsculas,
exceto B e D que são mostradas em minúsculas pois caso contrário, a representação é idêntica a 0 e 8
respectivamente.

| Digit | Display   | gfedcba | abcdefg | a     | b     | c     | d     | e     | f     | g     |
| :---: | :-------: | :-----: | :-----: | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 0     | ![0](https://upload.wikimedia.org/wikipedia/commons/thumb/4/49/7-segment_abcdef.svg/10px-7-segment_abcdef.svg.png)   | 0x3F    | 0x7E    | **on**  | **on**  | **on**  | **on**  | **on**  | **on**  | off |
| 1     | ![1](https://upload.wikimedia.org/wikipedia/commons/thumb/b/be/7-segment_bc.svg/10px-7-segment_bc.svg.png)           | 0x06    | 0x30    | off | **on**  | **on**  | off | off | off | off |
| 2     | ![2](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f8/7-segment_abdeg.svg/10px-7-segment_abdeg.svg.png)     | 0x5B    | 0x6D    | **on**  | **on**  | off | **on**  | **on**  | off | **on**  |
| 3     | ![3](https://upload.wikimedia.org/wikipedia/commons/thumb/b/be/7-segment_abcdg.svg/10px-7-segment_abcdg.svg.png)     | 0x4F    | 0x79    | **on**  | **on**  | **on**  | **on**  | off | off | **on**  |
| 4     | ![4](https://upload.wikimedia.org/wikipedia/commons/thumb/b/b0/7-segment_bcfg.svg/10px-7-segment_bcfg.svg.png)       | 0x66    | 0x33    | off | **on**  | **on**  | off | off | **on**  | **on**  |
| 5     | ![5](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9b/7-segment_acdfg.svg/10px-7-segment_acdfg.svg.png)     | 0x6D    | 0x5B    | **on**  | off | **on**  | **on**  | off | **on**  | **on**  |
| 6     | ![6](https://upload.wikimedia.org/wikipedia/commons/thumb/0/03/7-segment_acdefg.svg/10px-7-segment_acdefg.svg.png)   | 0x7D    | 0x5F    | **on**  | off | **on**  | **on**  | **on**  | **on**  | **on**  |
| 7     | ![7](https://upload.wikimedia.org/wikipedia/commons/thumb/6/62/7-segment_abc.svg/10px-7-segment_abc.svg.png)         | 0x07    | 0x70    | **on**  | **on**  | **on**  | off | off | off | off |
| 8     | ![8](https://upload.wikimedia.org/wikipedia/commons/thumb/a/ab/7-segment_abcdefg.svg/10px-7-segment_abcdefg.svg.png) | 0x7F    | 0x7F    | **on**  | **on**  | **on**  | **on**  | **on**  | **on**  | **on**  |
| 9     | ![9](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7a/7-segment_abcdfg.svg/10px-7-segment_abcdfg.svg.png)   | 0x6F    | 0x7B    | **on**  | **on**  | **on**  | **on**  | off | **on**  | **on**  |
| A     | ![A](https://upload.wikimedia.org/wikipedia/commons/thumb/2/28/7-segment_abcefg.svg/10px-7-segment_abcefg.svg.png)   | 0x77    | 0x77    | **on**  | **on**  | **on**  | off | **on**  | **on**  | **on**  |
| b     | ![b](https://upload.wikimedia.org/wikipedia/commons/thumb/1/19/7-segment_cdefg.svg/10px-7-segment_cdefg.svg.png)     | 0x7C    | 0x1F    | off | off | **on**  | **on**  | **on**  | **on**  | **on**  |
| C     | ![C](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2d/7-segment_adef.svg/10px-7-segment_adef.svg.png)       | 0x39    | 0x4E    | **on**  | off | off | **on**  | **on**  | **on**  | off |
| d     | ![d](https://upload.wikimedia.org/wikipedia/commons/thumb/3/33/7-segment_bcdeg.svg/10px-7-segment_bcdeg.svg.png)     | 0x5E    | 0x3D    | off | **on**  | **on**  | **on**  | **on**  | off | **on**  |
| E     | ![E](https://upload.wikimedia.org/wikipedia/commons/thumb/8/89/7-segment_adefg.svg/10px-7-segment_adefg.svg.png)     | 0x79    | 0x4F    | **on**  | off | off | **on**  | **on**  | **on**  | **on**  |
| F     | ![F](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a6/7-segment_aefg.svg/10px-7-segment_aefg.svg.png)       | 0x71    | 0x47    | **on**  | off | off | off | **on**  | **on**  | **on**  |

Figura 1: Display sete segmentos e representação dos números hexadecimais (Fonte https://en.wikipedia.org/wiki/Seven-segment_display).

Escreva um programa que dado um valor de tipo `unsigned long long int` imprima sua representação
num display de sete segmentos.

**Exemplo 1:** Para o inteiro `11073303771280` a saída do programa deve ser a seguinte.

     _       _  _       _   _   _   _   _   _
    |_|   |  _| _| |_| |_  |_    | |_| |_| | |
    | |   | |_  _|   |  _| |_|   | |_|   | |_|

**Exemplo 2:** Para o inteiro `11259375` a saída do programa deve ser a seguinte.

     _       _       _   _ 
    |_| |_  |    _| |_  |_ 
    | | |_| |_  |_| |_  |  
    
Note que, na saída do seu programa, cada número em sete segmentos ocupa três linhas
e três colunas de texto. Cada coluna tem um caractere que pode ser, espaço, `_` ou `|`. Use o
código a seguir para conferir a conversão hexadecimal.

```c
int main () {
  unsigned long long int n1 = 11073303771280, n2 = 11259375;
  printf("%llx\n", n1);
  printf("%llx\n", n2);
}
```