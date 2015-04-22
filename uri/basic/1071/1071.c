#include <stdio.h>

int main(int argc, char ** argv)
{
  int x = 0, y = 0, tmp = 0, sum = 0;

  scanf("%d", &x);
  scanf("%d", &y);

  if (y < x)
  {
    tmp = x;
    x = y;
    y = tmp;
  }

  for (x = x + 1; x != y; x++)
  {
    if (x % 2)
      sum += x;
  }

  printf("%d\n", sum);

  return 0;
}
