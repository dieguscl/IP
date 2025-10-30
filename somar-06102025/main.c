#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b, soma;
  a = 5;
  b = 10;
  soma = a + b;

  printf("%d + %d = %d\n", a, b, soma);
  int subtrair;
  subtrair = a - b;
  printf("%d - %d = %d\n", a, b, subtrair);
  int multiplicar;
  multiplicar = a * b;
  printf("%d x %d = %d\n", a, b, multiplicar);

  return 0;
}
