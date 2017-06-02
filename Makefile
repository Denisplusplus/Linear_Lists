start: main.o list.o iterator.o
	gcc -o exec main.o list.o iterator.o

main.o: main.c list.h iterator.h 
	gcc -c -w -std=c99 main.c

list.o: list.c 
	gcc -c -w -std=c99 list.c

iterator.o: iterator.c list.h 
	gcc -c -w -std=c99 iterator.c

clean:
	rm -rf *.o start
