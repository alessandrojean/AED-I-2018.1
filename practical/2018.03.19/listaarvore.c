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

TreeNode * insertInTree (TreeNode * t, Key key, Value value);
TreeNode * searchInTree (TreeNode * t, Key key, int * counter);
void freeTree (TreeNode * t);

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  Value value;
  LinkedNode * next;
};

void insertInList (LinkedNode ** list, Value value);
LinkedNode * searchInList (LinkedNode * list, Value value, int * counter);
void freeList (LinkedNode * list);

int main (int argc, char **argv) {
  LinkedNode * list = NULL;
  TreeNode * tree = NULL;

  int ra, counterList = 0, counterTree = 0;
  char op;
  while (1) {
    scanf("%c %d", &op, &ra);
    if (ra == 0 && op == 'P')
      break;

    if (op == 'I') {
      tree = insertInTree(tree, ra, ra);
      insertInList(&list, ra);
    } else if (op == 'B') {
      searchInTree(tree, ra, &counterTree);
      searchInList(list, ra, &counterList);
      printf("L=%d A=%d\n", counterList, counterTree);
    }
    counterList = counterTree = 0;
  }

  freeTree(tree);
  freeList(list);

  return EXIT_SUCCESS;
}

TreeNode * insertInTree (TreeNode * t, Key key, Value value) {
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
    t->pLeft = insertInTree(t->pLeft, key, value);
  else if (key > t->key)
    t->pRight = insertInTree(t->pRight, key, value);
  else
    t->value = value;
  return t;
}

TreeNode * searchInTree (TreeNode * t, Key key, int * counter) {
  if (t == NULL) {
    return NULL;
  }

  if (t->key == key) {
    (*counter)++;
    return t;
  }

  (*counter)++;
  if (t->key < key) {
    return searchInTree(t->pRight, key, counter);
  }

  return searchInTree(t->pLeft, key, counter);
}

void printTreeInOrder (TreeNode * t) {
  if (t == NULL)
    return;
  printTreeInOrder(t->pLeft);
  printf("%d ", t->key);
  printTreeInOrder(t->pRight);
}

void freeTree (TreeNode * t) {
  if (t == NULL)
    return;

  freeTree(t->pLeft);
  freeTree(t->pRight);
  free(t);
}

void insertInList (LinkedNode ** list, Value value) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
    if (tmp == NULL)
      return;

  tmp->value = value;

  if (*list == NULL) {
    tmp->next = NULL;
    *list = tmp;
    return;
  }

  if ((*list)->value > value) {
    tmp->next = *list;
    *list = tmp;
    return;
  }

  LinkedNode * prev, * curr;
  for (curr = *list; curr != NULL && curr->value <= value; prev = curr, curr = curr->next);

  if (prev->value != value) {
    tmp->next = prev->next;
    prev->next = tmp;
  }
  return;
}

LinkedNode * searchInList (LinkedNode * list, Value value, int * counter) {
  if (list != NULL && list->value > value) {
    *counter = 1;
    return NULL;
  }

  LinkedNode * prev;
  for (; list != NULL && list->value <= value; (*counter)++, prev = list, list = list->next);
  if (prev->value != value && prev->next != NULL)
    (*counter)++;

  return prev;
}

void printList (LinkedNode * list) {
  for (; list != NULL; list = list->next)
    printf("%d ", list->value);
  printf("\n");
}

void freeList (LinkedNode * list) {
  LinkedNode * next;
  for(; list != NULL; list = next) {
    next = list->next;
    free(list);
  }
}
