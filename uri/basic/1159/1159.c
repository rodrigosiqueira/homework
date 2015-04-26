#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  int input = 0, i = 0, sum = 0;

  do
  {
    scanf("%d", &input);
    if(!input)
      break;

    for (i = 0; i < 5; input++)
    {
      if (!(input % 2))
      {
        sum += input;
        i++;
      }
    }
    printf("%d\n", sum);
    sum = 0;
  }while(1);

  return 0;
}
