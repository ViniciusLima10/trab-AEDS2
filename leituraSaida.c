#include "leituraSaida.h"



void LeInput(Palavra t[], char **argv) {
    FILE *arq;
  char Linha[100];
  char *result;
  int l, i, j = 0;
  // Abre um arquivo TEXTO para LEITURA
  arq = fopen(argv[1], "rt");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  l = 1;
	result = (char*)calloc(100, sizeof(char));
  while (!feof(arq))
  {
      fgets(Linha, 100, arq); 
      for(i = 0; i < strlen(Linha); i++){
        if(!((Linha[i] >= 65 && Linha[i] <= 90) || (Linha[i] >= 97 && Linha[i] <= 122))){
            if(j > 1){
            inserir(t, result, l);
            free(result);
            result = (char*)calloc(100, sizeof(char));
            }
            j = 0;
        }else{
         if((Linha[i] >= 65 && Linha[i] <= 90) || (Linha[i] >= 97 && Linha[i] <= 122)){

        result[j] = Linha[i];
         if(result[j] >= 65 && result[j] <= 90){

                result[j] += 32;
            }
        j++;
         }
        }
      }
      i++;
      l++;
  }
  inserir(t, result, l);
  fclose(arq);

}

void LePesquisa(Palavra t[], char **argv) {
 FILE *arq;
  char Palavra[100];
  char *result;
  int i, j = 0, tamVetor;
  // Abre um arquivo TEXTO para LEITURA
  arq = fopen(argv[2], "rt");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }
    fscanf(arq, "%d", &tamVetor);

    for (i = 0; i <tamVetor; i++) {
        fscanf(arq, "%s", Palavra);
        busca(t, Palavra);
    }

  fclose(arq);
}
