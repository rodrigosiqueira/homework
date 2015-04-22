#include <stdio.h>

int main(int argc, char ** argv)
{
  int testCases = 0, i = 0;
  float a = 0.0, b = 0.0, c = 0.0, partialSum = 0.0;

  scanf("%d", &testCases);

  for (i = 0; i < testCases; i++)
  {
    scanf("%f %f %f", &a, &b, &c);
    partialSum = a * 2 + b * 3 + c * 5;
    printf("%.1f\n", partialSum / 10);    
  }

  return 0;
}
