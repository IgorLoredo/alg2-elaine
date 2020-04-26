//igor guilherme pereira loredo
// nusp 11275071

#include <stdio.h>
#include <stdlib.h>
#include "arq.h"

int main(void) {
    int comando,nusp,flag =1;
    int tamIndex =0;
    long endereco=0;
    ALUNO aux;
    INDEX *vetIndex = (INDEX*)malloc(sizeof(INDEX));
    FILE *df = NULL;
    FILE *index = NULL;

    do {
	    df= fopen("alunos.dad", "r+");        
	    if (df == NULL){
           criaArquivo(df);
           printf("Arquivos criado\n");
      }
	} while(df== NULL); // ver se ja tem o arquivo e cria caso no exista

    do {
	    index= fopen("index.dad", "r+");        
	    if (index == NULL){
           criaIndex(index);
           printf("\nArquivos index criado\n\n");
      }
	} while(index== NULL); // ver se ja tem o arquivo e cria caso no exista
    
     tamIndex = LerIndex(index, vetIndex); // pega o tamanho do fileindex junto e colcoa em um vetor
    
    do {
        menu();
        scanf("%d",&comando);
        switch(comando){

        case 1:
            printf("Inseri nUSP:");
            scanf("%d",&nusp); 
            if(pesquisaIndex(df,vetIndex,aux,nusp,tamIndex) == 0){
                insereRegistro(df,vetIndex,nusp,tamIndex, endereco);
            }

        break;

       case 2:
            printf("\nInseri nUSP:\n");
            scanf("%d",&nusp);     
            if(pesquisaIndex(df,vetIndex,aux,nusp,tamIndex) != 0 )
               imprimeRegistro(aux);
             else
                printf("\t\nRegistro nao existe ou foi apagado\n");
        break;

        case 3:
            printf("\nInseri nUSP:\n");
            scanf("%d",&nusp);
            if(pesquisaIndex(df,vetIndex,aux,nusp,tamIndex) != 0 )
               remover(df,vetIndex,tamIndex,nusp);
             else
                printf("\t\nRegistro nao existe ou ja foi apagado\n");
        break;

        case 4:
            printf("\nSaindo");
            flag =0;
		break;

        default:
            printf("Erro, comando nao valido");
        break;
        }
	} while(flag);

    GeraIndex(index,vetIndex,&tamIndex);
    fclose(index);
    fclose(df);

  return 0;
}