#include <stdio.h>
#include <assert.h>
#include "Set.h"
#include "new.h"

#if ! defined MANY || MANY < 1
#define MANY 10
#endif

/* For this example, we have a very rustic memory management based on array.
 * Note: There is a trick here, heap is a static global variable which means
 * it is not at the stack and all the initial values are set to 0.
 */
static int heap[MANY];

void * new (const void * type, ...)
{
  int * position = 0;

  for (position = heap + 1; position < heap + MANY; position++)
    if (!*position)
      break;
  assert(position < heap + MANY);
  *position = MANY;
  return position;
}

void delete(void * target)
{
  int * toRemove = target;

  if (toRemove)
  {
    assert(toRemove > heap && toRemove < heap + MANY);
    *toRemove = 0;
  }
}

void * add(void * _set, const void * _object)
{
  int * set = _set;
  const int * object = _object;

  assert(set > heap && set < heap + MANY);
  assert(*set == MANY);
  assert(object > heap && object < heap + MANY);

  // If true, means that object exists but is not a part of set
  if (*object == MANY)
    * (int *) object = set - heap;
  else
    assert(*object == set - heap);
  return (void *) object;
}

void * find(const void * _set, const void * _object)
{
  const int * set = _set;
  const int * object = _object;

  assert(set > heap && set < heap + MANY);
  assert(object > heap && set < heap + MANY);
  assert(*set == MANY);
  assert(*object);

  return * object == set - heap ? (void *) object : 0;
}

int contains(const void * _set, const void * _object)
{
  return find(_set, _object) != 0;
}

void * drop(void * _set, const void * _object)
{
  int * object = find(_set, _object);

  if (object)
    * object = MANY;
   return object;
}
