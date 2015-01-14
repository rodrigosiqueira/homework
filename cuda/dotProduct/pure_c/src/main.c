#include <stdio.h>
#include <stdlib.h>

#include "handleNumber.h"

int main (int argc, char ** argv)
{
  if (argc < 3)
  {
    puts("Wrong input, try: <binary> <matrix width> <matrix height>");
    return -1;
  }

  int width = atoi(argv[1]);
  int height = atoi(argv[2]);

  //For simplicity, just consider width = height
  int * matrixA = generateRandomMatrix(width, width);
  int * matrixB = generateRandomMatrix(width, width);
  int * result = emptyMatrix(width, width);

  dotProduct(matrixA, matrixB, result, width);

  return 0; 
}
