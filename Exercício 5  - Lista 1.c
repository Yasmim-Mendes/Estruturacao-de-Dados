//Desenvolva um TAD para um cubo. Inclua as funções de inicializações necessárias e as operações que retornem os tamanhos de cada lado, a sua área e o seu volume.

#include <stdio.h>

typedef struct {
  float aresta;
} cubo;

void inicializar (cubo *novo_cubo, float aresta){
  novo_cubo->aresta=aresta;
}

float lado (cubo cubo){
  return cubo.aresta;
}

float area (cubo cubo){
  return cubo.aresta*6;
}

float volume (cubo cubo){
  return cubo.aresta*cubo.aresta*cubo.aresta;
}

int main (){
  cubo cubo;

  inicializar(&cubo, 3.0);

  printf ("Lado do cubo = %f\n", lado(cubo));
  printf ("Área do cubo = %f\n", area(cubo));
  printf ("Volume do cubo = %f\n", volume(cubo));

  return 0;
}