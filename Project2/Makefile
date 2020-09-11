OBJS = thread_test.o
CC =	gcc
DEBUG =	-g	
CFLAGS = -Wall -c $(DEBUG)	
LFLAGS = -Wall $(DEBUG)	

p2 :	$(OBJS)	
	$(CC) $(LFLAGS) $(OBJS)	-o p2	
	
thread_test.o : thread_test.c
	$(CC) $(CFLAGS) thread_test.c
	
clean:	
	\rm	*.o	*~	thread_test	
	
tar:	
	tar	cfv	p2.tar	thread_test.c	