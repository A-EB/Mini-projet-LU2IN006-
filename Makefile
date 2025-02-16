CC = gcc
CFLAGS = -Wall
DIR1 = LC/
DIR2 = H/

all: compStruct

biblioLC.o: $(DIR1)biblioLC.c $(DIR1)biblioLC.h
			$(CC) $(CFLAGS) -c $(DIR1)biblioLC.c

entreeSortieLC.o: $(DIR1)entreeSortieLC.c $(DIR1)entreeSortieLC.h
			$(CC) $(CFLAGS) -c $(DIR1)entreeSortieLC.c 

biblioH.o: $(DIR2)biblioH.c $(DIR2)biblioH.h
			$(CC) $(CFLAGS) -c $(DIR2)biblioH.c 

entreeSortieH.o: $(DIR2)entreeSortieH.c $(DIR2)entreeSortieH.h
			$(CC) $(CFLAGS) -c $(DIR2)entreeSortieH.c 

compStruct.o: compStruct.c $(DIR1)biblioLC.h $(DIR1)entreeSortieLC.h $(DIR2)biblioH.h $(DIR2)entreeSortieH.h
			$(CC) $(CFLAGS) -c compStruct.c

compStruct : compStruct.o biblioLC.o entreeSortieLC.o biblioH.o entreeSortieH.o
			$(CC) $(CFLAGS) -o compStruct biblioLC.o entreeSortieLC.o biblioH.o entreeSortieH.o compStruct.o

clean:
		rm -f *.o compStruct