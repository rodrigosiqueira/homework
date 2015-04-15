#include <stdio.h>

#define PI 3.14159

int main(int argc, char ** argv)
{
  int radious = 0;

  scanf("%d", &radious);

  printf("VOLUME = %.3f\n", (4/3.0) * PI * radious * radious * radious);

  return 0;
}
