#include "include/fila_prioridade.h"

void inicializar_fila(FilaPrioridade* fila){
    fila->inicio = NULL;
}

void adicionar_cliente(FilaPrioridade* fila, Cliente* cliente){
    if(fila->inicio == NULL || cliente->prioridade < fila->inicio->prioridade){
        cliente->prox = fila->inicio;
        fila->inicio = cliente;
    } else{
        Cliente* atual = fila->inicio;

        while (atual->prox != NULL && atual->prox->prioridade <= cliente->prioridade){
            atual = atual->prox;
        }

        cliente->prox = atual->prox;
        atual->prox = cliente;
    }
}

Cliente* atender_cliente(FilaPrioridade* fila){
    if(fila->inicio == NULL){
        return NULL;
    }
    
    Cliente* atendido = fila->inicio;
    fila->inicio = fila->inicio->prox;
    atendido->prox = NULL;

    return atendido;
}

void imprimir_fila(FilaPrioridade* fila){
    Cliente* atual = fila->inicio;

    while(atual != NULL){
        imprimir_cliente(atual);
        atual = atual->prox;
    }
}