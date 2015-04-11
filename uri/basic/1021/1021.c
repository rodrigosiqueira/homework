#include <stdio.h>
#include <math.h>

#define notas100 " nota(s) de R$ 100.00\n"
#define notas50 " nota(s) de R$ 50.00\n"
#define notas20 " nota(s) de R$ 20.00\n"
#define notas10 " nota(s) de R$ 10.00\n"
#define notas5 " nota(s) de R$ 5.00\n"
#define notas2 " nota(s) de R$ 2.00\n"

#define moeda1 " moeda(s) de R$ 1.00\n"
#define moeda2 " moeda(s) de R$ 0.50\n"
#define moeda3 " moeda(s) de R$ 0.25\n"
#define moeda4 " moeda(s) de R$ 0.10\n"
#define moeda5 " moeda(s) de R$ 0.05\n"
#define moeda6 " moeda(s) de R$ 0.01\n"

int main(int argc, char ** argv)
{
  int totalMoney = 0, totalCoins = 0;
  float total = 0.0;

  scanf("%f", &total);

  totalMoney = total;
  totalCoins = roundf((total - (int)total) * 100);

  printf("NOTAS:\n");
  printf("%d%s", totalMoney / 100, notas100);

  totalMoney = totalMoney % 100;
  printf("%d%s", totalMoney / 50, notas50);

  totalMoney = totalMoney % 50;
  printf("%d%s", totalMoney / 20, notas20);

  totalMoney = totalMoney % 20;
  printf("%d%s", totalMoney / 10, notas10);

  totalMoney = totalMoney % 10;
  printf("%d%s", totalMoney / 5, notas5);

  totalMoney = totalMoney % 5;
  printf("%d%s", totalMoney / 2, notas2);

  printf("MOEDAS:\n");

  totalMoney = totalMoney % 2;
  printf("%d%s", totalMoney, moeda1);

  printf("%d%s", totalCoins / 50, moeda2);

  totalCoins = totalCoins % 50;
  printf("%d%s", totalCoins / 25, moeda3);

  totalCoins = totalCoins % 25;
  printf("%d%s", totalCoins / 10, moeda4);

  totalCoins = totalCoins % 10;
  printf("%d%s", totalCoins / 5, moeda5);

  totalCoins = totalCoins % 5;
  printf("%d%s", totalCoins, moeda6);

  return 0;
}
