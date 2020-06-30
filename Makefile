entrada.o: entrada.c
	gcc -c entrada.c -o entrada.o

tab.o : tab.c
	gcc -c tab.c -o tab.o

main.o: main.c
	gcc -c main.c -o main.o

qwirkle: entrada.o tab.o main.o
	gcc -o qwirkle *.o

all: qwirkle

run: all
	./qwirkle

clean: entrada.o tab.o main.o qwirkle
	rm *.o qwirkle

zip: struct.h entrada.c entrada.h tab.c tab.h main.c
	zip qwirkle.zip Makefile *.c *.h	