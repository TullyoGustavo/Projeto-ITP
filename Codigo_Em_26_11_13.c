#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 500

// ENUMERACAO PARA CATEGORIA DOS PRODUTOS
typedef enum {
        LIMPEZA, //0
        ALIMENTO_PERECIVEL, //1
        ALIMENTO_NAO_PERECIVEL, //2
        ELETRONICO //3
} Categoria;

// ESTRUTURA PARA CRIAR A VARIAVEL DATA
typedef struct {

        int d;
        int m;
        int a;

}Data;

// ESTRUTURA PARA VARIAVEL DE LOCALIZACAO
typedef struct{

        int c; //Corredor
        int p; //Prateleira

}Local;


//ESTRUTURA PARA CRIACAO DA VARIAVEL PRODUTO
typedef struct {

        Categoria cat;
        int codigo;
        float preco;
        int estoque;
        char descricao[500];
        char nome[50];
        char fabricante[50];
        Data validade;
        Local posicao;

}   Prod;

// PROGRAMA PRINCIPAL
int main() {
    // DECLARACAO DE VARIAVEIS
        Prod estoque[MAX];
        int n, i, x;

    // ABERTURA DO ARQUIVO UTILIZADO NO PROGRAMA >> ESTOQUE.txt
        FILE *arquivo = fopen( "ESTOQUE.txt", "r" );

    // VERIFICACAO SE O ARQUIVO É VÁLIDO OU NÃO
        if( arquivo == NULL ){
                printf( "Erro na abertura do arquivo" );
                }

    /* CASO SEJA VALIDO, VERIFICAR O NUMERO DE PRODUTOS CADASTRADOS "n" E RECEBER OS ELEMENTOS PARA
    ** PREENCHER AS VARIAVEIS */
                else {
                fscanf( arquivo, "numero = %i", &n );
                printf( "Existe %i PRODUTOS CADASTRADOS\n", n );

                for( i = 0 ; i < n; i++ ) {

                        fscanf( arquivo," %i", &estoque[i].cat );
                        fscanf( arquivo," %i", &estoque[i].codigo);
                        fscanf( arquivo," %f", &estoque[i].preco);
                        fscanf( arquivo," %i", &estoque[i].estoque);
                        fscanf( arquivo," %i", &estoque[i].descricao);
                        fscanf( arquivo," %i", &estoque[i].nome);
                        fgets( estoque[i].descricao, 500, arquivo);
                        fgets( estoque[i].nome, 50, arquivo);
                        fgets( estoque[i].fabricante, 50, arquivo);
                        fscanf( arquivo," %i", &estoque[i].validade.d);
                        fscanf( arquivo," %i", &estoque[i].validade.m);
                        fscanf( arquivo," %i", &estoque[i].validade.a);
                        fscanf( arquivo," %i", &estoque[i].posicao.c);
                        fscanf( arquivo," %i", &estoque[i].posicao.p);

                }
                        fclose( arquivo );
                        }
        //INICIO DAS ORDENACOES
        /* UTILIZEI O METODO CONHECIDO COMO "BUBBLE SORT" PARA
        ** REALIZAR AS ORDENAÇOES DAS VARIAVEIS. SO QUE NAO SEI
        ** O METODO CORRETO PARA, DEPOIS DE FAZER A ORDENAÇAO,
        ** IMPLEMENTAR NO CODIGO PARA QUE POSSA
        ** IMPRIMIR TODO O CONJUNTO DAS VARIAVEIS DO ARQUIVO.
        ** APENAS O QUE MUDOU NA IMPRESSAO DAS VARIAVEIS FORAM
        ** AQUELAS QUE FORAM AFETADAS PELA ORDENAÇAO, OU SEJA,
        ** PREÇO, ESTOQUE, NOME, CATEGORIA.
        */



   //ORDENAÇAO PRECO
    int ;
int vetor[MAX] = {} ; // Elementos quaisquer
//int tam = n; << - Ignorem esta variavel. É só um pequeno teste que estou fazendo.
int j, temp;
for ( i=n-1; i>0; i--) {
// Repetir o passo interno N-1 vezes
for ( j=0; j<i; j++ ) {
/*O passo interno consistem em fazer uma bolha
 subir o mais alto possivel. */

    if (estoque[i].preco<estoque[j].preco) {
    temp = estoque[i].preco;
    estoque[i].preco=estoque[j].preco;
    estoque[j].preco=temp;

            }
        }
    }
//FIM ORDENACAO PRECO

    // ORDENACAO ESTOQUE
    for ( i=n-1; i>0; i--) {
        for(j=0; j<i; j++ ) {
            if (estoque[i].estoque<estoque[j].estoque) {
            temp = estoque[i].estoque;
            estoque[i].estoque=estoque[j].estoque;
            estoque[j].estoque=temp;
            }
        }
    }
// FIM ORDENACAO ESTOQUE

// ORDENACAO POR NOME
 int cmp; // Criacao da variavel "cmp" << COMPARE
 char tmp[1][10]; // Criacao de outra variavel temporaria

 for(i=0; i<n; i++){
        for(j=0; j<n-1; j++){
            cmp=strcmp(estoque[j].nome,estoque[j+1].nome);

            if(cmp>0){
                strcpy(tmp[0],estoque[j+1].nome);
                strcpy(estoque[j+1].nome,estoque[j].nome);
                strcpy(estoque[j].nome,tmp[0]);
            }
        }
 }
//ORDENACAO DE CATEGORIA
 for ( i=n-1; i>0; i--) {
        for(j=0; j<i; j++ ) {
            if (estoque[i].cat<estoque[j].cat) {
            temp = estoque[i].cat;
            estoque[i].cat=estoque[j].cat;
            estoque[j].cat=temp;
            }
        }
    }
//FIM DA ORDENACAO DE CATEGORIA


// FIM ORDENACAO POR NOME

/* PRESTAR ATENCAO QUE NA IMPRESSAO DAS VARIAVEIS A UNICA ORDEM QUE SE TEM EH A
** DAS QUAIS AS VARIAVEIS FORAM MEXIDAS ANTERIORMENTE. AINDA PROCURANDO FORMAS PARA
** JUNTAR TUDO E ORDENAR TODO O CONJUNTO A PARTIR DISSO. */
               for( i = 0 ; i < n; i++ ) {
                        fprintf( stdout,"Nome %s", estoque[i].nome);
                        fprintf( stdout,"Categoria %i\n", estoque[i].cat );
                        fprintf( stdout,"Codigo %i\n", estoque[i].codigo);
                        fprintf( stdout,"Preco %.2f\n", estoque[i].preco);
                        fprintf( stdout,"Estoque: %i\n", estoque[i].estoque);
                        fprintf( stdout,"Descricao %s", estoque[i].descricao);
                        fprintf( stdout,"Fabricante %s", estoque[i].fabricante);
                        fprintf( stdout,"Validade: %i\/", estoque[i].validade.d);
                        fprintf( stdout," %i\/", estoque[i].validade.m);
                        fprintf( stdout,"%i\n", estoque[i].validade.a);
                        fprintf( stdout,"Corredor %i\n", estoque[i].posicao.c);
                        fprintf( stdout,"Prateleira %i\n\n", estoque[i].posicao.p);
                }

        return 0;
}
