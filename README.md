# C_Device_Driver_Learning
All my studying about linux device driver with c languages. Reference this course: https://embetronicx.com/tutorials/linux/device-drivers/linux-device-driver-part-1-introduction/
<h1>Table Content </h1>
<hr/>
<ol>
    <li>Introduction</li>
    <li>First Driver</li>
    <li>Passing Arguments</li>
    <li>Major & Minor Number</li>
    <li>Creating Device File</li>
    <li>File Operations</li>
    <li>Real Device Driver</li>
    <li>IOCTL Tutorial</li>
    <li>Procfs Tutorial</li>
    <li>Waitqueue Tutorial</li>
    <li>SysFS Tutorial</li>
    <li>Interrupt Tutorial</li>
    <li>Interrupt Programming</li>
    <li>Workqueue (Static Method)</li>
    <li>Workqueue (Dynamic Method)</li>
    <li>Own Workqueue</li>
    <li>Linked List 1</li>
    <li>Linked List 2</li>
    <li>Kernenl Thread</li>
    <li>Tasklet (Static Method)</li>
    <li>Tasklet (Dynamic Method)</li>
    <li>Mutex Tutorial</li>
    <li>Spinlock Tutorial 1</li>
    <li>Spinlock Tutorial 2</li>
    <li>Sending Signals</li>
    <li>Kernel Timer Tutorial</li>
    <li>High Resolution Timer Tutorial</li>
    <li>Completion Tutorial</li>
    <li>EXPORT_SYMBOL</li>
    <li>Atomic Variables Tutorial</li>
    <li>Seqlock</li>
    <li>Misc Device Driver</li>
    <li>USB Device Driver </li>
    <li>GPIO Driver Basic</li>
    <li>GPIO Interrupt</li>
    <li>I2C Linux Device Driver</li>
    <li>Dummy I2C Bus Driver</li>
    <li>Real I2C Bus Driver</li>
    <li>I2C Bus Driver Using I2C-GPIO</li>
    <li>SSD1306 I2C Linux Device Driver</li>
    <li>Poll Linux </li>
    <li>Select Linux</li>
    <li>E-Poll Linux</li>
    <li>Softirq Linux</li>
    <li>Threaded IRQ in Linux</li>
    <li>SPI Protocol Driver</li>
    <li>BMP280 I2C Pressure Sensor Driver</li>
    <li>Reference</li>
</ol>
<h1>1. Introduction</h1>
<h2>What is Linux?</h2>
<p>Linux is an open-source Unix-like operating system based on the Linux kernel, an operating system kernel first released on September 17, 1991, by Linus Torvalds. Linux is typically packaged as a Linux distribution.</p>
<h2>Linux Architechture</h2>
<img src="https://developer.ibm.com/developer/default/articles/l-linux-kernel/images/figure2.jpg">
<p>At the top is the user, or application, space. This is where the user applications are executed. Below the user space is the kernel space. Here, the Linux kernel exists.</p>
<br>
<p>There is also the GNU C Library (glibc). This provides the system call interface that connects to the kernel and provides the mechanism to transition between the user-space application and the kernel. This is important because the kernel and user application occupy different protected address spaces. And while each user-space process occupies its own virtual address space, the kernel occupies a single address space.</p>
<br>
<p>The Linux kernel can be further divided into three gross levels. At the top is the system call interface, which implements the basic functions such as read and write. Below the system call interface is the kernel code, which can be more accurately defined as the architecture-independent kernel code. This code is common to all of the processor architectures supported by Linux. Below this is the architecture-dependent code, which forms what is more commonly called a BSP (Board Support Package). This code serves as the processor and platform-specific code for the given architecture.</p>
<h2>Linux Kernel Module</h2>
<p>Kernel modules are pieces of code that can be loaded and unloaded into the kernel upon demand. They extend the functionality of the kernel without the need to reboot the system.</p>
<br>
<p>Custom Codes can be added to Linux kernels via two methods:</p>
<ul>
    <li>The basic way is to add the code to the kernel source tree and recompile the kernel</li>
    <li>A more efficient way is to do this is by adding code to the kernel while it is running. This process is called loading the module, where the module refers to the code that we want to add to the kernel.</li>
</ul>
<p>Since we are loading these codes at runtime and they are not part of the official Linux Kernel, these are called loadable kernel modules (LKM), which is different from the "base kernel". The base kernel is located in /boot directory and is always loaded when we boot our machine whereas LKMs ared loaded after the base kernel is alread loaded. Nonetheless, this LKM is very much part of out kernel and they communicate with base kernel to complete their functions.</p>
<p>LKMs can perform a variety of task, but basically, they come uner three main categories:</p>
<ul>
    <li>Device drivers</li>
    <li>Filesystem drivers</li>
    <li>System calls</li>
</ul>
<h2>Device Driver</h2>
<p>A device driver is a particular form of software application that is designed to enable interaction with hardware devices. Without the required device driver, the corresponding hardware device fails to work.</p>
<br>
<p>A device driver usually communicates with the hardware by means of the communications subsystem or computer bus to which the hardware is connected. Device drivers are operating system-specific and hardware-dependent. A device driver acts as a translator between the hardware device and the programs or operating systems that use it.</p>
<h3>Character Device</h3>
<p>A char file is a hardware file that reads/writes data in character by character fashion. Some classic examples are keyboard, mouse, serial printer. If a user uses a char file for writing data no other user can use the same char file to write data that blocks access to another user. Character files use synchronize Technic to write data. Of you observe char files are used for communication purposes and they can not be mounted.</p>
<h3>Block Device</h3>
<p>A block file is a hardware file that reads/writes data in blocks instead of character by character. This type of file is very much useful when we want to write/read data in a bulk fashion. All our disks such are HDD, USB, and CDROMs are block devices. This is the reason when we are formatting we consider block size. The writing of data is done in an asynchronous fashion and it is CPU-intensive activity. These device files are used to store data on real hardware and can be mounted so that we can access the data we have written.</p>
<h3>Network Device</h3>
<p>A network device is, so far as Linux’s network subsystem is concerned, an entity that sends and receives packets of data. This is normally a physical device such as an ethernet card. Some network devices though are software only such as the loopback device which is used for sending data to yourself.</p>
<h1>2. First Driver</h1>
<h2>Module Information</h2>
<ul>
    <li>License</li>
    <li>Author</li>
    <li>Module Description</li>
    <li>Module Version</li>
</ul>
<p>These pieces of infomations are present in the <b>linux/module.h</b> as macros.</p>
<h3>License</h3>
<p>GPL, or the GNU General Public License, is an open-source license meant for software. If your software is licensed under the terms of the GPL, it is free. However, “free” here does not essentially mean freeware—it can also be paid software. Instead, “free” as per the GPL means freedom. As proponents of GPL proudly proclaim, free as in freedom, not free beer.</p>
<p>The following license idents are currently accepted as indicating free software modules.</p>
<pre>
<p>"GPL" [GNU Public License v2 or later]</p>
<p>"GPL v2" [GNU Public License v2]</p>
<p>"GPL and additional rights" [GNU Public License v2 rights and more]</p>
<p>"Dual BSD/GPL" [GNU Public License v2 or BSD license choice]</p>
<p>"Dual MIT/GPL" [GNU Public License v2 or MIT license choice]</p>
<p>"Dual MPL/GPL" [GNU Public License v2 or Mozilla license choice]</p>
<p>"Proprietary" [Non free products]</p>
</pre>
<p>There are dual-licensed components, but when running with Linux it is the GPL that is relevant so this is a non-issue. Similarly, LGPL linked with GPL is a GPL combined work.</p>
<p>This exists for several reasons</p>
<ol>
    <li><b>modinfo</b> can show license info for users wanting to vet their setup is free</li>
    <li>The community can ignore bug reports including proprietary modules</li>
    <li>Vendors can do likewise based on their own policies</li>
</ol>
<h3>Author</h3>
<p>Using this Macro we can mention who is writing this Linux device driver or module. So modinfo can show the author’s name for users wanting to know. We can give the Author’s name for our driver (module) like below. For this, you need to include the <b>linux/module.h</b> header file.</p>
<pre>
MODULE_AUTHOR("Author");
</pre>
<h3>Version</h3>
<p>Using this Macro we can give the version of the module or driver. So, <b>modinfo</b> can show the module version for users wanting to know.</p>
<pre>
<b>Version of form [epoch:]version[-extra-version].</b>
<b>epoch</b>: A (small) unsigned integer which allows you to start versions anew. If not mentioned, it’s zero. eg. “2:1.0” is after “1:2.0”.
<b>version</b>: The version may contain only alphanumerics and the character `.’. Ordered by numeric sort for numeric parts, ASCII sort for ASCII parts (as per RPM or DEB algorithm).
<b>extraversion</b>: Like version, but inserted for local customizations, eg “rh3” or “rusty1”.
</pre>
<p>Example</p>
<pre>
MODULE_VERSION("2:1.0");
</pre>
<h2>Simple Kernel Module Programming</h2>
<h3>Init function</h3>
<p>This is the function that will execute first when the Linux device driver is loaded into the kernel. For example, when we load the driver using <b>insmod</b>, this function will execute. Please see below to know the syntax of this function.</p>
<pre>
static int __init hello_world_init(void) /* Constructor */
{
    return 0;
}
module_init(hello_world_init);
</pre>
<h3>Exit function</h3>
<p>This is the function that will execute last when the Linux device driver is unloaded from the kernel. For example, when we unload the driver using <b>rmmod</b>, this function will execute. Please see below to know the syntax of this function.</p>
<pre>
void __exit hello_world_exit(void)
{
}
module_exit(hello_world_exit);
</pre>
<h2>Printk()</h2>
<p>print a kernel message</p>
<p><b>KERN_EMERG</b>: Used for emergency messages, usually those that precede a crash.</p>
<p><b>KERN_ALERT</b>:A situation requiring immediate action.</p>
<p><b>KERN_CRIT</b>: Critical conditions are often related to serious hardware or software failures.</p>
<p><b>KERN_ERR</b>: Used to report error conditions; device drivers often use KERN_ERR to report hardware difficulties.</p>
<p><b>KERN_WARNING</b>: Warnings about problematic situations that do not, in themselves, create serious problems with the system.</p>
<p><b>KERN_NOTICE</b>: Situations that are normal, but still worthy of note. A number of security-related conditions are reported at this level.</p>
<p><b>KERN_INFO</b>:Informational messages. Many drivers print information about the hardware they find at startup time at this level.</p>
<p><b>KERN_DEBUG</b>: Used for debugging messages.<p>
<p>Example</p>
<pre>
printk(KERN_INFO "Welcome To EmbeTronicX");
</pre>
<p>In the newer Linux kernels, you can use the APIs below instead of this printk.</p>
<ol>
    <li>pr_info – Print an info-level message. (ex. pr_info("test info message\n")).</li>
    <li>pr_cont – Continues a previous log message in the same line.</li>
    <li>pr_debug – Print a debug-level message conditionally.</li>
    <li>pr_err – Print an error-level message. (ex. pr_err(“test error message\n”)).</li>
    <li>pr_warn – Print a warning-level message.</li>
</ol>
<h1>48. Reference</h1>
<ol>
    <li>https://embetronicx.com/tutorials/linux/device-drivers/</li>
    <li>https://developer.ibm.com/articles/l-linux-kernel/</li>
    <li>https://en.wikipedia.org/wiki/Linux</li>
</ol>