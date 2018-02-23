#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
  char *s1   = "Linguagem C";
  char *s2 = "Linguagem C";
  printf("%s\n", s1); 
  printf("%s\n", s2);
  printf(s1);
  printf(s2);
  printf(s1+2);
  printf("%c", *(s1+2));                  // O resultado dessa aritmética de ponteiros
                                          // retornará um char, porém o printf aceita
                                          // somente "strings".
  printf(&s2[2]);
  printf(s2+2);
  printf("%c", s2[2]);                    // O resultado dará um char, necessário formatar
                                          // no printf para funcionar.
  printf("%c", s1[2]);                    // Mesmo caso da linha anterior.
  s1 += 4; 
  s1++;
  s2 += 4;                                // A variável s2 é um vetor, portanto não é possível
                                          // fazer aritmética de ponteiros, seria necessário
                                          // declará-la com char * s2 para funcionar.
  s2++;

  char *s3 = "Linguagem", *s4, *s5;       // É necessário especificar um tamanho para s4.
  s3 = s4; 
  s2 = s5;
  s5 = "Linguagem C";                     // Seria necessário declarar s5 como um ponteiro para
                                          // isto funcionar.
  s5 = s3;

  return EXIT_SUCCESS;
}