#include <stdio.h>

int main(int argc, char ** argv)
{
  float tmpGrade = 0.0, grade1 = 0.0, grade2 = 0.0;
  int valid = 0, x = 0;

  while(1)
  {
    x++;
    scanf("%f", &tmpGrade);

    if (tmpGrade < 0.0 || tmpGrade > 10.0)
    {
      puts("nota invalida");
      continue;
    }

    valid++;
    if (valid == 2)
    {
      grade2 = tmpGrade;
      printf("media = %.2f\n", (grade1 + grade2) / 2);
      continue;
    }
    else if (valid == 1)
      grade1 = tmpGrade;

    if (valid > 2)
    {
      puts("novo calculo (1-sim 2-nao)");
      if (tmpGrade == 2)
        break;
      else if (tmpGrade == 1)
        valid = 0;
    }
  }
  return 0;
}

