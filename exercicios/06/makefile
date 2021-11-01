
all: item.o lista.o main.o 
	gcc item.o lista.o main.o -o execute -std=c99 -pedantic-errors -Wall -lm

item.o:
	gcc -c ./TAD_lista_duplamente_encadeada/TAD_item/item.c -I./TAD_item/ -o item.o

lista.o:
	gcc -c ./TAD_lista_duplamente_encadeada/lista.c -I/TAD_lista_duplamente_encadeada -o lista.o

main.o:
	gcc -c main.c -o main.o

run:
	./execute

clean:
	rm *.o *.zip execute