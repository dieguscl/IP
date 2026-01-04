#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#define MAX_NOME 100
#define MAX_CARGO 50
#define MAX_FUNCIONARIOS 50

typedef struct {
    char nome[MAX_NOME];
    int nif;
    char cargo[MAX_CARGO];
    float salario;
} Funcionario;

void inserirFuncionario(Funcionario *funcionarios, int *totalFuncionarios);
void alterarFuncionario(Funcionario *funcionarios, int *totalFuncionarios);
void removerFuncionario(Funcionario *funcionarios, int *totalFuncionarios);
void listarFuncionarios(Funcionario *funcionarios, int *totalFuncionarios);
int apresentarMenuFuncionarios(void);
void gerirFuncionarios(Funcionario *funcionarios, int *totalFuncionarios);
void guardarFuncionarios(Funcionario *funcionarios, int totalFuncionarios);
void carregarFuncionarios(Funcionario *funcionarios, int *totalFuncionarios);

#endif
