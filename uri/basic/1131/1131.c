#include <stdio.h>

int main(int argc, char ** argv)
{
  int g1 = 0, g2 = 0, stop = 0;
  int gremioWin = 0, interWin = 0, draw = 0, totalMatch = 0;

  while(1)
  {
    scanf("%d %d", &g1, &g2);

    if (g1 > g2)
      interWin++;
    else if (g1 < g2)
      gremioWin++;
    else
      draw++;
    totalMatch++;

    puts("Novo grenal (1-sim 2-nao)");
    scanf("%d", &stop);

    if(stop == 2)
      break;
  }

  printf("%d grenais\n", totalMatch);
  printf("Inter:%d\n", interWin);
  printf("Gremio:%d\n", gremioWin);
  printf("Empates:%d\n", draw);

  if (gremioWin > interWin)
    puts("Gremio venceu mais");
  else if(interWin > gremioWin)
    puts("Inter venceu mais");
  else
    puts("Nao houve vencedor");

  return 0;
}
