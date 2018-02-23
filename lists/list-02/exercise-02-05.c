#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char * manipular (char * str, int opt);

int main (int argc, char **argv) {
  char * str = "linguagem c\0";

  printf("Minúscula: %s\n", manipular(str, -1));
  printf("Maiúscula: %s\n", manipular(str, 1));
  printf("Título: %s\n", manipular(str, 0));

  return EXIT_SUCCESS;
}

char * manipular (char * str, int opt) {
  // Contagem de caracteres na "string".
  int n;
  for (n = 0; str[n] != '\0'; n++);

  char * nStr = (char *) malloc((n + 1) * sizeof(char));
  if (nStr == NULL) {
    return NULL;
  }

  for (int i = 0; i < n; i++) {
    unsigned char c = (unsigned char) str[i];

    if (opt > 0) {
      nStr[i] = toupper(c);
    } else if (opt < 0) {
      nStr[i] = tolower(c);
    } else {
      nStr[i] = (str[i - 1] == ' ' || i == 0) ? toupper((unsigned char) str[i]) : str[i];
    }
  }

  nStr[n] = '\0';

  return nStr;
}