#include <locale.h>
#include <stdio.h>

int main() {
  setlocale(LC_ALL, "Portuguese");
  printf("Bem-vindo à disciplina de Introdução à Programação!\n");
  printf("Vamos começar a programar em C.\n");
  printf("Gonçalo Ferreira, nº202300815\n");
  printf("Diego Laya, nº2025184378\n");
  printf("Tiago Martins, nº202001207\n");
  return 0;
}
