#include <linux/fs.h>
#include <linux/cdev.h>

#define NUM_CMOS_BANKS 2

//Per-device (per-bank) structure
struct cmos_dev
{
  unsigned short current_pointer;       /**< Current pointer within the bank.*/
  unsigned int size;                    /**< Size of the bank.*/
  int bank_number;                      /**< CMOS bank number.*/
  struct cdev cdev;                     /**< The cdev structure.*/
  char name[10];                        /**< Name of I/O.*/
} * cmos_devp[NUM_CMOS_BANKS]
