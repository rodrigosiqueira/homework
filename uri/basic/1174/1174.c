#include <stdio.h>

int main(int argc, char ** argv)
{
  float input;
  int i = 0;

  while(scanf("%f", &input) != EOF)
  {
    if (input <= 10)
      printf("A[%d] = %.1f\n", i, input);
    i++;
  } 

  return 0;
}
