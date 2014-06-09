#ifndef __DATA_TYPE_H__
#define __DATA_TYPE_H__

#define FUSE_USE_VERSION 30
#define _XOPEN_SOURCE 500

#include <limits.h>
#include <stdio.h>

struct stateFilesystem
{
	FILE * logFile;
	char * rootDirectory;
};

#define OSPDATA ((struct stateFilesystem *) fuse_get_context()->private_data) 

#endif
