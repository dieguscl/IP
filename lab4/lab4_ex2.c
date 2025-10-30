#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

/*
 Laboratório 4 – Controlo de Fluxo
 Grupo: 3
 Elementos:
 - Gonçalo Ferreira (nº202300815)
 - Diego Laya (nº2025184378)
 - Tiago Martins (nº202001207)
 Data: 20/10/2025
 Descrição: Peça ao utilizador que introduza um número inteiro e indique:
• se o número pertence ao intervalo [10, 50];
• se o número é múltiplo de 3 ou de 5.
O programa deve apresentar mensagens completas, indicando o número e a respetiva
condição..
*/

// se x % 3 == 0 e x % 5 == 0
int main() {
  setlocale(LC_ALL, "Portuguese");
  int numero;

  printf("Introduza um número inteiro: \n");
  scanf("%d", &numero);
  if (numero >= 10 && numero <= 50) {
    printf("O número %d pertence ao intervalo [10,50].\n", numero);
  }
  if (numero % 3 == 0 && numero % 5 == 0) {
    printf("O número %d é múltiplo de 3 ou de 5.", numero);
  }
}
