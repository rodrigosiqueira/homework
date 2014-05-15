/**
*	@file mainOperation.c
*	@author Jonas
*	@author Lorran
*	@author Rodrigo
* @brief This file keep the implementation of basic operation related with 
*		the device
*/
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/cdev.h>

#include "inc/memoryOperation.h"
#include "inc/virtualMemoryOperation.h"

/**
*	@var majorMemory
*	@brief Static global variable that keeps the major number.
*/
static int majorMemory = MAJOR_MEMORY;

/**
*	@var memoryOperations
* @brief keep the reference for the operations.
*/
static struct file_operations memoryOperations = 
{
	.owner		= THIS_MODULE,
	.open			= openMemory,
	.release	= releaseMemory,
	.mmap			= pageMmap,
};

/**
*	@var charDevice
*	@brief Keep the struct responsable for the char device.
*/
static struct cdev charDevice;

module_param(majorMemory, int, 0);
MODULE_AUTHOR("Lorran, Jonas, Rodrigo");
MODULE_LICENSE("GPL");

int openMemory(struct inode * _inode, struct file * _file)
{
	printk(KERN_WARNING "Open Memory\n");
	return 0;
}

int releaseMemory(struct inode * _inode, struct file * _file)
{
	printk(KERN_WARNING "Release Memory\n");
	return 0;
}

static void setupCdev(struct cdev * _device, int _minor, struct file_operations * _fileOperation)
{
	int error = 0, deviceNumber = MKDEV(majorMemory, _minor);

	cdev_init(_device, _fileOperation);
	_device->owner	= THIS_MODULE;
	_device->ops		= _fileOperation;
	error = cdev_add(_device, deviceNumber, 1);

	if(error)
	{
		printk (KERN_NOTICE "Error %d when try to add the minor: %d\n", error, _minor);
	}

	return;
}

int initFakeMemory(void)
{
	int result = 0;
	dev_t deviceMemory = MKDEV(majorMemory, 0);

	//Get major number
	if(majorMemory)
	{
		result = register_chrdev_region(deviceMemory, DEVICE_MEMORY, DEVICE_NAME);
	}
	else
	{
		result = alloc_chrdev_region(&deviceMemory, 0, DEVICE_MEMORY, DEVICE_NAME);
		majorMemory = MAJOR(deviceMemory);
	}

	if(result < 0)
	{
		printk(KERN_WARNING "Unable to get major number %d\n", majorMemory);
		return result;
	}

	allocSharedMemory();
	printk("share_mem = %p\n", getSharedMemory());

	if(!majorMemory)
	{
		majorMemory = result;
	}

	//Initialize 
	setupCdev(&charDevice, 0, &memoryOperations);
	
	printk(KERN_WARNING "Module load device \n");

	return 0;
}

void exitFakeMemory(void)
{
	if(getSharedMemory() != NULL)
	{
		freeSharedMemory();
	}
	cdev_del(&charDevice);
	unregister_chrdev_region(MKDEV(majorMemory, 0), 2);
	
	printk(KERN_WARNING "Module unload \n");

	return;
}

module_init(initFakeMemory);
module_exit(exitFakeMemory);
