# Árvores AVL

## Introdução

### Aulas anteriores - Estratégias de Busca - Caso Pior

| Técnica          | Ordem | Busca     | Inserção  | Remoção   |
| ---------------- | :---: | :-------: | :-------: | :-------: |
| Busca sequencial | Não   | $n$       | $n$       | $n$       |
| Busca Binária    | Sim   | $\log(n)$ | $n$       | $n$       |
| ABB              | Sim   | $h$       | $h$       | $h$       |
| ???              | Sim   | $\log(n)$ | $\log(n)$ | $\log(n)$ |

<p align="center">
  <img src="img/img1.png">
</p>

- As operações nas ABBs tem custo entre $O(\log(n))$ e $O(n)$;
- O caso melhor acontece quando elas são completas;
- Por que não "completar" a árvore após inserir/remover?

  Custo elevado $O(n)$.
- Na verdade as ABBs não precisam ser completas para ter custo $O(\log(n))$;
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

\begin{equation*}
  \begin{cases}
    -1 & \text{ se } n = \texttt{NULL} \\
    \mathrm{max}\left((n \rightarrow \mathrm{esq}), h(n \rightarrow \mathrm{dir})\right) + 1 & \text{ se } n \neq \texttt{NULL}
  \end{cases}
\end{equation*}

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

### Árvore AVL e Fator de Balanceamento de um nó $n$

$$FB(n) = h(n \rightarrow \mathrm{esq}) - h (n \rightarrow \mathrm{dir})$$

<p align="center">
  <img src="img/img6.png">
</p>

- Uma ABB é **AVL** se para cada nó $n$, $| FB(n) | \leq 1$.

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

Qual é a altura máxima $h$ que pode ter uma árvore AVL de $n$ nós?

**Prova:** Usar pergunta equivalente: fixando $h$, qual é a menor árvore
AVL (Nº de nós) que pode ser construída com altura $h$? Seja $N(h)$ o
menor número de nós de uma árvore AVL de altura $h$.

- $N(0) = 1$ e $N(1) = 2$
- Se $h > 1$ as sub-árvores esquerda e direita terão no máximo altura
$h - 1$. Na verdade, para fazer com que a árvore tenha o menor número
de nós possível (sem violar a condição de AVL) então uma sub-árvore terá
altura $h - 1$ e a outra $h - 2$. Isto leva à recorrência

$$N(h) = N(h - 1) + N(h - 2) + 1 \ \ \ \ \ \text{ se } h > 1$$

### Menor árvore AVL de altura $h$

\begin{gather*}
  N(0) = 1;\ N(1) = 2 \\
  N(h) = N(h - 1) + N(h - 2) + 1 \ \ \ \ \ \text{ se } h > 1
\end{gather*}

<p align="center">
  <img src="img/img10.png">
</p>

Para $h - 1$ temos $N(h - 1) = N(h - 2) + N(h - 3) + 1$, logo

\begin{align*}
  N(h) &= (N(h - 2) + N(h - 3) + 1) + N(h - 2) + 1 \\
  & \Rightarrow N(h) > 2 \cdot N(h - 2)  \\
  & \Rightarrow N(h) > 2 \cdot N(h - 2) > 2 \cdot 2 \cdot N(h - 4) > \dots > 2^{\frac{h}{2}}
\end{align*}

\begin{gather*}
  N(h) > 2^{\frac{h}{2}} \Rightarrow \log_2(N(h)) > \log_2(2^{\frac{h}{2}}) \\
  h < 2 \cdot \log_2(N(h))\ \ \ \square
\end{gather*}

Desta forma, para quaquer outra árvore com $n$ nós e altura $h$

$$n \geq N(h) > 2^{\frac{h}{2}} \Rightarrow \log_2(n) > \log_2(2^{\frac{h}{2}}) \Rightarrow h < 2 \cdot \log_2(n)$$

Qual é a altura máxima $h$ que pode ter uma árvore AVL de $n$ nós?

**Resposta:** A altura de uma árvore AVL com $n$ nós é $O(\log_2(n))$.

Resolvendo melhor a recorrência (notar que é parecida com a recorrência
dos números de Fibonacci)

\begin{gather*}
  N(0) = 1;\ N(1) = 2 \\
  N(h) = N(h - 1) + N(h - 2) + 1 \ \ \ \ \ \text{ se } h > 1
\end{gather*}

obtemos que

$$N(h) = \varphi^h,\ \varphi = \frac{1 + \sqrt{5}}{2} \approx 1.618 \text{ (the golden ratio )}$$

Calculando $\log_2(\varphi) = 1.44$; portanto, a altura de uma árvore AVL é
$\approx 1.44 \cdot \log_2(n)$ onde $n$ é o número de nós da árvore.

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