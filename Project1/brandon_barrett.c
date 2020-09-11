#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */

static int brandon_init(void)
{
	printk(KERN_INFO "Brandon\n");
	return 0; //A non 0 return means init_module failed; module can't be loaded. 
}

static void brandon_exit(void)
{
	printk(KERN_INFO "Goodbye from Brandon\n");
}

module_init(brandon_init);
module_exit(brandon_exit);