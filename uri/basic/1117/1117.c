#include <stdio.h>

int main(int argc, char ** argv)
{
  float tmpGrade = 0.0, grade1 = 0.0, grade2 = 0.0;
  int valid = 0;

  while(1)
  {
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
      break;
    }
    else
      grade1 = tmpGrade;
  }

  printf("media = %.2f\n", (grade1 + grade2)/2);

  return 0;
}
