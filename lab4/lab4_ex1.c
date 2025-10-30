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
 Descri��o: Pe�a ao utilizador que introduza um n�mero inteiro maior ou igual
a 30. Enquanto o valor inserido n�o cumprir essa condi��o, o programa deve
apresentar uma mensagem de erro clara (por exemplo: �Valor inv�lido! Tente
novamente.�) e voltar a pedir o n�mero. Quando for introduzido um valor v�lido,
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
