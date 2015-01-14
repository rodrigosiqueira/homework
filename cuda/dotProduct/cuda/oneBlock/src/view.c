#include <stdio.h>
#include "view.h"

void printMatrix(const int * _matrix, const char _width)
{
  int i = 0, j = 0;
  for (i = 0; i < _width; i++)
  {
    for (j = 0; j < _width; j++)
    {
      printf(" %d \t", *(_matrix + (_width * i + j)));
    }
    printf("\n");
  }
  return;
}
