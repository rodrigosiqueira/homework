#include <stdio.h>

#define PI 3.14159

int main(int argc, char ** argv)
{
  double radious = 0.0;

  scanf("%lf", &radious);

  printf("A=%.4f\n", PI * radious * radious);

  return 0;
}
