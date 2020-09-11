OBJS = proj-3.o
CC =	gcc
DEBUG =	-g	
CFLAGS = -Wall -c $(DEBUG)	
LFLAGS = -Wall $(DEBUG)	

p2 :	$(OBJS)	
	$(CC) $(LFLAGS) $(OBJS)	-o p3	
	
proj-3.o : proj-3.c
	$(CC) $(CFLAGS) proj-3.c
	
clean:	
	\rm	*.o	*~	proj-3	
	
tar:	
	tar	cfv	p3.tar	proj-3.c	