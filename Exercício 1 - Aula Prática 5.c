#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
  int valor;
  struct elemento *anterior;
} Elemento;

typedef struct pilha {
  Elemento *topo;
} Pilha;

Pilha* criarPilha(){
  Pilha* nova_pilha=(Pilha*)malloc(sizeof(Pilha));

  nova_pilha->topo=NULL;
  return nova_pilha;
}

void liberarPilha(Pilha* nova_pilha){
  Elemento* atual=nova_pilha->topo;
  Elemento* proximo;

  while (atual!=NULL){
    proximo=atual->anterior;
    free(atual);
    atual=proximo;
  }

  free(nova_pilha);
}

int vazia (Pilha* nova_pilha){
  if (nova_pilha->topo==NULL){
    return 1;
  }
  else {
    return 0;
  }
}

void empilha (Pilha* nova_pilha, int n){
  Elemento* novo_elemento=(Elemento*)malloc(sizeof*(Elemento));
  novo_elemento->valor=n;
  novo_elemento->anterior=nova_pilha->topo;
  nova_pilha->topo=novo_elemento;
}

void desempilha (Pilha*nova_pilha){
  Elemento* atual=nova_pilha->topo;

  if (atual!=NULL){
    nova_pilha->topo=atual->anterior;
    free(atual);
    atual=nova_pilha->topo;
  }
}


int main() {
  
  Pilha* nova_pilha=criarPilha();

  empilha(nova_pilha, 10);
  empilha(nova_pilha, 20);
  empilha(nova_pilha, 30);

  printf("Pilha vazia?\n");
  if (vazia(nova_pilha)==1){
    printf ("Sim\n");
  }
  else {
    printf ("Não\n");
  }

  printf("Desempilhando elemento: %d\n", nova_pilha->topo->valor);
  desempilha(nova_pilha);

  printf("Desempilhando elemento: %d\n", nova_pilha->topo->valor);
    desempilha(nova_pilha);

  printf("Desempilhando elemento: %d\n", nova_pilha->topo->valor);
  desempilha(nova_pilha);

  liberarPilha(nova_pilha);

  return 0;
}