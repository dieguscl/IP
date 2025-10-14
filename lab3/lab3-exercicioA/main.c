#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

/*
 Laboratório 3 – Introdução à Programação em C
 Grupo: 3
 Elementos:
 - Gonçalo Ferreira (nº202300815)
 - Diego Laya (nº2025184378)
 - Tiago Martins (nº202001207)
 Data: 13/10/2025
 Descrição: Peça ao utilizador três notas (0–20), calcule a média e indique se o aluno está aprovado (média ≥
10) ou reprovado. Use cast na divisão, se necessário.
*/

int main() {
    setlocale(LC_ALL, "Portuguese");
    float n1, n2, n3, media;
    printf("Insira 3 notas (0–20)\n");
    scanf("%f", &n1);
    scanf("%f", &n2);
    scanf("%f", &n3);
    media = (n1 + n2 + n3) / 3;
    printf("%.2f\n", media);
    if(media>=10) {
      printf("O aluno está aprovado");
    } else {
      printf("O aluno está reprovado");
    }

    return 0;
}
