#include <stdio.h>

int main(int argc, char ** argv)
{
  float values[6], average = 0.0;
  int i = 0, positiveNumber = 0;

  for (i = 0; i < 6; i++)
  {
    scanf("%f", values + i);
    if (*(values + i) > 0)
    {
      average += *(values + i);
      positiveNumber++;
    }
  }

  printf("%d valores positivos\n", positiveNumber);
  printf("%.1f\n", average / positiveNumber);

  return 0;
}
