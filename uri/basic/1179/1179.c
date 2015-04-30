#include <stdio.h>

#define evenStr "par"
#define oddStr "impar"

void printVector(int * vector, int * index, char * msg)
{
  int i;

  for (i = 0; i < 5; i++)
    printf("%s[%d] = %d\n", msg, i, vector[i]);
  *index = 0;
}

int main(int argc, char ** argv)
{
  int vectorEven = 0, vectorOdd = 0, even[5], odd[5], input = 0, i = 0;
  
  while(scanf("%d", &input) != EOF)
  {
    if (input % 2)
    {
      if (vectorOdd == 5)
        printVector(odd, &vectorOdd, oddStr);
      odd[vectorOdd] = input;
      vectorOdd++;
    }
    else
    {
      if (vectorEven == 5)
        printVector(even, &vectorEven, evenStr);
      even[vectorEven] = input;
      vectorEven++;
    }
  }

  for (i = 0; i < vectorOdd; i++)
    printf("%s[%d] = %d\n", oddStr, i, odd[i]);
  for (i = 0; i < vectorEven; i++)
    printf("%s[%d] = %d\n", evenStr, i, even[i]);

  return 0;
}
