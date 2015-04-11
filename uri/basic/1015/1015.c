#include <stdio.h>
#include <math.h>

int main(int argc, char ** argv)
{
  float x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0, partial1 = 0.0, partial2 = 0.0;


  scanf("%f %f", &x1, &y1);
  scanf("%f %f", &x2, &y2);

  partial1 = (x2 - x1) * (x2 - x1);
  partial2 = (y2 - y1) * (y2 - y1);

  partial1 = partial1 + partial2;
  partial1 = sqrt(partial1);

  printf("%.4f\n", partial1);

  return 0;
}
