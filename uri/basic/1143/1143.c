#include <stdio.h>

int main(int argc, char ** argv)
{
  int input = 0, i = 0, square = 0;

  scanf("%d", &input);

  for (i = 1; i <= input; i++)
  {
    square = i * i;
    printf("%d %d %d\n", i, square, square * i);
  }

  return 0;
}
