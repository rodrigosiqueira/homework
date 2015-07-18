/**
*Based on: https://iws44.iiita.ac.in/wiki/opencl/doku.php?id=clgetmemobjectinfo
*/

#include <stdio.h>
#include <CL/cl.h>

void printError(cl_int err)
{
  switch (err)
  {
    case CL_INVALID_CONTEXT:
      puts("Context is not a valid context..");
      break;
    case CL_INVALID_VALUE:
      puts("Vvalues specified in flags are not valid.");
      break;
    case CL_INVALID_BUFFER_SIZE:
      puts("Size is 0 or is greater than CL_DEVICE_MAX_MEM_ALLOC_SIZE");
      break;
    case CL_INVALID_HOST_PTR:
      puts("Host_ptr is NULL and CL_MEM_USE_HOST_PTR or CL_MEM_COPY_HOST_PTR");
      break;
    case CL_MEM_OBJECT_ALLOCATION_FAILURE:
      puts("There is a failure to allocate memory for buffer object.");
      break;
    case CL_OUT_OF_HOST_MEMORY:
      puts("There is a failure to allocate resources required by the OpenCL implementation on the host.");
      break;
    case CL_INVALID_MEM_OBJECT:
      puts ("memobj");
      break;
    default:
      puts ("Error, I do not know witch one.");
      break;

  }
}

int main()
{
  cl_platform_id platformId = NULL;
  cl_device_id device_id = NULL;
  cl_context context = NULL;
  float mainData[1000];

  cl_int err;
  cl_uint ret_value;
  void * returnedData =  NULL;

  cl_mem memObjectX = NULL;

  //1 : Get platform ID
  err = clGetPlatformIDs(1, &platformId, NULL);
  printf("platform: %p\n", &platformId);

  //2 : Get information about device
  err = clGetDeviceIDs(platformId, CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
  printf("device_id: %p\n", &platformId);

  //3 : Create context
  context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &err);
  memObjectX = clCreateBuffer(context,
                      CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, 
                      sizeof(mainData), mainData, &err);
  if (err != CL_SUCCESS)
  {
    puts("Create buffer problem");
    printError(err);
  }

  //4 : Memory information
  //Return the host_ptr argument value specified when memobj is created.
  size_t sizeReturned = -23;
  err = clGetMemObjectInfo(memObjectX,  CL_MEM_HOST_PTR,
                        sizeof(returnedData), &returnedData, NULL);

  printf("==> Size returned: %d\n", (int) sizeReturned);
  printf("==> Returned data: %p\n", returnedData);

  if (err != CL_SUCCESS)
  {
    printError(err);
  }

  //This feature is provided for identifying memory leaks. 
  err = clGetMemObjectInfo(memObjectX, CL_MEM_REFERENCE_COUNT,
                            sizeof(cl_uint), &ret_value, NULL);
  if (err != CL_SUCCESS)
  {
    printError(err);
  }

  puts("");
  printf( "Current Reference Count: %d\n", ret_value );

  return 0;
}
