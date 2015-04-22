#include <stdio.h>

int main(int argc, char ** argv)
{
  register int i, p1 = 0, p2 = 1, next;
  int n = 0;

  scanf("%d", &n);

  if (n == 1)
  {
    printf("0\n");
    return 0;
  }

  printf("0 1");
  for (i = 2; i < n; i++)
  {
    next = p1 + p2;
    p1 = p2;
    p2 = next;
    printf(" %d", next);
  }

  puts("");

  return 0;
}
