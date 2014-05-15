/**
*	@file testMem.c
*	@author Jonas
*	@author Lorran
*	@author Rodrigo
* @brief This file just test the code. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <memory.h>
#include <string.h>
#include <time.h>

#define DEV_NAME1 "/dev/ospn"
#define DEV_NAME2 "/dev/ospr"

#define SHARED_MEM_SIZE 1

int main(int argc, char ** argv)
{
	int descritorFile = 0;
	int i = 0;
	int * mappingOne = 0, * mappingTwo = 0;

	if(argc > 1)
	{
		srand(atoi(argv[1]));
	}
	else
	{
		time_t now = time(0);
		srand(now);
	}

	descritorFile = open(DEV_NAME1, O_RDWR | O_NDELAY);
	if(descritorFile < 0)
	{
		printf("Error: %d\n", descritorFile);
		puts(strerror(descritorFile));
		return descritorFile;
	}

	puts("+++++++++++++++++++++++++++++++++++++++++++++++");
	mappingOne = (int *)mmap(0, SHARED_MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, descritorFile, 0);
	mappingTwo = (int *)mmap(0, SHARED_MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, descritorFile, 0);

	puts("---- Reading for the first time ----");
	puts("-- Reading first reference --");
	for(i = 0; i < 10; i++)
	{
		printf("\tContent %d: 0x%x\n", i, *(mappingOne + i));
	}

	puts("-- Reading Second --");
	for(i = 0; i < 10; i++)
	{
		printf("\tContent %d: 0x%x\n", i, *(mappingTwo + i));
	}
	puts("++++++++++++++++++++++++++++++++++++++++++++++");
	puts("-- Write --");
	for(i = 0; i < 10; i++)
	{
		*(mappingOne + i) = rand();
	}
	puts("++++++++++++++++++++++++++++++++++++++++++++++");
	puts("-------- Read again --------");
	puts("-- Reading first reference --");
	for(i = 0; i < 10; i++)
	{
		printf("\tContent %d: 0x%x\n", i, *(mappingOne + i));
	}

	puts("-- Reading Second --");
	for(i = 0; i < 10; i++)
	{
		printf("\tContent %d: 0x%x\n", i, *(mappingTwo + i));
	}

	puts("================================================");

	munmap(mappingOne, SHARED_MEM_SIZE);
	munmap(mappingTwo, SHARED_MEM_SIZE);
	close(descritorFile);

	return 0;
}
