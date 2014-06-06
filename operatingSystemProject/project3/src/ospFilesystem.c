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

int ospGetAttribute(const char * _path, struct stat * _statusBuffer)
{
	int res = 0;

	res = lstat(_path, _statusBuffer);
	if(res == -1)
	{
		return -errno;
	}

	return 0;
}

int ospReadDirectory(const char * _path, void * _buffer, fuse_fill_dir_t _filler, 
	off_t _offset, struct fuse_file_info * _fileInfo)
{
	DIR * directoryPath = 0;

	//struct dirent * direntExtern;

	(void) _offset;
	(void) _fileInfo;

	directoryPath = opendir(_path);
	if(directoryPath == NULL)
	{
		return -errno;
	}
	/*
	while((direntExtern = readdir(directoryPath)) != NULL)
	{
		struct stat status;
		memset(&status, 0, sizeof(status));
		status.st_ino = direntExtern->d_ino;
		status.st_mode = direntExtern->d_type << 12;
		if(_filler(_buffer, direntExtern->d_name, &status, 0))
		{
			break;
		}
	}
	closedir(directoryPath);
	*/
	_filler(_buffer, ".", NULL, 0);
	_filler(_buffer, "..", NULL, 0);
	_filler(_buffer, _path + 1, NULL, 0);
	return 0;
}

int ospOpen(const char * _path, struct fuse_file_info * _fileInfo)
{
	int res = 0;

	res = open(_path, _fileInfo->flags);
	if(res == -1)
	{
		return -errno;
	}

	close(res);
	return 0;
}

int ospRead(const char * _path, char * _buffer, size_t _size, off_t _offset, 
	struct fuse_file_info * _fileInfo)
{
	int fileDescriptor = 0;
	int res = 0;

	(void) _fileInfo;
	fileDescriptor = open(_path, O_RDONLY);
	if(fileDescriptor == -1)
	{
		return -errno;
	}

	res = pread(fileDescriptor, _buffer, _size, _offset);
	if(res == -1)
	{
		return -errno;
	}

	close(fileDescriptor);
	return res;
}

int ospWrite(const char * _path, const char * _buffer, size_t _size, off_t _offset,
	struct fuse_file_info * _fileInfo)
{
	int fileDescriptor = 0;
	int res = 0;

	(void) _fileInfo;
	fileDescriptor = open(_path, O_WRONLY);
	if(fileDescriptor == -1)
	{
		return -errno;
	}

	res = pwrite(fileDescriptor, _buffer, _size, _offset);
	if(res == -1)
	{
		res = -errno;
	}

	close(fileDescriptor);
	return res;
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
