CC=gcc --std=c99 -g

all: connected

connected: connected.c queue.o dynarray.o
	$(CC) connected.c queue.o dynarray.o -o connected

dynarray.o: dynarray.c dynarray.h
	$(CC) -c dynarray.c

queue.o: queue.c queue.h
	$(CC) -c queue.c

clean:
	rm -f *.o connected
