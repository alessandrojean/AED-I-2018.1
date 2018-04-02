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
TreeNode * search (TreeNode * t, Key key);
TreeNode * rotateRight (TreeNode * root);
TreeNode * rotateLeft (TreeNode * root);
TreeNode * makeNewRoot (TreeNode * A, Key key);
TreeNode * findParent (TreeNode * root, Key key);
void printInOrder (TreeNode * t);
void freeTree (TreeNode * t);

int main (int argc, char **argv) {
  TreeNode * treeNode = NULL;
  int arr[10] = {4, 20, 17, 19, 1, 8, 25, 12, 28, 2};
  for (int i = 0; i < 10; i++)
    treeNode = insert(treeNode, arr[i], arr[i]);
  
  printInOrder(treeNode);
  printf("\n");

  treeNode = makeNewRoot(treeNode, 12);

  printInOrder(treeNode);
  printf("\n");

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

TreeNode * search (TreeNode * t, Key key) {
  if (t == NULL)
    return NULL;

  if (t->key == key)
    return t;

  if (t->key < key - 1)
    return search(t->pRight, key);

  return search(t->pLeft, key);
}

/**
 * Right rotation.
 * In this illustration, the new node will be '2'.
 *
 *     5                2
 *    / \              / \ 
 *   2   C     =>     A   5
 *  / \                  / \ 
 * A   B                B   C
 **/
TreeNode * rotateRight (TreeNode * root) {
  TreeNode * pivot = root->pLeft;
  root->pLeft = pivot->pRight;
  pivot->pRight = root;

  return pivot;  
}

/**
 * Left rotation.
 * In this illustration, the new node will be '7'.
 *
 *   5                    7
 *  / \                  / \ 
 * A   7       =>       5   C
 *    / \              / \ 
 *   B   C            A   B
 **/
TreeNode * rotateLeft (TreeNode * root) {
  TreeNode * pivot = root->pRight;
  root->pRight = pivot->pLeft;
  pivot->pLeft = root;

  return pivot;
}

/**
 * Make the node with the key specified the
 * new root of the BST A. If the node it's
 * not present, it will be added to A.
 * 
 * References:
 * https://stackoverflow.com/questions/30475115/given-a-bst-and-a-node-in-bst-make-that-node-as-new-root-of-the-tree
 * https://en.wikipedia.org/wiki/Tree_rotation
 **/
TreeNode * makeNewRoot (TreeNode * A, Key key) {
  // If an element with the key it's not in the
  // tree, we need to insert it first.
  if (search(A, key) == NULL)
    A = insert(A, key, key);

  TreeNode * root = NULL, * newRoot, * rootParent;

  // Keep running while the key of the root
  // it's not the key wanted.
  while (A->key != key) {
    // Find the parent of the node with the key.
    root = findParent(A, key);
    // Rotate the sub-tree where the node with the key
    // is the pivot with it's parent.
    newRoot = (key > root->key) ? rotateLeft(root) : rotateRight(root);
    // Find the parent of the parent of the node with the key.
    rootParent = findParent(A, root->key);

    // If the parent exists, need to change 
    // the old subtree to the new sub-tree,
    // that is now the pivot.
    if (rootParent) {
      if (rootParent->pLeft == root)
        rootParent->pLeft = newRoot;
      else
        rootParent->pRight = newRoot;
    } 
    
    // If doesn't exists, the loop reached
    // the root, so it's just replace it 
    // by the pivot.
    else A = newRoot;
  }

  return A;
}

TreeNode * findParent (TreeNode * root, Key key) {
  if (root->key == key)
    return NULL;

  TreeNode * parent = root;
  while (root != NULL) {
    if (root->key == key)
      return parent;
    else if (root->key > key) {
      parent = root;
      root = root->pLeft;
    } else {
      parent = root;
      root = root->pRight;
    }
  }

  return NULL;
}

void printInOrder (TreeNode * t) {
  if (t == NULL)
    return;
  printInOrder(t->pLeft);
  printf("%d ", t->key);
  printInOrder(t->pRight);
}

void freeTree (TreeNode * root) {
  if (root == NULL)
    return;

  freeTree(root->pLeft);
  freeTree(root->pRight);
  free(root);
}

