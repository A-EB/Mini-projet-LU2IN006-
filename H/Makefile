#	Q-1.5

all: mainH

mainH : mainH.o biblioH.o entreeSortieH.o
			gcc mainH.o biblioH.o entreeSortieH.o -o mainH

biblioH.o: biblioH.c biblioH.h
			gcc -c biblioH.c -o biblioH.o

mainH.o: mainH.c biblioH.h entreeSortieH.h
			gcc -c mainH.c -o mainH.o

entreeSortieH.o: entreeSortieH.c entreeSortieH.h
			gcc -c entreeSortieH.c -o entreeSortieH.o

clean:
		rm -f *.o mainH