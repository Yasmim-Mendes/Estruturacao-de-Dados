//Desenvolva um TAD para um cilindro. Inclua as funções de inicializações necessárias e as operações que retornem sua altura e raio, a sua área e o seu volume.

#include <stdio.h>

typedef struct {
  float altura;
  float raio;
} cilindro;

void inicializar (cilindro *novo_cilindro, float altura, float raio){
  novo_cilindro->altura=altura;
  novo_cilindro->raio=raio;
}

float altura (cilindro cilindro){
  return cilindro.altura;
}

float raio (cilindro cilindro){
  return cilindro.raio;
}

float area (cilindro cilindro){
  return 2.0*3.14*cilindro.raio*(cilindro.raio+cilindro.altura);
}

float volume (cilindro cilindro){
  return 3.14*(cilindro.raio*cilindro.raio)*cilindro.altura;
}

int main (){
  cilindro cilindro;

  inicializar(&cilindro, 5.0, 2.0);

  printf ("Altura do cilindro = %f\n", altura(cilindro));
  printf ("Raio do cilibro = %f\n", raio(cilindro));
  printf ("Área do cilindro = %f\n", area(cilindro));
  printf ("Volume do cilindro = %f\n", volume(cilindro));

  return 0;
}