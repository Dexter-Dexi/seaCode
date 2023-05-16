#include <stdio.h>
#include <windows.system.h>

int main(int argc, char const *argv[]) {
  unsigned int h, m, s;
  printf("enter:  Hours, Minutes, seconds ");
  scanf("%d%d%d", &h, &m, &s);
  for (int hh = h; hh >= 0; hh--) {
    for (int mm = m; mm >= 0; mm--) {
      for (int ss = s; ss >= 0; ss--) {
        printf("%02d : %02d : %02d", hh, mm, ss);
        Sleep(1000);
        system("cls");
      }
    }
  }
  printf("\a");
  return 0;
}
