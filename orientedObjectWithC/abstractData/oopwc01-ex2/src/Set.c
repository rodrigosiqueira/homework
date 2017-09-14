#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "Set.h"
#include "new.h"

static const size_t _Set = sizeof(struct Set);
static const size_t _Object = sizeof(struct Object);

const void * Set = &_Set;
const void * Object = &_Object;

void * new (const void * type, ...)
{
  const size_t size = * (const size_t *) type;
  void * newElement = calloc(1, size);
  assert(newElement);
  return newElement;
}

void delete(void * target)
{
  if (target)
    free(target);
}

void * add(void * _set, const void * _object)
{
  struct Set * set = _set;
  struct Object * object = (void *) _object;

  assert(set);
  assert(object);

  if (!object->in)
    object->in = set;
  else
    assert(object->in == set);

  object->count++;
  set->count++;

  return object;
}

void * find(const void * _set, const void * _object)
{
  struct Object * object = (void *) _object;

  assert(_set);
  assert(object);

  return (object->in == _set) ? (void *) object : 0;
}

int contains(const void * _set, const void * _object)
{
  return find(_set, _object) != 0;
}

void * drop(void * _set, const void * _object)
{
  struct Set * set = _set;
  struct Object * object = find(_set, _object);

  if (object) {
    object->count--;
    if (!object->count)
      object->in = 0;
    set->count--;
  }

  return object;
}
