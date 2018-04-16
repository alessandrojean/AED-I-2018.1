#include <stdio.h>
#include <stdlib.h>

typedef int Key;
typedef int Value;

typedef struct AVLTreeNode AVLTreeNode;
struct AVLTreeNode {
  Key key;
  Value value;
  int height;
  AVLTreeNode *left, *right;
};

int height (AVLTreeNode * t);
int balanceFactor (AVLTreeNode * n);
AVLTreeNode * rotateCaseLL (AVLTreeNode * z);
AVLTreeNode * rotateCaseLR (AVLTreeNode * z);
AVLTreeNode * rotateCaseRR (AVLTreeNode * x);
AVLTreeNode * rotateCaseRL (AVLTreeNode * x);
AVLTreeNode * insert (AVLTreeNode * root, Key key, Value value, int * balanceCount);
AVLTreeNode * searchIterative (AVLTreeNode * t, Key key, int * counter);
AVLTreeNode * minimumValue (AVLTreeNode * t);
AVLTreeNode * delete (AVLTreeNode * t, Key key, int * balanceCount);
void printTree (AVLTreeNode * root);
void printPostOrder (AVLTreeNode * root);
void printRotation (char rotation[2], int node, int x, int y, int z);
void freeTree (AVLTreeNode * root);

int main (int argc, char ** argv) {
  AVLTreeNode * root = NULL, * tmp;
  int ra, nota, counter, balance;

  char p;
  scanf("\n%c", &p);
  while (p != 'P') {
    if (p == 'I') {
      scanf("%d %d", &ra, &nota);
      balance = 0;
      root = insert(root, ra, nota, &balance);
      if (!balance)
        printf("[Ja esta balanceado]\n");
    } else if (p == 'R') {
      scanf("%d", &ra);
      balance = 0;
      root = delete(root, ra, &balance);
      if (!balance)
        printf("[Ja esta balanceado]\n");
    } else if (p == 'B') {
      scanf("%d", &ra);
      tmp = searchIterative(root, ra, &counter);
      printf("C=%d Nota=%d\n", counter, tmp == NULL ? -1 : tmp->value);
    } else if (p == 'A') {
      printf("A=%d\n", !root ? -1 : root->height);
    }

    scanf("\n%c", &p);
  }

  printTree(root);
  freeTree(root);

  return EXIT_SUCCESS;
}

int height (AVLTreeNode * t) {
  if (t == NULL)
    return -1;

  int hRight = height(t->right),
      hLeft = height(t->left);

  return (hRight > hLeft ? hRight : hLeft) + 1;
}

int balanceFactor (AVLTreeNode * n) {
  if (!n) return 0;
  n->height = height(n);
  return height(n->left) - height(n->right);
}

// Rotate to Right, case LL.
AVLTreeNode * rotateCaseLL (AVLTreeNode * z) {
  AVLTreeNode * y = z->left;
  z->left = y->right;
  y->right = z;

  return y;
}

// Rotate to Left, case RR.
AVLTreeNode * rotateCaseRR (AVLTreeNode * x) {
  AVLTreeNode * y = x->right;
  x->right = y->left;
  y->left = x;

  return y;
}

AVLTreeNode * rotateCaseLR (AVLTreeNode * z) {
  z->left = rotateCaseRR(z->left);
  AVLTreeNode * y = rotateCaseLL(z);

  z->height = height(z);
  y->left->height = height(y->left);
  y->height = height(y);

  return y;
}

AVLTreeNode * rotateCaseRL (AVLTreeNode * x) {
  x->right = rotateCaseLL(x->right);
  AVLTreeNode * y = rotateCaseRR(x);

  x->height = height(x);
  y->right->height = height(y->right);
  y->height = height(y);

  return y;
}

AVLTreeNode * insert (AVLTreeNode * t, Key key, Value value, int * balanceCount) {
  if (t == NULL) {
    AVLTreeNode * tmp = malloc(sizeof(AVLTreeNode));
    if (!tmp) return NULL;

    tmp->key = key;
    tmp->value = value;
    tmp->left = tmp->right = NULL;
    tmp->height = 0;

    return tmp;
  }

  if (key < t->key) {
    t->left = insert(t->left, key, value, balanceCount);


    if (balanceFactor(t) == 2) {
      (*balanceCount)++;
      if (key < t->left->key) {
        printRotation("SD", t->key, t->left->left->key, t->left->key, t->key);
        t = rotateCaseLL(t);
      } else {
        printRotation("DD", t->key, t->left->key, t->left->right->key, t->key);
        t = rotateCaseLR(t);
      }
    }
  } else if (key > t->key) {
    t->right = insert(t->right, key, value, balanceCount);

    if (balanceFactor(t) == -2) {
      (*balanceCount)++;
      if (key > t->right->key) {
        printRotation("SE", t->key, t->key, t->right->key, t->right->right->key);
        t = rotateCaseRR(t);
      } else {
        printRotation("DE", t->key, t->key, t->right->left->key, t->right->key);
        t = rotateCaseRL(t);
      }
    }
  } else {
    t->value = value;
    return t;
  }

  t->height = height(t);
  return t;
}

AVLTreeNode * searchIterative (AVLTreeNode * t, Key key, int * counter) {
  *counter = 0;
  while (t != NULL && ++(*counter)) {
    if (t->key == key)
      return t;
    if (t->key < key)
      t = t->right;
    else
      t = t->left;
  }

  return NULL;
}

AVLTreeNode * minimumValue (AVLTreeNode * t) {
  if (t == NULL)
    return NULL;
  
  while (t->left != NULL)
    t = t->left;

  return t;
}

AVLTreeNode * delete (AVLTreeNode * t, Key key, int * balanceCount) {
  if (t == NULL)
    return NULL;

  if (key < t->key) {
    t->left = delete(t->left, key, balanceCount);
  } else if (key > t->key) {
    t->right = delete(t->right, key, balanceCount);
  } else {
    if (t->left == NULL || t->right == NULL) {
      AVLTreeNode * tmp = (t->left == NULL) ? t->right : t->left;
      free(t);
      return tmp;
    }

    AVLTreeNode * tmp = minimumValue(t->right);
    t->key = tmp->key;
    t->value = tmp->value;
    t->right = delete(t->right, tmp->key, balanceCount);
  }

  int bf = balanceFactor(t);
  if (bf == -2 || bf == 2)
    (*balanceCount)++;

  if (bf == -2) {
    if (balanceFactor(t->right) <= 0) {
      printRotation("SE", t->key, t->key, t->right->key, t->right->right->key);
      t = rotateCaseRR(t);
    } else {
      printRotation("DE", t->key, t->key, t->right->left->key, t->right->key);
      t = rotateCaseRL(t);
    }
  } else if (bf == 2) {
    if (balanceFactor(t->left) >= 0) {
      printRotation("SD", t->key, t->left->left->key, t->left->key, t->key);
      t = rotateCaseLL(t);
    } else {
      printRotation("DD", t->key, t->left->key, t->left->right->key, t->key);
      t = rotateCaseLR(t);
    }
  }

  t->height = height(t);
  return t;
}

void printRotation (char rotation[2], int node, int x, int y, int z) {
  printf("[No desbalanceado: %d]\n", node);
  printf("[Rotacao: %s]\n", rotation);
  printf("[x=%d y=%d z=%d]\n", x, y, z);
}

void printTree (AVLTreeNode * root) {
  if (!root) {
    printf("[]\n");
    return;
  }

  printf("[");
  printPostOrder(root);
  printf("]\n");
}

void printPostOrder (AVLTreeNode * root) {
  if (root == NULL)
    return;

  printPostOrder(root->left);
  printPostOrder(root->right);
  printf("%d ", root->key);
}

void freeTree (AVLTreeNode * root) {
  if (root == NULL)
    return;

  freeTree(root->left);
  freeTree(root->right);
  free(root);
}
