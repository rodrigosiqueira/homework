#include <stdio.h>

int main(int argc, char ** argv)
{
  int total = 0, input = 0, inSet = 0, outSet = 0, i = 0;

  scanf("%d", &total);

  for (i = 0; i < total; i++)
  {
    scanf("%d", &input);
    if (input >= 10 && input <= 20)
      inSet++;
    else
      outSet++;
  }

  printf("%d in\n", inSet);
  printf("%d out\n", outSet);

  return 0;
}
