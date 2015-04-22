#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  int values[5], totalOdd = 0, totalEven = 0;
  int totalPositive = 0, totalNegative = 0, i = 0;

  for (i = 0; i < 5; i++)
  {
    scanf("%d", values + i);
    if (*(values + i) > 0)
      totalPositive++;
    if (*(values + i) < 0)
      totalNegative++;
    
    if (abs(*(values + i)) % 2)
      totalOdd++;
    else
      totalEven++;
  }

  printf("%d valor(es) par(es)\n", totalEven);
  printf("%d valor(es) impar(es)\n", totalOdd);
  printf("%d valor(es) positivo(s)\n", totalPositive);
  printf("%d valor(es) negativo(s)\n", totalNegative);

  return 0;
}
