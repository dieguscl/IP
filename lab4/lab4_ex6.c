#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

/*
 Laboratório 4 – Controlo de Fluxo
 Grupo: 3
 Elementos:
 - Gonçalo Ferreira (nº202300815)
 - Diego Laya (nº2025184378)
 - Tiago Martins (nº202001207)
 Data: 20/10/2025
 Descrição: Peça ao utilizador que introduza números inteiros positivos.
A leitura termina quando o utilizador introduzir o valor zero.
Durante a leitura:
• Se o número for positivo, deve ser incluído no cálculo da soma, da média e da contagem de
valores válidos.
• Se o número for negativo, o programa deve apresentar uma mensagem de aviso e ignorar o
valor.
No final, o programa deve apresentar:
- Página 4 de 4 -
• a quantidade de números válidos introduzidos,
• a soma desses números,
• e a média, apresentada com duas casas decimais.
Caso não tenha sido inserido nenhum número válido, deve apresentar a mensagem: Sem dados válidos.
Para implementar a leitura repetida, utilize a instrução do...while
*/

// Exemplo de execução:
// Introduza um número inteiro positivo (0 para terminar): 5
// Introduza um número inteiro positivo (0 para terminar): 12
// Introduza um número inteiro positivo (0 para terminar): -4
// Valor inválido (ignorado).
// Introduza um número inteiro positivo (0 para terminar): 9
// Introduza um número inteiro positivo (0 para terminar): 0
// Foram introduzidos 3 números válidos.
// Soma = 26
// Média = 8.67
int main() {
  setlocale(LC_CTYPE, "Portuguese");

  int soma = 0;
  int contador = 0;
  float media = 0;
  int numero;

  do {
    printf("Introduza um número inteiro positivo (0 para terminar): ");
    scanf("%d", &numero);
    if (numero > 0) {
      soma += numero;
      contador++;
      media = (float)soma / contador;
    } else if (numero < 0) {
      printf("Valor inválido (ignorado).\n");
    }
  } while (numero != 0);

  if (contador == 0) {
    printf("Sem dados válidos.\n");
  } else {
    printf("Foram introduzidos %d números válidos.\n", contador);
    printf("Soma = %d\n", soma);
    printf("Média = %.2f\n", media);
  }
}
