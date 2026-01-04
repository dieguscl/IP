# Manual Técnico - Aplicação de Gestão de Negócio

## 1. Descrição Geral da Aplicação
A aplicação de Gestão de Negócio é uma ferramenta de consola desenvolvida em C, destinada a apoiar a administração de uma pequena empresa. O sistema permite a gestão centralizada de quatro áreas fundamentais:
*   **Clientes:** Registo e manutenção de dados de clientes.
*   **Funcionários:** Gestão de recursos humanos e encargos salariais.
*   **Produtos/Serviços:** Controlo de inventário e preçário.
*   **Transações:** Registo de vendas com atualização automática de stock.
*   **Estatísticas:** Geração de relatórios de desempenho e resumos financeiros.

A aplicação utiliza uma interface puramente textual, facilitando a execução em diversos ambientes, e garante a persistência de dados através de ficheiros binários.

## 2. Decisões de Implementação
*   **Modularidade:** O código foi dividido em vários ficheiros (`.c` e `.h`) para cada módulo funcional, promovendo a organização e facilidade de manutenção.
*   **Encapsulamento de Dados:** Optou-se por passar as estruturas de dados e contadores por referência (ponteiros) entre funções, evitando estritamente o uso de variáveis globais conforme as boas práticas.
*   **Persistência Binária:** Utilizaram-se ficheiros binários (`.dat`) para o armazenamento dos arrays de estruturas, garantindo que o estado da aplicação é preservado entre sessões.
*   **Níveis de Acesso:** Implementou-se um sistema de login básico para distinguir entre **Gestores** (acesso total) e **Funcionários** (acesso limitado a Clientes e Transações).

## 3. Estruturas de Dados e Algoritmos
### Estruturas de Dados
As principais estruturas utilizadas são `structs` que agrupam dados relacionados:
*   `Cliente`: Nome, NIF, Telemóvel.
*   `Funcionario`: Nome, NIF, Cargo, Salário.
*   `Produto`: Código, Nome, Preço, Stock.
*   `Transacao`: ID, NIF do Cliente, Código do Produto, Quantidade, Total e Data.

### Algoritmos
*   **Ordenação:** Utilizou-se o algoritmo **Bubble Sort** para ordenar a lista de clientes por nome. É um algoritmo simples de implementar e adequado para volumes de dados moderados.
*   **Procura:** Implementou-se uma **Procura Sequencial** para localizar clientes e produtos através dos seus identificadores únicos (NIF ou Código).
*   **Gestão de Stock:** No momento do registo de uma transação, o sistema verifica a disponibilidade no array de produtos e subtrai a quantidade vendida antes de guardar as alterações.

## 4. Limitações e Melhorias Futuras
### Limitações
*   **Arrays Estáticos:** O número máximo de registos é limitado por constantes (`MAX_CLIENTES`, etc.), o que pode levar a desperdício de memória ou falta de espaço.
*   **Segurança:** A palavra-passe do gestor está "hardcoded" no código e é transmitida em texto limpo.
*   **Interface:** A navegação baseada em menus numéricos é funcional mas pode ser menos intuitiva que interfaces gráficas ou baseadas em comandos.

### Melhorias
*   **Memória Dinâmica:** Utilização de `malloc` e `realloc` ou Listas Ligadas para permitir um número ilimitado de registos.
*   **Criptografia:** Implementar hashing (ex: SHA-256) para as passwords dos utilizadores.
*   **Pesquisa Avançada:** Adicionar filtros de pesquisa por datas ou intervalos de preços.

## 5. Excertos de Código Comentados

### Definição da Estrutura de Transação
```c
typedef struct {
    int id;               // Identificador único da transação
    int nifCliente;       // Ligação ao cliente (chave estrangeira)
    int codigoProduto;    // Ligação ao produto (chave estrangeira)
    int quantidade;       // Quantidade vendida
    float total;          // Valor calculado (qtd * preço)
    char data[20];        // Timestamp do momento da venda
} Transacao;
```

### Persistência de Dados (Exemplo de Escrita)
```c
void guardarProdutos(Produto *produtos, int totalProdutos) {
    FILE *f = fopen("produtos.dat", "wb"); // Abre para escrita binária
    if (f == NULL) return;
    
    // Escreve primeiro o contador total para saber quantos registos ler depois
    fwrite(&totalProdutos, sizeof(int), 1, f);
    // Escreve o array completo de estruturas
    fwrite(produtos, sizeof(Produto), totalProdutos, f);
    
    fclose(f);
}
```

### Algoritmo de Ordenação (Bubble Sort)
```c
void ordenarClientes(Cliente *clientes, int totalClientes) {
    for (int i = 0; i < totalClientes - 1; i++) {
        for (int j = 0; j < totalClientes - i - 1; j++) {
            // Comparação de strings ignorando a capitalização se necessário
            if (strcmp(clientes[j].nome, clientes[j + 1].nome) > 0) {
                // Troca de estruturas completa
                Cliente temp = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = temp;
            }
        }
    }
}
```
