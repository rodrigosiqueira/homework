#include <stdio.h>

int main(int argc, char ** argv)
{
  register int i = 0, j = 0, p1 = 0, p2 = 1, next;
  int n = 0, testCase = 0;

  scanf("%d", &testCase);

  for (j = 0; j < testCase; j++)
  {
    scanf("%d", &n);

    if (!n)
    {
      puts("Fib(0) = 0");
      continue;
    }

    if (n == 1)
    {
      puts("Fib(1) = 1");
      continue;
    }

    for (i = 2, next = p1 = 0, p2 = 1; i <= n; i++)
    {
      next = p1 + p2;
      p1 = p2;
      p2 = next;
    }
    printf("Fib (%d) = %d\n", n, next);
  }
  return 0;
}
