/*
 Laboratório 8 - Matrizes
 Grupo: 3
 Elementos:
 - Gonçalo Ferreira (nº202300815)
 - Diego Laya (nº2025184378)
 - Tiago Martins (nº202001207)
 Turma: PL2
*/

#include <stdio.h>

#define MAX_DIM 10

/* ================================================================= */
/*                        PROTÓTIPOS DAS FUNÇÕES                     */
/* ================================================================= */

int apresentarMenu(void);
void pedirDimensoes(int *lin, int *col);
void pedirMatriz(int mat[][MAX_DIM], int lin, int col, const char *nome);
void mostrarMatriz(int mat[][MAX_DIM], int lin, int col, const char *nome);
void somaEMaiorPorLinha(int mat[][MAX_DIM], int lin, int col);
void estatisticasQuadrada(void);
void desenharArvore(int h);

/* ================================================================= */
/*                            PROGRAMA PRINCIPAL                     */
/* ================================================================= */

int main(void) {
  int matrizA[MAX_DIM][MAX_DIM], matrizB[MAX_DIM][MAX_DIM],
      matrizRes[MAX_DIM][MAX_DIM];
  int linA = 0, colA = 0, linB = 0, colB = 0;
  int opcao, i, j, k;

  do {
    opcao = apresentarMenu();

    switch (opcao) {
      case 1:
        pedirDimensoes(&linA, &colA);
        pedirMatriz(matrizA, linA, colA, "A");
        break;

      case 2:
        if (linA > 0)
          mostrarMatriz(matrizA, linA, colA, "A");
        else
          printf("Matriz A ainda nao foi lida!\n");
        break;

      case 3:
        if (linA > 0)
          somaEMaiorPorLinha(matrizA, linA, colA);
        else
          printf("Matriz A ainda nao foi lida!\n");
        break;

      case 4:
        if (linA > 0) {
          for (i = 0; i < linA; i++)
            for (j = 0; j < colA; j++) matrizB[i][j] = 2 * matrizA[i][j];
          mostrarMatriz(matrizB, linA, colA, "Dobro de A");
        } else
          printf("Matriz A ainda nao foi lida!\n");
        break;

      case 5:
        printf("Dimensoes para A e B:\n");
        pedirDimensoes(&linA, &colA);
        pedirMatriz(matrizA, linA, colA, "A");
        pedirMatriz(matrizB, linA, colA, "B");
        for (i = 0; i < linA; i++)
          for (j = 0; j < colA; j++)
            matrizRes[i][j] = matrizA[i][j] + matrizB[i][j];
        mostrarMatriz(matrizRes, linA, colA, "A+B");
        break;

      case 6:
        printf("Matriz A:\n");
        pedirDimensoes(&linA, &colA);
        printf("Matriz B:\n");
        pedirDimensoes(&linB, &colB);

        if (colA != linB) {
          printf(
              "Erro: O num de colunas de A deve ser igual ao num de linhas de "
              "B!\n");
        } else {
          pedirMatriz(matrizA, linA, colA, "A");
          pedirMatriz(matrizB, linB, colB, "B");
          for (i = 0; i < linA; i++) {
            for (j = 0; j < colB; j++) {
              matrizRes[i][j] = 0;
              for (k = 0; k < colA; k++)
                matrizRes[i][j] += matrizA[i][k] * matrizB[k][j];
            }
          }
          mostrarMatriz(matrizRes, linA, colB, "AxB");
        }
        break;

      case 7:
        estatisticasQuadrada();
        break;

      case 8:
        printf("Altura da arvore: ");
        scanf("%d", &i);
        desenharArvore(i);
        break;

      case 0:
        printf("A terminar...\n");
        break;

      default:
        printf("Opção inválida!\n\n");
    }
  } while (opcao != 0);

  return 0;
}

/* ---------------------------------------------------------- */
/*  FUNÇÃO: apresentarMenu                                     */
/*  Mostra o menu e devolve a opção escolhida pelo utilizador  */
/* ---------------------------------------------------------- */
int apresentarMenu(void) {
  int opcao;
  printf("\nOPERAÇÕES COM MATRIZES\n\n");
  printf(
      "1 – Ler matriz A\n2 – Mostrar matriz A\n3 – Soma/Maior por linha A\n4 – "
      "Dobro de A\n");
  printf(
      "5 – Soma (A + B)\n6 – Produto (A x B)\n7 – Estatísticas Quadrada\n8 – "
      "Árvore de Natal\n0 – Terminar\n");
  printf("\nQual a sua opção? ");
  scanf("%d", &opcao);
  return opcao;
}

/* ---------------------------------------------------------- */
/*  FUNÇÃO: pedirDimensoes                                     */
/*  Pede ao utilizador número de linhas e colunas válidos      */
/* ---------------------------------------------------------- */
void pedirDimensoes(int *lin, int *col) {
  do {
    printf("Linhas (1..%d): ", MAX_DIM);
    scanf("%d", lin);
  } while (*lin < 1 || *lin > MAX_DIM);
  do {
    printf("Colunas (1..%d): ", MAX_DIM);
    scanf("%d", col);
  } while (*col < 1 || *col > MAX_DIM);
}

/* ---------------------------------------------------------- */
/*  FUNÇÃO: pedirMatriz                                       */
/*  Lê os elementos de uma matriz já dimensionada             */
/* ---------------------------------------------------------- */
void pedirMatriz(int mat[][MAX_DIM], int lin, int col, const char *nome) {
  int i, j;
  printf("Elementos da matriz %s (%d x %d):\n", nome, lin, col);
  for (i = 0; i < lin; i++) {
    for (j = 0; j < col; j++) {
      printf("  %s[%d][%d] = ", nome, i, j);
      scanf("%d", &mat[i][j]);
    }
  }
}

void mostrarMatriz(int mat[][MAX_DIM], int lin, int col, const char *nome) {
  int i, j;
  printf("\nMatriz %s (%d x %d):\n", nome, lin, col);
  for (i = 0; i < lin; i++) {
    for (j = 0; j < col; j++) {
      printf("%5d", mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void somaEMaiorPorLinha(int mat[][MAX_DIM], int lin, int col) {
  int i, j, soma, maior;
  for (i = 0; i < lin; i++) {
    soma = 0;
    maior = mat[i][0];
    for (j = 0; j < col; j++) {
      soma += mat[i][j];
      if (mat[i][j] > maior) {
        maior = mat[i][j];
      }
    }
    printf("Linha %d: soma = %d, maior = %d\n", i + 1, soma, maior);
  }
}

void estatisticasQuadrada(void) {
  int mat[MAX_DIM][MAX_DIM], n, i, j;
  int somaPrincipal = 0, somaSecundaria = 0, positivos = 0;

  do {
    printf("Dimensao N (1..%d): ", MAX_DIM);
    scanf("%d", &n);
  } while (n < 1 || n > MAX_DIM);

  pedirMatriz(mat, n, n, "Quadrada");

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        somaPrincipal += mat[i][j];
      }
      if (i + j == n - 1) {
        somaSecundaria += mat[i][j];
      }
      if (mat[i][j] > 0) {
        positivos++;
      }
    }
  }
  printf("\nSoma Diagonal Principal: %d", somaPrincipal);
  printf("\nSoma Diagonal Secundaria: %d", somaSecundaria);
  printf("\nElementos Positivos: %d\n", positivos);
}

void desenharArvore(int h) {
  int i, j;
  // Copa
  for (i = 1; i <= h; i++) {
    for (j = 0; j < h - i; j++) {
      printf(" ");
    }
    for (j = 0; j < 2 * i - 1; j++) {
      printf("*");
    }
    printf("\n");
  }
  // Tronco (Versão Base)
  // for (i = 0; i < 2; i++) {
  //   for (j = 0; j < h - 1; j++) {
  //     printf(" ");
  //   }
  //   printf("*\n");
  // }
  // Tronco (Versão avançada)
  int largura = h / 3;
  if (largura < 1) {
    largura = 1;
  }

  int alturaTronco = h / 3;
  if (alturaTronco < 1) {
    alturaTronco = 1;
  }

  int espacosTronco = (h - 1) - (largura / 2);

  for (i = 0; i < alturaTronco; i++) {
    for (j = 0; j < espacosTronco; j++) {
      printf(" ");
    }
    for (j = 0; j < largura; j++) {
      printf("*");
    }
    printf("\n");
  }
}
