#include <stdio.h>

int main(int argc, char ** argv)
{
  int x = 0, y = 0;

  scanf("%d %d", &x, &y);
  while(x && y)
  {
    if (x > 0 && y > 0)
      puts("primeiro");
    else if (x < 0 && y > 0)
      puts("segundo");
    else if (x < 0 && y < 0)
      puts("terceiro");
    else
      puts("quarto");

    scanf("%d %d", &x, &y);
  }

  return 0;
}
