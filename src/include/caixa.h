#ifndef CAIXA_H
#define CAIXA_H

#include "fila_prioridade.h"

typedef struct Caixa{
    int id;
    int aberto;
    FilaPrioridade* fila;
} Caixa;

void inicializar_caixas(Caixa caixas[], int tamanho);
void abrir_caixa(Caixa* caixa);
void fechar_caixa(Caixa* caixa, Caixa caixas[], int num_caixas);

#endif