/**
*	@file fakeMemoryDevice.h
*	@author Jonas
* @author Lorran
* @author Rodrigo
*	@brief This is the header file for handle the fake memory.
*/

#ifndef __MEMORY_OPERATION_H__
#define __MEMORY_OPERATION_H__

#include <linux/cdev.h>

/**
*	@def MAJOR_MEMORY
*	@brief If you know the major number, you can add on this 
*		define. If you not do this, it will be assign 0 and the 
*		dinamyc allocation will happens.
*/
#define MAJOR_MEMORY 0

/**
*	@def DEVICE_MEMORY
*	@brief Total of devices that we want to create in the memory.
*/
#define DEVICE_MEMORY 2

/**
*	@def DEVICE_NAME
*	@brief The name of the device that will be showed in /dev/
*/
#define DEVICE_NAME "osp"

/**
*	@return return 0 on successful or a negative number on fail.
*	@brief This is the initialization function for the module. In
*		the implementation file you can check module_init at the end.
*	@see module_init
* @see memoryOperation.c
*/
extern int initFakeMemory(void);

/**
*	@brief Function responsible for remove the device drive from the 
*		memory. Check module_exit in the implementation file.
*	@see module_exit
*	@see memoryOperation.c
*/
extern void exitFakeMemory(void);

/**
*	@param _inode Data structure that holds information about a file or directory.
*	@param _file Hold the information about file.
*	@return In the caseof this module, just return 0.
*	@brief This is a default function that will be assign to file_operations structure.
*/
extern int openMemory(struct inode * _inode, struct file * _file);

/**
*	@param _inode Data structure that holds information about a file or directory.
*	@param _file Hold the information about the file.
*	@return In the case of this module, just return 0.
*	@brief Release the memory.
*/
extern int releaseMemory(struct inode * _inode, struct file * _file);

#endif
