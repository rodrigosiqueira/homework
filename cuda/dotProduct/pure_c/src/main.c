#include <stdio.h>
#include <stdlib.h>

#include "handleNumber.h"
#include "view.h"

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
  puts("MATRIX A");
  printMatrix(matrixA, width);

  int * matrixB = generateRandomMatrix(width, width);
  puts("MATRIX B");
  printMatrix(matrixB, width);

  int * result = emptyMatrix(width, width);
  puts("RESULT");
  dotProduct(matrixA, matrixB, result, width);
  printMatrix(result, width);

  return 0; 
}
