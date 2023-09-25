//Desenvolva um TAD para uma esfera. Inclua as funções de inicializações necessárias e as operações que retornem seu raio, a sua área e o seu volume.

#include <stdio.h>

typedef struct {
  float raio;
} esfera;

void inicializar (esfera *nova_esfera, float raio){
  nova_esfera->raio=raio;
}

float raio (esfera esfera){
  return esfera.raio;
}

float area (esfera esfera){
  return 4.0*3.14*(esfera.raio*esfera.raio);
}

float volume (esfera esfera){
  return (4.0/3.0)*3.14*(esfera.raio*esfera.raio*esfera.raio);
}

int main (){
  esfera esfera;

  inicializar(&esfera, 5.0);
  
  printf ("Raio da esfera = %f\n", raio(esfera));
  printf ("Área da esfera = %f\n", area(esfera));
  printf ("Volume da esfera = %f\n", volume(esfera));

  return 0;
}