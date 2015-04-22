#include <stdio.h>

int main(int argc, char ** argv)
{
  register unsigned char i;
  int n, mul = 0;

  scanf("%d", &n);
  mul = n;

  for (i = 1; i < n; i++) 
    mul *= (n - i);

  printf("%d\n", mul);
  return 0;
}
