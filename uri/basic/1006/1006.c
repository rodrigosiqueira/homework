#include <stdio.h>

int main(int argc, char ** argv)
{
  float testA = 0.0, testB = 0.0, testC = 0.0;
  float average = 0.0;

  scanf("%f", &testA);
  scanf("%f", &testB);
  scanf("%f", &testC);

  average = testA * 2 + testB * 3 + testC * 5;
  average = average / 10.0;

  printf("MEDIA = %.1f\n", average);

  return 0;
}
