#include <stdio.h>

int main(int argc, char ** argv)
{
  int input = 0, i = 0;

  scanf("%d", &input);

  for (i = 1; i <= 10000; i++)
  {
    if (i % input == 2)
      printf("%d\n", i);
  }

  return 0;
}
