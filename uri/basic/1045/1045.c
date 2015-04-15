#include <stdio.h>

int main(int argc, char ** argv)
{
  float a = 0.0, b = 0.0, c = 0.0;

  scanf("%f %f %f", &a, &b, &c);

  if (a > (b+c))
  {
    printf("NAO FORMA TRIANGULO\n");
    return 0;
  }

  if ((a*a) == (b*b + c*c))
    printf("TRIANGULO RETANGULO\n");
  if ((a*a) > (b*b + c*c))
    printf("TRIANGULO OBTUSANGULO\n");
  if ((a*a) < b*b + c*c)
    printf("TRIANGULO ACUTANGULO\n");
  if (a == b == c)
    printf("TRIANGULO EQUILATERO\n");
  if ((a == b || a == c) && a )

  return 0;
}
