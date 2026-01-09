#include <locale.h>
#include <stdio.h>
#include <string.h>

#include "clientes.h"
#include "estatisticas.h"
#include "funcionarios.h"
#include "produtos.h"
#include "transacoes.h"
#include "uteis.h"

#define TIPO_GESTOR 1
#define TIPO_FUNCIONARIO 2

int apresentarMenu(int tipoUtilizador);
int fazerLogin();

int main() {
  int opcao;
  int tipoUtilizador;

  Cliente clientes[MAX_CLIENTES];
  int totalClientes = 0;

  Funcionario funcionarios[MAX_FUNCIONARIOS];
  int totalFuncionarios = 0;

  Produto produtos[MAX_PRODUTOS];
  int totalProdutos = 0;

  Transacao transacoes[MAX_TRANSACOES];
  int totalTransacoes = 0;

  setlocale(LC_CTYPE, "Portuguese");

  // Carregar dados
  carregarClientes(clientes, &totalClientes);
  carregarFuncionarios(funcionarios, &totalFuncionarios);
  carregarProdutos(produtos, &totalProdutos);
  carregarTransacoes(transacoes, &totalTransacoes);

  tipoUtilizador = fazerLogin();
  if (tipoUtilizador == 0) return 0;

  do {
    opcao = apresentarMenu(tipoUtilizador);

    switch (opcao) {
      case 1:
        gerirClientes(clientes, &totalClientes);
        break;
      case 2:
        if (tipoUtilizador == TIPO_GESTOR) {
          gerirFuncionarios(funcionarios, &totalFuncionarios);
        } else {
          printf(
              "\nErro: Apenas o gestor tem permissão para esta "
              "funcionalidade.\n");
          printf("Pressione ENTER para continuar...");
          getchar();
          getchar();
        }
        break;
      case 3:
        gerirProdutos(produtos, &totalProdutos, tipoUtilizador);
        break;
      case 4:
        gerirTransacoes(transacoes, &totalTransacoes, clientes, totalClientes,
                        produtos, totalProdutos);
        break;
      case 5:
        if (tipoUtilizador == TIPO_GESTOR) {
          mostrarEstatisticas(clientes, totalClientes, funcionarios,
                              totalFuncionarios, produtos, totalProdutos,
                              transacoes, totalTransacoes);
        } else {
          printf(
              "\nErro: Apenas o gestor tem permissão para esta "
              "funcionalidade.\n");
          printf("Pressione ENTER para continuar...");
          getchar();
          getchar();
        }
        break;
      case 0:
        break;
      default:
        printf("\nOpção inválida! Tente novamente.\n");
    }
  } while (opcao != 0);

  return 0;
}

int fazerLogin() {
  int opcao;
  char pass[20];

  limparEcra();
  printf("--- LOGIN ---\n");
  printf("1 - Gestor\n");
  printf("2 - Funcionário\n");
  printf("0 - Sair\n");
  printf("\nTipo de utilizador: ");
  scanf("%d", &opcao);

  if (opcao == 0) return 0;

  if (opcao == TIPO_GESTOR) {
    printf("Palavra-passe (admin): ");
    scanf("%s", pass);
    if (strcmp(pass, "admin") == 0) {
      return TIPO_GESTOR;
    } else {
      printf("Palavra-passe incorreta!\n");
      printf("Pressione ENTER para continuar...");
      getchar();
      getchar();
      return 0;
    }
  }

  return TIPO_FUNCIONARIO;
}

int apresentarMenu(int tipoUtilizador) {
  limparEcra();
  int opcao;

  printf("\n--- GESTÃO DO NEGÓCIO (%s) ---\n\n",
         (tipoUtilizador == TIPO_GESTOR ? "Gestor" : "Funcionário"));
  printf("1 - Gestão de Clientes\n");
  if (tipoUtilizador == TIPO_GESTOR) {
    printf("2 - Gestão de Funcionários\n");
  }
  printf("3 - Gestão de Produtos\n");
  printf("4 - Registo de Transações\n");
  if (tipoUtilizador == TIPO_GESTOR) {
    printf("5 - Relatórios estatísticos\n");
  }
  printf("0 - Sair\n");
  printf("\nQual a sua opção: ");
  scanf("%d", &opcao);

  return opcao;
}
