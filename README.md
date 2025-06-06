# Sistema de Gerenciamento de Filas de Supermercado

Este projeto simula o funcionamento de caixas de supermercado utilizando filas com prioridade para atendimento de clientes. Foi desenvolvido em linguagem C com foco em práticas de programação estruturada, manipulação dinâmica de memória, modularização e uso de listas encadeadas.

## Funcionalidades

- Cadastro de clientes com nome, CPF, prioridade e número de itens
- Atendimento de clientes com base em prioridade (1 = alta, 2 = média, 3 = baixa)
- Abertura e fechamento de caixas
- Realocação automática de clientes ao fechar um caixa
- Impressão do status dos caixas e das filas de espera
- Interface de menu no terminal organizada com validações de entrada

## Estrutura de Dados Utilizadas

- **Lista encadeada**: utilizada para implementar as filas de clientes.
- **Inserção ordenada**: garante que os clientes sejam sempre adicionados na fila de acordo com a prioridade.

# Compilação e Execução

O algoritmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

<div>

| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

</div>


