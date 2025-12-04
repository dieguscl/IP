#ifndef CLIENTES_H
#define CLIENTES_H

#define MAX_NOME 100
#define MAX_TELEM 20
#define MAX_CLIENTES 50

typedef struct {
    char nome[MAX_NOME];
    int nif;
    char telemovel[MAX_TELEM]; // Opcional
} Cliente;

void inserirCliente(Cliente *clientes, int *totalClientes);
void alterarCliente(Cliente *clientes, int *totalClientes);
void removerCliente(Cliente *clientes, int *totalClientes);
void listarClientes(Cliente *clientes, int *totalClientes);
int apresentarMenuClientes(void);
void gerirClientes(Cliente *clientes, int *totalClientes);


#endif
