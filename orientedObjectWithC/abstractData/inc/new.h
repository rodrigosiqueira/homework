#ifndef _NEW_H_
#define _NEW_H_

/**
* @param type Type do be used.
* @return Returns a pointer to new data item with a representation conforming 
*   to the descriptor.
* @brief Accepts a descriptor like Set and possibly more arguments for 
*  initialization.
*/
void * new(const void * type, ...);

/**
* @param item Element to be removed.
* @brief Recycles the associated resources.
*/
void delete(void * item);

#endif
