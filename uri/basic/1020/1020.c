#include <stdio.h>

int main(int argc, char ** argv)
{
  int age = 0, year = 0, mouth = 0, days = 0;

  scanf("%d", &age);

  year = age / 365;
  mouth = (age % 365) / 30;
  days = (age % 365) % 30;

  printf("%d ano(s)\n", year);
  printf("%d mes(es)\n", mouth);
  printf("%d dia(s)\n", days);

  return 0;
}
