#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  int values[5], i = 0, totalEven = 0;

  for(i = 0; i < 5; i++)
  {
    scanf("%d", values + i);

    if (!(abs(*(values + i)) % 2))
      totalEven++;
  } 

  printf("%d  valores pares\n", totalEven);

  return 0;
}
