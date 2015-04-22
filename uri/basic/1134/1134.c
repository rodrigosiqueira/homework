#include <stdio.h>

int main(int argc, char ** argv)
{
  int g = 0, a = 0, d = 0, input = 0;

  while(1)
  {
    scanf("%d", &input);

    switch(input)
    {
      case 1: 
        a++;
        break;
      case 2:
        g++;
        break;
      case 3:
        d++;
        break;
    }
    if (input == 4)
      break;
  }

  puts("MUITO OBRIGADO");
  printf("Alcool: %d\n", a);
  printf("Gasolina: %d\n", g);
  printf("Diesel: %d\n", d);

  return 0;
}
