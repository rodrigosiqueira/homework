/**
*Based on: https://iws44.iiita.ac.in/wiki/opencl/doku.php?id=clgetmemobjectinfo
*
*/

#include <stdio.h>
#include <CL/cl.h>

int main()
{
  cl_platform_id platformId = NULL;
  cl_device_id device_id = NULL;
  cl_context context = NULL;

  cl_int err;
  cl_uint ret_value;
  void * returnedData =  NULL;

  cl_mem memObjectX = NULL;

  //1 : Get platform ID
  err = clGetPlatformIDs(1, &platformId, NULL);
  //2 : Get information about device
  err = clGetDeviceIDs(platformId, CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
  //3 : Create context
  context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &err);
  memObjectX = clCreateBuffer(context, CL_MEM_READ_WRITE, 1, NULL, NULL);

  //4 : Memory information
  //This feature is provided for identifying memory leaks. 
  err = clGetMemObjectInfo(memObjectX, CL_MEM_REFERENCE_COUNT,
                        sizeof(cl_uint), &ret_value, NULL);
  //Return the host_ptr argument value specified when memobj is created.
  err = clGetMemObjectInfo(memObjectX,  CL_MEM_HOST_PTR,
                        sizeof(cl_uint), &returnedData, NULL);

  printf( "Current Reference Count: %d\n", ret_value );
  printf( "Memory object: %p\n", returnedData );

  return 0;
}
