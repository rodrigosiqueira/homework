/**
*	@file cacheTarget.h
*	@brief 
*/

#ifndef _CACHE_TARGET_H_
#define _CACHE_TARGET_H_

/**
*	@struct cacheTarget
*	@brief This data struct manager the device.
*/
typedef struct _cacheTarget
{
	struct dm_dev * device;	/**< Device mapper.*/
	sector_t start;					/**< Start of the sector.*/
}cacheTarget;

/**
*	@param _target Here we can find the cacheTarget.
*	@param _blockIO Block I/O request from upper layer.
*	@param _mapContext It is mapping context of target.
* @return Return values from target map function.
* @brief Everytime, when you have any new BLOCK I/O (bio) request this function
*		is called.
*/
extern int cacheTargetMap(struct dm_target * _target, struct bio * _blockIO);

/**
*	@param _target cacheTarget can be find on this parameter.
*	@param _argumentNumber Total of arguments.
*	@param _argv Value of each argument.
*	@return If everything is right return 0, otherwise return a negative number.
*	@brief The construct are called when the command "dmsetup create" is executed.
*/
extern int cacheFakeConstructor(struct dm_target * _target, unsigned int _argumentNumber, char ** _argv);

/**
* @param _target 
*	@brief 
*/
extern void cacheFakeDestructor(struct dm_target * _target);

#endif
