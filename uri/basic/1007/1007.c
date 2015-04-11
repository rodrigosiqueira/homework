#include <stdio.h>

int main(int argc, char ** argv)
{
  int a = 0, b = 0, c = 0, d = 0;

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  scanf("%d", &d);

  printf("DIFERENCA = %d\n", (a*b) - (c*d));

  return 0;
}
