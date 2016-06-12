/**
* @file set.h
*/
#ifndef _SET_H_
#define _SET_H_

extern const void * Set; /**< */

/**
* @param set Set to add the element.
* @param element Element to add to set.
* @return Return a reference.
* brief Takes an element, adds it to a set, and returns whatever was added or 
*   already present in the set
*/
void * add(void * set, const void * element);

/**
* @param set Set to find an element.
* @param element Element to try to find in Set.
* @return Return the element.
* @brief Looks for an element in a set and returns whatever is present.
*/
void * find(const void * set, const void *element);

/**
* @param set Target set.
* @param element Remove element from set.
* @return Return whatever to be removed.
* @brief Locates an element, removes it from a set, and retrun whatever 
*   was removed
*/
void * drop(void * set, const void * element);

/**
* @param set Any set to verify.
* @param element Element for verify if is inside of set.
* @return 
* @brief Converts the result of find into a truth value.
*/
int contains(const void * set, const void * element);

#endif
