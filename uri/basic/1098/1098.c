#include <stdio.h>

int main(int argc, char ** argv)
{
  int j = 0;
  float valueI = 0.0, outputJ = 0.0;

  for (; valueI <= 2.2; valueI += 0.2)
    for (j = 1; j <= 3; j++)
    {
      outputJ = (valueI >= 1 && valueI < 2) ? j + (valueI - 1.0) : j + valueI;
      outputJ = (valueI >= 2) ? j + (valueI - 2.0) : j + valueI;

      if (!valueI || valueI == 1.0 || valueI >= 2.0)
      {
        printf("I=%.0f J=%.0f\n", valueI, outputJ);
        continue;
      }

      printf("I=%.1f J=%.1f\n", valueI, outputJ);
    }

  return 0;  
}
