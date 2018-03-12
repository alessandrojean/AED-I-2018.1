// Reference: https://stackoverflow.com/questions/69192/how-to-implement-a-queue-using-two-stacks
#include <stdio.h>
#include <stdlib.h>

#define MINCAPACITY 15

typedef struct Stack Stack;
struct Stack {
  int top;
  int capacity;
  int * data;
};

typedef struct Queue Queue;
struct Queue {
  int capacity;
  Stack * input, * output;
  int * data;
};

Queue * createQueue ();
int queueIsEmpty (Queue * queue);
int queueIsFull (Queue * queue);
int enqueue (Queue * queue, int element);
int dequeue (Queue * queue, int * element);
void printQueue (Queue * queue);
void freeQueue (Queue * queue);

int stackIsEmpty (Stack * stack, int reverse);
int push (Stack * stack, int element, int reverse);
int pop (Stack * stack, int * element, int reverse);

int main (int argc, char **argv) {
  Queue * queue = createQueue();

  for (int i = 0; i < MINCAPACITY / 3; i++)
    enqueue(queue, i + 1);

  printQueue(queue);
  printf("\nDequeuing 2 elements.\n");

  int tmp;
  for (int i = 0; i < 2; i++) {
    dequeue(queue, &tmp);
  }

  printQueue(queue);

  freeQueue(queue);

  return EXIT_SUCCESS;
}

Queue * createQueue () {
  Queue * queue = malloc(sizeof(Queue));
  if (queue == NULL)
    return NULL;

  queue->data = malloc(MINCAPACITY * sizeof(int));
  queue->input = malloc(sizeof(Stack));
  queue->output = malloc(sizeof(Stack));
  if (!queue->data || !queue->input || !queue->output) {
    free(queue->data);
    free(queue->input);
    free(queue->output);
    free(queue);
    return NULL;
  }

  queue->input->top = 0;
  queue->output->top = MINCAPACITY - 1;
  queue->input->data = queue->output->data = queue->data;
  queue->input->capacity = queue->output->capacity = queue->capacity = MINCAPACITY;

  return queue;
}

int queueIsEmpty (Queue * queue) {
  return !queue || (queue->input->top == 0 && queue->output->top == queue->capacity - 1);
}

int queueIsFull (Queue * queue) {
  return queue->output->top == -1 || queue->input->top == queue->capacity || queue->input->top -1 == queue->output->top;
}

int enqueue (Queue * queue, int element) {
  if (queueIsFull(queue))
    return 0;

  push(queue->input, element, 0);

  return queue->capacity;
}

int dequeue (Queue * queue, int * element) {
  if (queueIsEmpty(queue))
    return -1;

  // If the output it's empty, we need
  // to pop every element from input stack
  // and push to the output stack.
  if (stackIsEmpty(queue->output, 1)) {
    for (int i = 0, tmp, max = queue->input->top; i < max; i++) {
      pop(queue->input, &tmp, 0);
      push(queue->output, tmp, 1);
    }
  }

  pop(queue->output, element, 1);

  return queue->capacity;
}

void printQueue (Queue * queue) {
  for (int i = queue->output->top + 1; i < queue->capacity; i++)
    printf("%d ", queue->data[i]);
  for (int i = 0; i < queue->input->top; i++)
    printf("%d ", queue->data[i]);
  printf("\n");
}

void freeQueue (Queue * queue) {
  if (queue == NULL)
    return;

  free(queue->data);
  free(queue->input);
  free(queue->output);
  free(queue);
}

int stackIsEmpty (Stack * stack, int reverse) {
  return !stack || (reverse ? stack->top == stack->capacity - 1 : !stack->top);
}

// If reverse it's true, it'll push the element
// in the end of the array of the stack.
// The function will return 0 if the stack it's full.
int push (Stack * stack, int element, int reverse) {
  stack->data[stack->top] = element;

  if (reverse)
    return --stack->top;
  else
    return ++stack->top;
}

int pop (Stack * stack, int * element, int reverse) {
  *element = stack->data[(reverse) ? ++stack->top : --stack->top];
  return stack->top;
}
