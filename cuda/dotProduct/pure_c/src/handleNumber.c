/**
* @file handleNumber.c
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "dataType.h"

int * generateRandomMatrix(const unsigned char _width,
                          const unsigned char _height)
{
  int * matrix = (int *)malloc(sizeof(int) * _width * _height);
  unsigned long int cicles = 0;
  register int i = 0;

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


