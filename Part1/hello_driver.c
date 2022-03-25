#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Gufran Yesilyurt");
MODULE_DESCRIPTION("My first Linux Driver");
MODULE_VERSION("1.0");

static int __init hello_driver_init(void){
 printk(KERN_ALERT "Hello module!\n");
 return 0;
}

static void __exit hello_driver_exit(void){
 printk(KERN_ALERT "Bye module!\n");
}

module_init(hello_driver_init);
module_exit(hello_driver_exit);
