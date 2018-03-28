# Árvores AVL

## Introdução

### Aulas anteriores - Estratégias de Busca - Caso Pior

| Técnica          | Ordem | Busca     | Inserção  | Remoção   |
| ---------------- | :---: | :-------: | :-------: | :-------: |
| Busca sequencial | Não   | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       |
| Busca Binária    | Sim   | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/79badfc8340e83b5f4e91765c36fd4fe.svg?invert_in_darkmode" align=middle width=43.885215pt height=24.65759999999998pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       |
| ABB              | Sim   | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/>       |
| ???              | Sim   | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/79badfc8340e83b5f4e91765c36fd4fe.svg?invert_in_darkmode" align=middle width=43.885215pt height=24.65759999999998pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/79badfc8340e83b5f4e91765c36fd4fe.svg?invert_in_darkmode" align=middle width=43.885215pt height=24.65759999999998pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/79badfc8340e83b5f4e91765c36fd4fe.svg?invert_in_darkmode" align=middle width=43.885215pt height=24.65759999999998pt/> |

<p align="center">
  <img src="img/img1.png">
</p>

- As operações nas ABBs tem custo entre <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/9cf64727487f57b15f4c7a257f1dbaca.svg?invert_in_darkmode" align=middle width=69.66613500000001pt height=24.65759999999998pt/> e <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.647755pt height=24.65759999999998pt/>;
- O caso melhor acontece quando elas são completas;
- Por que não "completar" a árvore após inserir/remover?

  Custo elevado <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/1f08ccc9cd7309ba1e756c3d9345ad9f.svg?invert_in_darkmode" align=middle width=35.647755pt height=24.65759999999998pt/>.
- Na verdade as ABBs não precisam ser completas para ter custo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/9cf64727487f57b15f4c7a257f1dbaca.svg?invert_in_darkmode" align=middle width=69.66613500000001pt height=24.65759999999998pt/>;
basta serem **balanceadas**;
- Que tipo de **balanceamento**?
- Como balancear de forma eficiente e ao mesmo tempo preservar a ordem
simétrica após inserir/remover?

### Árvores Balanceadas

- Balanceamento pela altura (*height balance*): AVL trees, red-black trees.

  https://en.wikipedia.org/wiki/Red-black_tree

<p align="center">
  <img src="img/img2.png">
</p>

- Balanceamento perfeito pela altura (*perfect height balance*):
2-3 trees, 2-3-4 trees, B trees (B+, B*).

  https://en.wikipedia.org/wiki/B+tree

<p align="center">
  <img src="img/img3.png">
</p>

- Balanceamento pela "classe" (*rank balance*): WAVL trees **[1]**.

- Balanceamento pela frequência de acesso: splay trees **[2]**.

- Balanceamento pelo número de nós: weight-balanced binary trees **[3]**.  

**[1]**: Rank-balanced trees: Haeupler B., Sen, S., Tarjan, R. E., ACM Transactions 
on Algorithms, 2015

**[2]**: Self-Adjusting Binary Search Trees: Sleator, Daniel D., Tarjan, Robert E.
Journal of the ACM, 1985

**[3]**: Binary Search Trees of Bounded Balance: Nievergelt, J., Reingold, E. M.
SIAM Journal on Computing, 1973

## Árvores AVL

### Árvores Binárias Balanceadas pela Altura

**Altura de um nó:** número de passos do mais longo caminho até uma folha.

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/8e9b93777db13f693d263b596215dd97.svg?invert_in_darkmode" align=middle width=350.988pt height=49.31553pt/></p>

<p align="center">
  <img src="img/img4.png">
</p>

### Árvores Binárias AVL

Primeiras árvores balanceadas, propostas em 1962 pelos cientistas russos
Georgy **A**delson-**V**elsky e Evgenii **L**andis **[4]**.

- para cada nó na árvore, a diferença de altura de suas duas sub-árvores é
no máximo 1.

<p align="center">
  <img src="img/img5.png">
</p>

**[4]**: An algorithm for the organization of information. Proc. USSR Academy of
Sciences, 146: 263-266, 1962

### Árvore AVL e Fator de Balanceamento de um nó <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/253c68ec7096f4ac76a9318a647c7f27.svg?invert_in_darkmode" align=middle width=248.79855pt height=16.438356pt/></p>

<p align="center">
  <img src="img/img6.png">
</p>

- Uma ABB é **AVL** se para cada nó <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>, <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/f2e24e333ddee4dd3ecbf6b80321cc87.svg?invert_in_darkmode" align=middle width=88.068915pt height=24.65759999999998pt/>.

<p align="center">
  <img src="img/img7.png">
</p>

<p align="center">
  <img src="img/img8.png">
</p>

**Exercício:** Quais das ABBs abaixo são AVL?

<p align="center">
  <img src="img/img9.png">
</p>

### Exemplo de Implementação - Árvore AVL

Pode ser implementada armazenando a altura ou o fator de balanceamento.

```c
typedef struct AVLTreeNode AVLTreeNode;
struct AVLTreeNode {
  int key;
  int height; // unsigned short balanceFactor;

  // Pointers to the left and right children of the node.
  AVLTreeNode * left, * right;
}

void updateHeight (AVLTreeNode * n) {
  if (!n) return;
  int hl = (n->left)  ? n->left->height  : -1,
      hr = (n->right) ? n->right->height : -1;
  n->height = (hl > hr ? hl : hr) + 1;
}

const int LEFT_HEAVY = -1, BALANCED = 0, RIGHT_HEAVY = 1;

int balanceFactor (AVLTreeNode * n) {
  if (!n) return 0;
  updateHeight(n);
  return n->left->height - n->right->height;
}
```

## Análise das Árvores AVL

Qual é a altura máxima <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/> que pode ter uma árvore AVL de <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> nós?

**Prova:** Usar pergunta equivalente: fixando <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/>, qual é a menor árvore
AVL (Nº de nós) que pode ser construída com altura <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/>? Seja <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/75aaccdab5321b6ae9758ac6b88ac1af.svg?invert_in_darkmode" align=middle width=37.256505000000004pt height=24.65759999999998pt/> o
menor número de nós de uma árvore AVL de altura <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/>.

- <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/3c1ab59cb6504888e1b5b3ed37157f33.svg?invert_in_darkmode" align=middle width=66.14157pt height=24.65759999999998pt/> e <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/8531d974065c04447a17072e99aa5bbf.svg?invert_in_darkmode" align=middle width=66.14157pt height=24.65759999999998pt/>
- Se <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/94bd3bac738cb5ace3e7a7bb8ed7b503.svg?invert_in_darkmode" align=middle width=39.608085pt height=22.831379999999992pt/> as sub-árvores esquerda e direita terão no máximo altura
<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/c84cc62ecb00e0df700742b534ade734.svg?invert_in_darkmode" align=middle width=37.781535000000005pt height=22.831379999999992pt/>. Na verdade, para fazer com que a árvore tenha o menor número
de nós possível (sem violar a condição de AVL) então uma sub-árvore terá
altura <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/c84cc62ecb00e0df700742b534ade734.svg?invert_in_darkmode" align=middle width=37.781535000000005pt height=22.831379999999992pt/> e a outra <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/ed3d03f09a04c1d4e2eee6117df2f9b1.svg?invert_in_darkmode" align=middle width=37.781535000000005pt height=22.831379999999992pt/>. Isto leva à recorrência

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/87e66a7d2a2041c9b4fdc0f2bee3ae9a.svg?invert_in_darkmode" align=middle width=330.46365pt height=16.438356pt/></p>

### Menor árvore AVL de altura <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/c58b8bc03be6e7a227946417eaa49660.svg?invert_in_darkmode" align=middle width=330.46365pt height=41.09589pt/></p>

<p align="center">
  <img src="img/img10.png">
</p>

Para <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/c84cc62ecb00e0df700742b534ade734.svg?invert_in_darkmode" align=middle width=37.781535000000005pt height=22.831379999999992pt/> temos <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/d26be3830c7e83099820d01bb348e268.svg?invert_in_darkmode" align=middle width=267.020655pt height=24.65759999999998pt/>, logo

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/469cfa64c7ba215c4096bb997d89628b.svg?invert_in_darkmode" align=middle width=415.33305pt height=70.501695pt/></p>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/a541fbc5ae16f9440fede6239c041254.svg?invert_in_darkmode" align=middle width=266.2803pt height=45.67959pt/></p>

Desta forma, para quaquer outra árvore com <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> nós e altura <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/>

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/8c81a02c56fd30b046511a016defc0c4.svg?invert_in_darkmode" align=middle width=398.9865pt height=21.022154999999998pt/></p>

Qual é a altura máxima <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/> que pode ter uma árvore AVL de <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> nós?

**Resposta:** A altura de uma árvore AVL com <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> nós é <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/65cc914a8e522bd3768a507a45acd191.svg?invert_in_darkmode" align=middle width=77.040645pt height=24.65759999999998pt/>.

Resolvendo melhor a recorrência (notar que é parecida com a recorrência
dos números de Fibonacci)

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/c58b8bc03be6e7a227946417eaa49660.svg?invert_in_darkmode" align=middle width=330.46365pt height=41.09589pt/></p>

obtemos que

<p align="center"><img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/b60bf136aaf88dbdd50ec209cb2f8ecc.svg?invert_in_darkmode" align=middle width=375.3816pt height=36.652274999999996pt/></p>

Calculando <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/106e7afc1919bf12dfdbeaf161175739.svg?invert_in_darkmode" align=middle width=103.287855pt height=24.65759999999998pt/>; portanto, a altura de uma árvore AVL é
<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/07ddcca3a626cb395df4abc6092df48f.svg?invert_in_darkmode" align=middle width=109.70718000000001pt height=24.65759999999998pt/> onde <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> é o número de nós da árvore.

## Balanceamento nas Árvores AVL - Rotações

### Árvore AVL e Fator de Balanceamento de um nó <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>

- Como manter as árvores AVL balanceadas após uma inserção ou remoção?
- Como preservar a ordem simétrica das ABS?
- Como manter o custo logarítmico das operações?

**Resposta:** usar **transformações locais** (de baixo custo - <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/1e2f931ee6c0b8e7a51a7b0d123d514f.svg?invert_in_darkmode" align=middle width=34.000065pt height=24.65759999999998pt/>) que 
somente sejam efetuadas no caminho da operação.

**Rotações:** Permitem trocar o papel da raiz (nó com FB igual a -2 ou 2)
e um dos filhos, preservando a ordem das chaves

- **Simples:** Esquerda ou Direita;
- **Dupla:** (Direita-) Esquerda ou (Esquerda-) Direita.

### Rotação Simples à Direita - Caso LL

- O desbalanceamento está à esquerda-esquerda;
- Troca o papel da raiz e o filho esquerdo preservando a ordem.

<p align="center">
  <img src="img/img11.png">
</p>

#### Exemplos

- O desbalanceamento está à esquerda-esquerda: o nó desbalanceado
tem <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/e5742ed74a853ab303e76596a547de28.svg?invert_in_darkmode" align=middle width=56.28430500000001pt height=22.46574pt/> e o filho esquerdo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/05dfa05fff2c000b5dd0fe4cc6ab4f61.svg?invert_in_darkmode" align=middle width=56.28430500000001pt height=22.46574pt/> (note-se que é o mesmo
sinal do pai!);
- Rotaciona a raiz e o filho esquerdo em sentido horário.

<p align="center">
  <img src="img/img12.png">
</p>

### Rotação Simples à Esquerda - Caso RR

- O desbalanceamento está à direita-direita;
- Troca o papel da raiz e o filho direito preservando a ordem.

<p align="center">
  <img src="img/img13.png">
</p>

#### Exemplos

- O desbalanceamento está à direita-direita: o nó desbalanceado
tem <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/9ea06efebf839e8df6233980efe0a5c0.svg?invert_in_darkmode" align=middle width=69.06966pt height=22.46574pt/> e o filho direito <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/7c835cb3d022664d122a3b86e0021ea2.svg?invert_in_darkmode" align=middle width=69.06966pt height=22.46574pt/> (note-se que é o mesmo
sinal do pai!);
- Rotaciona a raiz e o filho direito em sentido anti-horário.

<p align="center">
  <img src="img/img14.png">
</p>

### Rotação Dupla à Direita - Caso LR

- O desbalanceamento está à esquerda-direita;
- Duas rotações simples: 1ª à esquerda; 2ª à direita.

<p align="center">
  <img src="img/img15.png">
</p>

#### Exemplos

- O desbalanceamento está à esquerda-direita: o nó desbalanceado
tem <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/e5742ed74a853ab303e76596a547de28.svg?invert_in_darkmode" align=middle width=56.28430500000001pt height=22.46574pt/> e o filho direito <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/7c835cb3d022664d122a3b86e0021ea2.svg?invert_in_darkmode" align=middle width=69.06966pt height=22.46574pt/> (sinal inverso do pai!);
- Rotaciona duas vezes o neto que está à esquerda-direita: primeiro
à esquerda e depois à direita.

<p align="center">
  <img src="img/img16.png">
</p>

### Rotação Dupla à Esquerda - Caso RL

- O desbalanceamento está à direita-esquerda;
- Duas rotações simples: 1ª à direita; 2ª à esquerda.

<p align="center">
  <img src="img/img17.png">
</p>

#### Exemplos

- O desbalanceamento está à direita-esquerda: o nó desbalanceado
tem <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/9ea06efebf839e8df6233980efe0a5c0.svg?invert_in_darkmode" align=middle width=69.06966pt height=22.46574pt/> e o filho direito <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/05dfa05fff2c000b5dd0fe4cc6ab4f61.svg?invert_in_darkmode" align=middle width=56.28430500000001pt height=22.46574pt/> (sinal inverso do pai!);
- Rotaciona duas vezes o neto que está à direita-esquerda: primeiro
à direita e depois à esquerda.

<p align="center">
  <img src="img/img18.png">
</p>

### Resumo Rotações

- São simétricas

<p align="center">
  <img src="img/img19.png">
</p>

- Nas simples, o nó não balanceado tem FB com o mesmo sinal do filho mais
alto ("simétrico" à rotação). São aplicadas no sentido inverso à maior altura;

- Nas duplas, o nó não balanceado tem FB o sinal inverso do filho mais
alto ("simétrico" à rotação). São compostas por uma rotação simples e a simétrica.

## Inserção nas Árvores AVL

- Inserir o nó da mesma forma que nas ABBS;
- Atualizar o FB de cada nó <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> no caminho de volta.
  - **Caso 1:** Se o nó tinha <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/85165d6c1754692c7b43dcf7ab5f0488.svg?invert_in_darkmode" align=middle width=56.28430500000001pt height=22.831379999999992pt/> antes da inserção (-1 ou 1), e a nova
  chave foi inserida na sub-árvore de menor altura (esquerda ou direita resp),
  atualizar FB para 0. Como a altura **não** mudou, não é preciso conferir o
  FB dos antecessores.
  - **Caso 2:** Se o nó tinha <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/5e8960269a349069907f0a02a36d585b.svg?invert_in_darkmode" align=middle width=56.28430500000001pt height=22.46574pt/> antes da inserção, atualizar FB para
  -1 ou 1 dependendo da sub-árvore onde acontece a inserção (direita ou 
  esquerda resp). Como a altura mudou, é preciso conferir o FB dos antecessores.
  - **Caso 3:** Se o nó tinha <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/85165d6c1754692c7b43dcf7ab5f0488.svg?invert_in_darkmode" align=middle width=56.28430500000001pt height=22.831379999999992pt/> antes da inserção (-1 ou 1), e a nova
  chave foi inserida na sub-árvore de maior altura (direita ou esquerda resp),
  efetuar a rotação. Como a sub-árvore será rebalanceada, não é preciso conferir
  o FB dos antecessores.

**Exemplo:** Inserir as seguintes chaves numa árvore AVL: 40, 20, 50, 30, 45,
60, **55**, **15**, **52**.

[AVL Tree Visualization](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html)

### Exemplo de Inserções nas Árvores AVL

<p align="center">
  <img src="img/img20.png">
</p>

No caso 3, a altura da sub-árvore após o balanceamento é a mesma que antes
da inserção.

### Exemplo de Implementação - Inserção AVL

```c
void insertAVL (AVLTreeNode ** treeRoot, int key, int * reviseBalanceFactor) {
  if (*treeRoot == NULL) {
    // Update the root to point at newNode.
    AVLTreeNode * newNode = malloc(sizeof(AVLTreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 0;
    *treeRoot = newNode;

    // Balance Factor must be checked!
    *reviseBalanceFactor = 1; // true;
    return;
  }

  if (key == (*treeRoot)->key) {
    *reviseBalanceFactor = 0; // false;
    return;
  }

  AVLTreeNode * tree = *treeRoot;
  // Indicates a change in node's Balance Factor.
  int rebalanceCurrNode, balanceFactorOld = balanceFactor(tree);

  if (key < tree->key) { // Recursively move to the left.
    insertAVL(&tree->left, key, &rebalanceCurrNode);

    // Check if Balance Factor must be updated.
    if (rebalanceCurrNode) {
      // Case 3: went left from node that is already heavy
      // on the left. Violates AVL condition; rotate.
      if (balanceFactorOld == LEFT_HEAVY)
        updateLeftTree(treeRoot, reviseBalanceFactor);
      
      // Case 1: inserting in the left on previously balanced
      // node that now will be heavy on left.
      else if (balanceFactorOld == BALANCED) {
        *reviseBalanceFactor = 1; // true;
        updateHeight(*treeRoot);  // Update the height.
      }

      // Case 1: scanning left from node heavy on the
      // right. The node will be balanced, the height
      // is the same.
      else *reviseBalanceFactor = 0; // false;
    }

    // No ballancing occurs; do not ask previous nodes.
    else *reviseBalanceFactor = 0; // false;
  }

  // Otherwise recursively move right.
  else {
    insertAVL(&tree->right, key, &rebalanceCurrNode);

    // Check if Balance Factor must be updated.
    if (rebalanceCurrNode) {
      // ...
    }
  }
}
```

Ver código completo [aqui].

[aqui]: avl-tree.c

### Rebalanceamento da sub-árvore à esquerda

```c
void updateLeftTree (AVLTreeNode ** pRoot, int * reviseBalanceFactor) {
  AVLTreeNode * leftChild = (*pRoot)->left;
  int balanceFactorChild = balanceFactor(leftChild);

  if (balanceFactorChild == LEFT_HEAVY) {
    // Left subtree is also heavy.
    caseLLrotateRight(pRoot); // Need a single rotation.
    *reviseBalanceFactor = 0; // false;
  }

  // Is right subtree heavy?
  else if (balanceFactorChild == RIGHT_HEAVY) {
    // Make a double rotation.
    caseLRrotateLeftRight(pRoot);
    // Root is now balanced.
    *reviseBalanceFactor = 0;
  }
}
```

## Conclusões

- A altura de uma árvore AVL é aproximadamente igual <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/a7d441f0e5ed09fa74fffd77dad00432.svg?invert_in_darkmode" align=middle width=92.355615pt height=24.65759999999998pt/> onde
<img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/> é o número de nós da árvore;
- O balanceamento usa transformações simples, locais, simétricas, de custo
constante;
- As operações de busca e inserção tem custo <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/65cc914a8e522bd3768a507a45acd191.svg?invert_in_darkmode" align=middle width=77.040645pt height=24.65759999999998pt/> no caso médio e
também no caso pior.

| Técnica          | Ordem | Busca     | Inserção  | Remoção   |
| ---------------- | :---: | :-------: | :-------: | :-------: |
| Busca sequencial | Não   | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       |
| Busca Binária    | Sim   | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/79badfc8340e83b5f4e91765c36fd4fe.svg?invert_in_darkmode" align=middle width=43.885215pt height=24.65759999999998pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.867000000000003pt height=14.155350000000013pt/>       |
| ABB              | Sim   | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/>       | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/2ad9d098b937e46f9f58968551adac57.svg?invert_in_darkmode" align=middle width=9.471165000000003pt height=22.831379999999992pt/>       |
| AVL              | Sim   | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/79badfc8340e83b5f4e91765c36fd4fe.svg?invert_in_darkmode" align=middle width=43.885215pt height=24.65759999999998pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/79badfc8340e83b5f4e91765c36fd4fe.svg?invert_in_darkmode" align=middle width=43.885215pt height=24.65759999999998pt/> | <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/79badfc8340e83b5f4e91765c36fd4fe.svg?invert_in_darkmode" align=middle width=43.885215pt height=24.65759999999998pt/> |

- Inserção simples, após inserir basta uma rotação para tornar a árvore AVL
novamente;
- A remoção pode precisar de <img src="https://rawgit.com/alessandrojean/AED-I-2018.1/master/classes/theory/2018.03.28/svgs/79badfc8340e83b5f4e91765c36fd4fe.svg?invert_in_darkmode" align=middle width=43.885215pt height=24.65759999999998pt/> rotações;
- Precisa armazenar a altura ou o fator de balanceamento (mais dois bits
por nó).

**É possível melhorar isto?** Sim, próxima aula árvores preto-vermelho.

## Referências Bibliográficas

- Donald Knuth. **The Art of Computer Programming, Volume 3: Sorting
and Searching, 3rd Ed**. Addison-Wesley, 1997, pages 458-475,
section 6.2.3: Balanced Trees.
- Jayme L. Szwarcfiter; Lilian Markezon. **Estruturas de Dados e seus
Algoritmos, 3ª edição**. 2010.
- Don Spickler, [Tutorial AVL TREES].
- Wikipédia: [AVL tree], [Red-black tree], [B tree].
- AVL Tree Visualization.

  https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

[Tutorial AVL TREES]: http://facultyfp.salisbury.edu/despickler/personal/Resources/AdvancedDataStructures/Handouts/AVL_TREES.pdf
[AVL tree]: https://en.wikipedia.org/wiki/AVL_tree
[Red-black tree]: https://en.wikipedia.org/wiki/Red-black_tree
[B tree]: https://en.wikipedia.org/wiki/B-tree