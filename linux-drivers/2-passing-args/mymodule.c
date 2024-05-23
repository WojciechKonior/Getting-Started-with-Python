#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Wojciech Konior");
MODULE_DESCRIPTION("Passing parameters into kernel module");

int param_var = 0;
module_param(
    param_var,
    int,
    S_IRUSR | S_IWUSR | S_IXUSR | S_IWGRP | S_IRGRP
);

#define SIZE 3
int param_arr[] = {1, 2, 3};
module_param_array(
    param_arr,
    int,
    SIZE,
    S_IRUSR | S_IWUSR | S_IXUSR | S_IWGRP | S_IRGRP
);

void display(void){
    printk(KERN_ALERT "VALUE: %d\n", param_var);
    printk(
        KERN_ALERT "ARR: %d, %d, %d\n",
        param_arr[0],
        param_arr[1],
        param_arr[2]
    );
}   

static int init_function(void){
    printk("Hello Kernel!\n");
    display();
    return 0;
}

static void exit_function(void){
    printk("Bye Bye Kernel!\n");
}

module_init(init_function);
module_exit(exit_function);