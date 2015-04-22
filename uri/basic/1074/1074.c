#include <stdio.h>

#define ODD "ODD"
#define EVEN "EVEN"
#define POSITIVE "POSITVE\0"
#define NEGATIVE "NEGATIVE\0"

int main(int argc, char ** argv)
{
  int total = 0, value = 0, i = 0;
  char * parity, * signal = 0;

  scanf("%d", &total);

  for (i = 0; i < total; i++)
  {
    scanf("%d", &value);

    if (value == 0)
    {
      puts("NULL");
      continue;
    }

    if (value % 2)
      parity = ODD;
    else
      parity = EVEN;

    if (value > 0)
      signal = POSITIVE;
    else
      signal = NEGATIVE;

    printf("%s %s\n", parity, signal);
  }

  return 0;
}
