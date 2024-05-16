#include <linux/module.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");

static int errval = 0;

module_param(errval, int, S_IRWXU);
MODULE_PARM_DESC(errval, "Value to return from init function");

int my_init_func(void) {
  printk(KERN_CRIT "CRIT: errval=%d\n", errval);
  printk(KERN_ERR "ERR: errval=%d\n", errval);
  printk(KERN_INFO "INFO: errval=%d\n", errval);
  printk(KERN_DEBUG "DBG: errval=%d\n", errval);
  return errval;
}

void my_cleanup_func(void) { 
    printk(KERN_WARNING "The module is now unloaded\n"); 
}

module_init(my_init_func);
module_exit(my_cleanup_func);