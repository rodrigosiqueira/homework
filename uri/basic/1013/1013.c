#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  int a = 0, b = 0, c = 0, biggest = 0;

  scanf("%d %d %d", &a, &b, &c);

  biggest = (a + b + abs(a - b)) >> 1;
  biggest = (c + biggest + abs(c - biggest)) >> 1;

  printf("%d eh o maior\n", biggest);

  return 0;
}
