//Faça um programa que contenha as seguintes funções: •Crie uma outra função de busca sequencial, onde o usuário buscará pela matrícula do aluno. Se o aluno estiver matriculado, imprima todas suas informações; •Da mesma forma que a função acima, crie agora uma função de busca binária. Obs: No último slide deste conteúdo possui uma função de ordenação, pode usá-la, no entanto agora que terá que efetuar adaptações nesta função; •Crie uma função imprime que imprimirá todos os elementos de um aluno;

#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char nome[50];
  int matricula;
  float nota1, nota2, nota3, media;
}aluno;


int buscaSequencial (int tam, aluno arr[], int n){
  for (int i=0; i<tam; i++){
    if (arr[i].matricula==n){
      return i;
    }
  }
  return -1;
}

void ordena(aluno arr[], int tam){
  int i, j, aux;
  for (j=tam-1; j>0; j--){
    for (i=0; i<j; i++){
      if (arr[i].matricula>arr[i+1].matricula){
        aux=arr[i].matricula;
        arr[i].matricula=arr[i+1].matricula;
        arr[i+1].matricula=aux;
      }
    }
  }
}

int buscaBinaria (int tam, aluno arr[], int n){
  if (arr[tam/2].matricula==n){
    return tam/2;
  }
  else if (arr[tam/2].matricula>n){
    for (int i=(tam/2)-1; i>=0; i--){
      if (arr[i].matricula==n){
        return i;
      }
    }
    return -1;
  }
  else if (arr[tam/2].matricula<n){
    for (int i=(tam/2)+1; i<=tam; i++){
      if (arr[i].matricula==n){
        return i;
      }
    }
    return -1;
  }
}


void dadosAlunos (aluno arr[], int posicao){
  printf ("\nNome do aluno: %s", arr[posicao].nome);
  printf ("\nNúmero de matrícula: %d", arr[posicao].matricula);
  printf ("\nNota 1: %f\nNota 2: %f\nNota 3: %f", arr[posicao].nota1, arr[posicao].nota2, arr[posicao].nota3);
  printf ("\nMédia: %f", arr[posicao].media);
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

  int n;
  int posicao;

  printf ("\nInforme o número de matrícula a ser buscado: ");
  scanf ("%d", &n);

  posicao=buscaSequencial(qalunos, alunos, n);
  if (posicao!=-1){
    dadosAlunos(alunos, posicao);
  }
  else {
    printf ("\nEste aluno não está matriculado!");
  }

  ordena(alunos, qalunos);
  posicao=buscaBinaria(qalunos, alunos, n);
  if (posicao!=-1){
    dadosAlunos(alunos, posicao);
  }
  else {
    printf ("\nEste aluno não está matriculado!");
  }

  return 0;
}