#include <stdio.h>

int main(int argc, char ** argv)
{
  int x = 0, y = 0, tmp = 0;

  scanf("%d", &x);
  scanf("%d", &y);

  if (x < y)
  {
    tmp = x;
    x = y;
    y = tmp;
  }

  for (tmp = 0; y <= x; y++)
  {
    if (!(y % 13))
      continue;
    tmp += y;
  }

  printf("%d\n", tmp);

  return 0;
}
