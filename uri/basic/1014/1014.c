#include <stdio.h>

int main(int argc, char ** argv)
{
  int kilometers = 0;
  float consuption = 0.0;

  scanf("%d", &kilometers);
  scanf("%f", &consuption);

  printf("%.3f km/l\n", kilometers/consuption);

  return 0;
}
