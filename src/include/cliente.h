#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente{
    char nome[100];
    char cpf[15];
    int prioridade;
    int num_itens;
    struct Cliente* prox;
} Cliente;

Cliente* criar_cliente(const char* nome, const char* cpf, int prioridade, int num_itens);
void imprimir_cliente(Cliente* cliente);

#endif