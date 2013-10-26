CFLAGS = -g -Wall
all: Es1.o Es2.o
	gcc -o copy -Wall Es1.o
	gcc -o e2 -Wall Es2.o
.PHONY: clean

clean:
	rm ./*.o
	rm ./*~
	rm copy