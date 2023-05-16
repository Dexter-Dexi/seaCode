#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int *arr = (int *)malloc(sizeof(int));
  arr[0] = 10;
  arr[1] = 4;
  arr[2] = 8;
  printf("%d\n", arr[0]);
  printf("%d\n", arr[1]);
  printf("%d\n", arr[2]);
  printf("%d\n", arr[3]);
  return 0;
}
