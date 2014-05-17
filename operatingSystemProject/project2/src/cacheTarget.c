/**
*	@file cacheTarget.c
*	@brief This file keep the implementation of the cache.
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/bio.h>
#include <linux/device-mapper.h>

#include "../inc/cacheTarget.h"

int cacheTargetMap(struct dm_target * _target, struct bio * _blockIO)
{
	cacheTarget * specificData = (cacheTarget *) _target->private;
	printk(KERN_CRIT "\n << [IN] of the <<MAP>> \n");

	_blockIO->bi_bdev = specificData->device->bdev;

	//TAKE A LOOK HERE!!!! THE CORE OF THE PROJECT!!
	printk(KERN_CRIT "\n INSIDE OF bi_rw: %lu (%llu)\n", _blockIO->bi_rw, WRITE);
	if ((_blockIO->bi_rw & WRITE) == WRITE)
	{
		printk(KERN_CRIT "\n cacheTargetMap: <WRITE> request ...");
	}
	else
	{
		printk(KERN_CRIT "\n cacheTargetMap: <READ> request ...");
	}
	//Submit the BIO to the block device layer for I/O
	submit_bio(_blockIO->bi_rw, _blockIO);

	printk(KERN_CRIT "\n >> [OUT] of function <<MAP>> \n");

	return DM_MAPIO_SUBMITTED;
}

int cacheFakeConstructor(struct dm_target * _target, unsigned int _argumentNumber, 
		char ** _argv)
{
	cacheTarget * specificData = 0;
	unsigned long long start = 0;

	printk(KERN_CRIT "\n >> [IN] function <<CREATE>> \n");

	if (_argumentNumber != 2)
	{
		printk(KERN_CRIT "\n Invalid number of arguments. \n");
		_target->error = "Invalid argument count";
		return -EINVAL;
	}

	specificData = kmalloc(sizeof(cacheTarget), GFP_KERNEL);

	if (!specificData)
	{
		printk(KERN_CRIT "\n specificData is null\n");
		_target->error = "cacheTarget cannot be allocate liner context";
		return -ENOMEM;
	}
	
	printk(KERN_CRIT "_ARGV[1] = %s", _argv[1]);
	if (sscanf(_argv[1], "%llu", &start) != 1)
	{
		_target->error = "dm_basic_target: Invalid sector";
		goto bad;
	}

	specificData->start = (sector_t)start;
	//dm_get_device: Constructor should call these functions to ensure destination devices are opened/closed correctly.
	//dm_table_get_mode: Just return the permission.
	if (dm_get_device(_target, _argv[0], dm_table_get_mode(_target->table), &specificData->device))
	{
		_target->error = "dm-basic_target: Device lookup failed";
		goto bad;
	}
	
	_target->private = specificData;

	printk(KERN_CRIT "\n >> [OUT] function <<CREATE>> \n");

	return 0;

bad:
	kfree(specificData);
	printk(KERN_CRIT "\n >> out function basic_target_ctr with error");
	return -EINVAL;
}

void cacheFakeDestructor(struct dm_target * _target)
{
	cacheTarget * specificData = (cacheTarget *)_target->private;
	printk(KERN_CRIT "\n << [IN] function <<DESTRUCTOR>> \n");
	//"Decrement a device's use count and remove it if necessary.
	dm_put_device(_target, specificData->device);
	kfree(specificData);
	printk(KERN_CRIT "\n >> [OUT] function <<DESTRUCTOR>> \n");
}

