#include <stdio.h>
#include <stdlib.h>

#define MINCAPACITY 10

typedef struct Queue Queue;
struct Queue {
  int start, end;
  int capacity;
  int * data;
};

Queue * createQueue ();
int isEmpty (Queue * queue);
int isFull (Queue * queue);
int isAtQuarterOfCapacity (Queue * queue);
int enqueue (Queue * queue, int element);
int dequeue (Queue * stack, int * element);
int increase (Queue * queue);
int decrease (Queue * queue);
int copyToNew (Queue * queue, int * newData);
void printQueue (Queue * queue);
void freeQueue (Queue * queue);

int main (int argc, char **argv) {
  Queue * queue = createQueue();

  printf("\nEnqueuing %d elements.\n", MINCAPACITY - 1);

  for (int i = 0; i < MINCAPACITY - 1; i++) {
    enqueue(queue, i + 1);
  }

  printQueue(queue);
  printf("Capacity: %d; Start: %d; End: %d\n", queue->capacity, queue->start, queue->end);
  printf("\nEnqueuing more %d elements.\n", MINCAPACITY - 1);

  for (int i = 0; i < MINCAPACITY - 1; i++) {
    enqueue(queue, i + MINCAPACITY);
  }

  printQueue(queue);
  printf("Capacity: %d; Start: %d; End: %d\n", queue->capacity, queue->start, queue->end);
  printf("\nDequeuing %d elements.\n", 13);

  int elem;
  for (int i = 0; i < 13; i++) {
    dequeue(queue, &elem);
  }

  printQueue(queue);
  printf("Capacity: %d; Start: %d; End: %d\n", queue->capacity, queue->start, queue->end);

  freeQueue(queue);

  return EXIT_SUCCESS;
}

Queue * createQueue () {
  Queue * queue = malloc(sizeof(Queue));
  if (queue == NULL)
    return NULL;

  queue->data = malloc(MINCAPACITY * sizeof(int));
  if (queue->data == NULL) {
    free(queue);
    return NULL;
  }

  queue->start = queue->end = 0;
  queue->capacity = MINCAPACITY;
  return queue;
}

int isEmpty (Queue * queue) {
  return !queue || queue->start == queue->end;
}

int isFull (Queue * queue) {
  return (queue->end + 1) % queue->capacity == queue->start;
}

int isAtQuarterOfCapacity (Queue * queue) {
  double elements = (queue->start < queue->end) ? queue->end - queue->start : queue->start + queue->end;
  return (elements / queue->capacity) == 0.25;
}

int enqueue (Queue * queue, int element) {
  if (isFull(queue)) {
    if (increase(queue) == 0)
      return 0;
  }
  queue->data[queue->end] = element;
  queue->end = (queue->end + 1) % queue->capacity;
  return queue->end;
}

int dequeue (Queue * queue, int * element) {
  if (isEmpty(queue))
    return -1;

  *element = queue->data[queue->start];

  queue->start = (queue->start + 1) % queue->capacity;

  if (isAtQuarterOfCapacity(queue)) {
    if (decrease(queue) == 0)
      return 0;
  }

  return queue->end;
}

int increase (Queue * queue) {
  int * newData = malloc(queue->capacity * 2 * sizeof(int));
  if (newData == NULL)
    return 0;

  int t = copyToNew(queue, newData);  

  queue->capacity *= 2;
  free(queue->data);
  queue->data = newData;
  queue->start = 0;
  queue->end = t;

  return queue->capacity;
}

int decrease (Queue * queue) {
  int * newData = malloc((queue->capacity / 2) * sizeof(int));
  if (newData == NULL)
    return 0;

  int t = copyToNew(queue, newData);

  queue->capacity /= 2;
  free(queue->data);
  queue->data = newData;
  queue->start = 0;
  queue->end = t;

  return queue->capacity;
}

// Copy the old elements to the new array.
int copyToNew (Queue * queue, int * newData) {
  int i, j;
  if (queue->start > queue->end) {
    for (i = queue->start, j = 0; i < queue->capacity; i++, j++)
      newData[j] = queue->data[i];
    for (i = 0; i < queue->end; i++, j++)
      newData[j] = queue->data[i];
  } else {
    for (i = queue->start, j = 0; i < queue->end; i++, j++)
      newData[j] = queue->data[i];
  }

  return j;
}

void printQueue (Queue * queue) {
  if (isEmpty(queue))
    return;
  
  if (queue->start > queue->end) {
    for (int i = queue->start; i < queue->capacity; i++)
      printf("%d, ", queue->data[i]);
    for (int i = 0; i < queue->end; i++)
      printf("%d%s", queue->data[i], (i == queue->end - 1) ? "\n" : ", ");
  } else {
    for (int i = queue->start; i < queue->end; i++)
      printf("%d%s", queue->data[i], (i == queue->end - 1) ? "\n" : ", ");
  }
}

void freeQueue (Queue * queue) {
  if (queue == NULL)
    return;

  free(queue->data);
  free(queue);
}