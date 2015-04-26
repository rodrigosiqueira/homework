#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  int testCase = 0, perfect = 0, num = 0, i = 0;
  
  scanf("%d", &testCase);

  while(testCase--)
  {
    scanf("%d", &num);

    for (i = 1, perfect = 0; i < num; i++)
    {
      if (num % i)
        continue;

      perfect += i;
    }

    if (perfect == num)
      printf("%d eh perfeito\n", num);
    else
      printf("%d nao eh perfeito\n", num);
  }

  return 0;
}
