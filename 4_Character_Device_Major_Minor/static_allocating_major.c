#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

dev_t dev = MKDEV(315, 0);

static int __init static_allocating_major_init(void)
{
    register_chrdev_region(dev, 1, "DoTaiDevice");
    pr_info("Major = %d Minor = %d\n", MAJOR(dev), MINOR(dev));
    pr_info("Kernel Module Inserted Successfully\n");
    return 0;   
}

static void __exit static_allocating_major_exit(void)
{
    unregister_chrdev_region(dev, 1);
    pr_info("Kernel Module Removed Successfully\n");
}

module_init(static_allocating_major_init);
module_exit(static_allocating_major_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DoTai dotai.3373@gmail.com");
MODULE_DESCRIPTION("Demo Statically allocating the major and minor number");
MODULE_VERSION("1.0");
