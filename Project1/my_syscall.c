#include <linux/kernel.h>

asmlinkage long sys_my_syscall(void)
{
	printk("This is the new system call BRANDON implemented.\n");
	return 0;
}