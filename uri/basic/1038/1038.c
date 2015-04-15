#include <stdio.h>

int main(int argc, char ** argv)
{
  int idProduct = 0, total = 0;
  float result = 0.0;

  scanf("%d %d", &idProduct, &total);

  switch(idProduct)
  {
    case 1:
      result = 4.00;
      break;
    case 2:
      result = 4.50;
      break;
    case 3:
      result = 5.00;
      break;
    case 4:
      result = 2.00;
      break;
    case 5:
      result = 1.50;
      break;
  }

  printf("Total: R$ %.2f\n", result * total);

  return 0;
}
