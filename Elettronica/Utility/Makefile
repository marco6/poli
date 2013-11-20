CFLAGS=-Wall -O3

all:eval.o parallelo.o
	$(CC) $(CFLAGS) -o eval eval.o
	$(CC) $(CFLAGS) -o parallelo parallelo.o

.PHONY: clean

clean:
	rm -f *.o *~ *# eval parallelo
