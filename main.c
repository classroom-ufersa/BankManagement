#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "BankManegement.c"



int main(void) 
{ 

     
    Agencia *num = (Agencia*) malloc(3*sizeof(Agencia)); 
    if (num==NULL) 
    { 
        printf("Erro de alocacao!\n"); 
        exit(1); 
    } 
     
    Lista * lista = (Lista*) malloc(sizeof(Lista)); 
    if(lista==NULL){ 
        printf("erro de alocacao!\n"); 
        exit(1); 
        } 
        
    inicializar(lista); 
    arquivo(lista); 
    int op = 0; 
    while (op!=8) 
    {    
         
        Menu(); 
        scanf("%d",&op); 
        if (op==1) 
        { 
            Conta *client = (Conta*) malloc(sizeof(Conta));  
             
            ler(client); 
            inserir_inicio(lista, client); 
             
            Ordenar(lista); 
            Salvar(lista); 
        } 
        else if (op == 2) 
        { 
         int num_cont; 
         printf("Digite o numero da conta: \n"); 
         scanf("%d", &num_cont); 
         remover_conta(lista, num_cont); 
        } 
         
        else if (op==3) 
        { 
            Listar_contas(lista); 
        } 
        else if(op == 4){ 
            Buscar(lista); 
        } 
        else if(op == 5){ 
            
            int n_c; 
            printf("Digite seu numero da conta: "); 
            scanf("%d", &n_c); 
            alterar(lista, n_c); 
        }else if (op == 6) 
        { 
            Consultar(lista); 
        }else if(op == 7){ 
            agencias(lista); 
 
        } 
 
    } 
    
    free(lista); 
    free(num); 
    return 0; 
}
