// Estrutura para 'venda'
typedef struct{
int codigo, codvnd, codcli, codprod, qtdeprod;
}Venda;


Venda vnd[100];


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
   
   
   
  // 3 Realiza Venda, verificando se a conta eh paga ou nao;
// Se conta paga, armazena o seu valor devido, informando
// se o produto tem estoque suficiente

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
     // fflush(stdin);

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
