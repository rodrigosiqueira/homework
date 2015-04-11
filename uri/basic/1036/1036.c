#include <stdio.h>
#include <math.h>

int main(int argc, char ** argv)
{
  float a = 0.0, b = 0.0, c = 0.0, delta = 0.0, r1 = 0.0, r2 = 0.0;

  scanf("%f %f %f", &a, &b, &c);

  delta = b*b - 4*a*c;
  if (delta < 0 || !((int)a))
  {
    printf("Impossivel calcular\n");
    return 0;
  }

  r2 = (- b - sqrt(delta)) / (2*a);
  r1 = (- b + sqrt(delta)) / (2*a);

  printf("R1 = %.5f\n", r1);
  printf("R2 = %.5f\n", r2);

  return 0;
}
