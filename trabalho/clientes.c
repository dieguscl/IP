/**
 * @file clientes.c
 * @brief Implementação das funções de gestão de clientes.
 */

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
            case 5:
                procurarCliente(clientes, *totalClientes);
                break;
            case 6:
                ordenarClientes(clientes, *totalClientes);
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
    printf("5 - Procurar cliente (por NIF)\n");
    printf("6 - Ordenar clientes (por Nome)\n");
    printf("0 - Sair\n");
    printf("\nQual a sua opção: ");
    scanf("%d", &opcao);

    return opcao;
}

void inserirCliente(Cliente *clientes, int *totalClientes) {
    limparEcra();
    if (*totalClientes >= MAX_CLIENTES) {
        printf("Erro: Número máximo de clientes atingido (%d).\n", MAX_CLIENTES);
        printf("Pressione ENTER para continuar...");
        getchar(); getchar(); 
        return;
    }

    Cliente cliente;
    printf("\nInserir cliente:\n");
    printf("Nome: ");
    scanf(" %[^\n]", cliente.nome);

    printf("NIF: ");
    scanf("%d", &cliente.nif);

    // Verificar se o NIF já existe
    for(int i = 0; i < *totalClientes; i++) {
        if(clientes[i].nif == cliente.nif) {
            printf("\nErro: Cliente com NIF %d já existe!\n", cliente.nif);
            printf("Pressione ENTER para continuar...");
            getchar(); getchar(); 
            return;
        }
    }

    printf("Telefone: ");
    scanf("%s", cliente.telemovel);

    clientes[*totalClientes] = cliente;
    (*totalClientes)++;

    guardarClientes(clientes, *totalClientes);

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
        printf("\n%-30s %-15s %-15s\n", "Nome", "NIF", "Telemóvel");
        printf("------------------------------------------------------------\n");
        for (int i = 0; i < *totalClientes; i++) {
            printf("%-30s %-15d %-15s\n", clientes[i].nome, clientes[i].nif, clientes[i].telemovel);
        }
    }

    printf("\nPressione ENTER para continuar...");
    getchar(); getchar(); 
}

void procurarCliente(Cliente *clientes, int totalClientes) {
    limparEcra();
    printf("\n--- PROCURAR CLIENTE ---\n");
    
    if (totalClientes == 0) {
        printf("\nNão existem clientes registados.\n");
        printf("Pressione ENTER para continuar...");
        getchar(); getchar();
        return;
    }

    int nifPesquisa;
    printf("Introduza o NIF do cliente: ");
    scanf("%d", &nifPesquisa);

    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].nif == nifPesquisa) {
            printf("\nCliente encontrado:\n");
            printf("  Nome: %s\n", clientes[i].nome);
            printf("  NIF: %d\n", clientes[i].nif);
            printf("  Telemóvel: %s\n", clientes[i].telemovel);
            printf("\nPressione ENTER para continuar...");
            getchar(); getchar();
            return;
        }
    }

    printf("\nCliente com NIF %d não encontrado.\n", nifPesquisa);
    printf("Pressione ENTER para continuar...");
    getchar(); getchar();
}

void ordenarClientes(Cliente *clientes, int totalClientes) {
    limparEcra();
    printf("\n--- ORDENAR CLIENTES ---\n");

    if (totalClientes < 2) {
        printf("\nNúmero insuficiente de clientes para ordenar.\n");
    } else {
        // Bubble sort por nome
        for (int i = 0; i < totalClientes - 1; i++) {
            for (int j = 0; j < totalClientes - i - 1; j++) {
                if (strcmp(clientes[j].nome, clientes[j + 1].nome) > 0) {
                    Cliente temp = clientes[j];
                    clientes[j] = clientes[j + 1];
                    clientes[j + 1] = temp;
                }
            }
        }
        guardarClientes(clientes, totalClientes);
        printf("\nClientes ordenados por nome com sucesso!\n");
    }

    printf("Pressione ENTER para continuar...");
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

    int nifPesquisa;
    printf("Introduza o NIF do cliente a alterar: ");
    scanf("%d", &nifPesquisa);

    int indice = -1;
    for (int i = 0; i < *totalClientes; i++) {
        if (clientes[i].nif == nifPesquisa) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\nCliente com NIF %d não encontrado.\n", nifPesquisa);
    } else {
        printf("\nDados atuais: %s, %d, %s\n", clientes[indice].nome, clientes[indice].nif, clientes[indice].telemovel);
        printf("Novo Nome: ");
        scanf(" %[^\n]", clientes[indice].nome);
        printf("Novo Telemóvel: ");
        scanf("%s", clientes[indice].telemovel);

        guardarClientes(clientes, *totalClientes);
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

    int nifPesquisa;
    printf("Introduza o NIF do cliente a remover: ");
    scanf("%d", &nifPesquisa);

    int indice = -1;
    for (int i = 0; i < *totalClientes; i++) {
        if (clientes[i].nif == nifPesquisa) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\nCliente com NIF %d não encontrado.\n", nifPesquisa);
    } else {
        char confirmacao;
        printf("Tem a certeza que deseja remover o cliente %s? (s/n): ", clientes[indice].nome);
        scanf(" %c", &confirmacao);

        if (confirmacao == 's' || confirmacao == 'S') {
            for (int i = indice; i < *totalClientes - 1; i++) {
                clientes[i] = clientes[i + 1];
            }
            (*totalClientes)--;
            guardarClientes(clientes, *totalClientes);
            printf("\nCliente removido com sucesso!\n");
        } else {
            printf("\nOperação cancelada.\n");
        }
    }

    printf("Pressione ENTER para continuar...");
    getchar(); getchar();
}

void guardarClientes(Cliente *clientes, int totalClientes) {
    FILE *f = fopen("clientes.dat", "wb");
    if (f == NULL) {
        printf("Erro ao abrir ficheiro para escrita!\n");
        return;
    }
    fwrite(&totalClientes, sizeof(int), 1, f);
    fwrite(clientes, sizeof(Cliente), totalClientes, f);
    fclose(f);
}

void carregarClientes(Cliente *clientes, int *totalClientes) {
    FILE *f = fopen("clientes.dat", "rb");
    if (f == NULL) {
        *totalClientes = 0;
        return;
    }
    fread(totalClientes, sizeof(int), 1, f);
    fread(clientes, sizeof(Cliente), *totalClientes, f);
    fclose(f);
}
