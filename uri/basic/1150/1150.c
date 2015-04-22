#include <stdio.h>

int main(int argc, char ** argv)
{
  int x = 0, z = 0, i, sum = 0;

  scanf("%d", &x);

  do
  {
    scanf("%d", &z);
  }while(z <= x);

  for(i = 1, sum = x; sum <= z ; i++)
  {
    sum = sum + (x + i);
  }

  printf("%d\n", i);

  return 0;
}
