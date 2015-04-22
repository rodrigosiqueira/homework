#include <stdio.h>

int main(int argc, char ** argv)
{
  int totalTest = 0, i = 0;
  float xFloat = 0.0, yFloat = 0.0;

  scanf("%d", &totalTest);

  for(i = 0; i < totalTest; i++)
  {
    scanf("%f %f", &xFloat, &yFloat);

    if (!yFloat)
    {
      puts("divisao impossivel");
      continue;
    }

    printf("%.1f\n", xFloat / yFloat);
  }

  return 0;
}
