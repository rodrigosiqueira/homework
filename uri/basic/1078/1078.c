#include <stdio.h>

int main(int argc, char ** argv)
{
  int input = 0, i = 0;

  scanf("%d", &input);

  for(i = 1; i <= 10; i++)
    printf("%d x %d = %d\n", i, input, i * input);

  return 0;
}
