#include <stdio.h>

int main(int argc, char ** argv)
{
  int A = 0, B = 0, tmp = 0;
  char * output = 0;

  scanf("%d %d", &A, &B);

  if (A < B)
  {
    tmp = A;
    A = B;
    B = tmp;
  }

  output = (A % B) ? "Nao sao Multiplos\n" : "Sao Multiplos\n" ;

  printf("%s", output);

  return 0;
}
