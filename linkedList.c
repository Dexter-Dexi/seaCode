#include <stdio.h>
#include <stdlib.h>

static int ID_COUNT = 0;
typedef struct Node {
  int key, data;
  Node *next;
} Node;

typedef struct {
  Node *head;
} linkedList;

// void init(Node *);
void init(Node *, int);
void append(linkedList *, Node *);
void printList(linkedList *);
void printNodes(Node *);
Node *exist(int, linkedList *);
void insert(int, Node *, linkedList *);
void remove(int, linkedList *);

int main(int argc, char const *argv[]) {
  linkedList *List = (linkedList *)malloc(sizeof(linkedList));
  List->head = NULL;
  /*
     Node *node1 = (Node *)malloc(sizeof(Node *));
    Node *node2 = (Node *)malloc(sizeof(Node *));
    Node *node3 = (Node *)malloc(sizeof(Node *));
    Node *node4 = (Node *)malloc(sizeof(Node *));
    init(node4, 29);
    init(node1, 15);
    init(node2, 7);
    init(node3, -17);
    append(List, node4);
    append(List, node1);
    append(List, node2);
    printList(List);
    insert(1, node3, List);
    printList(List);
    remove(3, List);
    printList(List);
    free(node1);
    free(node1);
    free(node1);
    free(node1);
    // printf("%d", exist(1, List));
   */
  Node *n1 = (Node *)malloc(sizeof(Node));
  init(n1, 77);
  append(List, n1);
  printList(List);
  free(List);
  return 0;
}

void init(Node *node) {
  node->key = ++ID_COUNT;
  node->data = 0;
  node->next = NULL;
}
void init(Node *node, int data) {
  node->key = ++ID_COUNT;
  node->data = data;
  node->next = NULL;
}
Node *exist(int key, linkedList *List) {
  Node *ptr = List->head;
  while (ptr != NULL) {
    if (ptr->key == key)
      return ptr;
    else
      ptr = ptr->next;
  }
  return ptr;
}
void append(linkedList *list, Node *node) {
  if (list->head != NULL) {
    Node *ptr = list->head;
    while (ptr->next)
      ptr = ptr->next;
    ptr->next = node;
    printf("node appended\n");
  } else {
    list->head = node;
    printf("Head Appointed\n");
  }
}
void printList(linkedList *List) {
  Node *ptr = List->head;
  while (ptr) {
    printf("(%d , %d)  -->  ", ptr->key, ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}
void printNodes(Node *List) {
  printf("inside print %x\n", List->next);
  Node *ptr = List;
  while (ptr) {
    printf("(%d , %d)  -->  ", ptr->key, ptr->data);
    ptr = ptr->next;
  }
}

void insert(int key, Node *node, linkedList *list) {
  if (list->head != NULL) {
    Node *ptr = exist(key, list);
    if (ptr) {
      Node *temp = ptr->next;
      ptr->next = node;
      node->next = temp;
      printf("node inserted \n");
    } else
      printf("node with key %d not found\n", key);
  } else {
    list->head = node;
    printf("Head appointed\n");
  }
}
void remove(int key, linkedList *List) {
  Node *ptr = exist(key, List);
  if (ptr) {
    Node *temp = List->head;
    while (temp->next->key != key) {
      temp = temp->next;
    }
    temp->next = temp->next->next;
    printf("node remved\n");
    return;
  }
  printf("node not found\n");
}