#include <locale.h>
#include <stdio.h>

int main() {
  setlocale(LC_ALL, "Portuguese");
  int x = 2;

  printf("Insira um n�mero inteiro:\n");
  scanf("%d", &x);

  if (x > 0) {
    printf("O n�mero � positivo\n");
  } else if (x < 0) {
    printf("O n�mero � negativo\n");
  } else {
    printf("O n�mero � nulo\n");
  }

  // se x % 2 = 1 � �mpar, = 0 par
  if (x % 2 == 0) {
    printf("O n�mero � par\n");
  } else {
    printf("O n�mero � �mpar\n");
  }

  return 0;
}
