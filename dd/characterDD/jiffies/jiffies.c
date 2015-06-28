#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <asm/uaccess.h>

#define MODULE_NAME "TEST"

static struct proc_dir_entry * jiffies_dir, * jiffies_file;

static int jiffies_read (char * page, char ** start, off_t off, int count,
                         int * eof, void * data)
{
  int len;

  /*MOD_INC_USE_COUNT;*/

  len = sprintf(page, "jiffies = %ld\n", jiffies);

  /*MOD_DEC_USE_COUNT;*/

  return len;
}

static int __init init_procfs_example (void)
{
  //Cria um diretório
  jiffies_dir = proc_mkdir (MODULE_NAME, NULL);
  if (jiffies_dir == NULL)
  {
    return -ENOMEM;
  }
  jiffies_dir->owner = THIS_MODULE;

  //Cria um arquivo chamdo jiffies
  jiffies_file = create_proc_read_entry("jiffies", 0444, jiffies_dir,
                          jiffies_read, NULL);

  if (jiffies_file == NULL)
  {
    remove_proc_entry ("tty", jiffies_dir);
    return -ENOMEM;
  }

  jiffies_file->owner = THIS_MODULE;

  printk(KERN_INFO "%s carregado\n", MODULE_NAME);
  return 0;
}

static void __exit cleanup_procfs_examples (void)
{
  remove_proc_entry("jiffies", jiffies_dir);
  remove_proc_entry(MODULE_NAME, NULL);
  printk (KERN_INFO "%s removido\n", MODULE_NAME);
}

//MACRO
module_init (init_procfs_example);
module_exit (cleanup_procfs_examples);

MODULE_DESCRIPTION ("Exemplo de procfs");
MODULE_LICENSE("GPL");
