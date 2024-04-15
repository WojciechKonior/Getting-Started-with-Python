#include <linux/init.h>
#include <linux/module.h>

// Meta infrormation
MODULE_LICENCE("GPL");
MODULE_AUTHOR("wkonior");
MODULE_DESCRIPTION("Hello world module");

static int __init ModuleInit(void) {
  printk("Hello Kernel\n");
  return 0;
}

static void __exit ModuleExit(void) { printk("Goodbye Kernel\n"); }

module_init(ModuleInit);
module_exit(ModuleExit);
