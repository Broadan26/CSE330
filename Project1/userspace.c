#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main()
{
         long int brandon = syscall(436);
         printf("System call my_syscall returned %ld\n", brandon);
         return 0;
}