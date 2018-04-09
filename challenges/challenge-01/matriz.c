#include <stdio.h>
#include <stdlib.h>

#define MODE_ROW 1
#define MODE_COLUMN 2

#define PRINT_A 'A'
#define PRINT_B 'B'
#define PRINT_M 'M'
#define FINISH 'S'

typedef struct LinkedElementNode LinkedElementNode;
struct LinkedElementNode {
  int data;
  int row, column;
  LinkedElementNode * right, * down;
};

typedef struct LinkedHeadNode LinkedHeadNode;
struct LinkedHeadNode {
  int index;
  LinkedElementNode * elements;
  LinkedHeadNode * next;
};

typedef struct SparseMatrix SparseMatrix;
struct SparseMatrix {
  int numRows, numColumns, numElements;
  LinkedHeadNode * rows, * columns;
};

SparseMatrix * createSparseMatrix (int nr, int nc, int ne);
void readSparseMatrix(SparseMatrix * m);
void printSparseMatrix(SparseMatrix * m);
void freeSparseMatrix(SparseMatrix * m);
LinkedElementNode * createElementNode (int r, int c, int e);
LinkedHeadNode * createHeadNode (int i);
LinkedElementNode * insert (SparseMatrix * m, int r, int c, int e);
LinkedHeadNode * findHeadNode (LinkedHeadNode ** h, int i);
int insertInHeadNode (LinkedHeadNode * h, LinkedElementNode * e, int m);
int getElementAtPosition (SparseMatrix * m, int r, int c);
SparseMatrix * multiplyMatrix (SparseMatrix * mA, SparseMatrix * mB);

int main (int argc, char ** argv) {
  int LA, LB, CA, CB, NA, NB, i = 0;
  scanf("%d %d %d %d %d %d", &LA, &CA, &NA, &LB, &CB, &NB);

  // Cria as matrizes esparsas A e B.
  SparseMatrix * matrixA = createSparseMatrix(LA, CA, NA),
               * matrixB = createSparseMatrix(LB, CB, NB);

  // Lê as matrizes esparsas A e B no
  // formato específicado.
  readSparseMatrix(matrixA);
  readSparseMatrix(matrixB);

  char c;
  scanf(" %c", &c);
  while (c != FINISH) {
    if (i++) printf("\n");

    if (c == PRINT_A)
      printSparseMatrix(matrixA);
    else if (c == PRINT_B)
      printSparseMatrix(matrixB);
    else if (c == PRINT_M) {
      SparseMatrix * matrixC = multiplyMatrix(matrixA, matrixB);
      if (!matrixC) printf("ERRO");
      else {
        printSparseMatrix(matrixC);
        freeSparseMatrix(matrixC);
      }
    }
    scanf(" %c", &c);
  }

  // Libera da memória as matrizes esparsas
  // A e B, ao fim do uso.
  freeSparseMatrix(matrixA);
  freeSparseMatrix(matrixB);

  return EXIT_SUCCESS;
}

/**
 * Cria uma matriz esparsa com nr linhas e nr colunas,
 * para ne elementos. Caso haja falta de memória,
 * retorna NULL.
 **/
SparseMatrix * createSparseMatrix (int nr, int nc, int ne) {
  SparseMatrix * tmp = malloc(sizeof(SparseMatrix));
  if (!tmp) return NULL;

  tmp->numRows = nr;
  tmp->numColumns = nc;
  tmp->numElements = ne;
  tmp->rows = tmp->columns = NULL;

  return tmp;
}

/**
 * Libera da memória uma matriz esparsa m.
 **/
void freeSparseMatrix(SparseMatrix * m) {
  if (!m) return;

  LinkedHeadNode * rows = m->rows,
                 * columns = m->columns,
                 * nextHead;
  
  LinkedElementNode * elements, * nextElement;
  
  for (; rows != NULL; rows = nextHead) {
    nextHead = rows->next;

    for (elements = rows->elements; elements != NULL; elements = nextElement) {
      nextElement = elements->right;
      free(elements);
    }

    free(rows);
  }

  for (; columns != NULL; columns = nextHead) {
    nextHead = columns->next;
    free(columns);
  }

  free(m);
}

/**
 * Imprime uma matriz esparsa m, no formato
 * especificado abaixo.
 * 
 * Formato:
 * 
 * [e01 e02 e03 ... e0n ]
 * [e11 e12 e13 ... e1n ]
 * [... ... ... ... ... ]
 * [... ... ... ... ... ]
 * [em1 em2 em3 ... emn ]
 **/
void printSparseMatrix(SparseMatrix * m) {
  int i, j, p;
  LinkedHeadNode * currRow;
  LinkedElementNode * currElement;
  for (i = 0, currRow = m->rows; i < m->numRows; i++) {
    printf("[");
    p = 0;

    currElement = (currRow) ? currRow->elements : NULL;
    for (j = 0; j < m->numColumns; j++) {
      if (currElement != NULL && currElement->column == j && currElement->row == i) {
        printf("%d ", currElement->data);
        currElement = currElement->right;
        p = 1;
      }

      // Caso 2: semelhante as linhas também.
      else printf("%d ", 0);
    }

    if (p) currRow = currRow->next;
    //printf(i < m->numRows - 1 ? "]\n" : "]");
    printf("]\n");
  }
}

/**
 * Cria um nó elemento, para a linha r e coluna c,
 * com conteúdo e. Caso haja falta de memória,
 * retorna NULL.
 **/
LinkedElementNode * createElementNode (int r, int c, int e) {
  LinkedElementNode * tmp = malloc(sizeof(LinkedElementNode));
  if (!tmp) return NULL;

  tmp->row = r;
  tmp->column = c;
  tmp->data = e;
  tmp->right = tmp->down = NULL;

  return tmp;
}

/**
 * Cria um nó cabeça, para uma linha ou coluna,
 * na posição i. Caso haja falta de memória,
 * retorna NULL.
 **/
LinkedHeadNode * createHeadNode (int i) {
  LinkedHeadNode * tmp = malloc(sizeof(LinkedHeadNode));
  if (!tmp) return NULL;

  tmp->index = i;
  tmp->elements = NULL;
  tmp->next = NULL;

  return tmp;
}

/**
 * Insere um elemento na linha r e coluna c,
 * com conteúdo e. Caso haja falta de memória,
 * retorna NULL.
 **/
LinkedElementNode * insert (SparseMatrix * m, int r, int c, int e) {
  if (!m) return NULL;

  LinkedElementNode * element = createElementNode(r, c, e);
  if (!element) return NULL;

  // Primeiro caso:
  // a matriz está vazia, então basta
  // criar uma coluna, uma linha e um
  // elemento, e inserí-los na matriz.
  if (!m->rows && !m->columns) {
    LinkedHeadNode * row = createHeadNode(r),
                   * column = createHeadNode(c);

    row->elements = column->elements = element;
    m->rows = row;
    m->columns = column;

    return element;
  }

  // Segundo caso:
  // a matriz já possui elementos, então basta 
  // achar (ou criar) a linha r e coluna c, 
  // e criar o elemento e e inseri-lo na
  // posição correta.

  // Acha a linha r e coluna c na matriz.
  LinkedHeadNode * rowToInsert = findHeadNode(&(m->rows), r),
                 * columnToInsert = findHeadNode(&(m->columns), c);
  
  // Insere na linha e coluna correta.
  int resultRow = insertInHeadNode(rowToInsert, element, MODE_ROW),
      resultColumn = insertInHeadNode(columnToInsert, element, MODE_COLUMN);

  // Caso alguma das operações de inserção
  // tiver dado erro, retorna NULL.
  if (!resultRow || !resultColumn) return NULL;

  return element;
}

/**
 * Procura na lista ligada ordenada de nós cabeça
 * um elemento com o valor i. Caso não exista,
 * ele será criado, inserido em sua posição correta,
 * e retornado. Caso haja falta de memória,
 * retorna NULL.
 **/
LinkedHeadNode * findHeadNode (LinkedHeadNode ** h, int i) {
  if (!(*h)) return NULL;

  // Caso o primeiro elemento já seja maior que i,
  // é necessário inserir antes.
  if ((*h)->index > i) {
    LinkedHeadNode * tmp = createHeadNode(i);
    if (!tmp) return NULL;

    tmp->next = *h;
    *h = tmp;

    return tmp;
  }

  LinkedHeadNode * prev, * curr;
  // Itera até achar o elemento anterior a i.
  for (prev = curr = *h; curr != NULL && curr->index <= i; prev = curr, curr = curr->next);

  // Caso o elemento encontrado seja o procurado,
  // basta retorná-lo.
  if (prev->index == i)
    return prev;

  // Senão, é necessário criá-lo e inseri-lo
  // em sua devida posição.
  LinkedHeadNode * tmp = createHeadNode(i);
  if (!tmp) return NULL;

  tmp->next = prev->next;
  prev->next = tmp;

  return tmp;
}

/**
 * Insere o elemento e na linha ou coluna h.
 * O estado de h é específicado através de m.
 * 
 * Possíveis modos:
 * MODE_ROW: Procura na linha, usando o e->right.
 * MODE_COLUMN: Procura na coluna, usando o e->down.
 * 
 * Caso haja algum erro, retorna 0.
 */
int insertInHeadNode (LinkedHeadNode * h, LinkedElementNode * e, int m) {
  if (m != MODE_COLUMN && m != MODE_ROW && (!h || !e)) return 0;

  // Se o elemento e deve ser inserido logo no 
  // início da coluna ou linha.
  if (!h->elements
      || (h->elements->column > e->column && m == MODE_ROW)
      || (h->elements->row > e->row && m == MODE_COLUMN)) {
    if (m == MODE_COLUMN) e->down = h->elements;
    else e->right = h->elements;

    h->elements = e;

    return 1;
  }

  // Então ele deve ser inserido em sua correta posição.
  LinkedElementNode * prev, * curr;
  if (m == MODE_ROW)
    for (prev = curr = h->elements; curr != NULL && curr->column <= e->column; prev = curr, curr = curr->right);
  else
    for (prev = curr = h->elements; curr != NULL && curr->row <= e->row; prev = curr, curr = curr->down);

  if ((prev->column == e->column && m == MODE_ROW) 
      || (prev->row == e->row && m == MODE_COLUMN)) {
    prev->data = e->data;
  } else if (m == MODE_COLUMN) {
    e->down = prev->down;
    prev->down = e;
  } else {
    e->right = prev->right;
    prev->right = e;
  }

  return 1;
}

/**
 * Lê m->numElements elementos com scanf utilizando 
 * a entrada especificada abaixo em uma matriz 
 * esparsa m, diferente de NULL.
 * 
 * Formato de entrada:
 * [linha] [coluna] [número]
 **/
void readSparseMatrix(SparseMatrix * m) {
  if (!m) return;

  int i, r, c, e;
  for (i = 0; i < m->numElements; i++) {
    scanf("%d %d %d", &r, &c, &e);
    insert(m, r, c, e);
  }
}

/**
 * Retorna o elemento na linha r e coluna c.
 * Caso não exista, retorna 0.
 **/
int getElementAtPosition (SparseMatrix * m, int r, int c) {
  if (m->rows->elements->row > r || m->columns->elements->column > c)
    return 0;

  LinkedHeadNode * currHead = m->rows, * prevHead = m->rows;
  for (; currHead != NULL && currHead->index <= r; prevHead = currHead, currHead = currHead->next);

  if (prevHead->index != r) return 0;

  LinkedElementNode * currNode = prevHead->elements, * prevNode = prevHead->elements;
  for (; currNode != NULL && currNode->column <= c; prevNode = currNode, currNode = currNode->right);

  if (prevNode->column == c) return prevNode->data;

  return 0;
}

/**
 * Retorna uma matriz resultado da operação
 * mA x mB. Caso a operação seja impossível,
 * retorna NULL.
 */
SparseMatrix * multiplyMatrix (SparseMatrix * mA, SparseMatrix * mB) {
  if (mA->numColumns != mB->numRows) return NULL;

  SparseMatrix * mResult = createSparseMatrix(mA->numRows, mB->numColumns, 0);

  int i, j, k, sum;
  for (i = 0; i < mA->numRows; i++) {
    for (j = 0; j < mB->numColumns; j++) {
      sum = 0;
      for (k = 0; k < mB->numRows; k++) {
        sum += getElementAtPosition(mA, i, k) * getElementAtPosition(mB, k, j);
      }

      insert(mResult, i, j, sum);
    }
  }

  return mResult;
}
