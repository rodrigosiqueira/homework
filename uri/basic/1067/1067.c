#include <stdio.h>

int main(int argc, char ** argv)
{
  int limit = 0, i = 0;

  scanf("%d", &limit);

  for(i = 1; i < limit; i++)
  {
    if ((i % 2))
      printf("%d\n", i);
  }

  return 0;
}
