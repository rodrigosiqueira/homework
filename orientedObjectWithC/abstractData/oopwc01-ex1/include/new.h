#ifndef NEW_H
#define NEW_H

/* Allocate space for new type and return a reference to it
 */
void * new (const void * type, ...);

/* Remove an object from memory
 */
void delete(void * target);

#endif
