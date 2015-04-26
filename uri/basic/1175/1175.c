#include <stdio.h>

int main(int argc, char ** argv)
{
  int inputs[20], i = 0, j = 0;

  while(i < 20)
  {
    scanf("%d", inputs + i);
    i++;
  }

  for(i = 19, j = 0; i >= 0; i--, j++)
    printf("N[%d] = %d\n", j, inputs[i]);

  return 0;
}
