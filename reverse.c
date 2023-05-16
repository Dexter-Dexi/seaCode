// #include <algorithm>
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void reverse1(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      swap(&arr[j], &arr[j + 1]);
    }
  }
}
void reverse2(int arr[], int size) {
  int i, j, temp, temp2 = arr[size - 1];
  for (i = 0; i < size - 1; i++) {
    temp = arr[0];
    for (j = 0; j < size - i - 1; j++) {
      arr[j - 1] = arr[j];
    }
    arr[size - i - 1] = temp;
  }
  arr[0] = temp2;
}
void print(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d  ", arr[i]);
  }
  printf("\n");
}
void input(int *arr, int size) {
  printf("enter the array elements: ");
  for (int i = 0; i < size; i++) {
    printf("enter the a1rray elements %d : ", i + 1);
    scanf("%d ", &arr[i]);
  }
}
int main() {
  int size, arr[5];
  size = sizeof(arr) / sizeof(int);
  input(arr, size);
  print(arr, size);
  reverse1(arr, size);
  print(arr, size);
  return 0;
}