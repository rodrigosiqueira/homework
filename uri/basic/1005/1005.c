#include <stdio.h>

int main(int argc, char ** argv)
{
  float test1 = 0.0;
  float test2 = 0.0;
  float average = 0.0;

  scanf("%f", &test1);
  scanf("%f", &test2);

  average = ((test1 * 3.5) + (test2 * 7.5)) / 11.0;

  printf("MEDIA = %.5f\n", average);

  return 0;
}
