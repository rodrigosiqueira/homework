#include <stdio.h>
#include "new.h"
#include "object.h"
#include "set.h"

const void * Set;
const void * Object; 

int main()
{
  void * s = new(Set);
  void * a = add(s, new(Object));
  void * b = add(s, new(Object));
  void * c = new(Object);

  if (contains(s, a) && contains(s, b))
  {
    puts("Ok");
  }

  if (contains(s, c))
  {
    puts("constains?");
  }

  if (differ(a, add(s, a)))
  {
    puts("differs?");
  }

  if (contains(s, drop(s, a)))
  {
    puts("drop?");
  }

  delete(drop(s, b));
  delete(drop(s, c));

  return 0;
}