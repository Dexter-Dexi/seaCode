#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct {
  int front, rear;
  int data[SIZE];
} Queue;

void init(Queue *);

int isEmpty(Queue *);
int isFull(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *q);

void print(Queue *q);
int size(Queue *q);

int main(int argc, char const *argv[]) {
  Queue q;
  init(&q);
  enqueue(&q, 12);
  enqueue(&q, 3);
  print(&q);
  enqueue(&q, 7);
  enqueue(&q, 10);
  enqueue(&q, 0);
  print(&q);

  printf("DQ = %d\n", dequeue(&q));
  printf("is empty: %d\n", isEmpty(&q));
  // enqueue(&q, 15);
  print(&q);
  return 0;
}

void init(Queue *q) {
  q->front = q->rear = -1;
  for (size_t i = 0; i < SIZE; i++)
    q->data[i] = 0;
}

int isEmpty(Queue *q) { return (q->rear == -1 && q->front == -1); }
int isFull(Queue *q) {
  //  return (q->rear == SIZE - 1);
  return ((q->rear + 1) % SIZE == q->front);
}
void enqueue(Queue *q, int d) {
  if (isFull(q))
    printf("Q overflow \n");
  else if (isEmpty(q))
    q->rear = q->front = 0;
  else {
    // q->rear++;
    q->rear = (q->rear + 1) % SIZE;
  }
  q->data[q->rear] = d;
}
int dequeue(Queue *q) {
  if (isEmpty(q))
    return -1;
  else if (q->rear == q->front) {
    int temp = q->data[q->front];
    q->rear = q->front = -1;
    return temp;
  } else
    return q->data[q->front++];
}
void print(Queue *q) {
  for (size_t i = q->front; i < size(q); i++)
    printf("%d  ", q->data[i]);
  printf("\n");
}
int size(Queue *q) { return q->rear - q->front + 1; }
