#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

int val, arr_val[4];
char *name;
int cb_val = 0;

module_param(val, int, S_IRUSR|S_IWUSR);                      //value can read and write by user
module_param(name, charp, S_IRUSR|S_IWUSR);                     //name can read and write by user
module_param_array(arr_val, int, NULL, S_IRUSR | S_IWUSR);    //arr_value can read and write by user

/*
* Callback function to notify about parameter
*/
int notify_param(const char *val, const struct kernel_param *kp)
{
    int res = param_set_int(val, kp);
    if (res == 0)
    {
        pr_info("Call back function called\n");
        pr_info("New value of cb_value = %d\n", cb_val);
        return 0;
    }
    return -1;
}

const struct kernel_param_ops my_param_ops =
{
    .set = &notify_param,
    .get = &param_get_int,
};

module_param_cb(cb_val, &my_param_ops, &cb_val, S_IRUGO | S_IWUSR);

/*
* Module init function
*/
static int __init passing_arguments_init(void)
{
    int index;
    pr_info("Value = %d\n", val);
    pr_info("cb_value = %d\n", cb_val);
    pr_info("name = %s\n", name);
    for(index = 0; index < (sizeof(arr_val) / sizeof(int)); index++)
    {
        pr_info("arr_value[%d] = %d\n", index, arr_val);
    }
    pr_info("Kernel Module Inserted Successfully\n");
    return 0;
}

/*
* Module Exit Function
*/
static void __exit passing_arguments_exit(void)
{
    pr_info("Kernel Module Removed Successfully\n");
}

module_init(passing_arguments_init);
module_exit(passing_arguments_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DoTai dotai.3373@gmail.com");
MODULE_DESCRIPTION("Passing Arguments");
MODULE_VERSION("1.0");
