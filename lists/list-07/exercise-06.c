#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * Key;
typedef int Value;

typedef struct AVLTreeNode AVLTreeNode;
struct AVLTreeNode {
  Key key;
  Value value;
  int height;
  AVLTreeNode * left, * right;
};

int height (AVLTreeNode * t);
int balanceFactor (AVLTreeNode * n);
AVLTreeNode * rotateCaseLL (AVLTreeNode * z);
AVLTreeNode * rotateCaseLR (AVLTreeNode * z);
AVLTreeNode * rotateCaseRR (AVLTreeNode * x);
AVLTreeNode * rotateCaseRL (AVLTreeNode * x);
AVLTreeNode * insert (AVLTreeNode * root, Key key, Value value);
void printInOrder (AVLTreeNode * root);
void printInOrderInFile (AVLTreeNode * root, FILE * outputFile);
void freeTree (AVLTreeNode * root);

int main (int argc, char **argv) {
  // If the user doesn't supplied the
  // needed arguments, "throw" an exception
  // and finish the program.
  if (argc != 3) {
    printf("Argumentos inválidos.\n");
    printf("Utilização correta: ./exercise-06 [arquivoEntrada] [arquivoSaída]\n");
    return EXIT_FAILURE;
  }

  printf("Lendo o arquivo: %s\n", argv[1]);

  // Open the file passed as argument in read mode.
  FILE * inputFile = fopen(argv[1], "r");
  // Create a temporary buffer to all the strings
  // that will be read from the file. I assumed
  // that the file will never have a word bigger
  // than 255 characters.
  // But, if the exercises changes, maybe
  // I need to change this to a Queue, and modify
  // the comparison in 'insert' and create
  // a method to convert a Queue to "string".
  char buff[255];
  AVLTreeNode * tree = NULL;

  // Keep reading until reaches the end of the file.
  while (fscanf(inputFile, "%s", buff) != EOF) {
    // Need to call malloc to dynamically alloc a new
    // "string", because if not, all the nodes of the
    // three will have the same reference.
    char * value = malloc(strlen(buff) * sizeof(char));
    // Need to copy the contents of buff to the new
    // "string", using the 'strcpy' from <string.h>.
    strcpy(value, buff);
    // Insert in the AVL tree.
    tree = insert(tree, value, 1);
  }

  // Closes the file opened for input data.
  fclose(inputFile);

  printf("Salvando no arquivo: %s\n", argv[2]);

  // Open the second file passed as argument in
  // write and read mode. If the file doesn't exists
  // it will be created, otherwise, his contents
  // will be overwritten.
  FILE * outputFile = fopen(argv[2], "wb+");
  printInOrderInFile(tree, outputFile);

  // Closes the file opened for output data.
  fclose(outputFile);
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

  // Because we're working with "strings",
  // the comparison need to be done with
  // an special function, in this case
  // 'strcmp' from <string.h>.
  // It returns:
  //   > 0 : if key > t->key
  //   < 0 : if key < t->key
  //     0 : if key == t->key
  int comparison = strcmp(key, t->key);

  if (comparison < 0) {
    t->left = insert(t->left, key, value);

    if (balanceFactor(t) == 2)
      t = (strcmp(key, t->left->key) < 0) ? rotateCaseLL(t) : rotateCaseLR(t);
  } else if (comparison > 0) {
    t->right = insert(t->right, key, value);

    if (balanceFactor(t) == -2)
      t = (strcmp(key, t->right->key) > 0) ? rotateCaseRR(t) : rotateCaseRL(t);
  } else {
    t->value++;
    return t;
  }

  t->height = height(t);
  return t;
}

void printInOrder (AVLTreeNode * root) {
  if (root == NULL)
    return;

  printInOrder(root->left);
  printf("%s %d\n", root->key, root->value);
  printInOrder(root->right);
}

void printInOrderInFile (AVLTreeNode * root, FILE * outputFile) {
  if (root == NULL)
    return;

  printInOrderInFile(root->left, outputFile);
  fprintf(outputFile, "%s %d\n", root->key, root->value);
  printInOrderInFile(root->right, outputFile);
}

void freeTree (AVLTreeNode * root) {
  if (root == NULL)
    return;

  freeTree(root->left);
  freeTree(root->right);
  free(root);
}
