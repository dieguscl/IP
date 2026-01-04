/**
 * @file produtos.c
 * @brief Implementação das funções de gestão de produtos.
 */

#include "produtos.h"
#include <stdio.h>
#include <string.h>
#include "uteis.h"

/**
 * @brief Menu principal para gestão de produtos.
 */
void gerirProdutos(Produto *produtos, int *totalProdutos) {
    int opcao;

    do {
        opcao = apresentarMenuProdutos();

        switch (opcao) {
            case 1:
                inserirProduto(produtos, totalProdutos);
                break;
            case 2:
                alterarProduto(produtos, totalProdutos);
                break;
            case 3:
                removerProduto(produtos, totalProdutos);
                break;
            case 4:
                listarProdutos(produtos, totalProdutos);
                break;
            case 0:
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

int apresentarMenuProdutos(void) {
    limparEcra();
    int opcao;

    printf("\n--- GESTÃO DE PRODUTOS ---\n\n");
    printf("1 - Inserir produto\n");
    printf("2 - Alterar produto\n");
    printf("3 - Remover produto\n");
    printf("4 - Listar produtos\n");
    printf("0 - Sair\n");
    printf("\nQual a sua opção: ");
    scanf("%d", &opcao);

    return opcao;
}

void inserirProduto(Produto *produtos, int *totalProdutos) {
    limparEcra();
    if (*totalProdutos >= MAX_PRODUTOS) {
        printf("Erro: Número máximo de produtos atingido (%d).\n", MAX_PRODUTOS);
        printf("Pressione ENTER para continuar...");
        getchar(); getchar(); 
        return;
    }

    Produto p;
    printf("\nInserir produto:\n");
    printf("Código: ");
    scanf("%d", &p.codigo);

    // Verificar se o código já existe
    for(int i = 0; i < *totalProdutos; i++) {
        if(produtos[i].codigo == p.codigo) {
            printf("\nErro: Produto com código %d já existe!\n", p.codigo);
            printf("Pressione ENTER para continuar...");
            getchar(); getchar(); 
            return;
        }
    }

    printf("Nome: ");
    scanf(" %[^\n]", p.nome);

    printf("Preço: ");
    scanf("%f", &p.preco);

    printf("Stock: ");
    scanf("%d", &p.stock);

    produtos[*totalProdutos] = p;
    (*totalProdutos)++;

    guardarProdutos(produtos, *totalProdutos);

    printf("\nProduto inserido com sucesso!\n");
    printf("Pressione ENTER para continuar...");
    getchar(); getchar(); 
}

void listarProdutos(Produto *produtos, int *totalProdutos) {
    limparEcra();
    printf("\n--- LISTAGEM DE PRODUTOS ---\n");
    
    if (*totalProdutos == 0) {
        printf("\nNão existem produtos registados.\n");
    } else {
        printf("\n%-10s %-30s %-10s %-10s\n", "Código", "Nome", "Preço", "Stock");
        printf("------------------------------------------------------------\n");
        for (int i = 0; i < *totalProdutos; i++) {
            printf("%-10d %-30s %-10.2f %-10d\n", 
                   produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].stock);
        }
    }

    printf("\nPressione ENTER para continuar...");
    getchar(); getchar(); 
}

void alterarProduto(Produto *produtos, int *totalProdutos) {
    limparEcra();
    printf("\n--- ALTERAR PRODUTO ---\n");

    if (*totalProdutos == 0) {
        printf("\nNão existem produtos para alterar.\n");
        printf("Pressione ENTER para continuar...");
        getchar(); getchar();
        return;
    }

    int codigoPesquisa;
    printf("Introduza o código do produto a alterar: ");
    scanf("%d", &codigoPesquisa);

    int indice = -1;
    for (int i = 0; i < *totalProdutos; i++) {
        if (produtos[i].codigo == codigoPesquisa) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\nProduto com código %d não encontrado.\n", codigoPesquisa);
    } else {
        printf("\nDados atuais: %s, %.2f€, Stock: %d\n", produtos[indice].nome, produtos[indice].preco, produtos[indice].stock);
        printf("Novo Nome: ");
        scanf(" %[^\n]", produtos[indice].nome);
        printf("Novo Preço: ");
        scanf("%f", &produtos[indice].preco);
        printf("Novo Stock: ");
        scanf("%d", &produtos[indice].stock);

        guardarProdutos(produtos, *totalProdutos);
        printf("\nProduto alterado com sucesso!\n");
    }

    printf("Pressione ENTER para continuar...");
    getchar(); getchar();
}

void removerProduto(Produto *produtos, int *totalProdutos) {
    limparEcra();
    printf("\n--- REMOVER PRODUTO ---\n");

    if (*totalProdutos == 0) {
        printf("\nNão existem produtos para remover.\n");
        printf("Pressione ENTER para continuar...");
        getchar(); getchar();
        return;
    }

    int codigoPesquisa;
    printf("Introduza o código do produto a remover: ");
    scanf("%d", &codigoPesquisa);

    int indice = -1;
    for (int i = 0; i < *totalProdutos; i++) {
        if (produtos[i].codigo == codigoPesquisa) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\nProduto com código %d não encontrado.\n", codigoPesquisa);
    } else {
        char confirmacao;
        printf("Tem a certeza que deseja remover o produto %s? (s/n): ", produtos[indice].nome);
        scanf(" %c", &confirmacao);

        if (confirmacao == 's' || confirmacao == 'S') {
            for (int i = indice; i < *totalProdutos - 1; i++) {
                produtos[i] = produtos[i + 1];
            }
            (*totalProdutos)--;
            guardarProdutos(produtos, *totalProdutos);
            printf("\nProduto removido com sucesso!\n");
        } else {
            printf("\nOperação cancelada.\n");
        }
    }

    printf("Pressione ENTER para continuar...");
    getchar(); getchar();
}

void guardarProdutos(Produto *produtos, int totalProdutos) {
    FILE *f = fopen("produtos.dat", "wb");
    if (f == NULL) {
        printf("Erro ao abrir ficheiro para escrita!\n");
        return;
    }
    fwrite(&totalProdutos, sizeof(int), 1, f);
    fwrite(produtos, sizeof(Produto), totalProdutos, f);
    fclose(f);
}

void carregarProdutos(Produto *produtos, int *totalProdutos) {
    FILE *f = fopen("produtos.dat", "rb");
    if (f == NULL) {
        *totalProdutos = 0;
        return;
    }
    fread(totalProdutos, sizeof(int), 1, f);
    fread(produtos, sizeof(Produto), *totalProdutos, f);
    fclose(f);
}
