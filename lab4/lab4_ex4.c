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
 Descrição: Peça ao utilizador que introduza um número inteiro positivo N.
O programa deve calcular o somatório dos números de 1 até N, ou seja, a soma de todos os números
inteiros consecutivos desde 1 até ao valor introduzido
*/

// Exemplo de execução:
// Introduza um número inteiro positivo: -3
// Erro: o número deve ser positivo.
// Introduza um número inteiro positivo: 5
// A soma de todos os números de 1 a 5 é 15
int main() {
  setlocale(LC_CTYPE, "Portuguese");

  printf("Introduza um número inteiro positivo: ");
  int numero;
  scanf("%d", &numero);

  if (numero < 0) {
    printf("Erro: o número deve ser positivo.\n");
    return 1;
  } 

  int soma = 0;
  for (int i = 1; i <= numero; i++) {
    soma += i;
  }
  printf("A soma de todos os números de 1 a %d é %d\n", numero, soma);
}
