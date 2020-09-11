#include <ucontext.h>
#include <string.h>

typedef struct TCB_t
{
	struct TCB_t* next;
	struct TCB_t* prev;
	ucontext_t context;
} TCB_t;

void init_TCB(TCB_t *tcb, void *function, void *stackP, int stack_size)
{
	memset(tcb, '\0', sizeof(TCB_t)); //Wash, rinse
	getcontext(&tcb->context); //have to get parent context or else hell freezes over
	tcb->context.uc_stack.ss_sp = stackP;
	tcb->context.uc_stack.ss_size = (size_t) stack_size;
	makecontext(&tcb->context, function, 0); //Context now cooked
}