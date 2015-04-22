#include <stdio.h>

int main(int argc, char ** argv)
{
  int initialJ = 60, i = 1;

  for(; initialJ; initialJ -= 5, i += 3)
    printf("I=%d J=%d\n", i, initialJ);

  printf("I=%d J=%d\n", i, initialJ);
  return 0;
}
