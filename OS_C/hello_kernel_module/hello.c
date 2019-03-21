#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("caijiaqi");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");

int init_module(void);
void cleanup_module(void);
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

#define DEVICE_NAME "hellodev"	/* Dev name as it appears in /proc/devices   */
#define EXAMPLE_MSG "HELLO, WORLD!\n"
#define MSG_BUFFER_LEN 77

static int Major;
static int device_open_count = 0;
static char msg[MSG_BUFFER_LEN];
static char *msg_ptr;

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release
};



static int __init lkm_example_init(void) {
	Major = register_chrdev(0, DEVICE_NAME, &fops);
    if (Major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", Major);
	    return Major;
    }

    printk(KERN_INFO "I was assigned major number %d. To talk to\n", Major);
	printk(KERN_INFO "the driver, create a dev file with\n");
	printk(KERN_INFO "'mknod /dev/%s c %d 0'.\n", DEVICE_NAME, Major);
	printk(KERN_INFO "Try various minor numbers. Try to cat and echo to\n");
	printk(KERN_INFO "the device file.\n");
	printk(KERN_INFO "Remove the device file and module when done.\n");

	return 0;
}
static void __exit lkm_example_exit(void) {
    unregister_chrdev(Major, DEVICE_NAME);
}

/* Register module functions */
module_init(lkm_example_init);
module_exit(lkm_example_exit);

/**
 * device methods 
 */

static int device_open(struct inode *inode, struct file *file)
{
    static int file_open_times = 0;

    if (device_open_count) {
        return -EBUSY;
    }
    device_open_count++;
    sprintf(msg, "I already told you %d times Hello world!\n", file_open_times++);
    msg_ptr = msg;
    try_module_get(THIS_MODULE);
    return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
    device_open_count--;
    module_put(THIS_MODULE);
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer,
                            size_t len, loff_t *offset)
{
    int bytes_read = 0;
    if (*msg_ptr == 0) {
        return 0;
    }

    while (len && *msg_ptr) {
        put_user(*(msg_ptr++), buffer++);
        len--;
        bytes_read++;
    }

    return bytes_read;
}

static ssize_t device_write(struct file *filp, const char *buff,
                size_t len, loff_t *off)
{
    printk(KERN_ALERT "This operation is not supported.\n");
    return -EINVAL;
}
