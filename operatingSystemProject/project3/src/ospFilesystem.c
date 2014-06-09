/**
*	@file ospFilesystem.c
*	@brief
*/

#define FUSE_USE_VERSION 30

#include <fuse.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/xattr.h>
#include <limits.h>

#include <ospFilesystem.h>
#include <dataType.h>
#include <log.h>

static void fullPath(const char * _path, char _filePath[PATH_MAX])
{
	strcpy(_filePath, OSPDATA->rootDirectory);
	strncat(_filePath, _path, PATH_MAX);
	logMessage("\n FULL PATH: root =  %s, path = %s, filePath = %s \n", 
			OSPDATA->rootDirectory, _path, _filePath);
	
	return;
}

int ospGetAttribute(const char * _path, struct stat * _statusBuffer)
{
	int result = 0;
	char filePath[PATH_MAX];

	logMessage("\n GET ATTRIBUTE: PATH = %s, STATUS BUFFER = %0x%08x \n", _path, _statusBuffer);
	fullPath(_path, filePath);

	result = lstat(filePath, _statusBuffer);
	if(result != 0)
	{
		logMessage("\n GET ATTRIBUTE (lstat): %s \n", strerror(errno));
		return -errno;
	}

	return 0;
}

int ospReadDirectory(const char * _path, void * _buffer, fuse_fill_dir_t _filler, 
	off_t _offset, struct fuse_file_info * _fileInfo)
{
	DIR * directoryPath = 0;
	struct dirent * formatOfDirectory;

	logMessage("\n READ DIRECTORY: path = %s, buffer = 0x%08x, offset = %lld \n", _path, _buffer, _offset);

	directoryPath = (DIR*)(uintptr_t) _fileInfo->fh;

	formatOfDirectory = readdir(directoryPath);

	if(formatOfDirectory == 0)
	{
		logMessage("\n Error when tried to read the directory. \n");
		return -errno;
	}
	
	do
	{
		if(_filler(_buffer, formatOfDirectory->d_name, NULL, 0) != 0)
		{
			logMessage("\n ERROR WHEN TRY TO READ THE BUFFER \n");
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
	if(fileDescriptor < 0)
	{
		logMessage("\n OPEN: Error when try to open. \n");
		return -errno;
	}

	_fileInfo->fh = fileDescriptor;
	logFileInformation(_fileInfo);

	return 0;
}

void * ospInit(struct fuse_conn_info * _connection)
{
	logMessage("\n OSP INIT!! \n");
	return OSPDATA;
}


int ospRead(const char * _path, char * _buffer, size_t _size, off_t _offset, 
	struct fuse_file_info * _fileInfo)
{
	int totalByte = 0;

	totalByte = pread(_fileInfo->fh, _buffer, _size, _offset);
	if(totalByte == -1)
	{
		logMessage("\n READ FAIL \n");
		return -errno;
	}

	return totalByte;
}

int ospWrite(const char * _path, const char * _buffer, size_t _size, off_t _offset,
	struct fuse_file_info * _fileInfo)
{
	int totalByte = 0;

	totalByte =  pwrite(_fileInfo->fh, _buffer, _size, _offset);
	if(totalByte == -1)
	{
		logMessage("\n WRITE FAIL\n");
		totalByte = -errno;
	}

	return totalByte;
}

int ospOpenDirectory(const char * _path, struct fuse_file_info * _fileInformation)
{
	DIR * directoryPath = 0;
	int returnStat = 0;
	char filePath[PATH_MAX];

	logMessage("\n OPEN DIRECTORY: path = %s, file information: %s  \n", _path, _fileInformation);

	fullPath(_path, filePath);

	directoryPath = opendir(filePath);
	if(directoryPath == NULL)
	{
		logMessage("Error when try to open. \n");
		return -errno;
	}

	_fileInformation->fh = (intptr_t) directoryPath;

	logFileInformation(_fileInformation);

	return returnStat;
}

int ospMkdir(const char * _path, mode_t _mode)
{
	int returnStat = 0;
	char filePath[PATH_MAX];

	logMessage("\n CREATE FOLDER: Path = %s , File path = 0%3o \n", _path, _mode);
	fullPath(_path, filePath);

	returnStat = mkdir(filePath, _mode);
	if(returnStat < 0)
	{
		logMessage("\n CREATE DIRECTORY: ERROR = %s \n", strerror(errno));
		return returnStat;
	}

	return 0;
}

int ospRmdir(const char * _path)
{
	int returnStat = 0;
	char filePath[PATH_MAX];

	logMessage("REMOVE DIRECTORY: %s", _path);

	fullPath(_path, filePath);

	returnStat = rmdir(filePath);
	if(returnStat < 0)
	{
		logMessage("\n REMOVE DIRECTORY: ERROR = %s \n", strerror(errno));
	}

	return returnStat;
}

int ospCreateFile(const char * _path, mode_t _mode, struct fuse_file_info * _fileInfo)
{
	int returnStat = 0;
	char filePath[PATH_MAX];
	int fileDescriptor = 0;

	fullPath(_path, filePath);
	fileDescriptor = creat(filePath, _mode);
	if(fileDescriptor < 0)
	{
		logMessage("\n CREATE FILE: %s \n", strerror(errno));
	}

	_fileInfo->fh = fileDescriptor;

	return returnStat;
}

static struct fuse_operations ospOperations = 
{
	.getattr	= ospGetAttribute,
	.readdir	= ospReadDirectory,
	.open			= ospOpen,
	.opendir	= ospOpenDirectory,
	.mkdir		= ospMkdir,
	.rmdir		= ospRmdir,
	.read			= ospRead,
	.write		= ospWrite,
	.init			= ospInit,
	.create		= ospCreateFile,
};

int main(int argc, char *argv[])
{
	int fuseStat = 0;
	struct stateFilesystem * data;
	
	//Check the permission
	if((getuid() == 0) || (geteuid() == 0))
	{
		fprintf(stderr, "Fail in the security access.");
	}

	data = malloc(sizeof(struct stateFilesystem));
	if(data == NULL)
	{
		perror("main calloc");
		abort();
	}

	data->rootDirectory = realpath(argv[argc - 2], NULL);
	argv[argc - 2] = argv[argc - 1];
	argv[argc - 1] = NULL;
	argc--;

	data->logFile = logOpen();

	fuseStat = fuse_main(argc, argv, &ospOperations, data);

	return fuseStat;
}
