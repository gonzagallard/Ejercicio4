PROGRAM=main
CC=gcc
CFLAGS=-Wall -Werror -std=c99 -pedantic -g
all: $(PROGRAM)
$(PROGRAM): main.o polilinea.o color.o tipo.o
	$(CC) $(CFLAGS) main.o polilinea.o color.o tipo.o -o $(PROGRAM)
main.o: main.c polilinea.h 
	$(CC) $(CFLAGS) -c main.c
polilinea.o: polilinea.c polilinea.h color.h tipo.h
	$(CC) $(CFLAGS) -c polilinea.c
color.o: color.c color.h
	$(CC) $(CFLAGS) -c color.c
tipo.o: tipo.c tipo.h
	$(CC) $(CFLAGS) -c tipo.c
clean:
	rm -vf *.o $(PROGRAM)
.PHONY: run
run: $(PROGRAM)
	./$(PROGRAM) figuras_in.bin

