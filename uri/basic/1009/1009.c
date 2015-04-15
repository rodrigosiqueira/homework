#include <stdio.h>

int main(int argc, char ** argv)
{
  char name[4096];
  float salary = 0.0, sold = 0.0;

  scanf("%s", name);
  scanf("%f", &salary);
  scanf("%f", &sold);

  printf("TOTAL = R$ %.2f\n", salary + (sold * 0.15));

  return 0;
}
