CFLAGS=-Wall -pedantic -std=c11 -I. -g

all:	qtest htest

%.o:	%.c %.h
			gcc $(CFLAGS) -c $<

qtest:	qtest.o queue.o
				gcc $(CFLAGS) qtest.o queue.o -o $@

htest: htest.o hash.o queue.o
				gcc $(CFLAGS) htest.o hash.o queue.o -o $@

clean:
				rm -f *.o qtest htest
