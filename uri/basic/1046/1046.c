#include <stdio.h>

int main(int argc, char ** argv)
{
  int start = 0, finished = 0;
  register int i = 0;

  scanf("%d %d", &start, &finished);

  if(!start && !finished)
  {
    printf("O JOGO DUROU 24 HORA(S)\n");
    return 0;
  }

  for(i = 0; start != finished; start++, i++)
  {
    if (start > 24)
      start = 1;
  }

  printf("O JOGO DUROU %d HORA(S)\n", i);

  return 0;
}
