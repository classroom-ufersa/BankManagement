#ifndef _DEFINED_BANKMANEGEMENTE_H
#define _DEFINED_BANKMANEGEMENTE_H


typedef struct data Data;
typedef struct agencia Agencia;
typedef struct conta Conta;
typedef struct lista Lista;
void inicializar(Lista *lista);
void ler(Conta *cliente);
void Menu();
void inserir_inicio(Lista * lista, Conta *dados);
void Listar_contas(Lista *lista);
void Buscar(Lista *lista);
void remover_conta(Lista *plista, int num_conta);
void alterar(Lista *plista, int num_conta);
void Ordenar(Lista *plista);
void Salvar(Lista *plista);
void Consultar(Lista *plista);
void agencias();
void arquivo();
#endif