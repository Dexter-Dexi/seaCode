#include <stdio.h>
int main(int argc, char const *argv[]) {
    int num, temp , result = 0;
    printf ("enter a number:");
    scanf ("%d", &num);
    temp = num;
    while (temp > 0) {
        int t = temp % 10;
        result = (result * 10) + t ;
        temp  /= 10;
    }
    printf ("%d = %d", num, result);
    return 0;
}
