#include <stdio.h>

#include "new.h"
#include "Object.h"
#include "Set.h"

const void * Object;
const void * Set;

int main (int argc, char ** argv)
{
  // Set class
  void * s = new(Set);

  // Elements
  void * o1 = new(Object);
  void * o2 = new(Object);
  void * o3 = new(Object);

  // Play a little
  add(s, o1);
  add(s, o2);

  // Verify some stuffs
  if (contains(s, o1) && contains(s, o2))
    printf("Yes, o1 and o2 are contained inside set\n");

  if (contains(s, o3))
    printf("o3 was not added to set\n");

  if (differ(o1, add(s, o1)))
    printf("Differ?");

  if (contains(s, drop(s, o1)))
    printf("Not contains anymore\n");

  delete(drop(s, o2));
  delete(drop(s, o3));

  return 0;
}
