#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include "cliente.h"

typedef struct FilaPrioridade{
    Cliente* inicio;
} FilaPrioridade;

void inicializar_fila(FilaPrioridade* fila);
void adicionar_cliente(FilaPrioridade* fila, Cliente* cliente);
void imprimir_fila(FilaPrioridade* fila);

Cliente* atender_cliente(FilaPrioridade* fila);

#endif