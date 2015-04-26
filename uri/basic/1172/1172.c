#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  int input, i = 0;

  do
  {
    scanf("%d", &input);
    if (input <= 0)
      printf("X[%d] = 1\n", i);
    else
      printf("X[%d] = %d\n", i, input);
    i++;
  }while (i < 10);

  return 0;
}
