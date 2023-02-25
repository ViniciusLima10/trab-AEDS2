### MAKEFILE ###

run: all
	./a.out input.txt pesquisa.txt

clean:
	rm *.o
	rm ./a.out

all: index

index: tabelaHash.o leituraSaida.o
	gcc -c index.c
	gcc index.o tabelaHash.o leituraSaida.o

tabelaHash.o: tabelaHash.c
	gcc -c tabelaHash.c

leituraSaida.o: leituraSaida.c
	gcc -c leituraSaida.c

