all: circulo.o ponto.o main
	gcc main.o circulo.o ponto.o -o execute -std=c99 -pedantic-errors -Wall -lm

circulo.o:
	gcc -c ./circulo/circulo.c -o circulo.o

ponto.o:
	gcc -c ./ponto/ponto.c -o ponto.o

main:
	gcc -c main.c -I./circulo -I./ponto -o main.o

run:
	./execute

clean:
	rm *.o *.zip execute
