#include <stdio.h>

int main(int argc, char ** argv)
{
  int x, y, i, j;

  scanf("%d %d", &x, &y);

  for (i = 1, j = 0; i <= y; i++, j++)
  {
    if (j == x)
    {
      puts("");
      printf("\n%d ", i);
      j = 0;
      continue;
    }
    printf("%d ", i);
  }

  puts("");
  return 0;
}
