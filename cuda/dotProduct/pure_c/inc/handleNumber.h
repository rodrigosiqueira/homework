/**
* @brief 
* @file handleNumber.h
*/
#ifndef _HANDLE_NUMBER_H_
#define _HANDLE_NUMBER_H_
/**
* @param _width Width of matrix.
* @param _height Height of matrix.
* @return Return a reference to allocated matrix.
* @brief This method generate a matrix based on width and height, wherein 
*       each element of the matrix is generated randomly.
*/
extern int * generateRandomMatrix(const unsigned char _width, 
                                  const unsigned char _height);

/**
* @param _width Width of matrix.
* @param _height Height of matrix.
* @return Return a reference of allocated matrix.
* @brief Create an empty matrix.
*/
extern int * emptyMatrix(const unsigned char _width, 
                         const unsigned char _height);

/**
* @param _matrixA First matrix for dot product.
* @param _matrixB Second matrix for dot product.
* @param _result Matrix for allocate the final result.
* @param _width Width of the matrix.
* @brief Apply dot product.
*/
extern void dotProduct(const int * _matrixA, const int * _matrixB, 
                       int * _result, const unsigned char _width);

#endif
