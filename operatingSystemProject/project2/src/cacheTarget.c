/**
*	@file cacheTarget.c
*	@brief This file keep the implementation of the cache.
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/bio.h>
#include <linux/device-mapper.h>
#include <linux/list.h>

#include "../inc/cacheTarget.h"

fifoPolicy myPolicy = 
{
	.list = LIST_HEAD_INIT(myPolicy.list),
	.position = 0,
	.size = 0
};

int cacheTargetMap(struct dm_target * _target, struct bio * _blockIO)
{
	cacheTarget * specificData = (cacheTarget *) _target->private;
	unsigned int count = 0;
	fifoPolicy * new = 0;

	printk(KERN_CRIT "\n << [IN] of the <<MAP>> \n");

	_blockIO->bi_bdev = specificData->device->bdev;

	//Check the current action
	if (bio_has_data(_blockIO))
	{
		if (unlikely(_blockIO->bi_rw & REQ_WRITE_SAME))
		{
			count = bdev_logical_block_size(_blockIO->bi_bdev) >> 9;
		}
		else
		{
			count = bio_sectors(_blockIO);
		}
		printk(KERN_CRIT "\n count: %d ", count);
		printk(KERN_CRIT "\n size: %ul ", _blockIO->bi_size);
		printk(KERN_CRIT "\n sector: %llu ", (unsigned long long)_blockIO->bi_sector);
		printk(KERN_CRIT "\n physical segment: %u ", _blockIO->bi_phys_segments);
		printk(KERN_CRIT "\n BIO cur bytes: %ul", bio_cur_bytes(_blockIO));
		printk(KERN_CRIT "\n Number of bio_vecs: %u \n", _blockIO->bi_vcnt);

		if ((_blockIO->bi_rw & WRITE) == WRITE)
		{
			printk(KERN_CRIT "\n cacheTargetMap: <WRITE> request ...");
			new = kmalloc(sizeof(fifoPolicy), GFP_KERNEL);
			//Check if cache is full.
			//FILL THE LIST
			//new->position = 1;
			//new->size = 1;
			//list_add_tail(&(new->list), &(myPolicy.list));
			//Store the data in cache.

			//Store the date in the backing store
		}
		else
		{
			printk(KERN_CRIT "\n cacheTargetMap: <READ> request ...");
			//Check if the cache is full

			//Go to backing store

			//Update the cache
		}
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

	//Alloc the size of the structure.
	specificData = kmalloc(sizeof(cacheTarget), GFP_KERNEL);
	if (!specificData)
	{
		printk(KERN_CRIT "\n specificData is null\n");
		_target->error = "cacheTarget cannot be allocate liner context";
		return -ENOMEM;
	}
	//Create the cache block.
	specificData->cacheDevice = kmalloc(sizeof(4096), GFP_KERNEL);
	if(!specificData->cacheDevice)
	{
		printk(KERN_CRIT "\n specificData->cacheDevice is null\n");
		_target->error = "Cannot allocate cache";
		return -ENOMEM;
	}
	//Initialize cache from 0
	specificData->cachePosition = 0;
	
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
	kfree(specificData->cacheDevice);
	kfree(specificData);
	//list_del(&fifoList);
	printk(KERN_CRIT "\n >> [OUT] function <<DESTRUCTOR>> \n");
}

