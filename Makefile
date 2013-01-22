CFLAGS = -I. -Wall -pedantic -ansi -std=c99 -c

SRC= $(patsubst %.c,%,$(wildcard *.c))

default_target: all
.PHONY : default_target

all: $(SRC)
	ar rcs lib $(SRC)

clean:
	rm -f *.out
	rm -f *.o
	rm -f lib
	rm -f $(SRC)
.PHONY: clean
