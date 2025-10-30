#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 Laboratório 4 – Controlo de Fluxo
 Grupo: 3
 Elementos:
 - Gonçalo Ferreira (nº202300815)
 - Diego Laya (nº2025184378)
 - Tiago Martins (nº202001207)
 Data: 20/10/2025
 Descrição: Peça ao utilizador que introduza:
• o ângulo inicial (em graus),
• o ângulo final (em graus),
• e o passo (em graus).
O programa deve:
1. Validar que o passo é positivo e que o ângulo inicial é menor ou igual ao ângulo final;
2. Calcular, para cada ângulo no intervalo indicado, os valores de seno e cosseno;
3. Utilizar as funções sin() e cos() da biblioteca math.h, convertendo os ângulos de graus para
radianos (as funções sin() e cos() recebem o ângulo em radianos);
4. Apresentar os resultados numa tabela formatada, com os valores alinhados e apresentados com
três casas decimais.
Para implementar o cálculo repetido, utilize a instrução for.
Para obter o valor de π, utilize a constante M_PI disponível na biblioteca math.h.*/

// Exemplo de execução:
// Introduza o ângulo inicial (graus): 0
// Introduza o ângulo final (graus): 40
// Introduza o passo (graus): 10
// +--------+---------+--------+
// | Ângulo | Cosseno | Seno   |
// |--------+---------+--------|
// | 0      | 1.000   | 0.000  |
// | 10     | 0.985   | 0.174  |
// | 20     | 0.940   | 0.342  |
// | 30     | 0.866   | 0.500  |
// | 40     | 0.766   | 0.643  |
// +--------+---------+--------+
int main() {
  setlocale(LC_CTYPE, "Portuguese");

  float angulo_inicial;
  float angulo_final;
  float passo;

  printf("Introduza o ângulo inicial (graus): ");
  scanf("%f", &angulo_inicial);
  printf("Introduza o ângulo final (graus): ");
  scanf("%f", &angulo_final);
  printf("Introduza o passo (graus): ");
  scanf("%f", &passo);

  if (passo <= 0) {
    printf("Erro: o passo deve ser positivo.\n");
    return 1;
  }

  if (angulo_inicial > angulo_final) {
    printf("Erro: o ângulo inicial deve ser menor ou igual ao ângulo final.\n");
    return 1;
  }

  printf("+--------+---------+--------+\n");
  printf("| Ângulo | Cosseno | Seno   |\n");
  printf("|--------+---------+--------|\n");
  for (float angulo = angulo_inicial; angulo <= angulo_final; angulo += passo) {
    printf("|  %3.0f   |  %.3f  |  %.3f |\n", angulo, cos(angulo * M_PI / 180), sin(angulo * M_PI / 180));
  }
  printf("+--------+---------+--------+\n");
}
