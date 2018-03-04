#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Opções para o menu
#define OPT_INSERIR_CONTATO 1
#define OPT_BUSCAR_POR_NOME 2
#define OPT_BUSCAR_POR_TELEFONE 3
#define OPT_MOSTRAR_AGENDA 4
#define OPT_SAIR 5
#define TAM_MENU 5

const char * MENU[] = {
  "Inserir um contato ao final da agenda.\0",
  "Buscar dados pelo Nome.\0",
  "Buscar dados pelo Telefone.\0",
  "Mostrar agenda.\0",
  "Sair.\0"
};

typedef struct Contato Contato;
struct Contato {
  char nome[50];
  char telefone[50];
  char email[50];
  Contato * prox;
};

void imprimirContato (Contato * contato);
void imprimirAgenda (Contato * agenda);
Contato * inserirContato (Contato * last);
void buscarPorNome (Contato * agenda);
void buscarPorTelefone (Contato * agenda);
void erro();
void liberarMemoria (Contato * agenda);

int menu ();

int main (int argc, char **argv) {
  // Inicializa a agenda.
  Contato * agenda = NULL, * last;

  int opt = 0;
  while (opt != OPT_SAIR) {
    opt = menu();

    switch (opt) {
      case OPT_INSERIR_CONTATO:
        last = inserirContato(last);
        if (agenda == NULL)
          agenda = last;
        break;
      case OPT_BUSCAR_POR_NOME:
        buscarPorNome(agenda);
        break;
      case OPT_BUSCAR_POR_TELEFONE:
        buscarPorTelefone(agenda);
        break;
      case OPT_MOSTRAR_AGENDA:
        imprimirAgenda(agenda);
        break;
      case OPT_SAIR:
        break;
      default:
        printf("Opção inválida, tente novamente.\n");
        break;
    }

  }

  liberarMemoria(agenda);

  return EXIT_SUCCESS;
}

void imprimirContato (Contato * contato) {
  printf("\nNome: %s\n", contato->nome);
  printf("Telefone: %s\n", contato->telefone);
  printf("E-mail: %s\n", contato->email);
}

void imprimirAgenda (Contato * agenda) {
  printf("\nAGENDA:\n\n");

  if (agenda == NULL) {
    printf("Agenda vazia.\n");
    return;
  }

  for (Contato * c = agenda; c != NULL; c = c->prox) {
    imprimirContato(c);
  }
}

Contato * inserirContato (Contato * last) {
  printf("\nNOVO CONTATO:\n\n");

  Contato * novo = malloc(sizeof(Contato));
  if (novo == NULL)
    erro();

  printf("Nome: ");
  scanf("%s", &(novo->nome));
  printf("Telefone: ");
  scanf("%s", &(novo->telefone));
  printf("E-mail: ");
  scanf("%s", &(novo->email)); 

  novo->prox = NULL;

  if (last != NULL)
    last->prox = novo;

  return novo;
}

void buscarPorNome (Contato * agenda) {
  printf("\nBUSCA POR NOME:\n\n");

  char nome[50];
  printf("Nome: ");
  scanf("%s", nome);

  for (Contato * c = agenda; c != NULL; c = c->prox) {
    if (strcmp(nome, c->nome) == 0) {
      imprimirContato(c);
      return;
    }
  }

  printf("\nNenhum resultado.\n");
}

void buscarPorTelefone (Contato * agenda) {
  printf("\nBUSCA POR TELEFONE:\n\n");

  char telefone[50];
  printf("Telefone: ");
  scanf("%s", telefone);

  for (Contato * c = agenda; c != NULL; c = c->prox) {
    if (strcmp(telefone, c->telefone) == 0) {
      imprimirContato(c);
      return;
    }
  }

  printf("\nNenhum resultado.\n");
}

void erro () {
  fprintf(stderr, "Falta de memória.\n");
  exit(1);
}

void liberarMemoria (Contato * agenda) {
  Contato * tmp;
  for (Contato * curr = agenda; curr != NULL; curr = tmp) {
    tmp = curr->prox;
    free(curr);
  }
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