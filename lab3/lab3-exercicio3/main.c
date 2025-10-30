#include <stdio.h>
#include <stdlib.h>

int main() {
  int idade;
  float altura;
  char inicial;

  printf("Insere a sua idade, altura e inicial (Ex: 20, 1.75, A): \n");
  scanf("%d, %f, %c", &idade, &altura, &inicial);

  // O estudante A tem 20 anos e mede 1.75 m.
  printf("O estudante %c tem %d anos e mede %.2f m.\n", inicial, idade, altura);

  return 0;
}
