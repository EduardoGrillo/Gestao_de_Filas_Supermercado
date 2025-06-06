#include "include/cliente.h"

Cliente* criar_cliente(const char* nome, const char* cpf, int prioridade, int num_itens){
    Cliente* novo = (Cliente*) malloc(sizeof(Cliente));
    if(novo == NULL){
        printf("Erro ao alocar memória para cliente.\n");
        exit(1);
    }
    
    strncpy(novo->nome, nome, sizeof(novo->nome));
    strncpy(novo->cpf, cpf, sizeof(novo->cpf)); 
    novo->prioridade = prioridade;
    novo->num_itens = num_itens;
    novo->prox = NULL;
    
    return novo;
}


void imprimir_cliente(Cliente* cliente){
    if(cliente != NULL){
        printf("Nome: %s | CPF: %s | Prioridade: %d | Itens: %d\n", cliente->nome, cliente->cpf, cliente->prioridade, cliente->num_itens);
    }
}