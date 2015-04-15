#include <stdio.h>

int main(int argc, char ** argv)
{
  int hourStart = 0, minuteStart = 0, startSeconds = 0;
  int hourFinish = 0, minuteFinish = 0, finalSeconds = 0;
  int finalResult = 0;

  scanf("%d %d %d %d", &hourStart, &minuteStart, &hourFinish, &minuteFinish);

  startSeconds = (hourStart * 3600) + (minuteStart * 60);
  finalSeconds = (hourFinish * 3600) + (minuteFinish * 60);
  
  finalResult = finalSeconds - startSeconds;

  finalResult = (finalResult > 0) ? finalResult : 86400 + finalResult;

  printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", finalResult / 3600,
          (finalResult % 3600) / 60);

  return 0;
}
