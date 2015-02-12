#ifndef _NEW_H_
#define _NEW_H_

extern void * new(const void * _class, ...);
extern void * delete(void * _class);
extern int differ(const void * self, const void * b);
extern void * clone(const void * _self); 

#endif
