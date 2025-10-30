#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  setlocale(LC_ALL, "portuguese");

  printf("Hello world!\n");
  printf("Hola, cómo estás!\n");
  printf("Olá!\n");

  return 0;
}
