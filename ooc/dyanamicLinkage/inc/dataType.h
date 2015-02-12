#ifndef _DATA_TYPE_H_
#define _DATA_TYPE_H_

#include <stdarg.h>
#include <stdio.h>

struct Class
{
  size_t size;
  void * (* constructor) (void * self, va_list * app);
  void * (* destructor) (void * self);
  void * (* clone)(const void * self);
  int (* differ) (const void * self, const void * b);
};

struct String
{
  const void * class;
  char * text;
};

#endif
