#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

# define MAX 50

void preencherManualUsuario();
void preencherManual(int v[], int n);
void preencherAleatorio(int v[], int n);
void mostrarVetor(int v[], int n);
int apresentarMenu(void);
void determinarMinMax(int v[]);

int main()
{
    int opcao;
    int tabela[MAX];
    int nElem;

    setlocale(LC_CTYPE, "Portuguese");
    srand((unsigned)time(NULL));
    do {
        opcao = apresentarMenu();

        switch (opcao) {
            case 1:
                do {
                    printf("Quantos inteiros quer inserir? (Max: %d)\n", MAX);
                    scanf("%d", &nElem);
                    if(nElem <= 0 || nElem > MAX) {
                        printf("Valor inválido, o valor deve estar entre 1 e %d\n", MAX);
                    }
                } while(nElem <= 0 || nElem > MAX);

                preencherManual(tabela, nElem);
                break;
            case 2:
                do {
                    printf("Quantos inteiros quer inserir? (Max: %d)\n", MAX);
                    scanf("%d", &nElem);
                    if(nElem <= 0 || nElem > MAX) {
                        printf("Valor inválido, o valor deve estar entre 1 e %d\n", MAX);
                    }
                } while(nElem <= 0 || nElem > MAX);

                preencherAleatorio(tabela, nElem);
                break;
            case 3:
                mostrarVetor(tabela, nElem);
                break;
            case 4:
                determinarMinMax(tabela);
                break;
            case 5:
                // calcularMedia();
                break;
            case 6:
                // procurarValor();
                break;
            case 7:
                // criarVetorAcumulado();
                break;
            case 0:
                printf("\nA terminar o programa...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

int apresentarMenu(void) {
    int opcao;

    printf("\n\n--- GESTÃO DE VETORES ---\n\n");
    printf("1 - Preencher o vetor manualmente\n");
    printf("2 - Preencher o vetor com valores aleatórios (0 a 100)\n");
    printf("3 - Mostrar o vetor\n");
    printf("4 - Determinar o valor máximo e o valor mínimo\n");
    printf("5 - Calcular a média dos valores\n");
    printf("6 - Procurar um valor no vetor (mostrar todas as posições)\n");
    printf("7 - Criar e mostrar o vetor acumulado\n");
    printf("0 - Sair\n");
    printf("\nQual a sua opção: ");
    scanf("%d", &opcao);

    return opcao;
}

void preencherManual(int v[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Insira o valor nº%d: \n", i+1);
        scanf("%d", &v[i]);
    }
}

void preencherAleatorio(int v[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        v[i] = rand() % 101;
    }
}

void mostrarVetor(int v[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d - valor = %d\n", i+1, v[i]);
    }
}

void determinarMinMax(int v[], int n) {
    int max = 0, min = 0;
    for(i = 0; i < n; i++) {
       if (v[i] > max) {
          max = v[i]
      } else if (v[i] < min) {
        min = v[i]
    } 
    }
}

