CFLAGS = -Wall -g

compile: es1.o es2.o es3.o es3_bello.o
	gcc $(CFLAGS) -o es1 es1.o
	gcc $(CFLAGS) -o es2 es2.o
	gcc $(CFLAGS) -o es3 es3.o
	gcc $(CFLAGS) -o es3_bello es3_bello.o
cancel:
	rm *.o
	rm es1
	rm es2
	rm es3
	rm es3_bello