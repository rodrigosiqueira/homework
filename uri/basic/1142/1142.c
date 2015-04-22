#include <stdio.h>

int main(int argc, char ** argv)
{
  int input = 0, i = 0, j = 0;

  scanf("%d", &input);

  for (i = 1, j = 1; input; i++, j++)
  {
    if (j == 4)
    {
      puts("PUM");
      j = 0;
      input--;
      continue;
    }
    printf("%d ", i);
  }
  return 0;
}
