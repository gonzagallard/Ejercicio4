gcc -Wall -std=c99 -pedantic -g -c main.c 
gcc -Wall -std=c99 -pedantic -g -c funciones.c 
gcc -Wall -std=c99 -pedantic -g main.o funciones.o -o main
