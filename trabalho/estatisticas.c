#include "estatisticas.h"
#include <stdio.h>
#include "uteis.h"

void mostrarEstatisticas(Cliente *clientes, int totalClientes, Funcionario *funcionarios, int totalFuncionarios, Produto *produtos, int totalProdutos, Transacao *transacoes, int totalTransacoes) {
    limparEcra();
    printf("\n--- RELATÓRIOS ESTATÍSTICOS ---\n\n");
    
    printf("Resumo Geral:\n");
    printf("Total de Clientes: %d\n", totalClientes);
    printf("Total de Funcionários: %d\n", totalFuncionarios);
    printf("Total de Produtos: %d\n", totalProdutos);
    printf("Total de Transações: %d\n", totalTransacoes);

    float totalVendas = 0;
    for(int i=0; i<totalTransacoes; i++) {
        totalVendas += transacoes[i].total;
    }
    printf("Volume Total de Vendas: %.2f€\n", totalVendas);

    float totalSalarios = 0;
    for(int i=0; i<totalFuncionarios; i++) {
        totalSalarios += funcionarios[i].salario;
    }
    printf("Total de Encargos com Salários: %.2f€\n", totalSalarios);

    printf("\n--- Top 3 Produtos em Stock ---\n");
    Produto tempProdutos[MAX_PRODUTOS];
    for(int i=0; i<totalProdutos; i++) tempProdutos[i] = produtos[i];
    
    for(int i=0; i<totalProdutos-1; i++) {
        for(int j=0; j<totalProdutos-i-1; j++) {
            if(tempProdutos[j].stock < tempProdutos[j+1].stock) {
                Produto temp = tempProdutos[j];
                tempProdutos[j] = tempProdutos[j+1];
                tempProdutos[j+1] = temp;
            }
        }
    }
    
    int limite = (totalProdutos < 3) ? totalProdutos : 3;
    for(int i=0; i<limite; i++) {
        printf("%d. %s - %d unidades\n", i+1, tempProdutos[i].nome, tempProdutos[i].stock);
    }

    printf("\nPressione ENTER para continuar...");
    getchar(); getchar();
}
