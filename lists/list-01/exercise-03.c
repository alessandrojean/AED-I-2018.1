#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct responsável por representar
// um segmento no painel.
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

char * converterParaHexadecimal (unsigned long long int numero);
struct Segmento ** converterParaSegmentos (char * numeroEmHexa, int n);
int charParaIndex (char c);
void imprimirRepresentacao (struct Segmento ** digitos, int n);

int main (int argc, char **argv) {
  /*unsigned long long int n1 = 11073303771280, n2 = 11259375;
  printf("%llx\n", n1);
  printf("%llx\n", n2); */

  unsigned long long int n;
  printf("Digite um número: ");
  scanf("%lld", &n);

  char * convertido = converterParaHexadecimal(n);
  int tam = strlen(convertido);

  struct Segmento ** segmentos = converterParaSegmentos(convertido, tam);

  imprimirRepresentacao(segmentos, tam);

  return EXIT_SUCCESS;
}

char * converterParaHexadecimal (unsigned long long int numero) {
  char * conversao = (char *) malloc(64 * sizeof(char));
  int tam = 0, i = 0;

  while (numero != 0) {
    // Número equivalente em hexadecimal.
    conversao[tam] = HEXADECIMAL[numero % 16];
    tam++;
    numero /= 16;
  }

  char temp;
  for (; i < tam / 2; i++) {
    temp = conversao[tam - i - 1];
    conversao[tam - i - 1] = conversao[i];
    conversao[i] = temp;
  }

  conversao[tam] = '\0';

  return conversao;
}

struct Segmento ** converterParaSegmentos (char * numeroEmHexa, int n) {
  struct Segmento ** segmentos = (struct Segmento **) malloc(n * sizeof(struct Segmento *));
  int ind = 0;

  for (int i = 0; i < n; i++) {
    ind = charParaIndex(numeroEmHexa[i]);
    segmentos[i] = &REPRESENTACOES[ind];
  }

  return segmentos;
}

int charParaIndex (char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  }

  return -1;
}

void imprimirRepresentacao (struct Segmento ** digitos, int n) {
  // Laço que cuida das 3 linhas.
  for (int i = 0; i < 3; i++) {
    // Laço que cuida de cada segmento no vetor.
    for (int j = 0; j < n; j++) {
      if (i == 0) {
        printf(digitos[j]->a ? " _ " : "   ");
      } else if (i == 1) {
        printf("%c%c%c", 
          digitos[j]->f ? '|' : ' ',
          digitos[j]->g ? '_' : ' ',
          digitos[j]->b ? '|' : ' '
        );
      } else {
        printf("%c%c%c", 
          digitos[j]->e ? '|' : ' ',
          digitos[j]->d ? '_' : ' ',
          digitos[j]->c ? '|' : ' '
        );
      }
      printf(" ");
    }
    printf("\n");
  }
}