#include <assert.h>
#include "Object.h"

int differ(const void * objectA, const void * objectB)
{
  return objectA != objectB;
}
