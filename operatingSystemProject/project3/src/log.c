/**
*	@file log.c
*/

#include <dataType.h>

#include <fuse.h> 
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <log.h>

FILE * logOpen()
{
	FILE * logFile = 0;

	logFile = fopen(FUSELOG, "w");
	
	if(logFile == NULL) 
	{
		perror("logfile");
		return NULL;
	}
    
	setvbuf(logFile, NULL, _IOLBF, 0);
	return logFile;
}

void logMessage(const char * _format, ...)
{
    va_list arguments;
    va_start(arguments, _format);

    vfprintf(OSPDATA->logFile, _format, arguments);
}
    
void logFileInformation(struct fuse_file_info * _fileInfo)
{
	log_struct(_fileInfo, flags, 0x%08x, );	
	log_struct(_fileInfo, fh_old, 0x%08lx, );
	log_struct(_fileInfo, writepage, %d, );
	log_struct(_fileInfo, direct_io, %d, );
	log_struct(_fileInfo, keep_cache, %d, );
	log_struct(_fileInfo, fh, 0x%016llx,  );
	log_struct(_fileInfo, lock_owner, 0x%016llx, );
};

void logStat(struct stat * _statInfo)
{
	log_struct(_statInfo, st_dev, %lld, );
	log_struct(_statInfo, st_ino, %lld, );
	log_struct(_statInfo, st_mode, 0%o, );
	log_struct(_statInfo, st_nlink, %d, );
	log_struct(_statInfo, st_uid, %d, );
	log_struct(_statInfo, st_gid, %d, );
	log_struct(_statInfo, st_rdev, %lld,  );
	log_struct(_statInfo, st_size, %lld,  );
	log_struct(_statInfo, st_blksize, %ld,  );
	log_struct(_statInfo, st_blocks, %lld,  );
	log_struct(_statInfo, st_atime, 0x%08lx, );
	log_struct(_statInfo, st_mtime, 0x%08lx, );
	log_struct(_statInfo, st_ctime, 0x%08lx, );
}

void logStatvfs(struct statvfs * _statusVfs)
{
	log_struct(_statusVfs, f_bsize, %ld, );
	log_struct(_statusVfs, f_frsize, %ld, );
	log_struct(_statusVfs, f_blocks, %lld, );
	log_struct(_statusVfs, f_bfree, %lld, );
	log_struct(_statusVfs, f_bavail, %lld, );
	log_struct(_statusVfs, f_files, %lld, );
	log_struct(_statusVfs, f_ffree, %lld, );
	log_struct(_statusVfs, f_favail, %lld, );
	log_struct(_statusVfs, f_fsid, %ld, );
	log_struct(_statusVfs, f_flag, 0x%08lx, );
	log_struct(_statusVfs, f_namemax, %ld, );
}

void logUtime(struct utimbuf * _buffer)
{
	log_struct(_buffer, actime, 0x%08lx, );
	log_struct(_buffer, modtime, 0x%08lx, );
}
