//Considere uma pilha que armazene caracteres. Escreva uma função que verifique se uma palavra é um palíndromo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct pilha {
  int topo;
  char vetor[MAX];
}Pilha;

Pilha* criarPilha(){
  Pilha* nova_pilha=(Pilha*)malloc(sizeof(Pilha));

  nova_pilha->topo=-1;
  return nova_pilha;
}

int vazia (Pilha* pilha){
  if (pilha->topo==-1){
    return 1;
  }
  else {
    return 0;
  }
}

int cheia (Pilha* pilha){
  if (pilha->topo==MAX-1){
    return 1;
  }
  else {
    return 0;
  }
}

int empilha (Pilha* pilha, char n){
  if (cheia(pilha)==1){
    return -1;
  }
  else {
    pilha->topo++;
    pilha->vetor[pilha->topo]=n;
    return n;
  }
}

int desempilha (Pilha* pilha){
  if (vazia(pilha)==1){
    return -1;
  }
  else {
    pilha->topo--;
    return pilha->vetor[pilha->topo+1];
  }
}

int palindromo (char palavra[]){
  Pilha* pilha=criarPilha();
  Pilha* invertida=criarPilha();
  int tam=strlen(palavra);

  for (int i=0; i<tam; i++){
    empilha(pilha, palavra[i]);
  }

  for (int j=0; j<tam; j++){
    if (desempilha(pilha)!=palavra[j]){
      return 0;
    }
    else {
      return 1;
    }
  }
}

int main (){
  char palavra[MAX];

  printf ("Informe uma palavra: ");
  scanf ("%s", palavra);

  if (palindromo(palavra)==1){
    printf ("Essa palavra é um palíndromo!\n");
  }
  else {
    printf("Essa palavra não é um palíndromo.\n");
  }

  return 0;
}