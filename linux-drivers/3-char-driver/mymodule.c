#include <linux/module.h>

MODULE_LICENSE("GPL");

static int init_function(void){
    printk("Hello Kernel!\n");
    return 0;
}

static void exit_function(void){
    printk("Bye Bye Kernel!\n");
}

module_init(init_function);
module_exit(exit_function);