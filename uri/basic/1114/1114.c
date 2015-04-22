#include <stdio.h>

int main(int argc, char ** argv)
{
  int password = 0;

  scanf("%d", &password);
  while(password != 2002)
  {
    puts("Senha Invalida");
    scanf("%d", &password);
  }
  puts("Acesso Permitido"); 

  return 0;
}
