//Construa um TAD para trabalhar com pontos cartesianos; Operações a serem criadas: •Inicialização passando parâmetros; •Inicialização fazendo a leitura dentro da função; •Analisar qual o quadrante um ponto se encontra; •Uma função que verifique se um determinado ponto passado por parâmetro está em um determinado quadrante, também passado por parâmetro; •Alterar os valores de um determinado ponto; •Retornar qual a distância entre dois pontos; •Retornar o maior valor de coordenada de um ponto.

#include <stdio.h>
#include <math.h>

typedef struct PontoCartesiano{
  int x;
  int y;
} PontoCartesiano;

PontoCartesiano inicializar(int x, int y){
  PontoCartesiano i;
  i.x=x;
  i.y=y;
  return i;
}

PontoCartesiano leitura(){
  PontoCartesiano l;
  printf("Informe o ponto cartesiano: ");
  scanf("%d %d", &l.x, &l.y);
  return l;
}

int quadrante(int x, int y){
  if (x>0 && y>0){
    return 1;
  }
  else if (x<0 && y>0){
    return 2;
  }
  else if (x<0 && y<0){
    return 3;
  }
  else {
    return 4;
  }
}

int verificar(int x, int y, int q){
  int quadranteLocal;
  if (x>0 && y>0){
    quadranteLocal=1;
  }
  else if (x<0 && y>0){
    quadranteLocal=2;
  }
  else if (x<0 && y<0){
    quadranteLocal=3;
  }
  else {
    quadranteLocal=4;
  }
  return (quadranteLocal==q);
}

PontoCartesiano alterar(){
  PontoCartesiano a;
  printf("Informe os novos valores de ponto cartesiano: ");
  scanf("%d %d", &a.x, &a.y);
  return a;
}

float distancia(int x1, int y1, int x2, int y2){
  return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int maior(int x, int y){
  return (x>y)?x:y;
}

int main(){
  PontoCartesiano foda;
  PontoCartesiano fake;
  int q;

  foda=leitura();

  printf("O quadrante dos pontos é %d", quadrante(foda.x, foda.y));

  printf("\n\nInforme um ponto cartesiano: ");
  scanf("%d %d", &foda.x, &foda.y);
  printf("\nInforme o quadrante desses pontos: ");
  scanf("%d", &q);
  if (verificar(foda.x, foda.y, q)){
    printf("\nCorreto! Esse é o quadrante dos pontos indicados");
  }
  else {
    printf("\nIncorreto! Esse não é o quadrante dos pontos indicados");
  }

  foda=alterar();

  printf("\n\nInforme o ponto cartesiano 1: ");
  scanf("%d %d", &foda.x, &foda.y);
  printf("\nInforme o ponto cartesiano 2: ");
  scanf("%d %d", &fake.x, &fake.y);
  printf("\nA distancia entre os pontos informados é igual a %f", distancia(foda.x, foda.y, fake.x, fake.y));

  printf("\n\nO maior valor de coordenada do ponto é %d", maior(foda.x, foda.y));

  return 0;
}
