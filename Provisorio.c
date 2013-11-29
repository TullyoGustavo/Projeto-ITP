# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# define limpa system("cls")

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
}Prod;
// Estrutura para 'cliente'
typedef struct  {
int codigo;
char nome[30];
char ende[30];
char fone[16];
float vdevido;
}Cliente;

// Estrutura para 'venda'
typedef struct{
int codigo, codvnd, codcli, codprod, qtdeprod;
}Venda;

// Variaveis das estruturas
Prod produto[100];
Cliente cli[100];
Venda vnd[100];

int n;
void carregar_arquivo(){
int i;
FILE *arquivo = fopen("ESTOQUE.TXT", "a");

    if( arquivo == NULL){
        printf("Erro na abertura do arquivo");
    }
        else{
                fscanf( arquivo, "numero = %i", &n );
              //  printf( "Existe %i PRODUTOS CADASTRADOS\n", n );
                for( i = 0 ; i < n; i++ ) {

                        fscanf( arquivo," %i", &produto[i].cat );
                        fscanf( arquivo," %i", &produto[i].codigo);
                        fscanf( arquivo," %f", &produto[i].preco);
                        fscanf( arquivo," %i", &produto[i].estoque);
                        fscanf( arquivo," %i", &produto[i].descricao);
                        fscanf( arquivo," %i", &produto[i].nome);
                        fgets( produto[i].descricao, 500, arquivo);
                        fgets( produto[i].nome, 50, arquivo);
                        fgets( produto[i].fabricante, 50, arquivo);
                        fscanf( arquivo," %i", &produto[i].validade.d);
                        fscanf( arquivo," %i", &produto[i].validade.m);
                        fscanf( arquivo," %i", &produto[i].validade.a);
                        fscanf( arquivo," %i", &produto[i].posicao.c);
                        fscanf( arquivo," %i", &produto[i].posicao.p);

                }
                        fclose( arquivo );
                        }
}

// 1 Cadastra Cliente
void cadastra_cliente () {
   int i,opcao;
    FILE *arquivo = fopen("CLIENTE.txt", "a");

    for (i=0;i<100;i++) {
         if (cli[i].codigo == 0) {
            cli[i].codigo = i+1;
            printf ("\n\tCodigo: \t\t\t%d",cli[i].codigo);
            printf ("\n\tDigite nome do cliente: \t");
            gets(cli[i].nome);
            printf ("\tDigite endereco do cliente: \t");
            gets (cli[i].ende);

            printf ("\tDigite fone do cliente: \t");
            gets (cli[i].fone);
            cli[i].vdevido = 0;

           //Continua ou nao cadastrar
            printf ("\n\n\n\tDeseja continuar cadastrando");
            printf ("\n\t1     - Sim");
            printf ("\n\tOutro - Nao");
            printf ("\n\tOpcao: ");
            scanf ("%d",&opcao);
            fflush (stdin);
            if (opcao != 1)
               break;
         limpa;
        }
    }
}

// Lista Clientes
void lista_cliente () {
   int i;

   for (i=0;i<100;i++) {
       if (cli[i].codigo != 0){
         limpa;
         printf ("\n\tCodigo: \t\t%d", cli[i].codigo);
         printf ("\n\tNome do cliente: \t%s", cli[i].nome);
         printf ("\n\tEndereco do cliente: \t%s", cli[i].ende);
         printf ("\n\tFone do cliente: \t%s", cli[i].fone);
         printf ("\n\tValor devido: \t\t%0.2f", cli[i].vdevido);
         printf ("\n\n\t");
         system ("pause");
        }
    }
}

// 2 Cadastra Produto
void cadastra_produto () {
  int i,opcao;
FILE *arquivo = fopen("ESTOQUE.txt", "a+");

    for (i=0;i<100;i++) {
         if (produto[i].codigo == 0) {
            produto[i].codigo = i+1;
            printf ("\n\tCodigo: \t\t\t%d",produto[i].codigo);
            fprintf(arquivo,"\n%i",produto[i].codigo);
            printf ("\n\tDigite nome do produto: \t");
            gets(produto[i].nome);
            fprintf(arquivo," %s",produto[i].nome);


            printf("\n\tDigite a categoria do produto: \t");
            scanf("%i", &produto[i].cat);
            fprintf(arquivo," %i", produto[i].cat);

            printf ("\n\tDigite preco do produto: \t");
            scanf ("%f",&produto[i].preco);
            fprintf(arquivo," %.2f",produto[i].preco);
            getchar();

            printf ("\n\tDigite a descricao do produto: \t");
            fgets(produto[i].descricao,500,stdin);
            fprintf(arquivo," %s",produto[i].descricao);

            printf ("\n\tDigite o estoque do produto: \t");
            scanf ("%i",&produto[i].estoque);
            fprintf(arquivo," %i",produto[i].estoque);
            getchar();

           printf ("\n\tDigite o fabricante do produto: \t");
             gets (produto[i].fabricante);
            fprintf(arquivo," %s",produto[i].fabricante);

            printf ("\n\tDigite a validade do produto no formato dd/mm/aaaa:  \t");
            scanf ("%i %i %i",&produto[i].validade.d, &produto[i].validade.m, &produto[i].validade.a);
            fprintf(arquivo," %i %i %i ",produto[i].validade.d, produto[i].validade.m, produto[i].validade.a);

            printf ("\n\tDigite a localizacao do produto (Corredor e Prateleira): \t");
            scanf ("%i %i",&produto[i].posicao.c, &produto[i].posicao.p);
            fprintf(arquivo," %i %i",produto[i].posicao.c, produto[i].posicao.p);

         //   produto[i].estoque = 0;
            fflush (stdin);
           //Continua ou nao cadastrar
            printf ("\n\n\n\tDeseja continuar cadastrando");
            printf ("\n\t1     - Sim");
            printf ("\n\tOutro - Nao");
            printf ("\n\tOpcao: ");
            scanf ("%d",&opcao);
            fflush (stdin);
            if (opcao != 1)
               break;
         limpa;
        }
    }
}

// Lista produto
void listar_produtos () {
  int i;

  // for (i=0;i<100;i++) {
      //if (produto[i].codigo != 0)
         limpa;

         FILE *arquivo = fopen("ESTOQUE.txt", "r+");
 if( arquivo == NULL){
        printf("Erro na abertura do arquivo");
    }

        else{
                fscanf( arquivo, "numero = %i", &n );

 for( i = 0 ; i < n; i++ ) {

                        fscanf( arquivo," %i", &produto[i].cat );
                        fscanf( arquivo," %i", &produto[i].codigo);
                        fscanf( arquivo," %f", &produto[i].preco);
                        fscanf( arquivo," %i", &produto[i].estoque);
                        fscanf( arquivo," %i", &produto[i].descricao);
                        fscanf( arquivo," %i", &produto[i].nome);
                        fgets( produto[i].descricao, 500, arquivo);
                        fgets( produto[i].nome, 50, arquivo);
                        fgets( produto[i].fabricante, 50, arquivo);
                        fscanf( arquivo," %i", &produto[i].validade.d);
                        fscanf( arquivo," %i", &produto[i].validade.m);
                        fscanf( arquivo," %i", &produto[i].validade.a);
                        fscanf( arquivo," %i", &produto[i].posicao.c);
                        fscanf( arquivo," %i", &produto[i].posicao.p);

                }
                        fclose( arquivo );
                        }
    if( arquivo == NULL){
        printf("Erro na abertura do arquivo");
    }

        else{
                //fscanf( arquivo, "numero = %i", &n );
              //  printf( "Existe %i PRODUTOS CADASTRADOS\n", n );

                for( i = 0 ; i < 2; i++ ) {
                        fprintf( stdout," %i", produto[i].codigo);
                        fprintf( stdout," %i", produto[i].cat );
                        fprintf( stdout," %f", produto[i].preco);
                        fprintf( stdout," %i", produto[i].estoque);
                        fprintf( stdout," %i", produto[i].descricao);
                        fprintf( stdout," %i", produto[i].nome);
                        fprintf( stdout," %s", produto[i].descricao);
                        fprintf( stdout," %s", produto[i].nome);
                        fprintf( stdout," %s", produto[i].fabricante);
                        fprintf( stdout," %i", produto[i].validade.d);
                        fprintf( stdout," %i", produto[i].validade.m);
                        fprintf( stdout," %i", produto[i].validade.a);
                        fprintf( stdout," %i", produto[i].posicao.c);
                        fprintf( stdout," %i", produto[i].posicao.p);

                }
                        fclose( arquivo );
                        }
         system("pause");
      }

}

int BUSCA_CLIENTE(int CLI) {
   int i,ind = -1;
   //Aqui vai permitir o cadastro de 100 clientes
   for (i=0;i<100;i++) {
      //Aqui é feita a busca somente nos registros que tem código cadastrado
      if (cli[i].codigo != 0) {
         //Verifica pelo código do cliente qual registro ele ocupa no vetor
         if (cli[i].codigo == CLI) {
            ind = i;
            break;
         }
      }
   }
   return(ind);
}

int BUSCA_PRODUTO(int PRODUTO) {
   int i,ind = -1;
   //Aqui vai permitir o cadastro de 100 clientes
   for (i=0;i<100;i++)      {
      //Aqui é feita a busca somente nos registros que tem código cadastrado
      if (produto[i].codigo != 0)          {
         //Verifica pelo código do cliente qual registro ele ocupa no vetor
         if (produto[i].codigo == PRODUTO)              {
            ind = i;
            break;
         }
      }
   }
   return(ind);
}

int BUSCA_VENDA(int VEND) {
   int i,ind = -1;
   //Aqui vai permitir o cadastro de 100 clientes
   for (i=0;i<100;i++)      {
      //Aqui é feita a busca somente nos registros que tem código cadastrado
      if (vnd[i].codigo != 0)          {
         //Verifica pelo código do cliente qual registro ele ocupa no vetor
         if (vnd[i].codigo == VEND)              {
            ind = i;
            break;
         }
      }
   }
   return(ind);
}

// 3 Realiza Venda, verificando se a conta eh paga ou nao;
// Se conta paga, armazena o seu valor devido, informando
// se o produto tem estoque suficiente
void realizar_venda() {
   int i,indice,opcao,IND_CLI,IND_PRO,CLI,PRO,qtd;
   char VENDA;
   float vdev;

   //Aqui vai permitir o cadastro de 100 pedidos
   for (i=0;i<100;i++) {
      //Onde não foi cadastrado código é possível cadastrar o pedido
      if (vnd[i].codigo == 0) {
         limpa;
         printf ("\n\n\t|==================  REALIZAR VENDA  ==================|");
         printf ("\n\t|Para retornar ao menu, digite '0' em codigo de venda|\n\n");
         printf("\tDigite codigo da venda: ");
         scanf("%d",&vnd[i].codvnd);
         fflush(stdin);
            if (vnd[i].codvnd == 0)
               break;
               vnd[i].codigo = i+1;
            //Entrada do cliente
         while (1) {
            //Limpa a tela
            limpa;
            printf ("\n\n\t|============  REALIZAR VENDA  %d  =============|\n\n",vnd[i].codvnd);
            printf ("\n\tDigite codigo do cliente: ");
            scanf("%d",&CLI);
            fflush(stdin);

            //Chama a funcao que ira procurar a existencia do cliente
            IND_CLI = BUSCA_CLIENTE(CLI);
            //Se o indice do cliente retornar -1 o cliente nao foi encontrado

            if (IND_CLI == -1) {
               printf("\n\t***  Cliente nao encontrado  ***\n\n\t");
               system("pause");
            }
            else {
               printf("\n\tCodigo do cliente.........: %d",cli[IND_CLI].codigo);
               printf("\n\tNome do cliente...........: %s",cli[IND_CLI].nome);
               printf("\n\tEndereco do cliente.......: %s",cli[IND_CLI].ende);
               printf("\n\tTelefone..................: %s",cli[IND_CLI].fone);

               //Continua ou nao cadastrar
               printf("\n\n\n\tConfirma o cliente");
               printf("\n\t1     - Sim");
               printf("\n\tOutro - Nao");
               // (strcmp(nome,cli[i].nome)==0))
               printf("\n\tOpcao: ");
               scanf("%d",&opcao);
               fflush(stdin);
                  if (opcao == 1)
                     break;
            }
         }
         vnd[i].codcli = CLI;
         //Entrada do produto
         while (1) {
         //Limpa a tela
         limpa;
            printf ("\n\n\t|============  REALIZAR VENDA  %d  =============|\n\n",vnd[i].codcli);
            printf("\nCLIENTE: %d %s\n\n\t",cli[IND_CLI].codigo,cli[IND_CLI].nome);
            system("pause");
            break;
         }

         //Venda do produto
         while (1) {
            //Limpa a tela
            limpa;
            printf ("\n\n\t|============  REALIZAR VENDA  %d  ============|\n\n",vnd[i].codvnd);
            printf ("\tCLIENTE : %d %s\n\n",cli[IND_CLI].codigo,cli[IND_CLI].nome);
            printf ("\n\tEntre com o codigo do produto: ");
            scanf("%d",&PRO);
            fflush(stdin);
            //Chama a funcao que ira procurar a existencia do produto
            IND_PRO = BUSCA_PRODUTO(PRO);

            //Se o indice do produto retornar -1 o produto nao foi encontrado
            if (IND_PRO == -1) {
               printf("\n\n\t***  Produto nao encontrado  ***\n\n\t");
               system("pause");
            }
            else {
               printf("\n\tDigite quantidade de produto: ");
               scanf("%d",&qtd);
               fflush(stdin);
                  if(qtd > produto[IND_PRO].estoque){
                     printf("\n\t***  Estoque Insuficiente  ***\n\n\t");
                     system("pause");
                  }
                  else {
                     vnd[i].qtdeprod = qtd;
                     produto[IND_PRO].estoque = (produto[IND_PRO].estoque - qtd);
                     printf("\n\tEstoque Subtotal: %d \n\n\t", produto[IND_PRO].estoque);
                     system("pause");
                  }
            }
            break;
         }

      printf ("\n\n|============  REALIZAR VENDA  %d  ============|\n\n",vnd[i].codvnd);
      printf ("\tCLIENTE : %d %s\n\n",cli[IND_CLI].codigo,cli[IND_CLI].nome);
      printf ("\n\tDeseja pagar compra (venda)('S' - sim, 'N' - nao: ");
      scanf("%c",&VENDA);
      fflush(stdin);

          if (VENDA == 'S') {
             printf ("\n\tTotal da venda: %0.2f", produto[IND_PRO].preco * vnd[i].qtdeprod);
             printf ("\n\n\t");
             system ("pause");
          }
          else if (VENDA == 'N') {
             cli[IND_CLI].vdevido = (cli[IND_CLI].vdevido + (produto[IND_PRO].preco * vnd[i].qtdeprod));
             printf ("\n\tTotal da venda: %0.2f\n",produto[IND_PRO].preco * vnd[i].qtdeprod);
             printf ("\tTotal devido pelo cliente: %0.2f\n", cli[IND_CLI].vdevido);
             printf ("\n\n\t");
             system ("pause");
          }
      }

   }
   if (vnd[i].codigo != 0) {
      printf("\n\t***  Cliente nao encontrado  ***\n\n\t");
      system("pause");
   }
}

// 4 Acrescenta produtos ao estoque
void estoque () {
   int i,indice,pro,ent;

   printf("\n\tDigite codigo do produto a ser dada entrada: ");
   scanf("%d",&pro);
   fflush(stdin);
   indice = BUSCA_PRODUTO(pro);

   if (indice != -1){
      printf("\tDigite estoque: ");
      scanf("%d",&ent);
      fflush(stdin);
      produto[indice].estoque = produto[indice].estoque + ent;
   }
   else {
      printf("\n\t***  Produto nao encontrado  ***\n\n\t");
      system("pause");
   }
}

// 5 Realiza pagamento conta do cliente
void pgtocta_cliente () {
   int i, CLI, IND_CLI;
   float vdev;

   printf("\n\tDigite codigo do cliente que pagarah conta: ");
   scanf("%d",&CLI);
   fflush(stdin);

   IND_CLI = BUSCA_CLIENTE(CLI);
     if (IND_CLI == -1){
        limpa;
        printf ("\n\t***  Cliente nao encontrado  ***\n\n\t");
        system ("pause");
     }
     // Aqui, ao digitar o valor a ser pago, eh feita a diminuicao
     // ou eliminacao da divida
     // *** ERROR: nao estah diminuindo, mantem a divida.
     else {
        printf("\tEntre com o valor a ser pago: ");
        scanf("%5.2f",&vdev);
        fflush(stdin);
        cli[IND_CLI].vdevido = cli[IND_CLI].vdevido - vdev;
        printf ("\tValor restante: %0.2f\n\n\t", cli[IND_CLI].vdevido);
        system ("pause");
     }
}

// 6 Listar Clientes
// Listar todos.
// Listar por código desejado.
// Listar por nome desejado.
// Listar devedores.
void lista_clientes () {
   int i, cod, achou = 0, opcao, IND_CLI;
   char nome[30], deved[30], VENDA;

   printf ("\n\t Digite opcao: ");
   printf ("\n\t 1 - Listar todos ");
   printf ("\n\t 2 - Listar por codigo desejado ");
   printf ("\n\t 3 - Listar por nome desejado ");
   printf ("\n\t 4 - Listar devedores ");
   printf ("\n\n\tOpcao: ");
   scanf ("%d",&opcao);
   fflush (stdin);

   if ((opcao != 1) && (opcao != 2) && (opcao != 3) && (opcao !=4)){
      printf ("\n\t*** Opcao Invalida ***\n\n\t");
      system ("pause");
  }
   //Limpa tela
     limpa;
   // Lista todos os clientes cadastrados
   // Para o primeiro cliente, no dado 'valor devido', eh exibido lixo e
   // para o segundo cliente, eh exibido o valor correto de sua divida.
     if (opcao == 1) {
        printf ("\n\t*** Todos os Clientes *** ");
        lista_cliente ();
     }
    // Lista cliente atraves da digitacao de seu codigo correspondente
    else if (opcao == 2) {
    printf ("\n\tDigite codigo desejado: ");
    scanf ("%d",&cod);
    fflush (stdin);
       for (i=0;i<100;i++) {
          if ((cli[i].codigo != 0) && (cod == cli[i].codigo)) {
             achou = 1;
             printf ("\n\tCodigo: \t\t%d", cli[i].codigo);
             printf ("\n\tNome do cliente: \t%s", cli[i].nome);
             printf ("\n\tEndereco do cliente: \t%s", cli[i].ende);
             printf ("\n\tFone do cliente: \t%s", cli[i].fone);
             printf ("\n\tValor devido: \t\t%0.2f", cli[i].vdevido);
             printf ("\n\n\t");
             system ("pause");
         }
     }
    if (achou==0) {
    limpa;
    printf ("\n\n\t***  Codigo nao cadastrado  ***");
    printf ("\n\n\t");
    system("pause");
    }
   }
   // Lista cliente atraves da digitacao de seu nome correspondente
   else if (opcao == 3) {
   printf ("\n\tDigite nome desejado: ");
   gets (nome);
      for (i=0;i<100;i++) {
          if (strcmp(nome,cli[i].nome) == 0) {
             achou = 1;
             printf ("\n\tCodigo: \t\t%d", cli[i].codigo);
             printf ("\n\tNome do cliente: \t%s", cli[i].nome);
             printf ("\n\tEndereco do cliente: \t%s", cli[i].ende);
             printf ("\n\tFone do cliente: \t%s", cli[i].fone);
             printf ("\n\tValor devido: \t\t%0.2f", cli[i].vdevido);
             printf ("\n\n\t");
             system ("pause");
         }
      }
      if (achou==0) {
      limpa;
      printf ("\n\n\t***  Cliente nao cadastrado  ***\n\n\t");
      system("pause");
      }
   }
   // Lista devedores
   else if (opcao == 4) {
   printf ("\n\t\t*** Devedores ***\n\n");
   for (i=0;i<100;i++){
      printf ("\n\tCodigo: \t\t%d", cli[IND_CLI].codigo);
      printf ("\n\tNome do cliente: \t%s", cli[IND_CLI].nome);
      printf ("\n\tEndereco do cliente: \t%s", cli[IND_CLI].ende);
      printf ("\n\tFone do cliente: \t%s", cli[IND_CLI].fone);
      printf ("\n\tValor devido: \t\t%0.2f", cli[IND_CLI].vdevido);
      printf ("\n\n\t");
      system ("pause");
      limpa;
   }
}
}
// 7 Listar Produto
// Listar todos.
// Listar por código desejado.
// Listar por nome desejado.
void lista_produto () {
   int i, cod, achou = 0, opcao;
   char nome[30];

   printf ("\n\t Digite opcao: ");
   printf ("\n\t 1 - Listar todos ");
   printf ("\n\t 2 - Listar por codigo desejado ");
   printf ("\n\t 3 - Listar por nome desejado ");
   printf ("\n\n\tOpcao: ");
   scanf ("%i",&opcao);
   fflush (stdin);

   if ((opcao != 1) && (opcao != 2) && (opcao != 3)){
      printf ("\n\t*** Opcao Invalida ***\n\n\t");
      system ("pause");
  }
   //Limpa tela
     limpa;
     // Lista todos os produtos
     if (opcao == 1) {
        printf ("\n\t*** Todos os Produtos *** ");
        listar_produtos ();
        achou = 1;
     }
    // Lista produto atraves da digitacao do seu codigo correspondente
    else if (opcao == 2) {
    printf ("\n\tDigite codigo desejado: ");
    scanf ("%d",&cod);
    fflush (stdin);
       for (i=0;i<100;i++) {
          if ((produto[i].codigo != 0) && (cod == produto[i].codigo)) {
            achou = 1;
            printf ("\n\tCodigo: \t\t\t%d",produto[i].codigo);
            printf ("\n\tNome do produto: \t\t%s", produto[i].nome);
            printf ("\n\tPreco do produto: \t\t%5.2f", produto[i].preco);
            printf ("\n\tQuantidade estoque produto: \t%d",produto[i].estoque);
            printf ("\n\n\t");
            system("pause");
          }
       }
       if (achou==0) {
       limpa;
       printf ("\n\n\t***  Codigo nao cadastrado  ***\n\n\t");
       system("pause");
       }
   }
   // Lista produto atraves da digitacao do seu nome correspondente
   else if (opcao == 3) {
   printf ("\n\tDigite nome desejado: ");
   gets (nome);
      for (i=0;i<100;i++) {
         if (strcmp(nome,produto[i].nome) == 0) {
            achou = 1;
            printf ("\n\tCodigo: \t\t\t%d",produto[i].codigo);
            printf ("\n\tNome do produto: \t\t%s", produto[i].nome);
            printf ("\n\tPreco do produto: \t\t%5.2f", produto[i].preco);
            printf ("\n\tQuantidade estoque produto: \t%d",produto[i].estoque);
            printf ("\n\n\t");
            system("pause");
          }
       }
       if (achou==0) {
       limpa;
       printf ("\n\n\t***  Produto nao cadastrado  ***\n\n\t");
       system("pause");
       }
   }
}

// 8 Listar vendas
void det_venda () {
   int i, cod, achou=0, IND_VEN;
   char VENDA;
   printf ("\n\tDigite codigo da venda procurada: ");
   scanf ("%d",&cod);
   fflush (stdin);

   IND_VEN = BUSCA_VENDA (cod);
      if (IND_VEN == -1) {
          printf ("\n\n\t***  Codigo de venda nao encontrado  ***\n\n\t");
          system ("pause");
      }
      else {
      limpa;
      printf ("\n");
      printf ("=============================================================================");
      printf ("\n                      \n");
      printf ("%4d     %-27s %8d %17.2f  %11.2f\n",vnd[IND_VEN].codvnd,produto[IND_VEN].nome,vnd[IND_VEN].qtdeprod,produto[IND_VEN].preco,produto[IND_VEN].preco * vnd[IND_VEN].qtdeprod);
      }
      printf ("=============================================================================");
      printf ("\n\n\n\t");
      system ("pause");
}

int main () {
    int i, op,opcao;
    FILE *arquivo = fopen("ESTOQUE.TXT", "r+");
    for (i=0;i<100;i++) {
        produto[i].codigo = 0;
        cli[i].codigo = 0;
    }
     carregar_arquivo();

     while (1) {
        limpa;
        printf ("\n\n\t|><><><><><><><><><><><><  MENU  ><><><><><><><><><><><|\n");
        printf ("\t|                                                      |\n");
        printf ("\t| (1) - Menu cliente                                   |\n");
        printf ("\t| (2) - Menu funcionario                               |\n");
        printf ("\t| (3) - Sair                                           |\n");
        printf ("\t|                                                      |\n");
        printf ("\t|><><><><><><><><><><><><><><><><><><><><><><><><><><><|\n\n");
        printf ("\t\tEntre com a opcao: ");
        scanf ("%d",&op);
        limpa;
        fflush (stdin);





    if(op==1){
    printf("\tSeja bem vindo ao menu do cliente\n\n");
    printf("\t(1) - Busca\n");
    printf("\t(2) - Carrinho de compras\n");
    scanf("%i", &opcao);

        if(opcao == 1){
            lista_produto();
            system("pause");
        }
        if(opcao == 2){
            realizar_venda();
        }

    }
    if(op==2){
        printf("\tSeja bem vindo ao menu do funcionario\n\n");


        for(i=0; i<n; i++){
        if(produto[i].estoque <=1){
        printf("\tO estoque do produto %s esta baixo\n", produto[i].nome);
        }
        if((produto[i].validade.d >3) && (produto[i].validade.m>12) && (produto[i].validade.a>2013)){
        printf("\tO produto %s esta vencido\n", produto[i].nome);
        }
        }
        printf("\t(1) - Cadastrar novos produtos\n");
        printf("\t(2) - Reposicao de estoque\n");
        printf("\t(3) - Listar produtos\n");
        printf("\t(4) - Cadastrar novos clientes\n");
        scanf("%i", &opcao);
        getchar();
        if(opcao == 1 ){
        cadastra_produto();
        }
        if(opcao == 2){
            estoque ();
        }
        if(opcao == 3){
            lista_produto();
        system("pause");
        }

        if(opcao==4){
            cadastra_cliente();
        }
    }

     /*if (op == 1)
        cadastra_cliente ();
     else if (op == 2)
        cadastra_produto();
     else if (op == 3)
        realizar_venda ();
     else if (op == 4)
        estoque ();
     else if (op == 5)
        pgtocta_cliente ();
     else if (op == 6)
        lista_clientes ();
     else if (op == 7)
        lista_produto ();
     else if (op == 8)
        det_venda ();
     */
     else if (op == 3)
        break;
     else {
        printf ("\n\t***  Opcao invalida  ***");
        getch();
     }


}   //gravar_arquivo();
return 0;
}
