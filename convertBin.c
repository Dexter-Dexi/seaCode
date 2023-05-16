#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char rem[100];
int count = 0;
int ToDecConv(int, int);
void FromDecConv(int, int);
int hex_dec();
void Dec_Hex(int);
void swap(char *, char *);
void print();
void reverse();

int main() {
  int num;
  char choice;
  do {
    printf("\n + ----------------------- +\n | Select an operation :-  |\n + "
           "----------------------- +\n\n 1 - Binary to Decimal Conversion\n 2 "
           "- Octal to Decimal Conversion\n 3 - Decimal to Binary Conversion\n "
           "4 - Decimal to Octal Conversion\n 5 - Decimal to Hexadecimal "
           "Conversion\n 6 - Hexadecimal to Decimal Conversion\n  ");
    scanf(" %c", &choice);
    switch (choice) {
    case '1':
      printf("Enter a number:");
      scanf("%d", &num);
      printf("the Decimal value is: %d\n", ToDecConv(num, 2));
      break;
    case '2':
      printf("Enter a number:");
      scanf("%d", &num);
      printf("the Decimal value is: %d\n", ToDecConv(num, 8));
      break;
    case '3':
      printf("Enter a number:");
      scanf("%d", &num);
      FromDecConv(num, 2);
      print();
      break;
    case '4':
      printf("Enter a number:");
      scanf("%d", &num);
      FromDecConv(num, 8);
      print();
      break;
    case '5':
      printf("Enter a number:");
      scanf("%d", &num);
      Dec_Hex(num);
      reverse();
      print();
      break;
    case '6':
      printf("Enter a number:");
      gets(rem);
      printf("the Decimal value is: %d\n", hex_dec());
      break;
    default:
      printf("Something went wrong\n");
    }
    printf("Want to try again ? [y or n] :  ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
      system("cls");
    else
      exit(0);
  } while (choice == 'y' || choice == 'Y');
  return 0;
}

int ToDecConv(int num, int base) {
  int result = 0, counter = 0;
  while (num != 0) {
    int last_digit = num % 10;
    result += last_digit * pow(base, counter);
    num /= 10;
    counter++;
  }
  return result;
}
void FromDecConv(int num, int base) {
  if (num != 0) {
    while (num != 0) {
      rem[count++] = (num % base) + 48;
      num /= base;
    }
    reverse();
  } else
    rem[count++] = '0';
}
int hex_dec() {
  int i, result = 0;
  for (i = strlen(rem) - 1; i >= 0; i--) {
    if (rem[i] >= '0' && rem[i] <= '9')
      result += (rem[i] - 48) * pow(16, i);
    else
      result += (rem[i] - 55) * pow(16, i);
  }
  return result;
}
void Dec_Hex(int num) {
  if (num != 0) {
    while (num != 0) {
      int val = num % 16;
      if (val >= 0 && val <= 9)
        rem[count++] = val + 48;
      else
        rem[count++] = val + 55;
      num /= 16;
    }
  } else
    rem[count++] = '0';
}
void swap(char *a, char *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void print() {
  int i;
  for (i = 0; i < count; i++) {
    printf("%c", rem[i]);
  }
  printf("\n");
}
void reverse() {
  int i;
  for (i = 0; i < count / 2; i++) {
    swap(&rem[i], &rem[count - i - 1]);
  }
}
