#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  float S = 1.0, i = 0.0, j = 0.0;

  for(i = 3.0, j = 2.0; i <= 39; i += 2, j *= 2 )
  {
    S += i / j;
  }

  printf("%.2f\n", S);

  return 0;
}
