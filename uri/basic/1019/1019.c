#include <stdio.h>

int main(int argc, char ** argv)
{
  int seconds = 0, hours = 0, minutes = 0;

  scanf("%d", &seconds);

  hours = seconds / 3600;
  minutes = (seconds % 3600) / 60;
  seconds = (seconds % 3600) % 60;

  printf("%d:%d:%d\n", hours, minutes, seconds);

  return 0;
}
