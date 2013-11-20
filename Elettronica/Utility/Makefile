CFLAGS=-Wall -O3

all:eval.o parallelo.o
	$(CC) $(CFLAGS) -o eval eval.o
	$(CC) $(CFLAGS) -o parallelo parallelo.c

.PHONY: clean

clean:
	rm *.o *~ *# eval parallelo
