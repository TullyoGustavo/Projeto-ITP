#include<stdio.h>
#define MAX=500 

typedef enum { 
        LIMPEZA, //0 
        ALIMENTO_PERECIVEL, //1 
        ALIMENTO_NAO_PERECIVEL, //2 
        ELETRONICO //3
} Categoria; 

typedef struct { 

        int a;
        int m;
        int d;
        
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
        Local localizacao;
        
}Prod; 


int main() {
        Prod estoque[MAX]={0};
        int n, i, x, y;
        
        FILE *arquivo = fopen( "ESTOQUE.txt", "r" ); 
        
        if( arquivo == NULL ){
                printf( "Erro na abertura do arquivo" );
                }
                else { 
                fscanf( arquivo, "numero = %i\n", &n );
                printf( "Existe %i PRODUTOS CADASTRADOS\n", n ); 
                
                for( i = 0 ; i < n; i++ ) {
                
                        fscanf( arquivo," %i", &estoque[i].cat );
                        fscanf( arquivo," %i", &estoque[i].codigo);
                        fscanf( arquivo," %i", &estoque[i].preco);
                        fscanf( arquivo," %i", &estoque[i].descricao); 
                        fscanf( arquivo," %i", &estoque[i].nome); 
                        fgets( estoque[i].descricao, 500, arquivo); 
                        fgets( estoque[i].nome, 50, arquivo);
                        fgets( estoque[i].fabricante, 50, arquivo);
                        fscanf( arquivo," %i", &estoque[i].validade.a);
                        fscanf( arquivo," %i", &estoque[i].validade.m);
                        fscanf( arquivo," %i", &estoque[i].validade.d);
                        fscanf( arquivo," %i", &estoque[i].posicao.c); 
                        fscanf( arquivo," %i", &estoque[i].posicao.p); 
                        
                } 
                        fclose( arquivo ); 
                        } 
                        
                        
                for( i = 0 ; i < n; i++ ) {
                        fprintf( stdout,"Categoria %i", &estoque[i].cat );
                        fprintf( stdout,"Codigo %i", &estoque[i].codigo); 
                        fprintf( stdout,"Preco %.2f", &estoque[i].preco);
                        fprintf( stdout,"Descricao %s", &estoque[i].descricao);
                        fprintf( stdout,"Nome %s", &estoque[i].nome); 
                        fprintf( stdout,"Fabricante %s" estoque[i].fabricante); 
                        fprintf( stdout,"Ano %i", &estoque[i].validade.a); 
                        fprintf( stdout,"Mes %i", &estoque[i].validade.m); 
                        fprintf( stdout,"Dia %i", &estoque[i].validade.d);
                        fprintf( stdout,"Corredor %i", &estoque[i].posicao.c); 
                        fprintf( stdout,"Prateleira %i", &estoque[i].posicao.p); 
                } 
        } 
        
        return 0; 
}
