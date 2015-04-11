#include <stdio.h>

#define approved "Aluno aprovado.\n"
#define reproved "Aluno reprovado.\n"

int main(int argc, char ** argv)
{
  float testA = 0.0, testB = 0.0, testC = 0.0, testD = 0.0;
  float average = 0.0;
  char * result = 0;

  scanf("%f %f %f %f", &testA, &testB, &testC, &testD);

  average = testA * 2 + testB * 3 + testC * 4 + testD;
  average /= 10;

  printf("Media: %.1f\n", average);
  if (average >= 7.0)
  {
    printf(approved);
    return 0;
  }
  if (average < 5.0)
  {
    printf(reproved);
    return 0;
  }

  scanf("%f", &testD);
  printf("Aluno em exame.\nNota do exame: %.1f\n", testD);
  average = (average + testD) / 2.0;
  result = (average >= 5.0) ? approved : reproved;
  printf("%sMedia final: %.1f\n",result, average);

  return 0;
}
