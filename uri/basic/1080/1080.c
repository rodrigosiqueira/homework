#include <stdio.h>

int main(int argc, char ** argv)
{
  int i = 0, highest = 0, position = 0, temp = 0;

  for (i = 1; i <= 100; i++)
  {
    scanf("%d", &temp);
    if (temp > highest)
    {
      highest = temp;
      position = i;
    }
  }

  printf("%d\n%d\n", highest, position);

  return 0;
}
