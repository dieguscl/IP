#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

/*
 Laboratório 3  Introdução à Programação em C
 Grupo: 3
 Elementos:
 - Gonçalo Ferreira (nº202300815)
 - Diego Laya (nº2025184378)
 - Tiago Martins (nº202001207)
 Data: 13/10/2025
 Descrição: Leia três números inteiros e apresente o maior, o menor e a média aritmética dos três.
*/

// A temperatura em Fahrenheit (F): F = (9.0 / 5.0) * C + 32
// A temperatura em Kelvin (K): K = C + 273.15

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float n1, n2, n3;
    printf("Insira três números inteiros:\n");
    scanf("%f", &n1);
    scanf("%f", &n2);
    scanf("%f", &n3);

    float max, min, media;
    if (n1 > n2) {
        max = n1;
        min = n2;
    } else {
        max = n2;
        min = n1;
    }
    if (max < n3) {
        max = n3;
    } else if (min > n3) {
        min = n3;
    }

    media = (n1 + n2 + n3) / 3;

    printf("O maior é %.2f, o menor é %.2f e a média é %.2f", max, min, media);

    return 0;
}
