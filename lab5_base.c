#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

int apresentarMenu(void);
int fatorialInt(int n);   // cálculo com int (fase A)
double fatorial(int n);   // cálculo com double (fase B)
void opcaoFatorial(void); // interface
void opcaoNumPar(void);
void opcaoPosOuNeg(void);
void opcaoCombinacoes(void);
void opcaoFibonacci(void);
void opcaoBinarioADecimal(void);
int pedirNumeroPositivo(char str[]);
int pedirNumeroPositivoComZero(char str[]);

int main(void)
{
    int opcao;

    setlocale(LC_CTYPE, "Portuguese");

    do {
        opcao = apresentarMenu();

        switch(opcao) {
        case 1:
            opcaoFatorial(); // chamada da função de interface
            break;
        case 2:
            opcaoNumPar();
            break;
        case 3:
            opcaoPosOuNeg();
            break;
        case 4:
            opcaoCombinacoes();
            break;
        case 5:
            opcaoFibonacci();
            break;
        case 6:
            opcaoBinarioADecimal();
            break;
        case 0:
            printf("A terminar o programa...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }

    } while(opcao != 0);

    return 0;
}

int apresentarMenu(void)
{
    int opcao;

    printf("\nMENU\n");
    printf("1. Calcular fatorial de n\n");
    printf("2. Imprimir números pares até n\n");
    printf("3. Verificar se um número é positivo\n");
    printf("4. Calcular combinações C(n, p)\n");
    printf("5. Imprimir os n primeiros termos de Fibonacci\n");
    printf("6. Converter um número binário para decimal\n");
    printf("0. Terminar\n");
    printf("Qual a sua opção: ");
    scanf("%d", &opcao);

    return opcao;
}

int fatorialInt(int n)
{
    int resultado;
    int i;
    resultado = 1;


    for (i = 2; i <= n; i++)
        resultado *= i;


    return resultado;
}


double fatorial(int n)
{
    double resultado;
    int i;
    resultado = 1.0;


    for (i = 2; i <= n; i++)
        resultado *= i;


    return resultado;
}


void opcaoFatorial(void)
{
    int n;
    int rInt; // resultado em int
    double rD; // resultado em double


    do {
        printf("Introduza um número inteiro não negativo: ");
        scanf("%d", &n);
        if (n < 0)
            printf("Valor inválido! Tente novamente.\n");
    } while (n < 0);


    rInt = fatorialInt(n);
    printf("[INT] %d! = %d (pode ocorrer overflow para n >= 13)\n", n, rInt);


    rD = fatorial(n);
    printf("[DOUBLE] %d! = %.0f\n", n, rD);
}

void opcaoNumPar(void) {
  int n;
  int i;

  n = pedirNumeroPositivo("Insira um numero inteiro positivo: ");

  for (i = 0; i <= n; i++) {
    if(i % 2 == 0) {
        printf("%d ", i);
    }
  }
}

void opcaoPosOuNeg(void) {
  int n;
  printf("Insira um numero inteiro: ");
  scanf("%d", &n);


}

// n! / ( p! * (n - p)! )
void opcaoCombinacoes(void) {
    int n;
    int p;
    double resultado;

    // Diga o numero de elementos que é preciso permutar
    n = pedirNumeroPositivoComZero("Insira o número de elementos que é preciso permutar: ");

    // Diga o tamanho do conjunto
    p = pedirNumeroPositivoComZero("Insira o tamanho do conjunto: ");

    // Calcular combinacao
    resultado = fatorial(n)/(fatorial(p)*fatorial(n-p));
    printf ("O resultado da combinação é: %.0f", resultado);
}

void opcaoFibonacci(void) {
    int n;
    double a = 0;
    double b = 1;
    double c;
    int i;

    n = pedirNumeroPositivo("Insira um número inteiro positivo: ");

    for(i = 0; i < n; i++) {
        printf("%.0f ", a);
        c = a + b;
        a = b;
        b = c;
    }

}

void opcaoBinarioADecimal(void) {
  char bin[20];
  int decimal;
  int i;
    
  printf("Insira um número binário: ");
  scanf("%s", bin);
  decimal = 0;

  int len = strlen(bin);
  for(i = 0; i < len; i++) {
    if (bin[i] != '0' && bin[i] != '1') {
       printf("Error: Entrada inválida.\n");
       return;
    }

    // '0' é representado por 48 e '1' por 49 (ASCII)
    // '1' - '0' = 49 - 48 = 1
    // '0' - '0' = 48 - 48 = 0
    int digito = bin[i] - '0';

    decimal += digito * pow(2, len - i - 1);
  }
  printf("O número decimal é: %d\n", decimal);
}

int pedirNumeroPositivo(char str[]) {
  int n;
  do {
    printf("%s", str);
    scanf("%d", &n);
    if (n <= 0) {
      printf("%d é inválido\n", n);
    }
  } while (n <= 0);
  return n;
}

int pedirNumeroPositivoComZero(char str[]) {
  int n;
  do {
    printf("%s", str);
    scanf("%d", &n);
    if (n < 0) {
      printf("%d é inválido\n", n);
    }
  } while (n < 0);
  return n;
}


