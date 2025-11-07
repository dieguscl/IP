#include <locale.h>
#include <stdio.h>

/*
 Laboratório 6 Subprogramas
 Grupo: 3
 Elementos:
 - Gonçalo Ferreira (nº202300815)
 - Diego Laya (nº2025184378)
 - Tiago Martins (nº202001207)
 Descrição: Exercício 2, 3 e 4
*/

int apresentarMenu(void);
void verificarPrimo(void);
int mdc(int a, int b);
void mdcUsuario(void);
void mmc(void);
void media10(void);
void eCapicua(void);
int inverterNumero(int num);
void inverterNumeroUsuario(void);
void verificarPrimosIntervalo(void);

void trocar(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main(void) {
  int opcao;
  setlocale(LC_CTYPE, "Portuguese");

  do {
    opcao = apresentarMenu();

    switch (opcao) {
      case 1:
        mdcUsuario();
        break;
      case 2:
        mmc();
        break;
      case 3:
        media10();
        break;
      case 4:
        inverterNumeroUsuario();
        break;
      case 5:
        eCapicua();
        break;
      case 6:
        verificarPrimo();
        break;
      case 7:
        verificarPrimosIntervalo();
        break;
      case 0:
        printf("A terminar o programa...\n");
        break;
      default:
        printf("Opção inválida!\n");
    }

  } while (opcao != 0);

  return 0;
}

int apresentarMenu(void) {
  int opcao;

  printf("\n\n                    OPERAÇÕES NUMÉRICAS                  \n\n");
  printf("1 - Calcular o máximo divisor comum de dois números naturais\n");
  printf("2 - Calcular o mínimo múltiplo comum de dois números naturais\n");
  printf("3 - Calcular a média de 10 números naturais\n");
  printf("4 - Inverter os algarismos de um número inteiro\n");
  printf("5 - Verificar se um número inteiro é uma capicua\n");
  printf("6 - Verificar se um número inteiro é primo\n");
  printf(
      "7 - Mostrar todos os números primos existentes num determinado "
      "intervalo\n");
  printf("0 - Terminar o programa\n");
  printf("Qual a sua opção: ");
  scanf("%d", &opcao);

  return opcao;
}

int pedirNumeroNatural(char str[]) {
  int n;
  do {
    printf("%s", str);
    scanf("%d", &n);
    if (n <= 0) {
      printf("%d é inválido, deve ser um número natural\n", n);
    }
  } while (n <= 0);
  return n;
}

int mdc(int a, int b) {
  int mdc, resto;

  // Verificar que a seja o major entre a e b
  if (a < b) {
    trocar(&a, &b);
  }

  do {
    resto = a % b;
    a = b;
    b = resto;
  } while (resto != 0);

  mdc = a;
  return mdc;
}

void mdcUsuario() {
  int a, b, valorMdc;

  a = pedirNumeroNatural("Insira o primer número:\n");
  b = pedirNumeroNatural("Insira o segundo número:\n");

  valorMdc = mdc(a, b);
  printf("O máximo divisor comum de %d e %d é %d\n", a, b, valorMdc);
}

void mmc() {
  int mmc;
  int a, b;

  a = pedirNumeroNatural("Insira o primeiro número:\n");
  b = pedirNumeroNatural("Insira o segundo número:\n");

  mmc = (a / mdc(a, b)) * b;
  printf("O mínimo múltiplo comum de %d e %d é %d\n", a, b, mmc);
}

void media10() {
  float media;
  int soma = 0;
  int a, i;

  for (i = 0; i < 10; i++) {
    a = pedirNumeroNatural("Insira um número natural:\n");
    soma += a;
  }

  printf("A média dos 10 números é: %d\n", soma / 10);
}

int inverterNumero(int num) {
  int reverso = 0;
  int digito;

  while (num != 0) {
    digito = num % 10;
    reverso = reverso * 10 + digito;
    num /= 10;
  }

  return reverso;
}

void inverterNumeroUsuario(void) {
  int n, nInvertido;
  n = pedirNumeroNatural("Insira um número natural:\n");
  nInvertido = inverterNumero(n);
  printf("O número invertido é: %d\n", nInvertido);
}

int ePrimo(int n) {
  for (int i = 2; i <= n - 1; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

void eCapicua() {
  int n;
  n = pedirNumeroNatural("Insira um número natural:\n");

  if (n == inverterNumero(n)) {
    printf("%d é capicua\n", n);
  } else {
    printf("%d não é capicua\n", n);
  }
}

void verificarPrimo(void) {
  int n, i;
  n = pedirNumeroNatural("Insira um número natural:\n");
  int resultado = ePrimo(n);
  if (resultado == 1) {
    printf("%d é primo\n", n);
  } else {
    printf("%d Não é primo\n", n);
  }
}

void verificarPrimosIntervalo(void) {
  int a, b, temPrimos = 0;
  a = pedirNumeroNatural("Insira o primeiro número:\n");
  b = pedirNumeroNatural("Insira o segundo número:\n");

  printf("Os números primos entre %d e %d são: ", a, b);
  for (int i = a; i <= b; i++) {
    if (ePrimo(i) == 1) {
      temPrimos++;
      printf("%d ", i);
    }
  }
  if (temPrimos == 0) {
    printf("Não há");
  }
}
