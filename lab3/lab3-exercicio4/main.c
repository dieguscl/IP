#include <stdio.h>
#include <stdlib.h>

int main() {
  int x;
  int y;
  int soma;
  int quo;
  int resto;
  float media;

  printf("insere dois números inteiros:\n");
  scanf("%d", &x);
  scanf("%d", &y);
  printf("x:%d y:%d\n", x, y);
  soma = x + y;
  quo = x / y;
  resto = x % y;
  media = ((float)x + (float)y) / 2;

  printf("soma: %d\nquociente: %d\nresto: %d\nmedia: %.2f", soma, quo, resto,
         media);

  return 0;
}
