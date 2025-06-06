#include "include/cliente.h"
#include "include/fila_prioridade.h"
#include "include/caixa.h"

#define NUM_CAIXAS 5

void cadastrar_cliente(Caixa caixas[], int num_caixas){
    char nome[100];
    char cpf[15];
    int prioridade, num_itens, id_caixa;

    printf("\n--- Cadastrar Cliente ---\n");

    printf(">> Nome: ");
    scanf(" %[^\n]", nome);

    printf(">> CPF: ");
    scanf(" %[^\n]", cpf);

    printf(">> Prioridade (1-Alta, 2-Média, 3-Baixa): ");
    scanf("%d", &prioridade);

    printf(">> Número de itens: ");
    scanf("%d", &num_itens);

    printf(">> ID do caixa (1-%d): ", num_caixas);
    scanf("%d", &id_caixa);

    if(id_caixa < 1 || id_caixa > num_caixas){
        printf("Caixa inválido.\n");
        return;
    }

    if(!caixas[id_caixa - 1].aberto){
        printf("Caixa está fechado.\n");
        return;
    }

    Cliente* cliente = criar_cliente(nome, cpf, prioridade, num_itens);
    adicionar_cliente(caixas[id_caixa - 1].fila, cliente);
    printf("Cliente adicionado à fila do caixa %d com sucesso!\n", id_caixa);
}

void atender_cliente_sistema(Caixa caixas[], int num_caixas){
    int id_caixa;
    printf("\n--- Atender Cliente ---\n");
    printf(">> ID do caixa (1-%d): ", num_caixas);
    scanf("%d", &id_caixa);

    if(id_caixa < 1 || id_caixa > num_caixas){
        printf("Caixa inválido.\n");
        return;
    }

    if(!caixas[id_caixa - 1].aberto){
        printf("Caixa está fechado.\n");
        return;
    }

    Cliente* cliente = atender_cliente(caixas[id_caixa - 1].fila);
    if(cliente){
        printf("Atendendo cliente:\n");
        imprimir_cliente(cliente);
        free(cliente);
    } else{
        printf("Fila vazia no caixa %d.\n", id_caixa);
    }
}

void abrir_ou_fechar_caixa(Caixa caixas[], int num_caixas){
    int id_caixa;
    printf("\n--- Abrir ou Fechar Caixa ---\n");
    printf(">> ID do caixa (1-%d): ", num_caixas);
    scanf("%d", &id_caixa);

    if(id_caixa < 1 || id_caixa > num_caixas){
        printf("Caixa inválido.\n");
        return;
    }

    Caixa* caixa = &caixas[id_caixa - 1];
    printf(">> 1 - Abrir\n>> 2 - Fechar\n>> Escolha: ");
    int opcao;
    scanf("%d", &opcao);

    if(opcao == 1){
        if(caixa->aberto){
            printf("Caixa %d já está aberto.\n", id_caixa);
        } else{
            abrir_caixa(caixa);
            printf("Caixa %d aberto.\n", id_caixa);
        }
    } else if(opcao == 2){
        if(!caixa->aberto){
            printf("Caixa %d já está fechado.\n", id_caixa);
        } else{
            fechar_caixa(caixa, caixas, num_caixas);
            printf("Caixa %d fechado.\n", id_caixa);
        }
    } else{
        printf("Opção inválida.\n");
    }
}

void imprimir_clientes_em_espera(Caixa caixas[], int num_caixas){
    printf("\n==== Clientes em Espera ====\n");

    for(int i = 0; i < num_caixas; i++){
        printf("\n+-----------------------------+\n");
        printf("| Caixa %d [%s]            |\n", caixas[i].id, caixas[i].aberto ? "Aberto" : "Fechado");
        printf("+-----------------------------+\n");

        Cliente* atual = caixas[i].fila->inicio;
        if(atual == NULL){
            printf("| Nenhum cliente.            \n");
        } else{
            while(atual != NULL){
                printf("| Nome: %s                  \n", atual->nome);
                printf("| CPF: %s                \n", atual->cpf);
                printf("| Prioridade: %d            \n", atual->prioridade);
                printf("| Itens: %d                 \n", atual->num_itens);
                printf("+-----------------------------+\n");
                atual = atual->prox;
            }
        }
    }
}

void imprimir_status_caixas(Caixa caixas[], int num_caixas){
    printf("\n+-----------------------------------------+\n");
    printf("|            STATUS DOS CAIXAS            |\n");
    printf("+--------+--------+-----------------------+\n");
    printf("| Caixa  | Estado | Clientes na fila      |\n");
    printf("+--------+--------+-----------------------+\n");

    for(int i = 0; i < num_caixas; i++){
        int qtd = 0;
        Cliente* atual = caixas[i].fila->inicio;

        while(atual != NULL){
            qtd++;
            atual = atual->prox;
        }

        printf("|   %d    | %s |           %d           |\n", caixas[i].id, caixas[i].aberto ? "Aberto" : "Fechado", qtd);
    }

    printf("+--------+--------+-----------------------+\n");
}

int main(){
    Caixa caixas[NUM_CAIXAS];
    inicializar_caixas(caixas, NUM_CAIXAS);

    int opcao;

    do{
        printf("\n+-------------------------------------+\n");
        printf("|       SISTEMA DE GESTÃO DE FILAS    |\n");
        printf("+-------------------------------------+\n");
        printf("| 1 | Cadastrar Cliente               |\n");
        printf("| 2 | Atender Cliente                 |\n");
        printf("| 3 | Abrir/Fechar Caixa              |\n");
        printf("| 4 | Imprimir Clientes               |\n");
        printf("| 5 | Imprimir Status dos Caixas      |\n");
        printf("| 0 | Sair                            |\n");
        printf("+-------------------------------------+\n");
        printf("| Escolha:\n> ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                cadastrar_cliente(caixas, NUM_CAIXAS);
                break;
            case 2:
                atender_cliente_sistema(caixas, NUM_CAIXAS);
                break;
            case 3:
                abrir_ou_fechar_caixa(caixas, NUM_CAIXAS);
                break;
            case 4:
                imprimir_clientes_em_espera(caixas, NUM_CAIXAS);
                break;
            case 5:
                imprimir_status_caixas(caixas, NUM_CAIXAS);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while(opcao != 0);

    return 0;
}