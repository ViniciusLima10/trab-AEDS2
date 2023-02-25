#ifndef __TABELAHASH__
#define __TABELAHASH__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 521
#define TAMPALAVRA 21
#define TAMLINHA 1000
#define Tabela_Hash t[id]

typedef struct {
    char palavra[TAMPALAVRA];
    int frequencia;
    int linhas[TAMLINHA];
}Palavra;

void inicializarTabela(Palavra t[]);

int funcaoHashString(char str[]);

int funcaoHash(int chave);

void inserir(Palavra t[], char *result, int linha);

void busca(Palavra t[], char chave[]);

void imprimeTabela(Palavra t[]);

#endif