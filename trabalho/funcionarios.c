/**
 * @file funcionarios.c
 * @brief Implementação das funções de gestão de funcionários.
 */

#include "funcionarios.h"
#include <stdio.h>
#include <string.h>
#include "uteis.h"

/**
 * @brief Menu principal para gestão de funcionários.
 */
void gerirFuncionarios(Funcionario *funcionarios, int *totalFuncionarios) {
    int opcao;

    do {
        opcao = apresentarMenuFuncionarios();

        switch (opcao) {
            case 1:
                inserirFuncionario(funcionarios, totalFuncionarios);
                break;
            case 2:
                alterarFuncionario(funcionarios, totalFuncionarios);
                break;
            case 3:
                removerFuncionario(funcionarios, totalFuncionarios);
                break;
            case 4:
                listarFuncionarios(funcionarios, totalFuncionarios);
                break;
            case 0:
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

int apresentarMenuFuncionarios(void) {
    limparEcra();
    int opcao;

    printf("\n--- GESTÃO DE FUNCIONÁRIOS ---\n\n");
    printf("1 - Inserir funcionário\n");
    printf("2 - Alterar funcionário\n");
    printf("3 - Remover funcionário\n");
    printf("4 - Listar funcionários\n");
    printf("0 - Sair\n");
    printf("\nQual a sua opção: ");
    scanf("%d", &opcao);

    return opcao;
}

void inserirFuncionario(Funcionario *funcionarios, int *totalFuncionarios) {
    limparEcra();
    if (*totalFuncionarios >= MAX_FUNCIONARIOS) {
        printf("Erro: Número máximo de funcionários atingido (%d).\n", MAX_FUNCIONARIOS);
        printf("Pressione ENTER para continuar...");
        getchar(); getchar(); 
        return;
    }

    Funcionario f;
    printf("\nInserir funcionário:\n");
    printf("Nome: ");
    scanf(" %[^\n]", f.nome); // Read string with spaces

    printf("NIF: ");
    scanf("%d", &f.nif);
    
    printf("Cargo: ");
    scanf(" %[^\n]", f.cargo);

    printf("Salário: ");
    scanf("%f", &f.salario);

    funcionarios[*totalFuncionarios] = f;
    (*totalFuncionarios)++;

    guardarFuncionarios(funcionarios, *totalFuncionarios);

    printf("\nFuncionário inserido com sucesso!\n");
    printf("Pressione ENTER para continuar...");
    getchar(); getchar(); 
}

void listarFuncionarios(Funcionario *funcionarios, int *totalFuncionarios) {
    limparEcra();
    printf("\n--- LISTAGEM DE FUNCIONÁRIOS ---\n");
    
    if (*totalFuncionarios == 0) {
        printf("\nNão existem funcionários registados.\n");
    } else {
        for (int i = 0; i < *totalFuncionarios; i++) {
            printf("\nFuncionário %d:\n", i + 1);
            printf("  Nome: %s\n", funcionarios[i].nome);
            printf("  NIF: %d\n", funcionarios[i].nif);
            printf("  Cargo: %s\n", funcionarios[i].cargo);
            printf("  Salário: %.2f€\n", funcionarios[i].salario);
        }
    }

    printf("\nPressione ENTER para continuar...");
    getchar(); getchar(); 
}

void alterarFuncionario(Funcionario *funcionarios, int *totalFuncionarios) {
    limparEcra();
    printf("\n--- ALTERAR FUNCIONÁRIO ---\n");

    if (*totalFuncionarios == 0) {
        printf("\nNão existem funcionários para alterar.\n");
        printf("Pressione ENTER para continuar...");
        getchar(); getchar();
        return;
    }

    int nifPesquisa;
    printf("Introduza o NIF do funcionário a alterar: ");
    scanf("%d", &nifPesquisa);

    int indice = -1;
    for (int i = 0; i < *totalFuncionarios; i++) {
        if (funcionarios[i].nif == nifPesquisa) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\nFuncionário com NIF %d não encontrado.\n", nifPesquisa);
    } else {
        printf("\nDados atuais: %s, %s, %.2f€\n", funcionarios[indice].nome, funcionarios[indice].cargo, funcionarios[indice].salario);
        printf("Novo Nome: ");
        scanf(" %[^\n]", funcionarios[indice].nome);
        printf("Novo Cargo: ");
        scanf(" %[^\n]", funcionarios[indice].cargo);
        printf("Novo Salário: ");
        scanf("%f", &funcionarios[indice].salario);

        guardarFuncionarios(funcionarios, *totalFuncionarios);
        printf("\nFuncionário alterado com sucesso!\n");
    }

    printf("Pressione ENTER para continuar...");
    getchar(); getchar();
}

void removerFuncionario(Funcionario *funcionarios, int *totalFuncionarios) {
    limparEcra();
    printf("\n--- REMOVER FUNCIONÁRIO ---\n");

    if (*totalFuncionarios == 0) {
        printf("\nNão existem funcionários para remover.\n");
        printf("Pressione ENTER para continuar...");
        getchar(); getchar();
        return;
    }

    int nifPesquisa;
    printf("Introduza o NIF do funcionário a remover: ");
    scanf("%d", &nifPesquisa);

    int indice = -1;
    for (int i = 0; i < *totalFuncionarios; i++) {
        if (funcionarios[i].nif == nifPesquisa) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("\nFuncionário com NIF %d não encontrado.\n", nifPesquisa);
    } else {
        char confirmacao;
        printf("Tem a certeza que deseja remover o funcionário %s? (s/n): ", funcionarios[indice].nome);
        scanf(" %c", &confirmacao);

        if (confirmacao == 's' || confirmacao == 'S') {
            for (int i = indice; i < *totalFuncionarios - 1; i++) {
                funcionarios[i] = funcionarios[i + 1];
            }
            (*totalFuncionarios)--;
            guardarFuncionarios(funcionarios, *totalFuncionarios);
            printf("\nFuncionário removido com sucesso!\n");
        } else {
            printf("\nOperação cancelada.\n");
        }
    }

    printf("Pressione ENTER para continuar...");
    getchar(); getchar();
}

void guardarFuncionarios(Funcionario *funcionarios, int totalFuncionarios) {
    FILE *f = fopen("funcionarios.dat", "wb");
    if (f == NULL) {
        printf("Erro ao abrir ficheiro para escrita!\n");
        return;
    }
    fwrite(&totalFuncionarios, sizeof(int), 1, f);
    fwrite(funcionarios, sizeof(Funcionario), totalFuncionarios, f);
    fclose(f);
}

void carregarFuncionarios(Funcionario *funcionarios, int *totalFuncionarios) {
    FILE *f = fopen("funcionarios.dat", "rb");
    if (f == NULL) {
        *totalFuncionarios = 0;
        return;
    }
    fread(totalFuncionarios, sizeof(int), 1, f);
    fread(funcionarios, sizeof(Funcionario), *totalFuncionarios, f);
    fclose(f);
}
