#include <stdio.h>

int main(int argc, char ** argv)
{
  float salary = 0.0, increase = 0, applied = 0.0;
  int outputPer = 0;

  scanf("%f", &salary);

  if (salary <= 400.0)
    increase = 0.15;
  else if (salary > 400.0 && salary <= 800.00)
    increase = 0.12;
  else if (salary > 800.00 && salary <= 1200.00)
    increase = 0.1;
  else if (salary > 1200.00 && salary <= 2000.00)
    increase = 0.07;
  else
    increase = 0.04;

  applied = salary * increase;
  outputPer = increase * 100;

  printf("Novo salario: %.2f\n", salary + applied);
  printf("Reajuste ganho: %.2f\n", applied);
  printf("Em percentual: %d %%\n", outputPer);

  return 0;
}
