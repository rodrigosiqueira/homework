#include <stdio.h>

int main(int argc, char ** argv)
{
  float salary = 0.0, result = 0.0;

  scanf("%f", &salary);

  if (salary <= 2000.00)
  {
    puts("Isento");
    return 0;
  }

  result = salary - 2000.00;

  if (result <= 1000.00)
  {
    result = result * 0.08;
    printf("R$ --- 1 -- %.2f\n", result);
    return 0;
  }

  if (result >= 1000.00 && result <= 2500.00)
  {
    result = 1000 * 0.08 + (result - 1000.00) * 0.18;
    printf("R$ --- 2 -- %.2f\n", result);
    return 0;
  }

  if (result >= 2500.00)
  {
    result = (1000.00 * 0.08) + 
              ((result - 1000.00) * 0.18) + 
              ((result - 2500.00) * 0.28);
    printf("R$ --- 3 -- %.2f\n", result);
    return 0;
  }

  return 0;
}
