/******************************************************************************
 * UNIVERSIDADE - Licenciatura em Eng. Eletrotécnica e de Computadores
 * Unidade Curricular: Introdução à Programação - 2025/2026
 * Trabalho Prático 1
 *
 * TEMA: Gestão de Loja de Informática (TechZone)
 * AUTOR: [O Teu Nome / Grupo]
 * DATA: Novembro 2025
 *
 * DESCRIÇÃO:
 * Aplicação de consola para gestão de clientes, funcionários, produtos e vendas.
 * Inclui persistência de dados (ficheiros txt), ordenação e pesquisa.
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* --- DEFINIÇÕES E CONSTANTES --- */
#define MAX_CLIENTES 100
#define MAX_FUNCIONARIOS 20
#define MAX_PRODUTOS 100
#define MAX_TRANSACOES 200
#define TAM_STRING 50
#define FICHEIRO_CLIENTES "clientes.txt"
#define FICHEIRO_FUNCIONARIOS "funcionarios.txt"
#define FICHEIRO_PRODUTOS "produtos.txt"
#define FICHEIRO_TRANSACOES "transacoes.txt"

/* --- ESTRUTURAS DE DADOS --- */

typedef struct {
    int id;
    char nome[TAM_STRING];
    char nif[10];
    char telefone[15];
    int ativo; // 1 = ativo, 0 = eliminado logicamente
} Cliente;

typedef struct {
    int id;
    char nome[TAM_STRING];
    char cargo[TAM_STRING];
    int is_admin; // 1 = Gestor, 0 = Funcionário normal
    int ativo;
} Funcionario;

typedef struct {
    int id;
    char designacao[TAM_STRING];
    char categoria[TAM_STRING];
    float preco;
    int stock;
    int ativo;
} Produto;

typedef struct {
    int id;
    int id_cliente;
    int id_produto;
    int quantidade;
    float valor_total;
    char data[12]; // Formato DD/MM/AAAA
} Transacao;

/* --- PROTÓTIPOS DE FUNÇÕES --- */

// Utilitários
void limparBuffer();
void limparEcra();
void pause();
int lerInteiro(char *mensagem);
float lerFloat(char *mensagem);
void lerString(char *mensagem, char *str, int tamanho);

// Gestão de Ficheiros
void carregarDados(Cliente cli[], int *qtdCli, Funcionario func[], int *qtdFunc, Produto prod[], int *qtdProd, Transacao trans[], int *qtdTrans);
void guardarDados(Cliente cli[], int qtdCli, Funcionario func[], int qtdFunc, Produto prod[], int qtdProd, Transacao trans[], int qtdTrans);

// Menus
void menuPrincipal(Cliente cli[], int *qtdCli, Funcionario func[], int *qtdFunc, Produto prod[], int *qtdProd, Transacao trans[], int *qtdTrans);
void menuClientes(Cliente cli[], int *qtdCli);
void menuFuncionarios(Funcionario func[], int *qtdFunc);
void menuProdutos(Produto prod[], int *qtdProd);
void menuTransacoes(Cliente cli[], int qtdCli, Produto prod[], int qtdProd, Transacao trans[], int *qtdTrans);

// Funções Específicas (Exemplos de Modularização)
void adicionarCliente(Cliente cli[], int *qtdCli);
void listarClientes(Cliente cli[], int qtdCli);
void ordenarClientesPorNome(Cliente cli[], int qtdCli); // Algoritmo de Ordenação
int procurarClienteNIF(Cliente cli[], int qtdCli, char *nif); // Algoritmo de Procura

void adicionarProduto(Produto prod[], int *qtdProd);
void listarProdutos(Produto prod[], int qtdProd);

void registarVenda(Cliente cli[], int qtdCli, Produto prod[], int qtdProd, Transacao trans[], int *qtdTrans);
void listarTransacoes(Transacao trans[], int qtdTrans);

/* --- FUNÇÃO MAIN --- */
int main() {
    // Configuração de localidade para aceitar caracteres portugueses
    setlocale(LC_ALL, "Portuguese");

    // Declaração de Arrays (Estruturas de Dados na Stack)
    Cliente clientes[MAX_CLIENTES];
    Funcionario funcionarios[MAX_FUNCIONARIOS];
    Produto produtos[MAX_PRODUTOS];
    Transacao transacoes[MAX_TRANSACOES];

    // Contadores de registos
    int qtdClientes = 0;
    int qtdFuncionarios = 0;
    int qtdProdutos = 0;
    int qtdTransacoes = 0;

    // Carregar dados iniciais
    carregarDados(clientes, &qtdClientes, funcionarios, &qtdFuncionarios, produtos, &qtdProdutos, transacoes, &qtdTransacoes);

    // Iniciar Aplicação
    menuPrincipal(clientes, &qtdClientes, funcionarios, &qtdFuncionarios, produtos, &qtdProdutos, transacoes, &qtdTransacoes);

    return 0;
}

/* --- IMPLEMENTAÇÃO DAS FUNÇÕES --- */

/* --- UTILITÁRIOS --- */
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limparEcra() {
    // Tenta limpar o ecrã tanto em Windows como Linux
    system("cls || clear");
}

void pause() {
    printf("\nPressione ENTER para continuar...");
    limparBuffer();
    getchar(); // Espera pelo Enter
}

int lerInteiro(char *mensagem) {
    int valor;
    printf("%s", mensagem);
    scanf("%d", &valor);
    return valor;
}

float lerFloat(char *mensagem) {
    float valor;
    printf("%s", mensagem);
    scanf("%f", &valor);
    return valor;
}

void lerString(char *mensagem, char *str, int tamanho) {
    printf("%s", mensagem);
    limparBuffer();
    fgets(str, tamanho, stdin);
    str[strcspn(str, "\n")] = 0; // Remover o \n final
}

/* --- MENUS --- */
void menuPrincipal(Cliente cli[], int *qtdCli, Funcionario func[], int *qtdFunc, Produto prod[], int *qtdProd, Transacao trans[], int *qtdTrans) {
    int opcao;
    do {
        limparEcra();
        printf("=== TECHZONE - GESTAO DE LOJA ===\n");
        printf("1. Gestao de Clientes\n");
        printf("2. Gestao de Produtos\n");
        printf("3. Gestao de Funcionarios\n");
        printf("4. Registar/Consultar Vendas\n");
        printf("0. Sair e Guardar\n");
        printf("=================================\n");
        opcao = lerInteiro("Opcao: ");

        switch (opcao) {
            case 1: menuClientes(cli, qtdCli); break;
            case 2: menuProdutos(prod, qtdProd); break;
            case 3: menuFuncionarios(func, qtdFunc); break;
            case 4: menuTransacoes(cli, *qtdCli, prod, *qtdProd, trans, qtdTrans); break;
            case 0: 
                guardarDados(cli, *qtdCli, func, *qtdFunc, prod, *qtdProd, trans, *qtdTrans);
                printf("Dados guardados. A encerrar...\n");
                break;
            default: printf("Opcao invalida!\n"); pause();
        }
    } while (opcao != 0);
}

void menuClientes(Cliente cli[], int *qtdCli) {
    int opcao;
    do {
        limparEcra();
        printf("--- MENU CLIENTES ---\n");
        printf("1. Adicionar Cliente\n");
        printf("2. Listar Clientes\n");
        printf("3. Ordenar Clientes (Nome)\n");
        printf("0. Voltar\n");
        opcao = lerInteiro("Opcao: ");

        switch (opcao) {
            case 1: adicionarCliente(cli, qtdCli); break;
            case 2: listarClientes(cli, *qtdCli); break;
            case 3: ordenarClientesPorNome(cli, *qtdCli); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menuProdutos(Produto prod[], int *qtdProd) {
    int opcao;
    do {
        limparEcra();
        printf("--- MENU PRODUTOS ---\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("0. Voltar\n");
        opcao = lerInteiro("Opcao: ");

        switch (opcao) {
            case 1: adicionarProduto(prod, qtdProd); break;
            case 2: listarProdutos(prod, *qtdProd); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menuFuncionarios(Funcionario func[], int *qtdFunc) {
    // Implementação simples apenas para demonstrar estrutura
    limparEcra();
    printf("--- LISTA DE FUNCIONARIOS ---\n");
    for(int i=0; i<*qtdFunc; i++) {
        printf("ID: %d | Nome: %s | Cargo: %s\n", func[i].id, func[i].nome, func[i].cargo);
    }
    printf("\n(Funcionalidade completa de Gestao de RH seria implementada aqui)\n");
    pause();
}

void menuTransacoes(Cliente cli[], int qtdCli, Produto prod[], int qtdProd, Transacao trans[], int *qtdTrans) {
    int opcao;
    do {
        limparEcra();
        printf("--- MENU VENDAS ---\n");
        printf("1. Nova Venda\n");
        printf("2. Relatorio de Vendas\n");
        printf("0. Voltar\n");
        opcao = lerInteiro("Opcao: ");

        switch (opcao) {
            case 1: registarVenda(cli, qtdCli, prod, qtdProd, trans, qtdTrans); break;
            case 2: listarTransacoes(trans, *qtdTrans); break;
            case 0: break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

/* --- GESTÃO DE CLIENTES --- */

void adicionarCliente(Cliente cli[], int *qtdCli) {
    if (*qtdCli >= MAX_CLIENTES) {
        printf("Limite de clientes atingido.\n");
        pause();
        return;
    }

    Cliente novo;
    novo.id = *qtdCli + 1;
    novo.ativo = 1;
    
    lerString("Nome: ", novo.nome, TAM_STRING);
    lerString("NIF: ", novo.nif, 10);
    lerString("Telefone: ", novo.telefone, 15);

    cli[*qtdCli] = novo;
    (*qtdCli)++;
    printf("Cliente adicionado com sucesso!\n");
    pause();
}

void listarClientes(Cliente cli[], int qtdCli) {
    limparEcra();
    printf("--- LISTAGEM DE CLIENTES ---\n");
    printf("%-5s %-20s %-15s %-15s\n", "ID", "Nome", "NIF", "Telefone");
    for (int i = 0; i < qtdCli; i++) {
        if (cli[i].ativo) {
            printf("%-5d %-20s %-15s %-15s\n", cli[i].id, cli[i].nome, cli[i].nif, cli[i].telefone);
        }
    }
    pause();
}

// Algoritmo de Ordenação (Bubble Sort)
void ordenarClientesPorNome(Cliente cli[], int qtdCli) {
    Cliente temp;
    for (int i = 0; i < qtdCli - 1; i++) {
        for (int j = 0; j < qtdCli - i - 1; j++) {
            if (strcmp(cli[j].nome, cli[j + 1].nome) > 0) {
                temp = cli[j];
                cli[j] = cli[j + 1];
                cli[j + 1] = temp;
            }
        }
    }
    printf("Clientes ordenados por nome.\n");
    pause();
}

// Algoritmo de Procura Linear
int procurarClienteNIF(Cliente cli[], int qtdCli, char *nif) {
    for (int i = 0; i < qtdCli; i++) {
        if (cli[i].ativo && strcmp(cli[i].nif, nif) == 0) {
            return i; // Retorna o índice
        }
    }
    return -1; // Não encontrado
}

/* --- GESTÃO DE PRODUTOS --- */

void adicionarProduto(Produto prod[], int *qtdProd) {
    if (*qtdProd >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n"); return;
    }
    Produto novo;
    novo.id = *qtdProd + 1;
    novo.ativo = 1;

    lerString("Designacao: ", novo.designacao, TAM_STRING);
    lerString("Categoria: ", novo.categoria, TAM_STRING);
    novo.preco = lerFloat("Preco: ");
    novo.stock = lerInteiro("Stock Inicial: ");

    prod[*qtdProd] = novo;
    (*qtdProd)++;
    printf("Produto registado!\n");
    pause();
}

void listarProdutos(Produto prod[], int qtdProd) {
    limparEcra();
    printf("--- STOCK ---\n");
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Produto", "Preco", "Stock");
    for (int i = 0; i < qtdProd; i++) {
        if (prod[i].ativo) {
            printf("%-5d %-20s %-10.2f %-10d\n", prod[i].id, prod[i].designacao, prod[i].preco, prod[i].stock);
        }
    }
    pause();
}

/* --- TRANSAÇÕES --- */

void registarVenda(Cliente cli[], int qtdCli, Produto prod[], int qtdProd, Transacao trans[], int *qtdTrans) {
    if (*qtdTrans >= MAX_TRANSACOES) {
        printf("Memoria de transacoes cheia.\n"); return;
    }

    int idCli, idProd, qtd, indexProd = -1, indexCli = -1;

    listarClientes(cli, qtdCli);
    idCli = lerInteiro("ID do Cliente: ");
    
    // Validar Cliente (Procura Simples por ID)
    for(int i=0; i<qtdCli; i++) {
        if(cli[i].id == idCli) indexCli = i;
    }
    if (indexCli == -1) { printf("Cliente nao encontrado.\n"); pause(); return; }

    listarProdutos(prod, qtdProd);
    idProd = lerInteiro("ID do Produto: ");

    // Validar Produto e Stock
    for(int i=0; i<qtdProd; i++) {
        if(prod[i].id == idProd) indexProd = i;
    }

    if (indexProd == -1) { printf("Produto nao encontrado.\n"); pause(); return; }

    qtd = lerInteiro("Quantidade: ");
    if (prod[indexProd].stock < qtd) {
        printf("Stock insuficiente (Stock atual: %d).\n", prod[indexProd].stock);
        pause();
        return;
    }

    // Efetuar Venda
    prod[indexProd].stock -= qtd; // Atualiza Stock

    Transacao nova;
    nova.id = *qtdTrans + 1;
    nova.id_cliente = idCli;
    nova.id_produto = idProd;
    nova.quantidade = qtd;
    nova.valor_total = qtd * prod[indexProd].preco;
    lerString("Data (DD/MM/AAAA): ", nova.data, 12);

    trans[*qtdTrans] = nova;
    (*qtdTrans)++;

    printf("Venda registada com sucesso! Total: %.2f EUR\n", nova.valor_total);
    pause();
}

void listarTransacoes(Transacao trans[], int qtdTrans) {
    limparEcra();
    printf("--- HISTORICO DE VENDAS ---\n");
    printf("%-5s %-10s %-10s %-5s %-10s\n", "ID", "Data", "Total", "Qtd", "ID Prod");
    float totalFaturado = 0;
    for(int i=0; i<qtdTrans; i++) {
        printf("%-5d %-10s %-10.2f %-5d %-10d\n", trans[i].id, trans[i].data, trans[i].valor_total, trans[i].quantidade, trans[i].id_produto);
        totalFaturado += trans[i].valor_total;
    }
    printf("\nTotal Faturado: %.2f EUR\n", totalFaturado);
    pause();
}

/* --- FICHEIROS (PERSISTÊNCIA) --- */

void guardarDados(Cliente cli[], int qtdCli, Funcionario func[], int qtdFunc, Produto prod[], int qtdProd, Transacao trans[], int qtdTrans) {
    FILE *f;

    // Guardar Clientes
    f = fopen(FICHEIRO_CLIENTES, "w");
    if (f) {
        fprintf(f, "%d\n", qtdCli);
        for (int i = 0; i < qtdCli; i++) {
            fprintf(f, "%d;%s;%s;%s;%d\n", cli[i].id, cli[i].nome, cli[i].nif, cli[i].telefone, cli[i].ativo);
        }
        fclose(f);
    }

    // Guardar Produtos
    f = fopen(FICHEIRO_PRODUTOS, "w");
    if (f) {
        fprintf(f, "%d\n", qtdProd);
        for (int i = 0; i < qtdProd; i++) {
            fprintf(f, "%d;%s;%s;%.2f;%d;%d\n", prod[i].id, prod[i].designacao, prod[i].categoria, prod[i].preco, prod[i].stock, prod[i].ativo);
        }
        fclose(f);
    }

    // Guardar Funcionarios e Transacoes seguem a mesma lógica (omitido por brevidade, mas necessário para o projeto completo)
}

void carregarDados(Cliente cli[], int *qtdCli, Funcionario func[], int *qtdFunc, Produto prod[], int *qtdProd, Transacao trans[], int *qtdTrans) {
    FILE *f;

    // Carregar Clientes
    f = fopen(FICHEIRO_CLIENTES, "r");
    if (f) {
        if (fscanf(f, "%d\n", qtdCli) != 1) *qtdCli = 0;
        for (int i = 0; i < *qtdCli; i++) {
            char buffer[200];
            fgets(buffer, 200, f);
            // Parse manual do CSV
            sscanf(buffer, "%d;%[^;];%[^;];%[^;];%d", &cli[i].id, cli[i].nome, cli[i].nif, cli[i].telefone, &cli[i].ativo);
        }
        fclose(f);
    } else {
        *qtdCli = 0;
    }
    
    // Carregar Produtos (Lógica similar)
    f = fopen(FICHEIRO_PRODUTOS, "r");
    if (f) {
        if (fscanf(f, "%d\n", qtdProd) != 1) *qtdProd = 0;
        for (int i = 0; i < *qtdProd; i++) {
            char buffer[200];
            fgets(buffer, 200, f);
            sscanf(buffer, "%d;%[^;];%[^;];%f;%d;%d", &prod[i].id, prod[i].designacao, prod[i].categoria, &prod[i].preco, &prod[i].stock, &prod[i].ativo);
        }
        fclose(f);
    } else {
        *qtdProd = 0;
    }
    
    // Para a primeira execução não dar erro, se não houver funcionarios, cria um Admin
    if (*qtdFunc == 0) {
        func[0].id = 1;
        strcpy(func[0].nome, "Administrador");
        strcpy(func[0].cargo, "Gerente");
        func[0].is_admin = 1;
        *qtdFunc = 1;
    }
}
