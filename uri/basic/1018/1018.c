#include <stdio.h>

#define notas100 " nota(s) de R$ 100,00\n"
#define notas50 " nota(s) de R$ 50,00\n"
#define notas20 " nota(s) de R$ 20,00\n"
#define notas10 " nota(s) de R$ 10,00\n"
#define notas5 " nota(s) de R$ 5,00\n"
#define notas2 " nota(s) de R$ 2,00\n"
#define notas1 " nota(s) de R$ 1,00\n"


int main(int argc, char ** argv)
{
  int total = 0;

  scanf("%d", &total);

  printf("%d\n", total);
  printf("%d%s", total / 100, notas100);

  total = total % 100;
  printf("%d%s", total / 50, notas50);

  total = total % 50;
  printf("%d%s", total / 20, notas20);

  total = total % 20;
  printf("%d%s", total / 10, notas10);

  total = total % 10;
  printf("%d%s", total / 5, notas5);

  total = total % 5;
  printf("%d%s", total / 2, notas2);

  total = total % 2;
  printf("%d%s", total, notas1);

  return 0;
}
