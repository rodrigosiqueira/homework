#include <stdio.h>
#include <stdlib.h>

#include <CL/cl.h>

const char * programSource = 
"__kernel                                       \n"
"void vecadd (__global int * A,                 \n"
"       __global int * B,                       \n"
"       __global int * C)                       \n"
"{                                              \n"
"  //Get the work-item unique ID                \n"
"  int idx = get_global_id(0);                  \n"
"                                               \n"
"  //Add the corresponding location of          \n"
"  //'A' and 'B', and store the result in 'C'.  \n"
"  C[idx] = A[idx] + B[idx];                    \n"
"}                                              \n";

int main()
{
  //This code executes on the OpenCL host

  //Host data
  int * A = NULL; //Input array
  int * B = NULL; //Input array
  int * C = NULL; //Output array

  //Elements in each array
  const int elements = 2048;
  
  //Compute the size of data
  size_t datasize = sizeof(int) * elements;

  //Allocate space for input/output data
  A = (int *)malloc(datasize);
  B = (int *)malloc(datasize);
  C = (int *)malloc(datasize);

  puts ("After allocation");

  //Initialize the input data
  int i;
  for (i = 0; i < elements; i++)
  {
    A[i] = i;
    B[i] = i;
  }

  puts ("After for");
  //Use this check the output of each API call
  cl_int status;

  /******************************************************************/
  /* PLATFORM */
  /******************************************************************/
  //Retrieve the number of platforms
  cl_uint numPlatforms = 0;
  puts ("Before get platform.");
  status = clGetPlatformIDs(0, NULL, &numPlatforms);

  //Allocate enough space for each platform
  cl_platform_id * platforms = NULL;
  printf ("Total platform: %d\n", numPlatforms);
  platforms = (cl_platform_id *)malloc(numPlatforms * sizeof(cl_platform_id));

  //Fill in the platforms
  puts ("Before fill platform");
  status = clGetPlatformIDs(numPlatforms, platforms, NULL);

  /******************************************************************/
  /* DEVICE ID */
  /******************************************************************/
  cl_uint numDevices = 0;
  puts ("Before get devices");
  status = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_ALL, 0,
                          NULL, &numDevices);
  //Alocate enough space for each device
  cl_device_id * devices;
  devices = (cl_device_id *) malloc(numDevices * sizeof(cl_device_id));

  //Fill in the devices
  puts ("Before alloc get devices");
  status = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_ALL,
                          numDevices, devices, NULL);
  printf ("total devices: %d\n", numDevices);
  printf ("devices: %p\n", devices);
  /******************************************************************/
  /* CONTEXT */
  /******************************************************************/
  cl_context context;
  puts ("Before context");
  context = clCreateContext(NULL, numDevices, devices, NULL, NULL, &status);

  /******************************************************************/
  /* COMMAND QUEUE */
  /******************************************************************/
  cl_command_queue cmdQueue;
  puts ("Before clCreateCommandQueue");
  cmdQueue = clCreateCommandQueue (context, devices[0], 0, &status);

  /******************************************************************/
  /* BUFFER OBJECT */
  /******************************************************************/
  cl_mem bufA;
  puts ("Before clCreateBuffer A.");
  bufA = clCreateBuffer(context, CL_MEM_READ_ONLY, datasize, NULL, &status);

  cl_mem bufB;
  puts ("Before clCreateBuffer A.");
  bufB = clCreateBuffer(context, CL_MEM_READ_ONLY, datasize, NULL, &status);

  // Create a buffer object that will hold the output
  cl_mem bufC;
  puts ("Before clCreateBuffer A.");
  bufC = clCreateBuffer(context, CL_MEM_WRITE_ONLY, datasize, NULL, &status);

  //Write input array A to the device bufferA
  puts ("Before clEnqueueWriteBuffer A.");
  status = clEnqueueWriteBuffer(cmdQueue, bufA, CL_FALSE, 0, 
                                datasize, A, 0, NULL, NULL);

  //Write input array B to the device bufferB
  puts ("Before clEnqueueWriteBuffer B.");
  status = clEnqueueWriteBuffer(cmdQueue, bufB, CL_FALSE, 0,
                               datasize, B, 0, NULL, NULL);

  /******************************************************************/
  /*Create a program with source code*/
  /******************************************************************/
  puts ("Before clCreateProgramWithSource.");
  cl_program program = clCreateProgramWithSource(context, 1,
                        (const char **)&programSource, NULL, &status);

  status = clBuildProgram(program, numDevices, devices, NULL, NULL, NULL);

  //Create the vector addition kernel
  cl_kernel kernel;
  kernel = clCreateKernel(program, "vecadd", &status);

  //Associate the input and output buffer with the kernel
  status = clSetKernelArg(kernel, 0, sizeof (cl_mem), &bufA);
  status = clSetKernelArg(kernel, 1, sizeof (cl_mem), &bufB);
  status = clSetKernelArg(kernel, 2, sizeof (cl_mem), &bufC);

  //Define an index space
  size_t globalWorkSize[1];

  // Execute the kernel for execution
  status = clEnqueueNDRangeKernel(cmdQueue, kernel, 1, NULL, globalWorkSize,
                                NULL, 0, NULL, NULL);

  // Read the device output buffer to the host output array
  clEnqueueReadBuffer(cmdQueue, bufC, CL_TRUE, 0, datasize, C, 0, NULL, NULL);

  //Verify the output
  int result = 1;
  for (i = 0; i < elements; i++)
  {
    if (C[i] != i + i)
    {
      result = 0;
      break;
    }
  }

  if (result)
  {
    printf("Output is correct\n");
  }
  else
  {
    printf("Output is wrong\n");
  }

  //Free OpenCL resoureces
  clReleaseKernel(kernel);
  clReleaseProgram(program);
  clReleaseCommandQueue(cmdQueue);
  clReleaseMemObject(bufA);
  clReleaseMemObject(bufB);
  clReleaseMemObject(bufC);
  clReleaseContext(context);
  //Free host resources
  free(A);
  free(B);
  free(C);
  free(platforms);
  free(devices);
  
  return 0;
}
