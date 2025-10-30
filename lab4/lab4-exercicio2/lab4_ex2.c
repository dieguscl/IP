#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

/*
 Laborat�rio 4 � Controlo de Fluxo
 Grupo: 3
 Elementos:
 - Gon�alo Ferreira (n�202300815)
 - Diego Laya (n�2025184378)
 - Tiago Martins (n�202001207)
 Data: 20/10/2025
 Descri��o: Pe�a ao utilizador que introduza um n�mero inteiro e indique:
� se o n�mero pertence ao intervalo [10, 50];
� se o n�mero � m�ltiplo de 3 ou de 5.
O programa deve apresentar mensagens completas, indicando o n�mero e a respetiva
condi��o..
*/

// se x % 3 == 0 e x % 5 == 0
int main() {
  setlocale(LC_ALL, "Portuguese");
  int numero;

  printf("Introduza um n�mero inteiro: \n");
  scanf("%d", &numero);
  if (numero >= 10 && numero <= 50) {
    printf("O n�mero %d pertence ao intervalo [10,50].\n", numero);
  }
  if (numero % 3 == 0 && numero % 5 == 0) {
    printf("O n�mero %d � m�ltiplo de 3 ou de 5.", numero);
  }
}
