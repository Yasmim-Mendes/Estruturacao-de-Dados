//Faça um programa que contenha as seguintes funções: •Uma função main que vá utilizar as demais funções criadas; •Uma função de busca sequencial para buscar um determinado valor em um vetor de inteiros, cujo tamanho será definido pelo usuário, usando alocação dinâmica de memória. O vetor deve ser preenchido pelo usuário; •Da mesma forma que a função acima, crie agora uma função de busca binária. •Crie uma struct “aluno” contendo os membros: nome, matricula, nota1, nota2, nota3 e media(que deve ser preenchida após a entrada das 3 notas). O usuário é quem vai definir a quantidade de alunos que ele deseja inserir, bem como inserir seus dados;
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char nome[50];
  int matricula;
  float nota1, nota2, nota3, media;
}aluno;


int buscaSequencial (int tam, int arr[], int n){
  for (int i=0; i<tam; i++){
    if (arr[i]==n){
      return i;
    }
  }
  return -1;
}

void ordena(int arr[], int tam){
  int i, j, aux;
  for (j=tam-1; j>0; j--){
    for (i=0; i<j; i++){
      if (arr[i]>arr[i+1]){
        aux=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=aux;
      }
    }
  }
}

int buscaBinaria (int tam, int arr[], int n){
  if (arr[tam/2]==n){
    return tam/2;
  }
  else if (arr[tam/2]>n){
    for (int i=(tam/2)-1; i>=0; i--){
      if (arr[i]==n){
        return i;
      }
    }
    return -1;
  }
  else if (arr[tam/2]<n){
    for (int i=(tam/2)+1; i<=tam; i++){
      if (arr[i]==n){
        return i;
      }
    }
    return -1;
  }
}


int main (){
  int qalunos;

  printf ("Informe a quantidade de alunos que deseja inserir:");
  scanf ("%d", &qalunos);

  aluno alunos[qalunos];

  for (int i=0; i<qalunos; i++){
    printf ("\n\nInforme o nome do aluno %d: ", i+1);
    scanf ("%s", alunos[i].nome);

    printf ("Informe o número de matrícula do aluno %d: ", i+1);
    scanf ("%d", &alunos[i].matricula);

    printf ("Informe as três notas do aluno %d:\n", i+1);
    scanf ("%f %f %f", &alunos[i].nota1, &alunos[i].nota2, &alunos[i].nota3);

    alunos[i].media=(alunos[i].nota1+alunos[i].nota2+alunos[i].nota3)/3;
  }

  int *arr;
  int tam;
  int n;
  int posicao;

  printf ("\n\n\nInforme o tamanho do vetor: ");
  scanf ("%d", &tam);
  
  arr=malloc(tam*(sizeof(int)));
  
  printf ("Informe o vetor: \n");
  for (int i=0; i<tam; i++){
    scanf ("%d", &arr[i]);
  }

  printf ("Informe o número inteiro a ser procurado no vetor: ");
  scanf ("%d", &n);

  posicao=buscaSequencial(tam, arr, n);
  if (posicao!=-1){
    printf ("Segundo a busca sequencial, o número %d está na posição %d\n", n, posicao+1);
  }
  else {
    printf ("ERRO! O número desejado não pertence ao vetor informado");
  }

  ordena(arr, tam);
  posicao=buscaBinaria(tam, arr, n);
  if (posicao!=-1){
    printf ("Segundo a busca binária, o número %d está na posição %d", n, posicao+1);
  }
  else {
    printf ("ERRO! O número desejado não pertence ao vetor informado");
  }

  free(arr);

  return 0;
}