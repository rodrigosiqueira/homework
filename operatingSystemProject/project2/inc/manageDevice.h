/**
*	@file manageDevice.h
*	@brief This file keep the basic function for insert and 
*			remove from the cache.
*/

#ifndef _MANAGE_DEVICE_H_
#define _MANAGE_DEVICE_H_

/**
* @def DEVICE_NAME
*	@brief Definition of the device name.
*/
#define DEVICE_NAME "cacheFake"

/**
*	@return In case of sucessful return 0.
*	@brief This function initialize the device. For achieve this 
*		objective, the first step it is register with 
*		dm_register_target
*/
extern int initCacheFake(void);

/**
*	@brief Unregister the device mapper.
*/
extern void cleanupCacheFake(void);

#endif
