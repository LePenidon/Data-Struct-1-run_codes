CFLAGS = -std=c99 -pedantic-errors -Wall -lm

all: item.o arvore.o main.o 
	gcc item.o arvore.o main.o -o execute $(CFLAGS);./execute

arvore.o:
	gcc -c arvore.c $(CFLAGS) -I/ -o arvore.o

main.o:
	gcc -c main.c $(CFLAGS) -I/ -o main.o

item.o:
	gcc -c TAD_item/item.c $(CFLAGS) -I./TAD_item/ -o item.o

run:
	./execute

clean:
	rm *.o *.zip execute;clear