//Crie um Tipo Abstrato de Dados (TAD) que represente o tipo conjunto de inteiros, utilizando uma representação de vetor de inteiros e que contenha as seguintes funções: a)União b)Cria um conjunto vazio c)Insere d)Remove e)Intersecção f)Diferença g)Testa se um número pertence ao conjunto h)Menor valor i)Maior valor j)Testa se os conjuntos são iguais k)Verifica o tamanho do conjunto l)Testa se o conjunto é vazio

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int elementos[100];
  int tam;
} Conjunto;

void criarVazio (Conjunto* conjunto){
  conjunto->tam=0;
}

int inserir (Conjunto* conjunto, int num){
  if (conjunto->tam<100){
    conjunto->elementos[conjunto->tam]=num;
    conjunto->tam++;
    return 1;
  }
  else {
    return 0;
  }
}

int remover (Conjunto* conjunto, int num){
  if (conjunto->tam>0){
    for (int i=0; i<conjunto->tam; i++){
      if (conjunto->elementos[i]==num){
        for (int j=i; j<conjunto->tam-1; j++){
          conjunto->elementos[j]=conjunto->elementos[j+1];
        }
        conjunto->tam--;
        return 1;
      }
      else {
      printf("Elemento %d não encontrado no conjunto\n", num);
        return -1;
      }
    }
    return -1;
  }
  else {
    return -1;
  }
}

Conjunto uniao (Conjunto conjunto1, Conjunto conjunto2){
  Conjunto resultado;
  criarVazio(&resultado);

  for (int i=0; i<conjunto1.tam; i++){
    inserir (&resultado, conjunto1.elementos[i]);
  }
  for (int i=0; i<conjunto2.tam; i++){
    inserir (&resultado, conjunto2.elementos[i]);
  }

  return resultado;
}

int pertence (Conjunto conjunto, int elemento){
  for (int i=0; i<conjunto.tam; i++){
    if (conjunto.elementos[i]==elemento){
      return 1;
    }
    else {
      return 0;
    }
  }
}

Conjunto intersecao (Conjunto conjunto1, Conjunto conjunto2){
  Conjunto resultado;
  criarVazio (&resultado);
  
  for (int i=0; i<conjunto1.tam; i++){
    if (pertence(conjunto2, conjunto1.elementos[i])){
      inserir (&resultado, conjunto1.elementos[i]);
    }
  }
  return resultado;
}

Conjunto diferenca (Conjunto conjunto1, Conjunto conjunto2){
  Conjunto resultado;
  criarVazio (&resultado);

  for (int i=0; i<conjunto1.tam; i++){
    if (pertence (conjunto2, conjunto1.elementos[i])){
      inserir (&resultado, conjunto1.elementos[i]);
    }
  }
  return resultado;
}

int menor (Conjunto conjunto){
  int menor;
  
  if (conjunto.tam==0){
    return -1;
  }

  menor=conjunto.elementos[0];

  for (int i=0; i<conjunto.tam; i++){
    if (conjunto.elementos[i]<menor){
      menor=conjunto.elementos[i];
    }
  }
  return menor;
}

int maior (Conjunto conjunto){
  int maior; 

  if (conjunto.tam==0){
    return -1;
  }

  maior=conjunto.elementos[0];

  for (int i=0; i<conjunto.tam; i++){
    if (conjunto.elementos[i]>maior){
      maior=conjunto.elementos[i];
    }
  }
  return maior;
}

int iguais(Conjunto conjunto1, Conjunto conjunto2){
  if (conjunto1.tam!=conjunto2.tam){
    return 0;
  }

  for (int i=0; i<conjunto1.tam; i++){
    if (!pertence(conjunto2, conjunto1.elementos[i])){
      return 0;
    }
  }

  return 1;
}

int tamanho (Conjunto conjunto){
  return conjunto.tam;
}

int vazio (Conjunto conjunto){
  if (conjunto.tam==0){
    return 1;
  }
  else {
    return 0;
  }
} 