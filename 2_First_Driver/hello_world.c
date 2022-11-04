#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

static int __init hello_world_init(void)
{
    printk(KERN_INFO "Kernel Module Inserted Successfully\n");
    return 0;
}

static void __exit hello_world_exit(void)
{
    printk(KERN_INFO "Kernel Module Removed Successfully\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dotai dotai.3373@gmail.com");
MODULE_DESCRIPTION("Hello World Driver");
MODULE_VERSION("2:1.0");