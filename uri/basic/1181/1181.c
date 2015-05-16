#include <stdio.h>

int main(int argc, char ** argv)
{
  int line = 0, i = 0, find = 0, lineCount = 0;
  char operation;
  float inputs, result = 0;

  scanf("%d", &line);
  scanf("%d", &i);
  scanf("%c", &operation);

  for(i = 0, find = 0; i < 144 && lineCount <= line; i++, find++)
  {
    scanf("%f", &inputs);

    if (find == 12)
    {
      lineCount++;
      find = 0;
    }
      
    if (lineCount == line)
    {
      result += inputs;
      printf("input: %f\n", inputs);
    }
  }

  switch(operation)
  {
    case 'S':
      printf("%.1f\n", result);
      break;
    case 'M':
      printf("%.1f -- %f\n", result / 12, result);
      break;
  }

  return 0;
}
