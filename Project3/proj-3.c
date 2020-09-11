#include "sem.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*Forward Declare Threads*/
void producer1();
void producer2();
void producer3();
void producer4();
void producer5();
void producer6();
void producer7();
void producer8();
void producer9();
void producer10();
void consumer1();
void consumer2();
void consumer3();
void consumer4();
void consumer5();
void consumer6();
void consumer7();
void consumer8();
void consumer9();
void consumer10();

/*Semaphores & Global Value*/
Semaphore* full; //consumer semaphore
Semaphore* empty; //producer semaphore
Semaphore* mutex; //Mutual Exclusion

#define N 6 //Size of the buffer
int buffer[N];
int whoMadeIt[N];
int in, out, filled;

/*Driver*/
int main(int argc, char** argv)
{
	runQ = (Queue*) malloc(sizeof(Queue)); //Allocate queue and semaphores

	full = (Semaphore*) malloc(sizeof(Semaphore));
	empty = (Semaphore*) malloc(sizeof(Semaphore));
	mutex = (Semaphore*) malloc(sizeof(Semaphore));

	InitSem(full, 0); //Start at 0 since buffer empty
	InitSem(empty, 6); //How large the buffer is
	InitSem(mutex, 1); //How many items we want in CS

	start_thread(consumer1); //Initialize all the threads
	start_thread(consumer2);
	start_thread(consumer3);
	start_thread(producer1);
	start_thread(producer2);
	start_thread(producer3);
	start_thread(producer4);
	start_thread(producer5);
	start_thread(producer6);
	start_thread(producer7);
	start_thread(consumer4);
	start_thread(consumer5);
	start_thread(consumer6);
	start_thread(consumer7);
	start_thread(consumer8);
	start_thread(consumer9);
	start_thread(consumer10);
	start_thread(producer8);
	start_thread(producer9);
	start_thread(producer10);
	
	run(); //Run the threads in the queue
	
	free(full); //Cleanup
	free(empty);
	free(mutex);
	free(runQ);
	return 0;
}

/*Producer 1*/
/*Fills the buffer*/
void producer1()
{
	int producer_num = 1;
	int item_count = 0;
	while(1)
	{
		if(filled != 6)
		{
			P(empty);
			//P(mutex);
			
			filled++;
			item_count++;
			int item = item_count;

			buffer[in] = item;
			whoMadeIt[in] = producer_num;
			printf("Producer %d placed item %d into buffer \n", producer_num, item);
			in = (in + 1) % N;
			sleep(1);

			V(full);
			//V(mutex);
		}
		else
		{
			printf("Producer %d is waiting \n", producer_num);
			sleep(1);
			yield();
		}
	}
}

/*Producer 2*/
/*Fills the buffer*/
void producer2()
{
	int producer_num = 2;
	int item_count = 0;
	while(1)
	{
		if(filled != 6)
		{
			P(empty);
			//P(mutex);
			
			filled++;
			item_count++;
			int item = item_count;

			buffer[in] = item;
			whoMadeIt[in] = producer_num;
			printf("Producer %d placed item %d into buffer \n", producer_num, item);
			in = (in + 1) % N;
			sleep(1);

			V(full);
			//V(mutex);
		}
		else
		{
			printf("Producer %d is waiting \n", producer_num);
			sleep(1);
			yield();
		}
	}
}

/*Producer 3*/
/*Fills the buffer*/
void producer3()
{
	int producer_num = 3;
	int item_count = 0;
	while(1)
	{
		if(filled != 6)
		{
			P(empty);
			//P(mutex);
			
			filled++;
			item_count++;
			int item = item_count;

			buffer[in] = item;
			whoMadeIt[in] = producer_num;
			printf("Producer %d placed item %d into buffer \n", producer_num, item);
			in = (in + 1) % N;
			sleep(1);

			V(full);
			//V(mutex);
		}
		else
		{
			printf("Producer %d is waiting \n", producer_num);
			sleep(1);
			yield();
		}
	}
}

/*Producer 4*/
/*Fills the buffer*/
void producer4()
{
	int producer_num = 4;
	int item_count = 0;
	while(1)
	{
		if(filled != 6)
		{
			P(empty);
			//P(mutex);
			
			filled++;
			item_count++;
			int item = item_count;

			buffer[in] = item;
			whoMadeIt[in] = producer_num;
			printf("Producer %d placed item %d into buffer \n", producer_num, item);
			in = (in + 1) % N;
			sleep(1);

			V(full);
			//V(mutex);
		}
		else
		{
			printf("Producer %d is waiting \n", producer_num);
			sleep(1);
			yield();
		}
	}
}

/*Producer 5*/
/*Fills the buffer*/
void producer5()
{
	int producer_num = 5;
	int item_count = 0;
	while(1)
	{
		if(filled != 6)
		{
			P(empty);
			//P(mutex);
			
			filled++;
			item_count++;
			int item = item_count;

			buffer[in] = item;
			whoMadeIt[in] = producer_num;
			printf("Producer %d placed item %d into buffer \n", producer_num, item);
			in = (in + 1) % N;
			sleep(1);

			V(full);
			//V(mutex);
		}
		else
		{
			printf("Producer %d is waiting \n", producer_num);
			sleep(1);
			yield();
		}
	}
}

/*Producer 6*/
/*Fills the buffer*/
void producer6()
{
	int producer_num = 6;
	int item_count = 0;
	while(1)
	{
		if(filled != 6)
		{
			P(empty);
			//P(mutex);
			
			filled++;
			item_count++;
			int item = item_count;

			buffer[in] = item;
			whoMadeIt[in] = producer_num;
			printf("Producer %d placed item %d into buffer \n", producer_num, item);
			in = (in + 1) % N;
			sleep(1);

			V(full);
			//V(mutex);
		}
		else
		{
			printf("Producer %d is waiting \n", producer_num);
			sleep(1);
			yield();
		}
	}
}

/*Producer 7*/
/*Fills the buffer*/
void producer7()
{
	int producer_num = 7;
	int item_count = 0;
	while(1)
	{
		if(filled != 6)
		{
			P(empty);
			//P(mutex);
			
			filled++;
			item_count++;
			int item = item_count;

			buffer[in] = item;
			whoMadeIt[in] = producer_num;
			printf("Producer %d placed item %d into buffer \n", producer_num, item);
			in = (in + 1) % N;
			sleep(1);

			V(full);
			//V(mutex);
		}
		else
		{
			printf("Producer %d is waiting \n", producer_num);
			sleep(1);
			yield();
		}
	}
}

/*Producer 8*/
/*Fills the buffer*/
void producer8()
{
	int producer_num = 8;
	int item_count = 0;
	while(1)
	{
		if(filled != 6)
		{
			P(empty);
			//P(mutex);
			
			filled++;
			item_count++;
			int item = item_count;

			buffer[in] = item;
			whoMadeIt[in] = producer_num;
			printf("Producer %d placed item %d into buffer \n", producer_num, item);
			in = (in + 1) % N;
			sleep(1);

			V(full);
			//V(mutex);
		}
		else
		{
			printf("Producer %d is waiting \n", producer_num);
			sleep(1);
			yield();
		}
	}
}

/*Producer 9*/
/*Fills the buffer*/
void producer9()
{
	int producer_num = 9;
	int item_count = 0;
	while(1)
	{
		if(filled != 6)
		{
			P(empty);
			//P(mutex);
			
			filled++;
			item_count++;
			int item = item_count;

			buffer[in] = item;
			whoMadeIt[in] = producer_num;
			printf("Producer %d placed item %d into buffer \n", producer_num, item);
			in = (in + 1) % N;
			sleep(1);

			V(full);
			//V(mutex);
		}
		else
		{
			printf("Producer %d is waiting \n", producer_num);
			sleep(1);
			yield();
		}
	}
}

/*Producer 10*/
/*Fills the buffer*/
void producer10()
{
	int producer_num = 10;
	int item_count = 0;
	while(1)
	{
		if(filled != 6)
		{
			P(empty);
			//P(mutex);
			
			filled++;
			item_count++;
			int item = item_count;

			buffer[in] = item;
			whoMadeIt[in] = producer_num;
			printf("Producer %d placed item %d into buffer \n", producer_num, item);
			in = (in + 1) % N;
			sleep(1);

			V(full);
			//V(mutex);
		}
		else
		{
			printf("Producer %d is waiting \n", producer_num);
			sleep(1);
			yield();
		}
	}
}

/*Consumer 1*/
/*Empties the buffer*/
void consumer1()
{
	int consumer_num = 1;
	while(1)
	{
		if(filled > 0)
		{
			P(full);
			//P(mutex);
			
			filled--;
			int item = buffer[out];
			printf("Consumer %d removed item %d made by Producer %d \n", consumer_num, item, whoMadeIt[out]);
			out = (out + 1) % N;
			sleep(1);

			V(empty);
			//V(mutex);
		}
		else
		{
			printf("Consumer %d is waiting \n", consumer_num);
			sleep(1);
			yield();
		}
	}
}

/*Consumer 2*/
/*Empties the buffer*/
void consumer2()
{
	int consumer_num = 2;
	while(1)
	{
		if(filled > 0)
		{
			P(full);
			//P(mutex);
			
			filled--;
			int item = buffer[out];
			printf("Consumer %d removed item %d made by Producer %d \n", consumer_num, item, whoMadeIt[out]);
			out = (out + 1) % N;
			sleep(1);

			V(empty);
			//V(mutex);
		}
		else
		{
			printf("Consumer %d is waiting \n", consumer_num);
			sleep(1);
			yield();
		}
	}
}

/*Consumer 3*/
/*Empties the buffer*/
void consumer3()
{
	int consumer_num = 3;
	while(1)
	{
		if(filled > 0)
		{
			P(full);
			//P(mutex);
			
			filled--;
			int item = buffer[out];
			printf("Consumer %d removed item %d made by Producer %d \n", consumer_num, item, whoMadeIt[out]);
			out = (out + 1) % N;
			sleep(1);

			V(empty);
			//V(mutex);
		}
		else
		{
			printf("Consumer %d is waiting \n", consumer_num);
			sleep(1);
			yield();
		}
	}
}

/*Consumer 4*/
/*Empties the buffer*/
void consumer4()
{
	int consumer_num = 4;
	while(1)
	{
		if(filled > 0)
		{
			P(full);
			//P(mutex);
			
			filled--;
			int item = buffer[out];
			printf("Consumer %d removed item %d made by Producer %d \n", consumer_num, item, whoMadeIt[out]);
			out = (out + 1) % N;
			sleep(1);

			V(empty);
			//V(mutex);
		}
		else
		{
			printf("Consumer %d is waiting \n", consumer_num);
			sleep(1);
			yield();
		}
	}
}

/*Consumer 5*/
/*Empties the buffer*/
void consumer5()
{
	int consumer_num = 5;
	while(1)
	{
		if(filled > 0)
		{
			P(full);
			//P(mutex);
			
			filled--;
			int item = buffer[out];
			printf("Consumer %d removed item %d made by Producer %d \n", consumer_num, item, whoMadeIt[out]);
			out = (out + 1) % N;
			sleep(1);

			V(empty);
			//V(mutex);
		}
		else
		{
			printf("Consumer %d is waiting \n", consumer_num);
			sleep(1);
			yield();
		}
	}
}

/*Consumer 6*/
/*Empties the buffer*/
void consumer6()
{
	int consumer_num = 6;
	while(1)
	{
		if(filled > 0)
		{
			P(full);
			//P(mutex);
			
			filled--;
			int item = buffer[out];
			printf("Consumer %d removed item %d made by Producer %d \n", consumer_num, item, whoMadeIt[out]);
			out = (out + 1) % N;
			sleep(1);

			V(empty);
			//V(mutex);
		}
		else
		{
			printf("Consumer %d is waiting \n", consumer_num);
			sleep(1);
			yield();
		}
	}
}

/*Consumer 7*/
/*Empties the buffer*/
void consumer7()
{
	int consumer_num = 7;
	while(1)
	{
		if(filled > 0)
		{
			P(full);
			//P(mutex);
			
			filled--;
			int item = buffer[out];
			printf("Consumer %d removed item %d made by Producer %d \n", consumer_num, item, whoMadeIt[out]);
			out = (out + 1) % N;
			sleep(1);

			V(empty);
			//V(mutex);
		}
		else
		{
			printf("Consumer %d is waiting \n", consumer_num);
			sleep(1);
			yield();
		}
	}
}

/*Consumer 8*/
/*Empties the buffer*/
void consumer8()
{
	int consumer_num = 8;
	while(1)
	{
		if(filled > 0)
		{
			P(full);
			//P(mutex);
			
			filled--;
			int item = buffer[out];
			printf("Consumer %d removed item %d made by Producer %d \n", consumer_num, item, whoMadeIt[out]);
			out = (out + 1) % N;
			sleep(1);

			V(empty);
			//V(mutex);
		}
		else
		{
			printf("Consumer %d is waiting \n", consumer_num);
			sleep(1);
			yield();
		}
	}
}

/*Consumer 9*/
/*Empties the buffer*/
void consumer9()
{
	int consumer_num = 9;
	while(1)
	{
		if(filled > 0)
		{
			P(full);
			//P(mutex);
			
			filled--;
			int item = buffer[out];
			printf("Consumer %d removed item %d made by Producer %d \n", consumer_num, item, whoMadeIt[out]);
			out = (out + 1) % N;
			sleep(1);

			V(empty);
			//V(mutex);
		}
		else
		{
			printf("Consumer %d is waiting \n", consumer_num);
			sleep(1);
			yield();
		}
	}
}

/*Consumer 10*/
/*Empties the buffer*/
void consumer10()
{
	int consumer_num = 10;
	while(1)
	{
		if(filled > 0)
		{
			P(full);
			//P(mutex);
			
			filled--;
			int item = buffer[out];
			printf("Consumer %d removed item %d made by Producer %d \n", consumer_num, item, whoMadeIt[out]);
			out = (out + 1) % N;
			sleep(1);

			V(empty);
			//V(mutex);
		}
		else
		{
			printf("Consumer %d is waiting \n", consumer_num);
			sleep(1);
			yield();
		}
	}
}