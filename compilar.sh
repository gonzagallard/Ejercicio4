gcc -Wall -std=c99 -pedantic -g -c ./build/main.c
gcc -Wall -std=c99 -pedantic -g -c ./build/funciones.c
gcc -Wall -std=c99 -pedantic -g main.o funciones.o -o ./build/main
