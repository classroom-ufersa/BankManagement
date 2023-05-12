#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "BankManegement.h"

typedef struct data
{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct agencia
{
    char nome[100];
    int codigo;
    char localizacao[100];
    int num_clientes;
    int contas;
    int horario_funcionamento;
}Agencia;


typedef struct conta
{
    char cliente[100];
    int agencia;
    Data data_abertura;
    float saldo;
    int status;
    int numero;
}Conta;

struct No{
    Conta *dado;
    struct No *prox;
};

typedef struct lista
{
    struct No * inicio;
}Lista;

void inicializar(Lista *lista){
    lista->inicio = NULL;
}

void ler(Conta *cliente){
    int bb=0;
    printf("Digite seu nome: ");
    scanf(" %[^\n]s", cliente->cliente);
    while (bb!=1)
    {
    printf("Qual agencia\nBanco do Brasil - 1010\nBradesco - 2020\nSantAnder - 3030\n");
    scanf(" %d", &cliente->agencia);
    if (cliente->agencia == 1010 || cliente->agencia == 2020 || cliente->agencia == 3030)
    {
        bb = 1;
    }
    }
    printf("Digite o saldo: ");
    scanf("%f", &cliente->saldo);
    printf("Digite o numero da conta: ");
    scanf("%d", &cliente->numero);
    printf("digite o data da abertura: ");
    scanf("%d%d%d", &cliente->data_abertura.dia, &cliente->data_abertura.mes, &cliente->data_abertura.ano);    
    cliente->status=1;
}

void Menu(){
    printf("1 - adicionar conta\n2 - Remover conta\n3 - Listar contas cadastradas\n4 - Buscar conta\n5 - Editar conta\n6 - Consultar contas ativas em uma dada agencia\n7 - Consultar quantitativo de agencias\n8 - sair\n");
    printf("Digite uma opcao\n");
}

void inserir_inicio(Lista * lista, Conta *dados){
    struct No *novo = (struct No*) malloc(sizeof(struct No));
    if (novo==NULL)
    {
        printf("Erro de alocacao!\n");
        exit(1);
    }
    novo->dado = dados;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

void Listar_contas(Lista *lista){
    struct No *pi = lista->inicio;
    while (pi!=NULL)
    {
        printf("Nome: %s\nAgencia: %d\nData de abertura: %d/%d/%d\n", pi->dado->cliente, pi->dado->agencia, pi->dado->data_abertura.dia, pi->dado->data_abertura.mes, pi->dado->data_abertura.ano);
        if (pi->dado->status == 1)
        {
            printf("Conta Ativa\n");
        }else if(pi->dado->status == 2){
            printf("Conta Desativada\n");
        }
        else{
            printf("Conta bloqueada\n");
        }
        pi = pi->prox;
    }
}

void Buscar(Lista *lista){
    struct No *pi = (struct No*) malloc(sizeof(struct No));
    if (pi==NULL)
    {
        printf("Erro de alocacao!\n");
        exit(1);
    }
    int num;
    printf("Digite o numero da conta: ");
    scanf("%d", &num);
    for (pi = lista->inicio; pi != NULL; pi = pi->prox)
    {
        if (pi->dado->numero == num)
        {
        printf("Nome: %s\nAgencia: %d\nSaldo: %.2f\nData de abertura: %d/%d/%d\n", pi->dado->cliente, pi->dado->agencia ,pi->dado->saldo, pi->dado->data_abertura.dia, pi->dado->data_abertura.mes, pi->dado->data_abertura.ano);
        if (pi->dado->status == 1){
            printf("Conta Ativa\n");
        }else if(pi->dado->status == 2){
            printf("Conta Desativada\n");
        }
        else{
            printf("Conta bloqueada\n");
        }
        }
    }  
}

void remover_conta(Lista *plista, int num_conta){
    if (plista==NULL)
    {
        printf("Alista esta vazia!\n");
    }else{
        struct No *pa = (struct No*) malloc(sizeof(struct No));
        if (pa==NULL){
            printf("Erro de alocacao!\n");
            exit(1);
        }
        struct No *pi = (struct No*) malloc(sizeof(struct No));
        if (pi==NULL){
            printf("Erro de alocacao!\n");
            exit(1);
            }
            for (pi = plista->inicio; pi != NULL && pi->dado->numero != num_conta; pi = pi->prox)
            {
                pa = pi;
            }
            if (pi==NULL)
            {
                printf("Nao existe alguem com esta conta para ser removido\n");
            }else{
                pa->prox = pi->prox;
                free(pi);
            }
        }
}

void alterar(Lista *plista, int num_conta){
    struct No *pi = (struct No*) malloc(sizeof(struct No));
    if (pi==NULL){
        printf("Erro de alocacao!\n");
        exit(1);
    }
    for(pi = plista->inicio; pi != NULL; pi = pi->prox){
        if(pi->dado->numero == num_conta){
            printf("Digite o novo nome: ");
            scanf(" %[^\n]s", pi->dado->cliente);
            printf("Digite o novo numero da agencia\nBanco do Brasil - 1010\nBradesco - 2020\nSantAnder - 3030");
            scanf("%d", &pi->dado->agencia);
            printf("Digite o novo status da conta\n1 - Ativa\n2 - Desativar\n3 - Bloquear");
            scanf(" %d", &pi->dado->status);
            printf("Digite o novo saldo: ");
            scanf("%f", &pi->dado->saldo);
        }
    }
}



void Ordenar(Lista *plista){
    struct No *pi = (struct No*) malloc(sizeof(struct No));
    if (pi==NULL){
        printf("Erro de alocacao!\n");
        exit(1);
    }
    struct No *pj = (struct No*) malloc(sizeof(struct No));
    if (pj==NULL){
        printf("Erro de alocacao!\n");
        exit(1);
    }
    struct No *pfim = (struct No*) malloc(sizeof(struct No));
    if (pfim==NULL){
        printf("Erro de alocacao!\n");
        exit(1);
    }
    if (plista->inicio == NULL)
    {
        printf("Lista vazia\n");
    }
    
    pfim = NULL;
    for(pi = plista->inicio; pi->prox != NULL; pi = pi->prox){
        for (pj = plista->inicio; pj->prox != pfim; pj = pj->prox)
        {
        if (strcmp(pj->dado->cliente, pj->prox->dado->cliente)>0)
        {
            Conta *temp = pj->dado;
            pj->dado = pj->prox->dado;
            pj->prox->dado = temp;
        }
        }
        pfim = pj;
    }

}

void Salvar(Lista *plista){
    FILE *file = fopen("BankManegement.txt", "wb");
    if (file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    struct No * pi = (struct No*) malloc(sizeof(struct No));
    if(pi==NULL){
        printf("Erro de alocacao!\n");
        exit(1);
    }
    for(pi = plista->inicio; pi!=NULL; pi = pi->prox){
        fprintf(file, "Nome: %s\n", pi->dado->cliente);
        fprintf(file, "Saldo: %.2f\n", pi->dado->saldo);
        fprintf(file, "Agencia: %d\n", pi->dado->agencia);
        fprintf(file, "Conta criada em: %d/%d/%d \n", pi->dado->data_abertura.dia, pi->dado->data_abertura.mes, pi->dado->data_abertura.ano);
        fprintf(file, "Status da conta: %d\n", pi->dado->status);
        fprintf(file, "Numero da conta: %d\n", pi->dado->numero);

    }
    fclose(file);
}

void Consultar(Lista *plista){
    struct No *pi = (struct No*) malloc(sizeof(struct No));
    if (pi==NULL)
    {
        printf("erro!\n");
        exit(1);
    }

    int BB=0, Bra=0, Sant=0;
    for (pi = plista->inicio; pi !=NULL; pi = pi->prox)
    {
        if (pi->dado->agencia == 1010 && pi->dado->status == 1)
        {
            BB = BB + 1;
            printf("Banco do Brasil - %d\n", BB);

        }else if (pi->dado->agencia == 2020 && pi->dado->status == 1)
        {
            Bra = Bra + 1;
            printf("Bradesco - %d\n",Bra);
        }else if (pi->dado->agencia == 3030 && pi->dado->status == 1)
        {
            Sant = Sant + 1;
            printf("Santander - %d\n", Sant);
        }
    }
}

void agencias(){
    int op;
    char loc[]="R. independencia, Pau dos Ferros - RN\n";
    char cidade[]="Av. Getulio Vargas - Centro Pau dos Ferros - RN\n";
    printf("Banco do Brasil \nBradesco \nSantander\n");
    printf("Deseja saber a localizacao de uma delas\n1 - Banco do Brasil\n2 - Banco Bradesco\n3 - Santander\n");
    scanf("%d", &op);

    if (op == 1)
    {
        printf("%s 1109\n", loc);

    }else if (op==2)
    {
        printf("%s 1950\n ", loc);

    }else if (op==3)
    {
        printf("%s 1369\n", cidade);
    }
}

void arquivo(Lista *plista){

    Conta * dados = (Conta*)malloc(sizeof(Conta));
    struct No * pi = (struct No*) malloc(sizeof(struct No));
 if(pi==NULL){
    printf("Erro de alocacao!\n");
    exit(1);
    }
    FILE *file = fopen("BankManegement.txt", "r");
    if (file==NULL)
    {
        printf("Arquivo nao aberto\n");
        exit(1);
    }
        while (fscanf(file, "Nome: %[^\n]s\nSaldo: %f\nAgencia: %d\nConta criada em: %d/%d/%d\nStatus da conta: %d\nNumero da conta: %d\n,", dados->cliente, &dados->saldo, &dados->agencia, &dados->data_abertura.dia, &dados->data_abertura.mes, &dados->data_abertura.ano, &dados->status, &dados->numero)==7)
        {

        }

    fclose(file);
        inserir_inicio(plista, dados);
} 

