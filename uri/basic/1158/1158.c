#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  int testCases = 0, begin = 0, total = 0, i = 0, sum = 0;

  scanf("%d", &testCases);
  testCases--;
  do
  {
    scanf("%d %d", &begin, &total);
    for(i = 0, sum = 0; i < total; begin++)
    {
      if (begin % 2)
      {
        sum += begin;
        i++;
      }
    }
    printf("%d\n", sum);
  }while(testCases--);

  return 0;
}
