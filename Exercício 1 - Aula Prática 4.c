//Implemente as operações presentes em um TAD Pilha estática; Implemente uma função main que faça uso das operações desenvolvidas anteriormente.

#include <stdio.h>
#include <stdlib.h>

struct pilha {
  int topo;
  int vetor[100];
};


struct pilha* criaPilha (){
  struct pilha* nova_pilha=(struct pilha*)malloc(sizeof(struct pilha));
  nova_pilha->topo=-1;
  return nova_pilha;
}
 
int vazio (struct pilha* pilha){
  if (pilha->topo==-1){
    return -1;
  }
  else {
    return 1;
  }
}

int cheio (struct pilha* pilha){
  if (pilha->topo==100-1){
    return 1;
  }
  else {
    return 0;
  }
}

int empilha (struct pilha* pilha, int n){
  if (cheio(pilha)==1){
    printf ("ERRO! Pilha cheia");
    return -1;
  }
  else {
    pilha->topo++;
    pilha->vetor[pilha->topo]=n;
    return n;
  }
}

int desempilhar (struct pilha* pilha){
  if (vazio(pilha)==-1){
    printf ("ERRO! Pilha vazia");
    return -1;
  }
  else {
    pilha->topo--;
    int n_removido=pilha->vetor[pilha->topo];
    return n_removido;
  }
}

void liberaPilha (struct pilha* pilha){
  free(pilha);
}

int main (){
  struct pilha* pilha;
  int q, n;

  pilha=criaPilha();

  printf("Informe quantos números serão adicionados à pilha: ");
  scanf ("%d", &q);

  for (int i=0; i<q; i++){
    printf ("Informe um número para adicionar à pilha: ");
    scanf ("%d", &n);

    empilha (pilha, n);
  }
  printf ("\nNúmero atual no topo: %d", pilha->topo);

  printf ("\nNúmero removido do topo: %d", desempilhar(pilha));
  printf ("\nNúmero atual no topo: %d", pilha->topo);

  liberaPilha(pilha);

  return 0;
}