/**
*	@file log.h
* @see http://www.cs.nmsu.edu/~pfeiffer/fuse-tutorial/files.html
* @brief This file keeps some functions for handle files, the original 
*		job was made for Joseph J. Pfeiffer, Jr., Ph.D. We just rewrite some
*		functions. 
*/
#ifndef __LOG_H__
#define __LOG_H__


#include <stdio.h>

/**
*
*/
#define log_struct(status, field, format, typecast) \
	logMessage("     " #field " = " #format "\n", typecast status->field)

#define FUSELOG "fuseLog.log"

/**
*	@return Return a reference of opened file othewise return NULL.
*	@brief This functions open the file of log and mark that we got in there.
*/
FILE * logOpen(void);

/**
*	@param _fileInfo Struct with all the data. 
*	@brief Print all the informations of the struct fuse_file_info.
*/
void logFileInformation(struct fuse_file_info * _fileInfo);

/**
*	@param _statusInfo
*	@brief
*/
void logStat(struct stat * _statusInfo);

/**
*	@param _statusVfs
*	@brief 
*/
void logStatvfs(struct statvfs * _statusVfs);

/**
*	@param _buffer
*	@brief 
*/
void logUtime(struct utimbuf * _buffer);

/**
*	@param _format String to print.
* @param ... Parameters for print
*	@brief This function takes the format, and based on that print the log.
*/
void logMessage(const char * _format, ...);

#endif
