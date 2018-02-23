#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * concatenar(char * str1, char * str2);

int main (int argc, char **argv) {
  char * str1 = "Linguagem\0", * str2 = "C\0";
  char * str3 = concatenar(str1, str2);

  printf("Após a concatenação: %s\n", str3);

  return EXIT_SUCCESS;
}

char * concatenar(char * str1, char * str2) {
  int n1 = strlen(str1), n2 = strlen(str2);
  
  char * str = (char *) malloc((n1 + n2 + 1) * sizeof(char));
  if (str == NULL) {
    return NULL;
  }

  int i, j;
  for (i = 0; i < n1; i++) {
    str[i] = str1[i];
  }
  for (j = 0; j < n2; j++) {
    str[i + j] = str2[j];
  }

  str[i + j] = '\0';

  return str;
}