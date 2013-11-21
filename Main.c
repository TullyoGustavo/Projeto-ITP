#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char categoria[50];
	int codigo;
	float preco;					
	char descricao[50];
	char fabricante[50];
	int dataval;
	int local [10][20];
	int estoque;
}Produto;

void buscapreco(float precodigitado){

 


void buscaestoque(int estoquedigitado){


}

int main (void){
int entrada,entrada2,repestoque;
Produto produto[10];
int i;
printf("Digite 1 para acessar o menu do funcionario\n");
printf("Digite 2 para acessar o menu do cliente\n");
scanf("%i",&entrada);
switch(entrada){
	case 1
		for(i=0;i<10;i++){		
		if(produto[i].estoque < 250){
			printf("Produto %i esta com o estoque baixo",i+1);		
			}			
		if(produto[i].dataval > produto[i].dataval ){
			printf("Produto %i esta fora da validade");
			}
		}
		printf("Digite 1  para entrada de produtos novos\n");
		printf("Digite 2  para reposição de estoque\n");
		scanf("%i",&entrada2);	
		if(entrada2==1){
		
		}
		if(entrada2==2){
			for(i=0;i<10;i++){
			
			printf("Reponha o estoque do produto %i\n",i+1);
			scanf("%i",&repestoque);
			produto[i].estoque+= repestoque;
		}	
					}	

	break;
	case 2
	
	break;
printf("Volte sempre");
return 0;
}
