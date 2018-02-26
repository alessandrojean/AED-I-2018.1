#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
  int data;
  LinkedNode * next;
};

// 0: igual.
// 1: seq1 é maior.
// 2: seq2 é maior.
int cmp (LinkedNode * seq1, LinkedNode * seq2) {
  LinkedNode * curr1 = seq1;
  LinkedNode * curr2 = seq2;

  while (curr1 != NULL && curr2 != NULL) {
    if (curr1->data > curr2->data)
      return 1;
    else if (curr2->data > curr1->data)
      return 2;

    curr1 = curr1->next;
    curr2 = curr2->next;
  }

  if (curr1 != NULL && curr2 == NULL)
    return 1;

  if (curr2 != NULL && curr1 == NULL)
    return 2;

  return 0;
}

LinkedNode * appendNode (LinkedNode * last, int num) {
  if (last != NULL && last->next != NULL)
    return NULL;

  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (tmp == NULL)
    return NULL;

  tmp->data = num;
  tmp->next = NULL;

  if (last != NULL)
    last->next = tmp;

  return tmp;
}

LinkedNode * insertFirst (LinkedNode * first, int num) {
  LinkedNode * tmp = malloc(sizeof(LinkedNode));
  if (tmp == NULL)
    return NULL;

  tmp->data = num;
  tmp->next = first;
  return tmp;
}

// mode = 1 lista1
// mode = 2 lista2
LinkedNode * lerSeq (int mode) {
  LinkedNode * first = NULL;
  LinkedNode * last = NULL;

  int item1, item2;
  scanf("%d", &item1);
  scanf("%d", &item2);

  int num;
  while (1) {
    scanf("%d", &num);

    if (num == 0 && item1 == 0 && item2 == 0)
      return first;

    if (mode == 1) {
      last = appendNode(last, item1);
      if (first == NULL)
        first = last;
    } else {
      first = insertFirst(first, item1);
    }

    item1 = item2;
    item2 = num;
  }
}

void printSeq(LinkedNode * seq) {
  printf("( ");
  LinkedNode * curr = seq;
  while (curr != NULL) {
    printf("%d%s", curr->data, curr->next == NULL ? " " : ", ");
    curr = curr->next;
  }
  printf(")\n");
}


int main (int argc, char **argv) {
  LinkedNode * seq1, * seq2;

  printf("\nEntre com a primeira sequência\n");
  seq1 = lerSeq(1);
  printSeq(seq1);

  printf("\nEntre com a segunda sequência\n");
  seq2 = lerSeq(2);
  printSeq(seq2);

  // Saída.
  int n = cmp(seq1, seq2);
  printf("%d\n", n);

  return EXIT_SUCCESS;
}
