#include <stdio.h>

int main(int argc, char ** argv)
{
  int input = 0, i = 0;

  do
  {
    scanf("%d", &input);
    for (i = 1; i < input; i++)
      printf("%d ", i);
    if (input)
      printf("%d\n", i);
  }while(input);

  return 0;
}
