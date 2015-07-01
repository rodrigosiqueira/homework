#include <CL/cl.h>

int main(int argc, char ** argv)
{
  cl_platform_id platforms = 0;
  cl_uint num_platforms;
  cl_int retPlatform = 0, retDevices = 0;
  cl_uint retNumDevices = 0;

  cl_device_id deviceID = NULL;

  // Discover a set of available platform.
  retPlatform = clGetPlatformIDs(1, &platforms, &num_platforms);

  // Discover devices IDs
  retDevices = clGetDeviceIDs(platforms, CL_DEVICE_TYPE_ALL, 1,
                              &deviceID, &retNumDevices); 

  // Get information
  clGetPlatformInfo();

  return 0;
}
