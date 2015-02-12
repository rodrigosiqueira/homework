#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>

#include "dataType.h"
#include "new.h"

void * new(const void * _class, ...)
{
  const struct Class * class = _class;
  void * pointer = calloc(1, class->size);

  assert(pointer);
  * (const struct Class **) pointer = class;

  if (class->constructor)
  {
    va_list ap;
    va_start(ap, _class);
    pointer = class->constructor(pointer, &ap);
    va_end(ap);
  }
  return pointer;
}

void * delete(void * _self)
{
  const struct Class ** cp = _self;
  if (_self && * cp && (*cp)->destructor)
  {
    _self = (*cp)->destructor(_self);
  }
  free(_self);
}

void * clone(const void * _self)
{
  const struct Class * const * cp = _self;
  assert(_self && *cp && (*cp)->clone);
  return (* cp)->clone(_self);
}

int differ(const void * self, const void * b)
{
  const struct Class * const * cp = self;
  assert(self && * cp && (*cp)->differ);
  return (*cp)->differ(self, b);
}

size_t sizeOf(const void * self)
{
  const struct Class * const * cp = self;
  assert(self && * cp);
  return (* cp)->size;
}
