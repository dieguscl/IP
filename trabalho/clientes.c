#include "clientes.h"

#include <stdio.h>
#include <string.h>
#include "uteis.h"

void gerirClientes(Cliente *clientes, int *totalClientes) {
  int opcao;

  do {
    opcao = apresentarMenuClientes();

    switch (opcao) {
      case 1:
        inserirCliente(clientes, totalClientes);
        break;
      case 2:
        alterarCliente(clientes, totalClientes);
        break;
      case 3:
        removerCliente(clientes, totalClientes);
        break;
      case 4:
        listarClientes(clientes, totalClientes);
        break;
      case 0:
        break;
      default:
        printf("\nOpção inválida! Tente novamente.\n");
    }
  } while (opcao != 0);
}

int apresentarMenuClientes(void) {
  limparEcra();
  int opcao;

  printf("\n--- GESTÃO DE CLIENTES ---\n\n");
  printf("1 - Inserir cliente\n");
  printf("2 - Alterar cliente\n");
  printf("3 - Remover cliente\n");
  printf("4 - Listar clientes\n");
  printf("0 - Sair\n");
  printf("\nQual a sua opção: ");
  scanf("%d", &opcao);

  return opcao;
}

void inserirCliente(Cliente *clientes, int *totalClientes) {
    limparEcra();
    if (*totalClientes >= MAX_CLIENTES) {
        printf("Erro: Número máximo de clientes atingido (%d).\n", MAX_CLIENTES);
        // Pequena pausa para o utilizador ler
        printf("Pressione ENTER para continuar...");
        getchar(); getchar(); 
        return;
    }

    int i;
    Cliente cliente;
    printf("\nInserir cliente:\n");
    printf("Nome: ");
    scanf("%s", cliente.nome);

    for(i = 0; i < *totalClientes; i++) {
        if(strcmp(clientes[i].nome, cliente.nome) == 0) {
            printf("\nErro: Cliente '%s' já existe!\n", cliente.nome);
            printf("Pressione ENTER para continuar...");
            getchar(); getchar(); 
            return;
        }
    }

    printf("NIF: ");
    scanf("%d", &cliente.nif);
    printf("Telefone: ");
    scanf("%s", cliente.telemovel);

    // Guardar no array
    clientes[*totalClientes] = cliente;
    (*totalClientes)++;

    printf("\nCliente inserido com sucesso!\n");
    printf("Pressione ENTER para continuar...");
    getchar(); getchar(); 
}

void listarClientes(Cliente *clientes, int *totalClientes) {
    limparEcra();
    printf("\n--- LISTAGEM DE CLIENTES ---\n");
    
    if (*totalClientes == 0) {
        printf("\nNão existem clientes registados.\n");
    } else {
        for (int i = 0; i < *totalClientes; i++) {
            printf("\nCliente %d:\n", i + 1);
            printf("  Nome: %s\n", clientes[i].nome);
            printf("  NIF: %d\n", clientes[i].nif);
            printf("  Telemóvel: %s\n", clientes[i].telemovel);
        }
    }

    printf("\nPressione ENTER para continuar...");
    getchar(); getchar(); 
}

void alterarCliente(Cliente *clientes, int *totalClientes) {
    limparEcra();
    printf("\n--- ALTERAR CLIENTE ---\n");

    if (*totalClientes == 0) {
        printf("\nNão existem clientes para alterar.\n");
        printf("Pressione ENTER para continuar...");
        getchar(); getchar();
        return;
    }

    char nomePesquisa[MAX_NOME];
    printf("Introduza o nome do cliente a alterar: ");
    scanf("%s", nomePesquisa);

    int indice = -1;
    for (int i = 0; i < *totalClientes; i++) {
        if (strcmp(clientes[i].nome, nomePesquisa) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\nCliente '%s' não encontrado.\n", nomePesquisa);
    } else {
        printf("\nNovos dados para o cliente (deixe o NIF como 0 para manter o mesmo):\n");
        
        // Alterar Nome
        printf("Novo Nome (Atual: %s): ", clientes[indice].nome);
        scanf("%s", clientes[indice].nome);

        // Alterar NIF
        int novoNif;
        printf("Novo NIF (Atual: %d): ", clientes[indice].nif);
        scanf("%d", &novoNif);
        if (novoNif != 0) {
            clientes[indice].nif = novoNif;
        }

        // Alterar Telemóvel
        printf("Novo Telemóvel (Atual: %s): ", clientes[indice].telemovel);
        scanf("%s", clientes[indice].telemovel);

        printf("\nCliente alterado com sucesso!\n");
    }

    printf("Pressione ENTER para continuar...");
    getchar(); getchar();
}

void removerCliente(Cliente *clientes, int *totalClientes) {
    limparEcra();
    printf("\n--- REMOVER CLIENTE ---\n");

    if (*totalClientes == 0) {
        printf("\nNão existem clientes para remover.\n");
        printf("Pressione ENTER para continuar...");
        getchar(); getchar();
        return;
    }

    char nomePesquisa[MAX_NOME];
    printf("Introduza o nome do cliente a remover: ");
    scanf("%s", nomePesquisa);

    int indice = -1;
    for (int i = 0; i < *totalClientes; i++) {
        if (strcmp(clientes[i].nome, nomePesquisa) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\nCliente '%s' não encontrado.\n", nomePesquisa);
    } else {
        // Confirmar remoção
        char confirmacao;
        printf("Tem a certeza que deseja remover o cliente %s? (s/n): ", clientes[indice].nome);
        // Limpar buffer antes de ler char
        getchar(); 
        scanf("%c", &confirmacao);

        if (confirmacao == 's' || confirmacao == 'S') {
            // Remover movendo todos os elementos seguintes uma posição para trás
            for (int i = indice; i < *totalClientes - 1; i++) {
                clientes[i] = clientes[i + 1];
            }
            (*totalClientes)--;
            printf("\nCliente removido com sucesso!\n");
        } else {
            printf("\nOperação cancelada.\n");
        }
    }

    printf("Pressione ENTER para continuar...");
    getchar(); getchar();
}

