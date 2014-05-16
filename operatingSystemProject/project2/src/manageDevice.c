/**
*	@file manageDevice.c
*	@brief This file keep the implementation of the basic 
*		manage of the cacheFake.
*/

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/device-mapper.h>
#include <linux/bio.h>
#include <linux/module.h>

#include "../inc/cacheTarget.h"
#include "../inc/manageDevice.h"

//Fill out the necessary filds for create the device mapper.
static struct target_type cacheFakeTarget = 
{
	.name = DEVICE_NAME,
	.version = {1,0,0},
	.module = THIS_MODULE,
	.ctr = cacheFakeConstructor,
	.dtr = cacheFakeDestructor,
	.map = cacheTargetMap,
};

//Module function
int initCacheFake(void)
{
	int result = 0;
	result = dm_register_target(&cacheFakeTarget);

	if (result < 0)
	{
		printk(KERN_CRIT "\n Error in registering target \n");
	}

	printk(KERN_CRIT "\n Module has been <<INSERTED>>.");

	return 0;
}

void cleanupCacheFake(void)
{
	dm_unregister_target(&cacheFakeTarget);

	printk(KERN_CRIT "\n Module has been <<REMOVED>>.");

	return;
}

module_init(initCacheFake);
module_exit(cleanupCacheFake);
MODULE_LICENSE("GPL");
