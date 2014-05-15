/**
*	@file virtualMemoryOperation.h
*	@author Jonas
*	@author Lorran
*	@author Rodrigo
*	@brief This file keeps the virtual memory functions.
*/
#ifndef __VIRTUAL_MEMORY_OPERATION_H__
#define __VIRTUAL_MEMORY_OPERATION_H__

#include <linux/mm.h>
#include <asm/page.h>

/**
*	@param _vma Reference to struct virtual memory address.
*	@brief This function is simple in the case of this module, and 
*		just print some data.
*/
extern void virtualMemoryOpen(struct vm_area_struct * _vma);

/**
*	@param _vma Reference to the struct for handle virtual address. 
*	@brief Handle the operation of close the file.
*/
extern void virtualMemoryClose(struct vm_area_struct * _vma);

/**
*	@param _vma Struct for handle virtual memory address.	
*	@param _vmf Struct for handle virtual memory fault.
* @return On successful return 0 othewise return a negative number.
**/
extern int virtualMemoryFault(struct vm_area_struct * _vma, struct vm_fault * _vmf);

/**
*	@param _file File that holds the information about file.
*	@param _vma Data struct with the information about the virtual area.
*	@return	On successful return 0 othewise return a negative number.
*	@brief
*/
extern int pageMmap(struct file * _file, struct vm_area_struct * _vma);

/**
*	@return Just return a reference to shared memory.
* @brief Get the reference of the shared memory.
*/
extern int * getSharedMemory(void);

/**
* @return Return a reference for the allocated area, or NULL.
*	@brief Allocate memory for one page and return it.
*/
extern int * allocSharedMemory(void);

/**
* @brief Just clean the memory.
*/
extern void freeSharedMemory(void);

#endif
