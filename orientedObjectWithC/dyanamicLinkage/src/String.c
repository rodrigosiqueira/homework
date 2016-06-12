#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "String.h"
#include "new.h"
#include "dataType.h"

static void * stringConstructor(void * _self, va_list * app)
{
  struct String * self = _self;
  const char * text = va_arg(* app, const char *);

  self->text = malloc((size_t)strlen(text) + 1);
  assert(self->text);
  strcpy(self->text, text);
  return self;
}

static void * stringDestructor(void * _self)
{
  struct String * self = _self;
  free(self->text);
  self->text = 0;
  return self;
}

static void * stringClone(const void * _self)
{
  const struct String * self = _self;
  return new(String, self->text);
}

static int stringDiffer(const void * _self, const void * _b)
{
  const struct String * self = _self;
  const struct String * b = _b;

  if (self == b)
  {
    return 0;
  }

  if (!b || b->class != String)
  {
    return 1;
  }

  return strcmp(self->text, b->text);
}

static const struct Class _String = 
{
  sizeof(struct String),
  stringConstructor, 
  stringDestructor,
  stringClone, 
  stringDiffer
};

const void * String = & _String;

