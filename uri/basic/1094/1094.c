#include <stdio.h>

int main(int argc, char ** argv)
{
  int testCase = 0, i = 0, animals = 0, habbit = 0, frog = 0, rat = 0;
  int total = 0;
  char type = 0;

  scanf("%d", &testCase);

  for (i = 0; i < testCase; i++)
  {
    scanf("%d %c", &animals, &type);
    total += animals;
    switch (type)
    {
      case 'C':
        habbit += animals;
        break;
      case 'R':
        rat += animals;
        break;
      case 'S':
        frog += animals;
        break;
    }
  }

  printf("Total: %d cobaias\n", total);
  printf("Total de coelhos: %d\n", habbit);
  printf("Total de ratos: %d\n", rat);
  printf("Total de sapos: %d\n", frog);
  printf("Percentual de coelhos: %.2f %%\n", (100.00 * habbit) / total);
  printf("Percentual de ratos: %.2f %%\n", (100.00 * rat) / total);
  printf("Percentual de sapos: %.2f %%\n", (100.00 * frog) / total);

  return 0;
}
