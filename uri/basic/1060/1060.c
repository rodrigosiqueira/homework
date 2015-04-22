#include <stdio.h>

int main(int argc, char ** argv)
{
  float values[6];
  int i = 0, positives = 0;

  for (i = 0; i < 6; i++)
  {
    scanf("%f", values + i);
    if (*(values + i) > 0)
      positives++;
  }

  printf("%d valores positivos\n", positives);

  return 0;
}
