#include<stdio.h>
#include<stdlib.h>

// Struct responsável por representar
// um segmento no painel.
typedef struct Segmento Segmento;
struct Segmento {
  int a;
  int b;
  int c;
  int d;
  int e;
  int f;
  int g;
  char digit;
};

typedef struct Digito Digito;
struct Digito {
  Segmento * segmento;
  Digito * prox;
};

struct Segmento REPRESENTACOES[] = {
  { 1, 1, 1, 1, 1, 1, 0 }, // 0 (i =  0)
  { 0, 1, 1, 0, 0, 0, 0 }, // 1 (i =  1)
  { 1, 1, 0, 1, 1, 0, 1 }, // 2 (i =  2)
  { 1, 1, 1, 1, 0, 0, 1 }, // 3 (i =  3)
  { 0, 1, 1, 0, 0, 1, 1 }, // 4 (i =  4)
  { 1, 0, 1, 1, 0, 1, 1 }, // 5 (i =  5)
  { 1, 0, 1, 1, 1, 1, 1 }, // 6 (i =  6)
  { 1, 1, 1, 0, 0, 0, 0 }, // 7 (i =  7)
  { 1, 1, 1, 1, 1, 1, 1 }, // 8 (i =  8)
  { 1, 1, 1, 1, 0, 1, 1 }, // 9 (i =  9)
  { 1, 1, 1, 0, 1, 1, 1 }, // A (i = 10)
  { 0, 0, 1, 1, 1, 1, 1 }, // b (i = 11)
  { 1, 0, 0, 1, 1, 1, 0 }, // C (i = 12)
  { 0, 1, 1, 1, 1, 0, 1 }, // d (i = 13)
  { 1, 0, 0, 1, 1, 1, 1 }, // E (i = 14)
  { 1, 0, 0, 0, 1, 1, 1 }, // F (i = 15)
};

const char HEXADECIMAL[] = "0123456789abcdef";

Digito * converterParaHexadecimal (unsigned long long int numero);
void imprimirRepresentacao (Digito * digitos);
void erro();
void liberarMemoria (Digito * digitos);

int main (int argc, char **argv) {
  /*unsigned long long int n1 = 11073303771280, n2 = 11259375;
  printf("%llx\n", n1);
  printf("%llx\n", n2); */

  unsigned long long int n;
  printf("Digite um número: ");
  scanf("%lld", &n);

  Digito * digitos = converterParaHexadecimal(n);

  imprimirRepresentacao(digitos);

  liberarMemoria(digitos);

  return EXIT_SUCCESS;
}

Digito * converterParaHexadecimal (unsigned long long int numero) {
  Digito * digitos = NULL, * tmp;
  int i = 0;

  while (numero != 0) {
    tmp = malloc(sizeof(Digito));
    if (tmp == NULL)
      erro();

    // Número equivalente em hexadecimal.
    tmp->segmento = &(REPRESENTACOES[numero % 16]);

    if (digitos == NULL)
      tmp->prox = NULL;
    else
      tmp->prox = digitos;

    digitos = tmp;

    numero /= 16;
  }

  return digitos;
}

void imprimirRepresentacao (Digito * digitos) {
  // Laço que cuida das 3 linhas.
  for (int i = 0; i < 3; i++) {
    // Laço que cuida de cada segmento na lista ligada.
    for (Digito * c = digitos; c != NULL; c = c->prox) {
      if (i == 0) {
        printf(c->segmento->a ? " _ " : "   ");
      }else if (i == 1) {
        printf("%c%c%c", 
          c->segmento->f ? '|' : ' ',
          c->segmento->g ? '_' : ' ',
          c->segmento->b ? '|' : ' '
        );
      } else {
        printf("%c%c%c", 
          c->segmento->e ? '|' : ' ',
          c->segmento->d ? '_' : ' ',
          c->segmento->c ? '|' : ' '
        );
      }
      printf(" ");
    }
    printf("\n");
  }
}

void erro () {
  fprintf(stderr, "Falta de memória.\n");
  exit(1);
}

void liberarMemoria (Digito * digitos) {
  Digito * tmp;
  for (Digito * curr = digitos; curr != NULL; curr = tmp) {
    tmp = curr->prox;
    free(curr);
  }
}