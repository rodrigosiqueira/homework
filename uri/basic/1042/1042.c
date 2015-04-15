#include <stdio.h>

int main(int argc, char ** argv)
{
  int valueIn[3], copy[3], b = 0, tmp = 0;
  register int i;

  scanf("%d %d %d", valueIn, valueIn + 1, valueIn + 2);

  copy[0] = valueIn[0];
  copy[1] = valueIn[1];
  copy[2] = valueIn[2];

  for(i = 0; i < 3; ++i)
  {
    for(b = 2; b >= i; --b)
    {
      if(valueIn[b - 1] > valueIn[b])
      {
        tmp = valueIn[b - 1];
        valueIn[b - 1] = valueIn[b];
        valueIn[b] = tmp;
      }
    }
  }

  printf("%d\n%d\n%d\n\n", valueIn[0], valueIn[1], valueIn[2]);
  printf("%d\n%d\n%d\n", copy[0], copy[1], copy[2]);

  return 0;
}
