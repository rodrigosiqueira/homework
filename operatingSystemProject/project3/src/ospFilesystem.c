/**
*	@file ospFilesystem.c
*	@brief
*/

#define FUSE_USE_VERSION 30

#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/xattr.h>

#include <ospFilesystem.h>

static void fullPath(const char * _path, char _filePath[PATH_MAX])
{
	strcpy(_filePath, OSPDATA->rootDirectory);
	strncat(_filePath, _path, PATH_MAX);
	logMessage("FULL PATH: %s, path: %s, filePath: %s", 
			OSPDATA->rootDirectory, _path, _filePath);
	
	return;
}

int ospGetAttribute(const char * _path, struct stat * _statusBuffer)
{
	int result = 0;
	char filePath[PATH_MAX];

	fullPath(_path, filePath);

	result = lstat(_path, _statusBuffer);
	if(result == -1)
	{
		return -errno;
	}

	return 0;
}

int ospReadDirectory(const char * _path, void * _buffer, fuse_fill_dir_t _filler, 
	off_t _offset, struct fuse_file_info * _fileInfo)
{
	int returnStat = 0;
	DIR * directoryPath = 0;
	struct dirent * formatOfDirectory;

	logMessage("\nREAD DIRECTORY: path = %s, buffer = 0x%08x, offset = %lld\n", _path, _buffer, _offset);

	directoryPath = (DIR*)(uintptr_t) _fileInfo->fh;

	formatOfDirectory = readdir(directoryPath);

	if(formatOfDirectory == 0)
	{
		return -errno;
	}
	
	do
	{
		if(_filler(_buffer, formatOfDirectory->d_name, NULL, 0) != 0)
		{
			logMessage("ERROR WHEN TRY TO READ THE BUFFER");
			return -ENOMEM;
		}
	}while((formatOfDirectory = readdir(directoryPath)) != NULL);

	logFileInformation(_fileInfo);
	
	return 0;
}

int ospOpen(const char * _path, struct fuse_file_info * _fileInfo)
{
	int fileDescriptor = 0;
	char filePath[PATH_MAX];
	
	fullPath(_path, filePath);

	fileDescriptor = open(filePath, _fileInfo->flags);
	if(result == -1)
	{
		logMessage("Error when try to open.");
		return -errno;
	}

	_fileInfo->fh = fileDescriptor;
	logFileInformation(_fileInfo);

	return 0;
}

int ospRead(const char * _path, char * _buffer, size_t _size, off_t _offset, 
	struct fuse_file_info * _fileInfo)
{
	int totalByte = 0;

	totalByte = pread(_fileInfo->fileDescriptor, _buffer, _size, _offset);
	if(totalByte == -1)
	{
		return -errno;
	}

	return totalByte;
}

int ospWrite(const char * _path, const char * _buffer, size_t _size, off_t _offset,
	struct fuse_file_info * _fileInfo)
{
	int totalByte = 0;

	totalByte =  pwrite(fileDescriptor, _buffer, _size, _offset);
	if(totalByte == -1)
	{
		totalByte = -errno;
	}

	return totalByte;
}

static struct fuse_operations ospOperations = 
{
	.getattr	= ospGetAttribute,
	.readdir	= ospReadDirectory,
	.open			= ospOpen,
	.read			= ospRead,
	.write		= ospWrite,
};

int main(int argc, char *argv[])
{
	umask(0);

	fuse_main(argc, argv, &ospOperations, NULL);

	return 0;
}
