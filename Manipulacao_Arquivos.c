#include<stdio.h>
#define MAX 500

typedef enum {
        LIMPEZA, //0
        ALIMENTO_PERECIVEL, //1
        ALIMENTO_NAO_PERECIVEL, //2
        ELETRONICO //3
} Categoria;

typedef struct {

        int d;
        int m;
        int a;

}Data;

typedef struct{

        int c; //Corredor
        int p; //Prateleira

}Local;

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


int main() {
        Prod estoque[MAX];
        int n, i, x;

        FILE *arquivo = fopen( "ESTOQUE.txt", "r" );

        if( arquivo == NULL ){
                printf( "Erro na abertura do arquivo" );
                }
                else {
                fscanf( arquivo, "numero = %i", &n );
                printf( "Existe %i PRODUTOS CADASTRADOS\n", n );

                for( i = 0 ; i < n; i++ ) {

                        fscanf( arquivo," %i", &estoque[i].cat );
                        fscanf( arquivo," %i", &estoque[i].codigo);
                        fscanf( arquivo," %f", &estoque[i].preco);
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


                for( i = 0 ; i < n; i++ ) {
                        fprintf( stdout,"Categoria %i\n", estoque[i].cat );
                        fprintf( stdout,"Codigo %i\n", estoque[i].codigo);
                        fprintf( stdout,"Preco %.2f\n", estoque[i].preco);
                        fprintf( stdout,"Descricao %s\n", estoque[i].descricao);
                        fprintf( stdout,"Nome %s\n", estoque[i].nome);
                        fprintf( stdout,"Fabricante %s\n", estoque[i].fabricante);
                        fprintf( stdout,"Validade: %i\/", estoque[i].validade.d);
                        fprintf( stdout," %i\/", estoque[i].validade.m);
                        fprintf( stdout,"%i\n", estoque[i].validade.a);
                        fprintf( stdout,"Corredor %i\n", estoque[i].posicao.c);
                        fprintf( stdout,"Prateleira %i\n", estoque[i].posicao.p);
                }


        return 0;
}
