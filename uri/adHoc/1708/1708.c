#include <stdio.h>

int main(int argc, char ** argv)
{
  int x = 0, y = 0, accum = 0, laps = 0, differ = 0;

  scanf("%d %d", &x, &y);

  differ = y - x;

  for(laps = 1; laps < 10000; laps++)
  {
    accum += differ;
    if(accum >= y)
    {
      break;
    }
  }

  printf("%d\n", laps);

  return 0;
}
