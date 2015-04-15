#include <stdio.h>

int main(int argc, char ** argv)
{
  int id = 0, hours = 0;
  float salaryPerHour = 0.0;

  scanf("%d", &id);
  scanf("%d", &hours);
  scanf("%f", &salaryPerHour);

  printf("NUMBER = %d\n", id);
  printf("SALARY = U$ %.2f\n", salaryPerHour * hours);

  return 0;
}
