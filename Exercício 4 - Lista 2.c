//Desenvolva uma função para inverter a posição dos elementos de uma pilha P.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct pilha{
  int topo;
  int vetor[MAX];
} Pilha;

Pilha* criarPilha(){
  Pilha* nova_pilha=(Pilha*)malloc(sizeof(Pilha));

  if (nova_pilha==NULL){
    printf("Erro: Falha ao alocar memória para a pilha\n");
    exit(EXIT_FAILURE);
  }

  nova_pilha->topo=-1;
  return nova_pilha;
}

void libera(Pilha* pilha){
  free(pilha);
}

int vazia(Pilha* pilha){
  return (pilha->topo==-1);
}

int cheia(Pilha* pilha){
  return (pilha->topo==MAX-1);
}

int empilhar(Pilha* pilha, int n){
  if (cheia(pilha)==1){
    return -1;
  } 
  else {
    pilha->topo++;
    pilha->vetor[pilha->topo]=n;
    return n;
  }
}

int desempilhar(Pilha* pilha){
  if (vazia(pilha)==1){
    return -1;
  } 
  else {
    int elemento=pilha->vetor[pilha->topo];
    pilha->topo--;
    return elemento;
  }
}

void inverte(Pilha* pilha){
  int temp[MAX];
  int i=0;

  while (!vazia(pilha)){
    temp[i++]=desempilhar(pilha);
  }

  for (int j=0; j<i; j++){
    empilhar(pilha, temp[j]);
  }
}

int main(){
  Pilha* pilha=criarPilha();

  for (int i=1; i<=10; i++){
    empilhar(pilha, i);
  }

  printf("Pilha original:\n");
  for (int i=0; i<=pilha->topo; i++){
    printf("%d\n", pilha->vetor[i]);
  }

  inverte(pilha);

  printf("Pilha invertida:\n");
  for (int i=0; i<=pilha->topo; i++){
    printf("%d\n", pilha->vetor[i]);
  }

  libera(pilha);

  return 0;
}