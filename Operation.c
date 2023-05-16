#include <stdio.h>
int main(int argc, char const *argv[]) {
  int num1, num2, result;
  char op;
  printf("enter the fiest number: ");
  scanf("%d", &num1);
  printf("enter the second number: ");
  scanf("%d", &num2);
  printf("enter the sing: ");
  scanf(" %c", &op);
  switch (op) {
  case '+':
    result = num1 + num2;
    break;
  case '-':
    result = num1 - num2;
    break;
  case '*':
    result = num1 * num2;
    break;
  case '/':
    result = num1 / num2;
    break;
  case '%':
    result = num1 % num2;
    break;
  default:
    break;
  }
  printf("%d %c %d = %d \n", num1, op, num2, result);
  return 0;
}
