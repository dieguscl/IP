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
 Descrição: Peça ao utilizador um número inteiro N e apresente a tabuada de multiplicar desse número, de 1 a 10,
formatada em colunas. Usar ciclo `for` e especificadores de formato (`%2d`, `%3d`, etc.) para alinhar os
resultados. O cabeçalho e o formato da tabuada devem ser idênticos ao exemplo apresentado
*/

// Exemplo de execução:
// Introduza um número: 7
// Tabuada do 7:
// -----------------
// 7 x 1 = 7
// 7 x 2 = 14
// 7 x 3 = 21
// 7 x 4 = 28
// 7 x 5 = 35
// 7 x 6 = 42
// 7 x 7 = 49
// 7 x 8 = 56
// 7 x 9 = 63
// 7 x 10 = 70
int main() {
  setlocale(LC_CTYPE, "Portuguese");

  printf("Introduza um número: ");
  int numero;
  scanf("%d", &numero);

  printf("Tabuada do %d:\n", numero);
  printf("-----------------\n");
  for (int i = 1; i <= 10; i++) {
    printf("%2d x %2d = %3d\n", numero, i, numero * i);
  }
}
