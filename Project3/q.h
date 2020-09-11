#include "tcb.h"
#include <stdlib.h>

typedef TCB_t Node; //Make TCB_t easier to use

/*Queue Struct*/
typedef struct List_Node
{
	Node *head, *tail;
	int count;
} Queue;

/*Forward Declarations*/
void InitQueue(Queue *q);
Node* NewItem(void);
void FreeItem(Node *item);
void AddQueue(Queue *q, Node *n);
Node* DelQueue(Queue *q);
void RotateQ(Queue *q);

/*Init Queue*/
/*Initializes the queue for usage*/
void InitQueue(Queue *q)
{
	q->count = 0;
}

/*New Item*/
/*Creates a new node item*/
Node *NewItem()
{
	return (Node*) malloc(sizeof(Node));
}

/*Free Item*/
/*Deallocates a node*/
void FreeItem(Node *item)
{
	free(item);
}

/*Add Queue*/
/*Adds a new node to the end of the queue*/
void AddQueue(Queue* q, Node* n)
{
	if(q->count == 0) //First item in the queue
	{
		q->head = n;
		q->tail = n;
	}
	else //Adding additional items
	{
		q->tail->next = n;
		n->prev = q->tail;
		q->tail = n;
	}
	q->count++; //Increment the count

	//Move head and tail over 1 each
	q->head->prev = q->tail;
	q->tail->next = q->head;
}

/*Delete Queue*/
/*Deletes the first node in the queue and returns its contents*/
Node* DelQueue(Queue* q)
{
	if(q->count != 0)
	{
		Node * item = q->head;

		if(q->head == q->tail)
		{
			q->head = q->tail = 0;
		}
		else
		{
			//Move head and tail over 1 each
			q->head = q->head->next;
			q->head->prev = q->tail;
			q->tail->next = q->head;
		}
		q->count--; //Decrement count for removal
		return item; //Return removed node
	}
	else
	{
		return 0;
	}
}

/*Rotate Queue*/
/*Rotates the queue nodes over 1*/
void RotateQ(Queue *q)
{
	if(q->count == 0) //Don't attempt to rotate an empty queue
	{ 
		//Do nothing
	}
	else if(q->head == q->tail) //Don't attempt to rotate a single element
	{
		//Do nothing
	}
	else //More than a single element in the queue
	{
		q->head = q->head->next;
		q->tail = q->tail->next;
	}
}