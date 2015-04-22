#include <stdio.h>

int main(int argc, char ** argv)
{
  int totalTest = 0, x = 0, y = 0, sum = 0, i = 0, tmp = 0, j = 0;

  scanf("%d", & totalTest);

  for (i = 0; i < totalTest; i++)
  {
    scanf("%d %d", &x, &y);
    if (x < y)
    {
      tmp = x;
      x = y;
      y = tmp;
    }

    for (j = y + 1; j < x; j++)
    {
      if (j % 2)
       sum += j;
    }
    printf("%d\n", sum);
    sum = j = 0;
  }

  return 0;
}
