#include <stdio.h>

int main(int argc, char ** argv)
{
  int ages;
  float total = 0.0, count = 0.0;
  scanf("%d", &ages);

  while(ages >= 0)
  {
    total += ages;
    count++;
    scanf("%d", &ages);
  }

  printf("%.2f\n", total / count);

  return 0;
}
