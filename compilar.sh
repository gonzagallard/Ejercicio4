gcc -Wall -std=c99 -pedantic -g -c main.c ./build/
gcc -Wall -std=c99 -pedantic -g -c funciones.c ./build/
gcc -Wall -std=c99 -pedantic -g ./build/main.o ./build/funciones.o -o ./build/main
