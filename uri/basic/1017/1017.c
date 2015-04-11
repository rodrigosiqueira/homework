#include <stdio.h>

int main(int argc, char ** argv)
{
  int time = 0, average = 0;

  scanf("%d", &time);
  scanf("%d", &average);

  printf("%.3f\n", (time*average)/12.0);

  return 0;
}
