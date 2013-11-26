CFLAGS = -g -Wall
all: e1.o e2.o e3.o e4.o
	gcc $(CFLAGS) -o e1 e1.o
	gcc $(CFLAGS) -o e2 e2.o
	gcc $(CFLAGS) -o e3 e3.o
	gcc $(CFLAGS) -o e4 e4.o

.PHONY: clean
clean:
	rm ./*.o e1 e2 e3 e4
