#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include "clientes.h"
#include "funcionarios.h"
#include "produtos.h"
#include "transacoes.h"

void mostrarEstatisticas(Cliente *clientes, int totalClientes, Funcionario *funcionarios, int totalFuncionarios, Produto *produtos, int totalProdutos, Transacao *transacoes, int totalTransacoes);
void relatorioVendas(Transacao *transacoes, int totalTransacoes);
void relatorioStock(Produto *produtos, int totalProdutos);

#endif
