#	Q-1.5

all: main

main : main.o biblioLC.o entreeSortieLC.o
			gcc main.o biblioLC.o entreeSortieLC.o -o main

biblioLC.o: biblioLC.c biblioLC.h
			gcc -c biblioLC.c -o biblioLC.o

main.o: main.c biblioLC.h entreeSortieLC.h
			gcc -c main.c -o main.o

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h
			gcc -c entreeSortieLC.c -o entreeSortieLC.o

clean:
		rm -f *.o main