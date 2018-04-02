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
AVLTreeNode * insert (AVLTreeNode * root, Key key, Value value);
AVLTreeNode * minimumValue (AVLTreeNode * t);
AVLTreeNode * delete (AVLTreeNode * t, Key key);
void printInOrder (AVLTreeNode * root);
void freeTree (AVLTreeNode * root);

int main (int argc, char ** argv) {
  AVLTreeNode * tree = NULL;
  int arr[9] = {9, 5, 10, 0, 6, 11, -1, 1, 2};
  for (int i = 0; i <= 9; i++)
    tree = insert(tree, arr[i], arr[i]);

  printInOrder(tree);
  printf("\n");

  printf("After delete root:\n");
  tree = delete(tree, 10);

  printInOrder(tree);
  printf("\n");

  freeTree(tree);

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

AVLTreeNode * insert (AVLTreeNode * t, Key key, Value value) {
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
    t->left = insert(t->left, key, value);

    if (balanceFactor(t) == 2)
      t = (key < t->left->key) ? rotateCaseLL(t) : rotateCaseLR(t);
  } else if (key > t->key) {
    t->right = insert(t->right, key, value);

    if (balanceFactor(t) == -2)
      t = (key > t->right->key) ? rotateCaseRR(t) : rotateCaseRL(t);
  } else {
    t->value = value;
    return t;
  }

  t->height = height(t);
  return t;
}

AVLTreeNode * minimumValue (AVLTreeNode * t) {
  if (t == NULL)
    return NULL;
  
  while (t->left != NULL)
    t = t->left;

  return t;
}

AVLTreeNode * delete (AVLTreeNode * t, Key key) {
  if (t == NULL)
    return NULL;

  if (key < t->key) {
    t->left = delete(t->left, key);

    if (balanceFactor(t) == -2)
      t = balanceFactor(t->right) <= 0 ? rotateCaseRR(t) : rotateCaseRL(t);
  } else if (key > t->key) {
    t->right = delete(t->right, key);

    if (balanceFactor(t) == 2)
      t = balanceFactor(t->left) >= 0 ? rotateCaseLL(t) : rotateCaseLR(t);
  } else {
    if (t->left == NULL || t->right == NULL) {
      AVLTreeNode * tmp = (t->left == NULL) ? t->right : t->left;
      free(t);
      return tmp;
    }

    AVLTreeNode * tmp = minimumValue(t->right);
    t->key = tmp->key;
    t->value = tmp->value;
    t->right = delete(t->right, tmp->key);
  }

  t->height = height(t);
  return t;
}

void printInOrder (AVLTreeNode * root) {
  if (root == NULL)
    return;

  printInOrder(root->left);
  printf("%d ", root->value);
  printInOrder(root->right);
}

void freeTree (AVLTreeNode * root) {
  if (root == NULL)
    return;

  freeTree(root->left);
  freeTree(root->right);
  free(root);
}
