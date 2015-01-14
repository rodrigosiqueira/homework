extern "C" 
{
  #include "dotProductStub.h"
}

__global__ void MatrixMulKernel(int * _matrixA, int * _matrixB, 
                                int * _result, int _width)
{
  int k = 0, elementA = 0, elementB = 0;
  //2D thread ID
  int tx = threadIdx.x;
  int ty = threadIdx.y;

  //valeu store the _result element that is computed by thread
  int value = 0;
  for (k = 0; k < _width; k++)
  {
      elementA = *(_matrixA + (ty*_width + k));  //Go accross the line
      elementB = *(_matrixB + (k*_width + tx));  //Go accross the column
      value += (elementA * elementB);   //Take each element
  }
  *(_result + (_width*ty + tx)) = value;

  return;
}

void matrixMultiplication(int * _matrixA, int * _matrixB, int * _result, 
                          int _width)
{
  int size = _width * _width * sizeof(int);
  int * matrixADevice, * matrixBDevice, * resultDevice;

  //Transfer MatrixA and MatrixB to device memory
  cudaMalloc((void**) &matrixADevice, size);
  cudaMemcpy(matrixADevice, _matrixA, size, cudaMemcpyHostToDevice);
  cudaMalloc((void**) &matrixBDevice, size);
  cudaMemcpy(matrixBDevice, _matrixB, size, cudaMemcpyHostToDevice);

  //Allocate result on the device
  cudaMalloc((void**) &resultDevice, size);

  //Invoking kernel
  dim3 dimBlock(_width, _width);
  dim3 dimGrid(1, 1);
  MatrixMulKernel<<<dimGrid, dimBlock>>>(matrixADevice, matrixBDevice, 
                                         resultDevice, _width);

  //Transfer from device to host
  cudaMemcpy(_result, resultDevice, size, cudaMemcpyDeviceToHost);

  //Free memory
  cudaFree(matrixADevice);
  cudaFree(matrixBDevice);
  cudaFree(resultDevice);
}

