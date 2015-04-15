#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv)
{
  char input1[128], input2[128], input3[128];

  scanf("%s", input1);
  scanf("%s", input2);
  scanf("%s", input3);

  if (!strcmp(input1, "vertebrado"))
  {
    if (!strcmp(input2, "ave"))
    {
      if(!strcmp(input3, "carnivoro"))
        printf("aguia\n");
      else
        printf("pomba\n");
    }
    else
    {
      if(!strcmp(input3, "onivoro"))
        printf("homem\n");
      else
        printf("vaca\n");
    }
  }
  else
  {
    if(!strcmp(input2, "inseto"))
    {
      if(!strcmp(input3, "hematofago"))
        printf("pulga\n");
      else
        printf("lagarta\n");
    }
    else
    {
      if(!strcmp(input3, "hematofago"))
        printf("sanguessuga\n");
      else
        printf("minhoca\n"); 
    }
  }

  return 0;
}
