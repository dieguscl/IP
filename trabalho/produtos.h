#ifndef PRODUTOS_H
#define PRODUTOS_H

#define MAX_NOME_PRODUTO 100
#define MAX_PRODUTOS 100

typedef struct {
    int codigo;
    char nome[MAX_NOME_PRODUTO];
    float preco;
    int stock;
} Produto;

void inserirProduto(Produto *produtos, int *totalProdutos);
void alterarProduto(Produto *produtos, int *totalProdutos);
void removerProduto(Produto *produtos, int *totalProdutos);
void listarProdutos(Produto *produtos, int *totalProdutos);
int apresentarMenuProdutos(int tipoUtilizador);
void gerirProdutos(Produto *produtos, int *totalProdutos, int tipoUtilizador);
void guardarProdutos(Produto *produtos, int totalProdutos);
void carregarProdutos(Produto *produtos, int *totalProdutos);

#endif
