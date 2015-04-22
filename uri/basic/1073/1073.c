#include <stdio.h>

int main(int argc, char ** argv)
{
  int value = 0, i = 0;

  scanf("%d", &value);

  for(i = 1; i <= value; i++)
    if (!(i % 2))
      printf("%d^2 = %d\n", i, i*i);

  return 0;
}
