#include <stdio.h>
#define CAPACITY 100

typedef struct {
  int data[CAPACITY], SIZE;
} Stack;
void init(Stack *);
int isEmpty(Stack *);
int isFull(Stack *);
void push(Stack *, int);
int pop(Stack *);
void print(Stack *);

int main(int argc, char const *argv[]) {
  Stack s1;
  init(&s1);
  printf("%d ,", isEmpty(&s1));
  push(&s1, 13);
  push(&s1, 20);
  push(&s1, 9);
  // printf("%d", pop(&s1));
  // printf("%d ", pop(&s1));
  // printf("%d ", pop(&s1));
  print(&s1);

  return 0;
}
void init(Stack *s) {
  for (int i = 0; i < CAPACITY; i++)
    s->data[i] = 0;
  s->SIZE = 0;
}
int isEmpty(Stack *s) { return (s->SIZE == 0); }
int isFull(Stack *s) { return (s->SIZE == CAPACITY); }
void push(Stack *s, int d) {
  if (isFull(s))
    printf("Stack overflow \n");
  else
    s->data[s->SIZE++] = d;
}
int pop(Stack *s) {
  if (isEmpty(s))
    return -1;
  else
    return s->data[--s->SIZE];
}
void print(Stack *s) {
  for (size_t i = 0; i < s->SIZE; i++)
    printf("%d  ", s->data[i]);
}
