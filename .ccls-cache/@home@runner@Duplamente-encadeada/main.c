#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct no_ no;
struct no_ {
  int valor;
  no *prox;
  no *ant;
};

/**
 *
 * @param cabeca = endereco do no cabeca.
 * @param valor = valor a ser inserido.
 * @return 1 caso seja possivel inserir, e 0 caso contrario.
 *
 */
int inserir(no *cabeca, int valor) {
  no *ptr;
  ptr = cabeca;
  while (ptr->prox != NULL && valor > ptr->prox->valor) {
    ptr = ptr->prox;
  }
  if (ptr->prox->valor == valor) {
    return 0;
  }
  no *p = malloc(sizeof(no));
  p->valor = valor;
  p->prox = ptr->prox;
  if(ptr->prox != NULL){
  ptr->prox->ant = p;}
  p->ant = ptr;
  ptr->prox = p;
  return 1;
}


int inserir2(no *cabeca, int valor) {
  no *ptr = malloc(sizeof(no));
  no *p = malloc(sizeof(no));
  ptr = cabeca;

  while (ptr->prox != NULL && valor > ptr->prox->valor) {
    ptr = ptr->prox;
  }
  p->prox = ptr->prox;
  if (ptr->prox != NULL) {
    ptr->prox->ant = p;
  }
  p->ant = ptr;
  ptr->prox = p;
  p->valor = valor;
 
  return 1;
}

// TODO: implemente a funcao inserir.
// O cabecalho da funcao nao pode ser alterado.

/**
 *
 * @param cabeca = endereco do no cabeca.
 * @param valor = valor a ser removido.
 * @return = ponteiro para o no removido, ou NULL caso nao seja possivel
 * remover.
 */
no *remover(no *cabeca, int valor) {
  no *ptr;
  no* rem;
  ptr = cabeca;
  
  while (ptr->prox != NULL) {
    rem = ptr->prox;
    if (ptr->prox->valor == valor) {
      if(rem->prox != NULL){
      rem->prox->ant = ptr;
      }
      ptr->prox = rem->prox;
      return rem;
    }
    ptr = ptr->prox;
  }
  return NULL;
}

/**
 *
 * @param cabeca = endereco do no cabeca.
 */
void escrever(no *cabeca) {
  printf("[");
  no *atual = cabeca->prox;

  while (atual != NULL) {
    printf("%d", atual->valor);
    if (atual->prox != NULL)
      printf(" -> ");

    atual = atual->prox;
  }
  printf("]\n\n");
}

/**
 *
 * @param cabeca = endereco do no cabeca.
 */
void desaloca_lista(no *cabeca) {
  while (cabeca != NULL) {
    no *n = cabeca;
    cabeca = cabeca->prox;
    free(n);
  }
}

/**
 *
 * @return = ponteiro para o no cabeca alocado.
 */
no *aloca_no_cabeca() {
  no *cabeca = malloc(sizeof(no));
  cabeca->prox = NULL;
  cabeca->ant = NULL;
  return cabeca;
}

int main() {
  no *cabeca = aloca_no_cabeca();
  no *n;
  cabeca->valor = 0;

  int valor;
  int ans = 0;
  printf("\nOpções:\n0 -> inserir\n1 -> remover\n2 -> escrever\n3 -> sair\n");
  do {
    // Opcoes:
    // 0 -> inserir
    // 1 -> remover
    // 2 -> escrever
    // 3 -> sair

    scanf("%d", &ans);

    switch (ans) {
      // inserir
    case 0:
      scanf("%d", &valor);
      inserir(cabeca, valor);
      printf("Feito!\n");

      break;
      // remover
    case 1:
      scanf("%d", &valor);
      n = remover(cabeca, valor);
      printf("Feito!\n");
      if (n != NULL) {
        free(n);
      }

      break;
      // escrever
    case 2:
      escrever(cabeca);
      printf("Feito!\n");

      break;
      // sair
    case 3:
      desaloca_lista(cabeca);
      printf("Tchau!\n");

      break;
    default:

      break;
    }
  } while (ans != 3);

  return (0);
}