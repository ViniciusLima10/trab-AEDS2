#include "leituraSaida.h"



int main (int argc, char *argv[]){
    FILE *arqInput;
    FILE *arqPesquisa;
    FILE **fileName;
    Palavra t[TAM];

    inicializarTabela(t);

	if (argc < 3)
		printf("Faltam parametros. Sao necessarios 2 arquivos para executar corretamente.\n");
	else if (argc > 3)
		printf("Parametros demais. Sao necessarios somente 2 arquivos.\n");
	else {

        LeInput(t, argv);
        LePesquisa(t, argv);
    }
    
    // imprimeTabela(t);

	return 0;
}