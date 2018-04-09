#include <stdio.h>
#include <stdlib.h>

typedef int Key;
typedef int Value;

typedef struct TreeNode TreeNode;
struct TreeNode {
  Key key;
  Value value;
  TreeNode * pLeft, * pRight;
};

TreeNode * insert (TreeNode * t, Key key, Value value);
TreeNode * minimumValue (TreeNode * t);
TreeNode * searchIterative (TreeNode * t, Key key, int * counter);
TreeNode * delete (TreeNode * t, Key key);
int height (TreeNode * t);
void freeTree (TreeNode * t);

int main (int argc, char **argv) {
  TreeNode * root = NULL, * tmp;
  int ra, nota, counter;

  char p;
  scanf("\n%c", &p);
  while (p != 'P') {
    if (p == 'I') {
      scanf("%d %d", &ra, &nota);
      tmp = insert(root, ra, nota);
      if (root == NULL)
        root = tmp;
    } else if (p == 'R') {
      scanf("%d", &ra);
      root = delete(root, ra);
    } else if (p == 'B') {
      scanf("%d", &ra);
      tmp = searchIterative(root, ra, &counter);
      printf("C=%d Nota=%d\n", counter, tmp == NULL ? -1 : tmp->value);
    } else if (p == 'A') {
      printf("A=%d\n", height(root));
    }

    scanf("\n%c", &p);
  }

  freeTree(root);

  return EXIT_SUCCESS;
}

TreeNode * insert (TreeNode * t, Key key, Value value) {
  if (t == NULL) {
    TreeNode * tmp = malloc(sizeof(TreeNode));
    if (tmp != NULL) {
      tmp->key = key;
      tmp->value = value;
      tmp->pRight = tmp->pLeft = NULL;
    }
    return tmp;
  }

  if (key < t->key)
    t->pLeft = insert(t->pLeft, key, value);
  else if (key > t->key)
    t->pRight = insert(t->pRight, key, value);
  else
    t->value = value;
  return t;
}

TreeNode * minimumValue (TreeNode * t) {
  if (t == NULL)
    return NULL;
  
  while (t->pLeft != NULL)
    t = t->pLeft;

  return t;
}

TreeNode * searchIterative (TreeNode * t, Key key, int * counter) {
  *counter = 0;
  while (t != NULL && ++(*counter)) {
    if (t->key == key)
      return t;
    if (t->key < key)
      t = t->pRight;
    else
      t = t->pLeft;
  }

  return NULL;
}

TreeNode * delete (TreeNode * t, Key key) {
  if (t == NULL)
    return NULL;

  if (key < t->key)
    t->pLeft = delete(t->pLeft, key);
  else if (key > t->key)
    t->pRight = delete(t->pRight, key);
  else {
    if (t->pLeft == NULL || t->pRight == NULL) {
      TreeNode * tmp = (t->pLeft == NULL) ? t->pRight : t->pLeft;
      free(t);
      return tmp;
    }

    TreeNode * tmp = minimumValue(t->pRight);
    t->key = tmp->key;
    t->value = tmp->value;
    t->pRight = delete(t->pRight, tmp->key);
  }

  return t;
}

int height (TreeNode * t) {
  if (t == NULL)
    return -1;

  int hRight = height(t->pRight),
      hLeft = height(t->pLeft);

  return (hRight > hLeft ? hRight : hLeft) + 1;
}

void freeTree (TreeNode * t) {
  if (t == NULL)
    return;

  freeTree(t->pLeft);
  freeTree(t->pRight);
  free(t);
}
