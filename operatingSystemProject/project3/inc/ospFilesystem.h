#ifndef __OPERATING_SYSTEM_PROJECT_FILESYSTEM_H__
#define __OPERATING_SYSTEM_PROJECT_FILESYSTEM_H__

/**
*	@file ospFilesystem.h
*	@brief This file keep the definitions of the basic functions.
*/

#include <fuse.h>
#include <errno.h>

/**
*	@param _path Receives the path of the directory that wants to check the attribute.
*	@param _statusBuffer Structure stat responsable for keep the information about file attribute.
* @return Return 0 if everything is all right, otherwise return a code error.
*	@brief
*/
extern int ospGetAttribute(const char * _path, struct stat * _statusBuffer);

/**
*	@param _path Path directory for read.
*	@param _buffer Buffer for keep the information read from the path.
*	@param _filler Insert directory entry entries into the directory structure.
*	@param _offset 
*	@param _fileInfo
*	@return Return 0 if the operation done without any problem, or errno in the case of error.
*	@brief
*/
extern int ospReadDirectory(const char * _path, void * _buffer, fuse_fill_dir_t _filler, 
	off_t _offset, struct fuse_file_info * _fileInfo);

/**
*	@param _path 
*	@param _fileInfo
*	@return Return 0 if the operation finish without any problem or error in the case of fail.
*	@brief This operation usually is called when creation or truncation wasn't used.
*/
extern int ospOpen(const char * _path, struct fuse_file_info * _fileInfo);

/**
*	@param _path
*	@param _buffer
*	@param _size
*	@param _offset
*	@param _fileInfo
*	@return Return 0 in the case of sucessful or negative number in the case of fail
*	@brief
*/
extern int ospRead(const char * _path, char * _buffer, size_t _size, off_t _offset, 
	struct fuse_file_info * _fileInfo);

/**
*	@param _path Path of the directory for write.
*	@param _buffer Buffer with the information for save.
*	@param _size Total of bytes for write.
*	@param _offset Offset for write a data.
*	@param _fileInfo Informations of all the files.
*	@return Return the total of bytes write, otherwise return a error code.
*	@brief Just write data in the open file.
*/
extern int ospWrite(const char * _path, const char * _buffer, size_t _size, off_t _offset,
	struct fuse_file_info * _fileInfo);

#endif
