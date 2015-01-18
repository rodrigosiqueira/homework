#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

//Call the initialization
static int hello_init(void)
{
  printk("<1> Hello world!\n");
  return 0;
}

static void hello_exit(void)
{
  printk("<1> Bye, cruel world \n");
}

module_init(hello_init);
module_exit(hello_exit);
