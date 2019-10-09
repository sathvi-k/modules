CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:	qtest

queue.o:	queue.c queue.h
					gcc $(CFLAGS) -c queue.c

qtest.o:	qtest.c queue.h
					gcc $(CFLAGS) -c qtest.c

qtest:	qtest.o queue.o
				gcc $(CFLAGS) qtest.o queue.o -o qtest

clean:
				rm -f *.o qtest
