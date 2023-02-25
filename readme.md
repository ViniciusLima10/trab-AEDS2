Vinicius de Almeida Lima


Anexos: 
    Listagem dos programas: 
        • index.c
        • leituraSaida.c 
        • leituraSaida.h
        • tabelaHash.c
        • tabelaHash.h
        • input.txt
        • pesquisa.txt
        • makefile


Compilação:

 	> make run
	o comando "make run" compila e executa o código para isso é necessário que os dois arquivos, input.txt(arquivo referente ao texto) e pesquisa.txt(arquivo referente às palavras a serem pesquisadas), estejam presentes na pasta do programa.

    
> make
   	o comando "make" compila e cria o binário e para executar recebe dois parâmetros sendo o primeiro um arquivo de entrada e o segundo um arquivo de pesquisa
    exemplo:
    > ./a.out texto.txt pesquisa.txt

  	> make clean
	O comando “make clean” apaga os arquivos criados pelos comandos acima e deixa apenas os códigos do programa.