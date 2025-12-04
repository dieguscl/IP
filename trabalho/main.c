#include <stdio.h>
// #include <stdlib.h>
#include <locale.h>
#include "clientes.h"
#include "uteis.h"
// #include "funcionarios.h"
// #include "produtos.h"
// #include "transacoes.h"
// #include "estatisticas.h"

// Desenvolver uma aplicação de consola em C para a gestão de um pequeno negócio.
// Módulos obrigatórios:
// • Gestão de Clientes
// • Gestão de Funcionários
// • Gestão de Produtos ou Serviços
// • Registo de Transações
// • Relatórios estatísticos simples integrados nos módulos existentes
// O programa deve incluir:
// • pelo menos uma procura
// • pelo menos uma ordenação
// • utilização de ficheiros para persistência
// • interface totalmente textual
// Funcionalidade opcional (valorizada):
// ➢ dois tipos de utilizador (gestor e funcionário), com permissões distintas
//

int apresentarMenu(void);
void gerirFuncionarios();
void gerirProdutos();
void registarTransacoes();
void gerirEstatisticas();

int main()
{
    int opcao;
    Cliente clientes[MAX_CLIENTES];
    int totalClientes = 0;

    // Funcionario funcionarios[MAX_FUNCIONARIOS];
    // int totalFuncionarios = 0;
    // Produto produtos[MAX_PRODUTOS];
    // int totalProdutos = 0;
    // Transacao transacoes[MAX_TRANSACOES];
    // int totalTransacoes = 0;

    setlocale(LC_CTYPE, "Portuguese");
    do {
        opcao = apresentarMenu();

        switch (opcao) {
            case 1:
                gerirClientes(clientes, &totalClientes);
                break;
            case 2:
                // gerirFuncionarios();
                break;
            case 3:
                // gerirProdutos();
                break;
            case 4:
                // registarTransacoes();
                break;
            case 5:
                // gerirEstatisticas();
                break;
            case 0:
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

int apresentarMenu(void) {
    limparEcra();
    int opcao;

    printf("\n--- GESTÃO DO NEGÓCIO ---\n\n");
    printf("1 - Gestão de Clientes\n");
    printf("2 - Gestão de Funcionários\n");
    printf("3 - Gestão de Produtos\n");
    printf("4 - Registo de Transações\n");
    printf("5 - Relatórios estatísticos\n");
    printf("0 - Sair\n");
    printf("\nQual a sua opção: ");
    scanf("%d", &opcao);

    return opcao;
}

