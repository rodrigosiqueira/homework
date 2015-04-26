#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  int input = 0, totalTest = 0, divided = 0, i = 0;

  scanf("%d", &totalTest);

  while(totalTest--)
  {
    scanf("%d", &input);

    for (i = 1, divided = 0; i <= input && divided <= 2; i++)
    {
      if (input % i)
        continue;

      divided++;
    }

    if (divided == 2)
      printf("%d eh primo\n", input);
    else
      printf("%d nao eh primo\n", input);
  }

  return 0;
}
