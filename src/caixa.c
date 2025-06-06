#include "include/caixa.h"

void inicializar_caixas(Caixa caixas[], int tamanho){
    for(int i = 0;i < tamanho;i++){
        caixas[i].id = i + 1;
        caixas[i].aberto = 1;
        caixas[i].fila = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));

        if(caixas[i].fila == NULL){
            printf("Erro ao alocar memória para fila do caixa %d.\n", i + 1);
            exit(1);
        }

        inicializar_fila(caixas[i].fila);
    }
}

void abrir_caixa(Caixa* caixa){
    caixa->aberto = 1;
}

void fechar_caixa(Caixa* caixa, Caixa caixas[], int num_caixas){
    if(caixa->aberto == 0){
        printf("Caixa %d já está fechado.\n", caixa->id);
        return;
    }

    caixa->aberto = 0;

    Cliente* cliente = NULL;
    while((cliente = atender_cliente(caixa->fila)) != NULL){
        for(int i = 0;i < num_caixas;i++){
            if(caixas[i].aberto && caixas[i].id != caixa->id){
                adicionar_cliente(caixas[i].fila, cliente);
                printf("Cliente realocado para o caixa %d.\n", caixas[i].id);
                break;
            }
        }
    }
}
