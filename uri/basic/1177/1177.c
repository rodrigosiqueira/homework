#include <stdio.h>

int main(int argc, char ** argv)
{
  int T = 0;
  register int i = 0, j = 0;

  scanf("%d", &T);

  for (i = 0, j = 0; i < 1000; i++, j++)
  {
    if (j >= T)
      j = 0;
    printf("N[%d] = %d\n", i, j);
  }
  
  return 0;
}
