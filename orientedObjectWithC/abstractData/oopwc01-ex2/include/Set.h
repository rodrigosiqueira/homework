#ifndef SET_H
#define SET_H

struct Set
{
  unsigned count;
};

struct Object
{
  unsigned count;
  struct Set * in;
};

/* Add new object to a set element
 */
void * add(void * set, const void * object);

/* Find the object inside set
 */
void * find(const void * set, const void * object);

/* Remove object from set
 */
void * drop(void * set, const void * object);

/* Check if object is contained inside set
 */
int contains(const void * set, const void * object);

#endif
