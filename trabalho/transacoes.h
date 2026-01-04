#ifndef TRANSACOES_H
#define TRANSACOES_H

#define MAX_TRANSACOES 1000

typedef struct {
    int id;
    int nifCliente;
    int codigoProduto;
    int quantidade;
    float total;
    char data[20]; // YYYY-MM-DD
} Transacao;

#include "clientes.h"
#include "produtos.h"

void registarTransacao(Transacao *transacoes, int *totalTransacoes, Cliente *clientes, int totalClientes, Produto *produtos, int totalProdutos);
void listarTransacoes(Transacao *transacoes, int totalTransacoes);
int apresentarMenuTransacoes(void);
void gerirTransacoes(Transacao *transacoes, int *totalTransacoes, Cliente *clientes, int totalClientes, Produto *produtos, int totalProdutos);
void guardarTransacoes(Transacao *transacoes, int totalTransacoes);
void carregarTransacoes(Transacao *transacoes, int *totalTransacoes);

#endif
