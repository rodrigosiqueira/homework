#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  int input = 0, i = 0;

  scanf("%d", &input);

  printf("N[0] = %d\n", input);
  for(i = 1; i < 10; i++)
    printf("N[%i] = %d\n", i, input *= 2);
 
  return 0;
}
