#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NUM 50

// Opções para o menu
#define OPT_INSERIR_CONTATO 1
#define OPT_BUSCAR_POR_NOME 2
#define OPT_BUSCAR_POR_TELEFONE 3
#define OPT_MOSTRAR_AGENDA 4
#define OPT_SAIR 5
#define TAM_MENU 5

const char *MENU[] = {
  "Inserir um contato ao final da agenda.\0",
  "Buscar dados pelo Nome.\0",
  "Buscar dados pelo Telefone.\0",
  "Mostrar agenda.\0",
  "Sair.\0"
};

struct Contato {
  char nome[50];
  char telefone[50];
  char email[50];
};

void imprimirContato (struct Contato contato);
void imprimirAgenda (struct Contato *agenda, int n);
void inserirContato ();
void buscarPorNome ();
void buscarPorTelefone ();
int tamanho ();

int menu ();
void realizarOpcao (int opt);

struct Contato *agenda = NULL;
int ultimaPosicao = -1;

int main (int argc, char **argv) {
  // Inicializa a agenda.
  agenda = (struct Contato *) malloc(MAX_NUM * sizeof(struct Contato));

  int opt = 0;
  while (1) {
    opt = menu();
    realizarOpcao(opt);
    fflush(stdin);
    fflush(stdout);
  }

  return EXIT_SUCCESS;
}

void imprimirContato (struct Contato contato) {
  printf("\nNome: %s\n", contato.nome);
  printf("Telefone: %s\n", contato.telefone);
  printf("E-mail: %s\n", contato.email);
}

void imprimirAgenda (struct Contato *agenda, int n) {
  printf("\nAGENDA:\n\n");

  if (n == 0) {
    printf("Agenda vazia.\n");
    return;
  }

  for (int i = 0; i < n; i++) {
    imprimirContato(agenda[i]);
  }
}

void inserirContato () {
  printf("\nNOVO CONTATO:\n\n");

  ultimaPosicao++;

  printf("Nome: ");
  scanf("%s", agenda[ultimaPosicao].nome);
  printf("Telefone: ");
  scanf("%s", agenda[ultimaPosicao].telefone);
  printf("E-mail: ");
  scanf("%s", agenda[ultimaPosicao].email); 
}

void buscarPorNome () {
  printf("\nBUSCA POR NOME:\n\n");

  char nome[50];
  printf("Nome: ");
  scanf("%s", nome);

  for (int i = 0, t = tamanho(); i < t; i++) {
    if (strcmp(nome, agenda[i].nome) == 0) {
      imprimirContato(agenda[i]);
      return;
    }
  }
}

void buscarPorTelefone () {
  printf("\nBUSCA POR TELEFONE:\n\n");

  char telefone[50];
  printf("Telefone: ");
  scanf("%s", telefone);

  for (int i = 0, t = tamanho(); i < t; i++) {
    if (strcmp(telefone, agenda[i].telefone) == 0) {
      imprimirContato(agenda[i]);
      break;
    }
  }
}

int tamanho () {
  return ultimaPosicao + 1;
}

int menu () {
  printf("\nMENU:\n\n");

  for (int i = 0; i < TAM_MENU; i++) {
    printf("%d) %s\n", i + 1, MENU[i]);
  }

  int opt = 0;
  printf("\nEscolha uma opção: ");
  scanf("%d", &opt);

  return opt;
}

void realizarOpcao (int opt) {
  switch (opt) {
    case OPT_INSERIR_CONTATO:
      inserirContato();
      break;
    case OPT_BUSCAR_POR_NOME:
      buscarPorNome();
      break;
    case OPT_BUSCAR_POR_TELEFONE:
      buscarPorTelefone();
      break;
    case OPT_MOSTRAR_AGENDA:
      imprimirAgenda(agenda, tamanho());
      break;
    case OPT_SAIR:
      exit(EXIT_SUCCESS);
      break;
    default:
      printf("Opção inválida, finalizando.\n");
      exit(EXIT_FAILURE);
  }
}