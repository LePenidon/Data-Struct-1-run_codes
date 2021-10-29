
all: item.o pilha.o main.o 
	gcc item.o pilha.o main.o -o execute -std=c99 -pedantic-errors -Wall -lm

item.o:
	gcc -c ./TAD_item/item.c -I./TAD_item/ -o item.o

pilha.o:
	gcc -c ./TAD_pilha_din_encadeada/pilha.c -I/TAD_pilha_din_encadeada -o pilha.o

main.o:
	gcc -c main.c -o main.o

run:
	./execute

clean:
	rm *.o *.zip execute