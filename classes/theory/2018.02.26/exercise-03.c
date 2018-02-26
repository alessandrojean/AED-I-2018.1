#include <stdio.h>
#include <stdlib.h>

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
  int data;
  DLinkedNode * prev;
  DLinkedNode * next;
};

// 0: igual.
// 1: seq1 é maior.
// 2: seq2 é maior.
int cmp (DLinkedNode * seq1, DLinkedNode * seq2) {
  DLinkedNode * curr1 = seq1;
  DLinkedNode * curr2 = seq2;

  while (curr1 != NULL && curr2 != NULL) {
    if (curr1->data > curr2->data)
      return 1;
    else if (curr2->data > curr1->data)
      return 2;

    curr1 = curr1->next;
    curr2 = curr2->prev;
  }

  if (curr1 != NULL && curr2 == NULL)
    return 1;

  if (curr2 != NULL && curr1 == NULL)
    return 2;

  return 0;
}

DLinkedNode * appendNodeD (DLinkedNode * last, int num) {
  DLinkedNode * tmp = malloc(sizeof(DLinkedNode));
  if (tmp == NULL)
    return NULL;

  tmp->data = num;
  tmp->prev = last;
  tmp->next = NULL;

  if (last != NULL)
    last->next = tmp;

  return tmp;
}

DLinkedNode * lerSeq (DLinkedNode ** last) {
  DLinkedNode * first = NULL;
  *last = NULL;

  int item1, item2;
  scanf("%d", &item1);
  scanf("%d", &item2);

  int num;
  while (1) {
    scanf("%d", &num);

    if (num == 0 && item1 == 0 && item2 == 0)
      return first;

    *last = appendNodeD(*last, item1);
    if (first == NULL)
      first = *last;

    item1 = item2;
    item2 = num;
  }
}

void printSeq(DLinkedNode * seq) {
  printf("( ");
  DLinkedNode * curr = seq;
  while (curr != NULL) {
    printf("%d%s", curr->data, curr->next == NULL ? " " : ", ");
    curr = curr->next;
  }
  printf(")\n");
}


int main (int argc, char **argv) {
  DLinkedNode * seq1, * seq2;
  DLinkedNode * last1, * last2;

  printf("\nEntre com a primeira sequência\n");
  seq1 = lerSeq(&last1);
  printSeq(seq1);

  printf("\nEntre com a segunda sequência\n");
  seq2 = lerSeq(&last2);
  printSeq(seq2);

  // Saída.
  int n = cmp(seq1, last2);
  printf("%d\n", n);

  return EXIT_SUCCESS;
}
