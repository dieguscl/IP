#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  setlocale(LC_ALL, "portuguese");

  printf("Hello world!\n");
  printf("Hola, c�mo est�s!\n");
  printf("Ol�!\n");

  return 0;
}
