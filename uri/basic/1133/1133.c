#include <stdio.h>

int main(int argc, char ** argv)
{
  int x, y, i, tmp;
  x = y = i = tmp = 0;

  scanf("%d", &x);
  scanf("%d", &y);

  if (x < y)
  {
    tmp = x;
    x = y;
    y = tmp;
  }

  for (; y < x; y++)
  {
    if (((y % 5) == 2) || ((y % 5) == 3))
      printf("%d\n", y);
  } 

  return 0;
}
