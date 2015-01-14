/**
* @file handleNumber.c
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "dataType.h"
#include "handleNumber.h"

int * generateRandomMatrix(const unsigned char _width,
                          const unsigned char _height)
{
  int * matrix = NULL;
  unsigned long int cicles = 0;
  register int i = 0;
  
  matrix = emptyMatrix(_width, _height);
  if (!matrix)
  {
    return NULL;
  }

  for (i = 0; i < _height * _width; i++)
  {
    cicles = clock();
    srandom(cicles);
    *(matrix + i) = ((int)random()) % 0xffff;
    (!(i % _width)) ? printf("\n") : printf("\t");
    printf("%d", *(matrix + i));
  }
  printf("\n"); 
  return matrix;
}


int * emptyMatrix(const unsigned char _width, 
                  const unsigned char _height)
{
  int * newMatrix = (int *) malloc(sizeof(int) * _width * _height);
  if (!newMatrix)
  {
    return NULL;
  }

  return newMatrix;
}

void dotProduct(const int * _matrixA, const int * _matrixB, 
                int * _result, const unsigned char _width)
{
  int i, j, k, sum, elementA, elementB;
  i = j = k = sum = elementA, elementB = 0;

  for (i = 0; i < _width; i++)
  {
    for(j = 0; j < _width; j++)
    {
      sum = 0;
      for(k = 0; k < _width; k++)
      {
        elementA = *(_matrixA + (j*_width + k));     //Go accross the line
        elementB = *(_matrixB + (j + k*_width));     //Go accross the column
        sum += (elementA * elementB);   //Take each element
      }
      *(_result + (_width*i + j)) = sum;
    }
  }
}

