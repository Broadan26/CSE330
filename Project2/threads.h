#include "q.h"
#include <stdio.h>

/*Global Run Queue*/
Queue* runQ;

/*Start Thread*/
/*Creates a thread on a stack and adds it to the queue*/
void start_thread(void (*function)(void))
{
	void* stackP = malloc(8192);//allocate a stack (via malloc) of a certain size, 8192

	TCB_t* tcb = (TCB_t*)malloc(sizeof(TCB_t));//allocate TCB (via malloc)

	init_TCB(tcb, function, stackP, 8192);//call init_TCB with apropriate arguments
	
	AddQueue(runQ, tcb); //call addQ to add this TCB into the RunQ which is a global header pointer
}

/*Run*/
/*Runs the current context of the queue*/
void run()
{
	ucontext_t parent; //Get place to store the main context
	getcontext(&parent); //Grabs the context from the parent
	swapcontext(&parent, &(runQ->head->context)); //Start the first thread
}

/*Yield*/
/*Stops the current thread*/
void yield()
{
	ucontext_t *current, *next; //Create context pointers
	current = &runQ->head->context; //Set current context
	RotateQ(runQ); //Rotate the RunQ
	next = &runQ->head->context; //Set the next context
	swapcontext(current, next); //Swap the context, from the previous thread to the thread pointed to by RunQ
}