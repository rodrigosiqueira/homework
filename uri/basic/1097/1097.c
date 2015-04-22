#include <stdio.h>

int main(int argc, char ** argv)
{
  int initialJ = 7, i = 1, j = 0;

  for(; i <= 9; i += 2, initialJ += 2)
    for(j = 0;j < 3; j++)
      printf("I=%d J=%d\n", i, initialJ - j);

  return 0;
}
