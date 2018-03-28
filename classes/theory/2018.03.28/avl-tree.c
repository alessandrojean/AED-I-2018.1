#include <stdio.h>
#include <stdlib.h>

// Declares a tree node object for a binary tree.
typedef struct AVLTreeNode AVLTreeNode;
struct AVLTreeNode {
  int key;
  int height; // unsigned short balanceFactor;

  // Pointers to the left and right children of the node.
  AVLTreeNode *left, *right;
};

void updateHeight (AVLTreeNode * n) {
  if (!n) return;
  int hl = (n->left)  ? n->left->height  : -1, 
      hr = (n->right) ? n->right->height : -1;
  n->height =  (hl > hr ? hl : hr) + 1 ;
}

const int LEFT_HEAVY = -1, BALANCED = 0, RIGHT_HEAVY = 1;

int balanceFactor (AVLTreeNode * n) {
  if (!n) return 0;
  updateHeight(n);
  return n->left->height - n->right->height;
}

// Rotate once clockwise
void caseLLrotateRight (AVLTreeNode ** pRoot) {
  AVLTreeNode * leftChild, * p;

  p = *pRoot;
  leftChild = p->left;

  // The left subtree of p is heavy
  p->left = leftChild->right;
  leftChild->right = p;

  // The height of p and leftChild remain the same.

  // Update the root.
  *pRoot = leftChild;
}

// Rotate once counterclockwise
void caseRRrotateLeft (AVLTreeNode ** pRoot) {
  AVLTreeNode * rightChild, * p;

  p = *pRoot;
  rightChild = p->right;

  // The right subtree of p is heavy.
  p->right = rightChild->left;
  rightChild->left = p;

  // The height of p and rightChild remain the same.

  // Update the root.
  *pRoot = rightChild;
}

// Rotate twice: 1-counterclockwise 2-clockwise
void caseLRrotateLeftRight (AVLTreeNode ** pRoot) {
  AVLTreeNode * p, * leftChild, * rightgrandChild;

  p = *pRoot;
  leftChild = p->left;
  rightgrandChild = leftChild->right;

  // The left subtree of p is heavy.
  *pRoot = leftChild;

  // rotateLeft(leftChild)
  leftChild->right = rightgrandChild->left;
  rightgrandChild->left = leftChild;

  // rotateRight(p)
  p->left = rightgrandChild->right;
  rightgrandChild->right = p;

  // Update the heights.
  updateHeight(p);
  updateHeight(leftChild);
  updateHeight(rightgrandChild);

  // Update the root.
  *pRoot = rightgrandChild;
}

// Rotate twice: 1-clockwise 2-counterclockwise
void caseRLrotateRightLeft (AVLTreeNode ** pRoot) {
  AVLTreeNode * p, * rightChild, * leftgrandChild;

  p = *pRoot;
  rightChild = p->right;
  leftgrandChild = rightChild->right;

  // the right subtree of p is heavy
  *pRoot = rightChild;

  // rotateRight(rightChild)
  rightChild->left = leftgrandChild->right;
  leftgrandChild->right = rightChild;

  // rotateLeft(p)
  p->left = leftgrandChild->right;
  leftgrandChild->right = p;

  // Update the heights.
  updateHeight(p);
  updateHeight(rightChild);
  updateHeight(leftgrandChild);

  // Update the root.
  *pRoot = leftgrandChild;
}

void updateLeftTree (AVLTreeNode ** pRoot, int * reviseBalanceFactor) {
  AVLTreeNode * leftChild = (*pRoot)->left; 
  int balanceFactorChild = balanceFactor(leftChild);
  
  if (balanceFactorChild == LEFT_HEAVY) {
    // Left subtree is also heavy.
    caseLLrotateRight(pRoot); // Need a single rotation.
    *reviseBalanceFactor = 0; // false;
  }
  // Is right subtree heavy?
  else if (balanceFactorChild == RIGHT_HEAVY) {
    // Make a double rotation.
    caseLRrotateLeftRight(pRoot);
    // Root is now balanced.
    *reviseBalanceFactor = 0; // false;
  }
}

void updateRightTree (AVLTreeNode ** pRoot, int * reviseBalanceFactor) {
  AVLTreeNode * rightChild;
  rightChild = (*pRoot)->right; // Left subtree is also heavy.
  int balanceFactorChild = balanceFactor(rightChild);

  if (balanceFactorChild == RIGHT_HEAVY) {
    caseRRrotateLeft(pRoot);  // Need a single rotation.
    *reviseBalanceFactor = 0; // false;
  }
  // Is right subtree heavy?
  else if (balanceFactorChild == LEFT_HEAVY) {
    // Make a double rotation.
    caseRLrotateRightLeft(pRoot);
    // Root is now balanced.
    *reviseBalanceFactor = 0; // false;
  }
}

void insertAVL (AVLTreeNode **treeRoot, int key, int *reviseBalanceFactor) {
  if (*treeRoot == NULL) {
    // Update the root to point at newNode.
    AVLTreeNode * newNode = malloc(sizeof(AVLTreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    newNode->height = 0;
    *treeRoot = newNode;
    
    // Balance Factor must be checked!
    *reviseBalanceFactor = 1; // true;
    return;
  }
  
  if (key == (*treeRoot)->key) {
    *reviseBalanceFactor = 0; // false;
    return;
  } 

  AVLTreeNode *tree = *treeRoot;
  // Indicates a change in node's Balance Factor.
  int rebalanceCurrNode, balanceFactorOld = balanceFactor(tree);

  if (key < tree->key) { // Recursively move to the left.
    insertAVL(&tree->left, key, &rebalanceCurrNode);
    
    // Check if Balance Factor must be updated.
    if (rebalanceCurrNode) {
      // Case 3: went left from node that is already heavy
      // on the left. violates AVL condition; rotate.
      if (balanceFactorOld == LEFT_HEAVY)
        updateLeftTree(treeRoot, reviseBalanceFactor);
        
      // Case 1: inserting in the left on previously balanced 
      // node that now will be heavy on left.
      else if (balanceFactorOld == BALANCED) {
        *reviseBalanceFactor = 1; // true;
        updateHeight(*treeRoot); // Update the height.
      }
      
      // Case 2: scanning left from node heavy on the right. 
      // The node will be balanced, the height is the same.
      else *reviseBalanceFactor = 0; // false;
    } 
    
    // No balancing occurs; do not ask previous nodes.
    else *reviseBalanceFactor = 0; // false;
  }
  
  // Otherwise recursively move right.
  else {
    insertAVL(&tree->right, key, &rebalanceCurrNode);

    // check if Balance Factor must be updated.
    if (rebalanceCurrNode) {
      
      // Case 2: node becomes balanced
      if (balanceFactorOld == LEFT_HEAVY) {
        // Scanning right subtree. node heavy on left.
        // The node will become balanced.
        // The height remains the same.
        *reviseBalanceFactor = 0; // false;
      }

      // Case 1: node is initially balanced.
      else if (balanceFactorOld == BALANCED) {
        // Node is balanced; will become heavy on right.
        // tree->balanceFactor = RIGHT_HEAVY;
        *reviseBalanceFactor = 1; // true;
        
        // Update the height.
        updateHeight(*treeRoot);
      } 
      
      // Case 3: need to update node
      // scanning right from a node already heavy on
      // the right. This violates the AVL condition
      // and rotations are needed.
      else updateRightTree(treeRoot, reviseBalanceFactor);
    } 
      
    else *reviseBalanceFactor = 0; // false;
  }
}


int main (int argc, char ** argv) {
  return EXIT_SUCCESS;
}
