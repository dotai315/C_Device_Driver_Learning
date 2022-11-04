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