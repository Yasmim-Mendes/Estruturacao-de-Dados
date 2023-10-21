#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct pilha {
  int topo;
  int vetor[MAX];
}Pilha;

Pilha* criarPilha(){
  Pilha* nova_pilha=(Pilha*)malloc(sizeof(Pilha));

  if (nova_pilha==NULL){
    printf("Erro: Falha ao alocar memória para a pilha.\n");
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

int empilha(Pilha* pilha, int n){
  if (cheia(pilha)==1){
    return -1;
  }
  else {
    pilha->topo++;
    pilha->vetor[pilha->topo]=n;
    return n;
  }
}

int desempilha(Pilha* pilha){
  if (vazia(pilha)==1){
    return -1;
  }
  else {
    int elemento=pilha->vetor[pilha->topo];
    pilha->topo--;
    return elemento;
  }
}

void mmm(Pilha* pilha, int* maior, int* menor, float* media){
  int i, soma=0;

  *maior=pilha->vetor[0];
  *menor=pilha->vetor[0];

  for (i=0; i<=pilha->topo; i++){
    if (pilha->vetor[i]>*maior){
      *maior=pilha->vetor[i];
    }

    if (pilha->vetor[i]<*menor){
      *menor=pilha->vetor[i];
    }

    soma+=pilha->vetor[i];
  }

  *media=(float)soma/(pilha->topo+1);
}

int main(){
  Pilha* pilha=criarPilha();
  int tam;
  int n;
  int maior=0;
  int menor=0;
  float media=0;

  printf("Informe quantos números serão empilhados: ");
  scanf("%d", &tam);

  for (int i=0; i<tam; i++){
    printf("Informe um número: ");
    scanf("%d", &n);

    empilha(pilha, n);
  }

  mmm(pilha, &maior, &menor, &media);
  printf("Maior número: %d\nMenor número: %d\nMédia aritmética: %.2f\n", maior, menor, media);

  libera(pilha);

  return 0;
}
