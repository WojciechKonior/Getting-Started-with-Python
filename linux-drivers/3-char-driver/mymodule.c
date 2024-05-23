#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> //file_operations structure
#include <linux/cdev.h> //char driver; makes cdev available
#include <linux/semaphore.h>
#include <asm/uaccess.h> //copy_to_user; copy_from_user

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Wojciech Konior");
MODULE_DESCRIPTION("Char driver");

//Create a structure for our fake device
typedef struct fake_device {
    char data[100];
    struct semaphore sem;
} FakeDevice;
typedef struct cdev CDev;
typedef struct file_operations FileOperations;
typedef struct inode Inode;
typedef struct file File;

FakeDevice virtual_device;
CDev *my_cdev; //for registering our device
int major_number; // for storing major number extracted from dev_t using macro mknod /director/file c major minor
int ret; //hold return values of function because the kernel stack is very small
dev_t dev_num; // for holding major number that kernel gives us

#define DEVICE_NAME "wkdevice"

// calls on device_file open
int device_open(Inode *inode, File *filp){
    //only allow one process to open
    if(down_interruptible(&virtual_device.sem) != 0){
        printk(KERN_ALERT "Could not lock device during open");
        return -1;
    }

    printk(KERN_INFO "device opened");
    return 0;
}

// called when user wants to get info from device
ssize_t device_read(File *filp, char* bufStoreData, size_t bufCount, loff_t* curOffset){
    // take data from kernel space to user space
    printk(KERN_INFO "Reading from device");
    ret = copy_to_user(bufStoreData, virtual_device.data, bufCount);
    return ret;
}

// called when user wants to send info to device
ssize_t device_write(File *filp, const char* bufSourceData, size_t bufCount, loff_t* curOffset){
    //send data from user to kernel
    printk(KERN_INFO "Writing to device");
    ret = copy_from_user(virtual_device.data, bufSourceData, bufCount);
    return ret;
}

// called when user want to close
int device_close(Inode *inode, File *file){
    up(&virtual_device.sem);
    printk(KERN_INFO "Device closed");
    return 0;
}

// Telling the kernel which funcs to call when user operates on our device file
FileOperations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_close,
    .write = device_write,
    .read = device_read
};

static int driver_entry(void){
    //registering device
    ret = alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);
    if(ret < 0){
        printk(KERN_ALERT  "Failed to allocate a major number");
        return ret;
    }
    major_number = MAJOR(dev_num); // extracts the major number and store in variable
    printk(KERN_INFO "Major number is %d", major_number);
    printk(
        KERN_INFO "\tuse \"mknod /dev/%s c %d 0\" for device file",
        DEVICE_NAME,
        major_number
    );

    my_cdev = cdev_alloc(); // create cves struct
    my_cdev->ops = &fops;
    my_cdev->owner = THIS_MODULE;

    ret = cdev_add(my_cdev, dev_num, 1);
    if(ret < 0){
        printk(KERN_ALERT "Unable to add cdev to kernel");
        return ret;
    }
    sema_init(&virtual_device.sem, 1);
    return 0;
}

static void driver_exit(void){
    cdev_del(my_cdev);
    unregister_chrdev_region(dev_num, 1);
    printk(KERN_ALERT "Module unloaded\n");
}

module_init(driver_entry);
module_exit(driver_exit);