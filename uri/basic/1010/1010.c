#include <stdio.h>

int main(int argc, char ** argv)
{
  int idProduct[2], units[2];
  float prices[2];

  scanf("%d %d %f", idProduct, units, prices);
  scanf("%d %d %f", &idProduct[1], &units[1], &prices[1]);
  
  printf("VALOR A PAGAR: R$ %.2f\n", (units[0] * prices[0]) + 
                                     (units[1] * prices[1]));

  return 0;
}
