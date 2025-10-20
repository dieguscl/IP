#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*
 Laboratório 4 – Controlo de Fluxo
 Grupo: 3
 Elementos:
 - Gonçalo Ferreira (nº202300815)
 - Diego Laya (nº2025184378)
 - Tiago Martins (nº202001207)
 Data: 20/10/2025
 Descrição: Peça ao utilizador a altura em metros e o peso em kg. Calcule o IMC: `imc = peso / (altura * altura)` e
apresente o valor do IMC com uma casa decimal, juntamente com a classificação correspondente:
• IMC < 18.5 → Baixo peso
• 18.5 ≤ IMC < 25.0 → Peso normal
• 25.0 ≤ IMC < 30.0 → Excesso de peso
• 30.0 ≤ IMC < 35.0 → Obesidade I
• 35.0 ≤ IMC < 40.0 → Obesidade II
• IMC ≥ 40.0 → Obesidade III
*/

// imc = peso / (altura * altura)
int main (){
setlocale(LC_CTYPE, "Portuguese");
float altura;
float peso;
float imc;
int classificacao;

printf("Insira a sua altura(m): ");
scanf("%f", &altura);
printf("Insira o seu peso(kg): ");
scanf("%f", &peso);
imc = peso / (altura*altura);
printf("%.1f", imc);
if(imc<18.5){
  classificacao="Baixo Peso";
} else if (imc >=18.5 && imc <25.0){
  classificacao="Peso Normal";
}
printf("%s", classificacao);
}
