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
<hr/>
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
<h1>48. Reference</h1>
<ol>
    <li>https://embetronicx.com/tutorials/linux/device-drivers/</li>
    <li>https://developer.ibm.com/articles/l-linux-kernel/</li>
    <li>https://en.wikipedia.org/wiki/Linux</li>
</ol>