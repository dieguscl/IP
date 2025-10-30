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
 Descrição: Peça ao utilizador que introduza um número inteiro maior ou igual
a 30. Enquanto o valor inserido não cumprir essa condição, o programa deve
apresentar uma mensagem de erro clara (por exemplo: “Valor inválido! Tente
novamente.”) e voltar a pedir o número. Quando for introduzido um valor válido,
o programa deve apresentar uma mensagem a indicar o valor aceite.
*/

int main() {
  int numero;
  setlocale(LC_ALL, "Portuguese");

  do {
    printf("Introduza um numero inteiro maior ou igual a 30: ");
    scanf("%d", &numero);
    if (numero < 30) {
      printf("Valor invalido! Tente novamente\n");
    }
  } while (numero < 30);

  printf("Valor aceite: %d", numero);
}
