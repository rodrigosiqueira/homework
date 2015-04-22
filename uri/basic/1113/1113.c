#include <stdio.h>

int main(int argc, char ** argv)
{
  int x = 0, y = 0;

  scanf("%d %d", &x, &y);
  while(x != y)
  {
    if (x < y)
      puts("Crescente");
    else
      puts("Decrescente");
    scanf("%d %d", &x, &y);
  }

  return 0;
}
