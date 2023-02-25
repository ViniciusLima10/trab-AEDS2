#include "tabelaHash.h"


void inicializarTabela(Palavra t[]){
    int i;
    for(i = 0; i < TAM; i++)
        strcpy(t[i].palavra, ""); 
}


int funcaoHashString(char str[]){ 
    int i, tamS = strlen(str);
    unsigned int hash = 0;

    for(i = 0; i < tamS; i++)
        hash += str[i] * (i + 1); 
    return hash % TAM;
}


int funcaoHash(int chave){
    return chave % TAM;
}

void inserir(Palavra t[], char *result, int linha){
    int aux = 0, i;
    Palavra p;
    strcpy(p.palavra, result);
    p.frequencia = 1;

    for(i = 0; i < TAMLINHA; i++){
        p.linhas[i] = 0;
    }
    p.linhas[0] = linha;
        
    int id = funcaoHashString(p.palavra);
    while(strlen(Tabela_Hash.palavra) > 0){ //Tabela_Hash == t[id]
        if(strcmp(p.palavra, Tabela_Hash.palavra) == 0){
           Tabela_Hash.frequencia += 1;
            for(i = 0; Tabela_Hash.linhas[i] != 0; i++){
                if(Tabela_Hash.linhas[i] < linha && Tabela_Hash.linhas[i + 1] == 0){
                    Tabela_Hash.linhas[i + 1] = linha;
                    break;
                }
            }


            aux = 1;
            break;
        }
        id = funcaoHash(id + 1);
    }
    if (aux == 0){
    Tabela_Hash = p; 
    }
}

void busca(Palavra t[], char chave[]){
    int aux = 0;
    int id = funcaoHashString(chave);
    while(strlen(t[id].palavra) > 0){ 
        if(strcmp(t[id].palavra, chave) == 0){
            printf("%d ", t[id].frequencia);
            printf("%s ", t[id].palavra);
            for(int i=0; t[id].linhas[i] != 0; i++){
               printf("%d ", t[id].linhas[i]); 
            }
            printf("\n");
            aux = 1;
        }   
        id = id + 1;
    }
    if (aux == 0)
    {
       printf("Palavra nao encontrada!");
    }
    
}

void imprimeTabela(Palavra t[]){
    int i, j;

    for(i = 0; i < TAM; i++){
        if(strlen(t[i].palavra) > 0){
            printf("frequencia %d: %s", t[i].frequencia, t[i].palavra);
            for(j = 0; t[i].linhas[j] != 0 ; j++){
                printf(" %d", t[i].linhas[j]);
            }
        printf("\n--------------------------\n");
        }
    }
}