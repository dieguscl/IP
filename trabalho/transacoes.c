/**
 * @file transacoes.c
 * @brief Implementação das funções de registo de transações.
 */

#include "transacoes.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "uteis.h"

/**
 * @brief Menu principal para gestão de transações.
 */
void gerirTransacoes(Transacao *transacoes, int *totalTransacoes, Cliente *clientes, int totalClientes, Produto *produtos, int totalProdutos) {
    int opcao;

    do {
        opcao = apresentarMenuTransacoes();

        switch (opcao) {
            case 1:
                registarTransacao(transacoes, totalTransacoes, clientes, totalClientes, produtos, totalProdutos);
                break;
            case 2:
                listarTransacoes(transacoes, *totalTransacoes);
                break;
            case 0:
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

int apresentarMenuTransacoes(void) {
    limparEcra();
    int opcao;

    printf("\n--- REGISTO DE TRANSAÇÕES ---\n\n");
    printf("1 - Registar nova transação\n");
    printf("2 - Listar todas as transações\n");
    printf("0 - Sair\n");
    printf("\nQual a sua opção: ");
    scanf("%d", &opcao);

    return opcao;
}

void registarTransacao(Transacao *transacoes, int *totalTransacoes, Cliente *clientes, int totalClientes, Produto *produtos, int totalProdutos) {
    limparEcra();
    if (*totalTransacoes >= MAX_TRANSACOES) {
        printf("Erro: Limite de transações atingido.\n");
        printf("Pressione ENTER para continuar...");
        getchar(); getchar();
        return;
    }

    Transacao t;
    int nif, codigo, qtd;

    printf("\nNova Transação:\n");
    
    // Validar Cliente
    printf("NIF do Cliente: ");
    scanf("%d", &nif);
    int idxCliente = -1;
    for(int i=0; i<totalClientes; i++) {
        if(clientes[i].nif == nif) {
            idxCliente = i;
            break;
        }
    }
    if(idxCliente == -1) {
        printf("Erro: Cliente não encontrado!\n");
        printf("Pressione ENTER para continuar...");
        getchar(); getchar();
        return;
    }

    // Validar Produto
    printf("Código do Produto: ");
    scanf("%d", &codigo);
    int idxProduto = -1;
    for(int i=0; i<totalProdutos; i++) {
        if(produtos[i].codigo == codigo) {
            idxProduto = i;
            break;
        }
    }
    if(idxProduto == -1) {
        printf("Erro: Produto não encontrado!\n");
        printf("Pressione ENTER para continuar...");
        getchar(); getchar();
        return;
    }

    printf("Quantidade: ");
    scanf("%d", &qtd);
    if(qtd > produtos[idxProduto].stock) {
        printf("Erro: Stock insuficiente (Disponível: %d)!\n", produtos[idxProduto].stock);
        printf("Pressione ENTER para continuar...");
        getchar(); getchar();
        return;
    }

    // Preencher transação
    t.id = *totalTransacoes + 1;
    t.nifCliente = nif;
    t.codigoProduto = codigo;
    t.quantidade = qtd;
    t.total = qtd * produtos[idxProduto].preco;
    
    // Obter data atual
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(t.data, 20, "%Y-%m-%d %H:%M", info);

    // Atualizar stock
    produtos[idxProduto].stock -= qtd;
    guardarProdutos(produtos, totalProdutos);

    // Guardar transação
    transacoes[*totalTransacoes] = t;
    (*totalTransacoes)++;
    guardarTransacoes(transacoes, *totalTransacoes);

    printf("\nTransação registada com sucesso! Total: %.2f€\n", t.total);
    printf("Pressione ENTER para continuar...");
    getchar(); getchar();
}

void listarTransacoes(Transacao *transacoes, int totalTransacoes) {
    limparEcra();
    printf("\n--- LISTAGEM DE TRANSAÇÕES ---\n");
    
    if (totalTransacoes == 0) {
        printf("\nNão existem transações registadas.\n");
    } else {
        printf("\n%-5s %-15s %-10s %-10s %-10s %-20s\n", "ID", "Cliente (NIF)", "Prod", "Qtd", "Total", "Data");
        printf("----------------------------------------------------------------------------\n");
        for (int i = 0; i < totalTransacoes; i++) {
            printf("%-5d %-15d %-10d %-10d %-10.2f %-20s\n", 
                   transacoes[i].id, transacoes[i].nifCliente, transacoes[i].codigoProduto, 
                   transacoes[i].quantidade, transacoes[i].total, transacoes[i].data);
        }
    }

    printf("\nPressione ENTER para continuar...");
    getchar(); getchar(); 
}

void guardarTransacoes(Transacao *transacoes, int totalTransacoes) {
    FILE *f = fopen("transacoes.dat", "wb");
    if (f == NULL) {
        printf("Erro ao abrir ficheiro para escrita!\n");
        return;
    }
    fwrite(&totalTransacoes, sizeof(int), 1, f);
    fwrite(transacoes, sizeof(Transacao), totalTransacoes, f);
    fclose(f);
}

void carregarTransacoes(Transacao *transacoes, int *totalTransacoes) {
    FILE *f = fopen("transacoes.dat", "rb");
    if (f == NULL) {
        *totalTransacoes = 0;
        return;
    }
    fread(totalTransacoes, sizeof(int), 1, f);
    fread(transacoes, sizeof(Transacao), *totalTransacoes, f);
    fclose(f);
}
