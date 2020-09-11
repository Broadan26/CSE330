#include "threads.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*Forward Declarations*/
void thread1();
void thread2();
void thread3();

/*Global Value*/
int global_value;

/*Driver Code*/
int main(int argc, char** argv)
{
	global_value = 0;
	runQ = (Queue*) malloc(sizeof(Queue));
	
	start_thread(thread1);
	start_thread(thread2);
	start_thread(thread3);

	run(); //Begin running the queues
	free(runQ); //Deallocate memory

	return 0;
}

/*Thread 1*/
/*Increments the local variable by 1 and global by 1*/
void thread1()
{
	int local_value = 0;
	while(1)
	{
		global_value++; //Increment global value by 1
		local_value++; //Increment local value by 1
		printf("This is function %d the execution of thread 1 with global variable value %d\n", local_value, global_value);
		sleep(1);
		yield();
	}
}

/*Thread 2*/
/*Increments the global variable by 2 and local by 1*/
void thread2()
{
	int local_value = 0;
	while(1)
	{
		global_value = global_value + 2; //Increment global value by 2
		local_value++; //Increment local value by 1
		printf("This is function %d the execution of thread 2 with global variable value %d\n", local_value, global_value);
		sleep(1);
		yield();
	}
}

/*Thread 3*/
/*Increments the global variable by 3 and local by 1*/
void thread3()
{
	int local_value = 0;
	while(1)
	{
		global_value = global_value + 3; //Increment global value by 3
		local_value++; //Increment local value by 1
		printf("This is function %d the execution of thread 3 with global variable value %d\n", local_value, global_value);
		sleep(1);
		yield();
	}
}