#include <stdio.h>

int main(int argc, char ** argv)
{
  float S = 0.0, i;

  for(i = 1.0; i <= 100; i++)
    S +=  1.0 / i;

  printf("%.2f\n", S);

  return 0;
}
