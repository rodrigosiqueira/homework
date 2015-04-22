#include <stdio.h>

int main(int argc, char ** argv)
{
  int a = 0, n = 0, i, sum = 0;

  scanf("%d %d", &a, &n);

  while(n <= 0)
  {
    scanf("%d", &n);
  }

  for(i = 0; i < n; i++)
  {
    sum += (a + i);
  }

  printf("%d\n", sum);

  return 0;
}
