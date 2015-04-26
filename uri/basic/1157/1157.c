#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  int N = 0, i = 0;

  scanf("%d", &N);

  for (i = 1; i <= N; i++)
  {
    if (!(N % i))
    {
      printf("%d\n", i);
    }
  }

  return 0;
}
