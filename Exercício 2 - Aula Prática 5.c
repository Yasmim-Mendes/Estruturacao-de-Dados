#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
  int valor;
  struct elemento* proximo;
} Elemento;

typedef struct fila {
  Elemento* inicio;
  Elemento* fim;
} Fila;

Fila* criarFila(){
  Fila* nova_fila=(Fila*)malloc(sizeof*(Fila));

  nova_fila->inicio=NULL;
  nova_fila->fim=NULL;
  return nova_fila;
}

void liberaFila(Fila* nova_fila){
  Elemento* aux=nova_fila->inicio;

  while(aux!=NULL){
    Elemento* aux2=aux->proximo;
    free(aux);
  }
  free(nova_fila);
  nova_fila=NULL;
}

int vazia (Fila* nova_fila){
  if(nova_fila->inicio==NULL){
    return 1;
  }
  else {
    return 0;
  }
}

void enfileirar (Fila* nova_fila, int n){
  Elemento* novo_elemento=(Elemento*)malloc(sizeof*(novo_elemento));

  novo_elemento->valor=n;
  novo_elemento->proximo=NULL;
  if(vazia(nova_fila)==1){
    nova_fila->inicio=novo_elemento;
    nova_fila->fim=novo_elemento;
  }
  else {
    nova_fila->fim->proximo=novo_elemento;
    nova_fila->fim=novo_elemento;
  }
}

void desenfileirar (Fila* nova_fila){
  Elemento* aux=nova_fila->inicio;

  if(vazia(nova_fila)==1){
    printf("Fila vazia!");
  }
  else {
    nova_fila->inicio=nova_fila->inicio->proximo;
    free(aux);
    
    if(nova_fila->inicio==NULL){
      nova_fila->fim=NULL;
    }
  }
}

int main (){

  Fila* nova_fila=criarFila();

  enfileirar(nova_fila, 10);
  enfileirar(nova_fila, 20);
  enfileirar(nova_fila, 30);

  int x;
  desenfileirar(nova_fila, &x);

  liberaFila(nova_fila);
}