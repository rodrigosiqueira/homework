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

  generateRandomMatrix(width, height);

  return 0; 
}
