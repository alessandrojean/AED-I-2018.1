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

void printInOrder (TreeNode * t);
TreeNode * insert (TreeNode * t, Key key, Value value);
TreeNode * minimumValue (TreeNode * t);
TreeNode * delete (TreeNode * t, Key key);

int main (int argc, char **argv) {
  TreeNode * treeNode = insert(NULL, 15, 15);
  int arr[10] = {4, 20, 17, 19, 1, 8, 25, 12, 28, 2};
  for (int i = 0; i < 10; i++)
    insert(treeNode, arr[i], arr[i]);
  
  printInOrder(treeNode);
  printf("\n");

  TreeNode * minimum = minimumValue(treeNode);
  printf("Minimum value: %d\n", minimum->key);

  treeNode = delete(treeNode, 15);

  printInOrder(treeNode);
  printf("\n");

  return EXIT_SUCCESS;
}

void printInOrder (TreeNode * t) {
  if (t == NULL)
    return;
  printInOrder(t->pLeft);
  printf("%d ", t->key);
  printInOrder(t->pRight);
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