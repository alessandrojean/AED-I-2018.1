# Lista de Exercícios 5: Estruturas Lineares

## Variantes auto-ajustáveis

1. Implemente uma pilha auto-ajustável com as operações para criar, empilhar,
desempilhar e liberar.
1. Implemente uma fila auto-ajustável com as operações para criar, enfileirar,
desenfileirar e liberar.
1. Implemente uma fila estática usando duas pilhas com as operações para
criar, enfileirar e desenfileirar.
   
   ![image](https://user-images.githubusercontent.com/14254807/37259884-20ab4286-256b-11e8-9c22-8b8e34625253.png)

## Conversão binário 🡪 sete segmentos

Um "display" de sete segmentos é constitúido por sete LEDs dispostos de forma 
retangular como mostra na Figura 1. Cada LED é chamado de segmento porque, quando 
iluminado, o segmento faz parte de um dígito numérico hexadecimal. Os dígitos 
hexadecimais maiores do que nove são mostrados usando letras maiúsculas,
exceto B e D que são mostradas em minúsculas pois caso contrário, a representação 
é idêntica a 0 e 8 respectivamente.

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

Escreva um programa que dado um número binário de tamanho arbitrário imprima
sua representação em um display de sete segmentos. O número binário deve
ser lido como sequência de caracteres `'0'` e `'1'` terminada no caractere
`'b'`.

**Exemplo 1:** Dada a entrada

    000001010101111001101111011110001001000110100010101100111100010010000b

a saída do progra,a deve ser a seguinte

     _       _       _   _      _   _       _   _   _   _   _   _
    |_| |_  |    _| |_  |_   |  _|  _| |_| |_  |_    | |_| |_| | |
    | | |_| |_  |_| |_  |    | |_   _|   |  _| |_|   | |_|   | |_|

Note que, na saída do seu programa, cada número em sete segmentos ocupa três linhas
e três colunas de texto. Cada coluna tem um caractere que pode ser, espaço, `_` ou 
`|`. 