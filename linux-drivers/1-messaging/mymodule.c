#include <linux/module.h>

MODULE_LICENSE("GPL");

int my_init_func(void) {
    printk(KERN_CRIT "CRIT: errval=%d\n", 1);
    printk(KERN_ERR "ERR: errval=%d\n", 2);
    printk(KERN_INFO "INFO: errval=%d\n", 3);
    printk(KERN_DEBUG "DBG: errval=%d\n", 4);
    return 0;
}

void my_cleanup_func(void) { 
    printk(KERN_WARNING "The module is now unloaded\n"); 
}

module_init(my_init_func);
module_exit(my_cleanup_func);