#include "threads.h"

typedef struct Semaphore
{
	int value;
	Queue blocked;
} Semaphore;

int InitSem(Semaphore* s, int value)
{
	s->value = value;
	InitQueue(&s -> blocked);

	return 0;
}

/*P*/
/*Decrements the semaphore count and blocks the run process if the count is less than 0*/
void P(Semaphore *s)
{
	s->value = s->value - 1; //Decrement the value
	if(s->value < 0) //Check the value
	{
		TCB_t* tcb = DelQueue(runQ); //Remove & Save node from Ready queue

		AddQueue(&s -> blocked, tcb); //Add node to Blocked queue
		swapcontext(&tcb -> context, &runQ -> head -> context); //Swap the context
	}
}

/*V*/
/*Increments the semaphore counter and moves a thread from the blocked queue to the run queue*/
void V(Semaphore *s)
{
	s->value = s->value + 1;
	if(s->value <= 0)
	{
		TCB_t* tcb = DelQueue(&s -> blocked); //Remove & Save node from Blocked queue
		AddQueue(runQ, tcb); //Add node to Ready Queue
	}
	yield();
}