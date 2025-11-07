#include <locale.h>
#include <stdio.h>

/*
 Laboratório 6 Subprogramas
 Grupo: 3
 Elementos:
 - Gonçalo Ferreira (nº202300815)
 - Diego Laya (nº2025184378)
 - Tiago Martins (nº202001207)
 Descrição: Exercício 1
*/

void trocar(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  setlocale(LC_CTYPE, "Portuguese");
  int a, b;
  printf("Insira dois numeros:\n");
  scanf("%d", &a);
  scanf("%d", &b);
  printf("Antes de trocar: %d, %d", a, b);
  trocar(&a, &b);
  printf("Depois de trocar: %d, %d", a, b);
}
