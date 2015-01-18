#include <linux/module.h>
#include <linux/init.h>

#include "../inc/hello.h"

MODULE_LICENSE("DUAL BSD / GPL");

int initializeHello(void)
{
  printk("<1> Hello world: organized");
  return 0;
}

void exitInitialize(void)
{
  printk("<1> It time to say Good by! Just let me go... hehehe");
  return;
}

module_init(initializeHello);
module_exit(exitInitialize);
