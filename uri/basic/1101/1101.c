#include <stdio.h>

int main(int argc, char ** argv)
{
  int x = 0, y = 0, biggest = 0, lowerst = 0, accum = 0;

  scanf("%d %d", &x, &y);
  while (!(x <= 0 || y <= 0))
  {
    biggest = (x > y) ? x : y;
    lowerst = (x > y) ? y : x;

    for(accum = 0; lowerst <= biggest; lowerst++)
    {
      printf("%d ", lowerst);
      accum += lowerst;
    } 

    printf("Sum=%d\n", accum);

    scanf("%d %d", &x, &y);
  }

  return 0;
}
