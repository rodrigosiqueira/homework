#include <stdio.h>

int main(int argc, char ** argv)
{
  float input, result;
  register int i;

  scanf("%f", &input);

  for(i = 0, result = input; i < 100; i++)
  {
    printf("N[%d] = %.4f\n", i, result);
    result /= 2;
  }

  return 0;
}
