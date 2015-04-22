#include <stdio.h>

int main(int argc, char ** argv)
{
  int i = 0;

  for(i = 1; i <= 100; i++)
  {
    if(!(i % 2))
      printf("%d\n", i);
  }
  return 0;
}
