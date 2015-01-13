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

#endif
