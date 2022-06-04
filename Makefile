PROGRAM=main
CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -g
all: $(PROGRAM)
$(PROGRAM): main.o funciones.o
	$(CC) $(CFLAGS) main.o funciones.o -o $(PROGRAM)
main.o: main.c funciones.h
	$(CC) $(CFLAGS) -c main.c
funciones.o: funciones.c funciones.h
	$(CC) $(CFLAGS) -c funciones.c
clean:
	rm -vf *.o $(PROGRAM)
.PHONY: run
run: $(PROGRAM)
	./$(PROGRAM) figuras_in.bin
