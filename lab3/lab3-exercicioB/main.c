#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

/*
 Laborat�rio 3 � Introdu��o � Programa��o em C
 Grupo: 3
 Elementos:
 - Gon�alo Ferreira (n�202300815)
 - Diego Laya (n�2025184378)
 - Tiago Martins (n�202001207)
 Data: 13/10/2025
 Descri��o: Leia uma temperatura em graus Celsius e apresente o valor em
Fahrenheit e Kelvin. Com duas casas decimais.
*/

// A temperatura em Fahrenheit (F): F = (9.0 / 5.0) * C + 32
// A temperatura em Kelvin (K): K = C + 273.15

int main() {
  float celsius, faren, kelvin;
  printf("Insira uma temperatura em Celsius:\n");
  scanf("%f", &celsius);

  faren = (9.0 / 5.0) * celsius + 32;
  kelvin = celsius + 273.15;
  printf("%.2f Celsius em Kelvin � %.2f e em Farenheif � %.2f", celsius, kelvin,
         faren);
  return 0;
}
