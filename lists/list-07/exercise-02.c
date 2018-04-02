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
int isAVL (TreeNode * t);
int height (TreeNode * t);
int balanceFactor (TreeNode * t);
void printInOrder (TreeNode * t);
void freeTree (TreeNode * t);

int main (int argc, char **argv) {
  TreeNode * treeNode = NULL;
  for (int i = 0; i < 11; i++)
    treeNode = insert(treeNode, i, i);

  TreeNode * balanced = NULL;
  int arr2[5] = {15, 4, 19, 17, 20};
  for (int i = 0; i < 5; i++)
    balanced = insert(balanced, arr2[i], arr2[i]);
  
  printInOrder(treeNode);
  printf("\n");

  printInOrder(balanced);
  printf("\n");

  printf("treeNode isAVL? %d\n", isAVL(treeNode));
  printf("balanced isAVL? %d\n", isAVL(balanced));

  freeTree(treeNode);

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

int isAVL (TreeNode * t) {
  if (t == NULL)
    return 1;

  return abs(balanceFactor(t)) <= 1 && isAVL(t->pLeft) && isAVL(t->pRight);
}

int height (TreeNode * t) {
  if (t == NULL)
    return -1;

  int hLeft = height(t->pLeft),
      hRight = height(t->pRight);

  return (hLeft > hRight ? hLeft : hRight) + 1;
}

int balanceFactor (TreeNode * t) {
  return height(t->pLeft) - height(t->pRight);
}

void printInOrder (TreeNode * t) {
  if (t == NULL)
    return;
  printInOrder(t->pLeft);
  printf("%d ", t->key);
  printInOrder(t->pRight);
}

void freeTree (TreeNode * t) {
  if (t == NULL)
    return;
  freeTree(t->pLeft);
  freeTree(t->pRight);
  free(t);
}
