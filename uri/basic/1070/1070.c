#include <stdio.h>

int main(int argc, char ** argv)
{
  int start = 0, i = 0;

  scanf("%d", &start);

  for (i = start; i < (start + 12); i++)
  {
    if (i % 2)
      printf("%d\n", i);
  }
 
  return 0;
}
