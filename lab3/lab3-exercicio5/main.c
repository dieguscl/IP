#include <locale.h>
#include <stdio.h>

int main() {
  setlocale(LC_ALL, "Portuguese");
  int x = 2;

  printf("Insira um número inteiro:\n");
  scanf("%d", &x);

  if (x > 0) {
    printf("O número é positivo\n");
  } else if (x < 0) {
    printf("O número é negativo\n");
  } else {
    printf("O número é nulo\n");
  }

  // se x % 2 = 1 é ímpar, = 0 par
  if (x % 2 == 0) {
    printf("O número é par\n");
  } else {
    printf("O número é ímpar\n");
  }

  return 0;
}
