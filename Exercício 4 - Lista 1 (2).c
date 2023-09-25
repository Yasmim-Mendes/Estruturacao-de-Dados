//Crie um Tipo Abstrato de Dados (TAD) que represente os números racionais e que contenha as seguintes funções: a)Cria racional; b)Soma racionais; c)Multiplica racionais; d)Testa se são iguais.

#include <stdio.h>

typedef struct {
  int numerador;
  int denominador;
} racional;

int mdc (int a, int b){
  int cont;
  
   while (b!=0){
    cont=a%b;
    a=b;
    b=cont;
  }
  return a;
}

racional cria (int numerador, int denominador){
  racional novo_racional;

  novo_racional.numerador=numerador;
  novo_racional.denominador=denominador;

  int divisor=mdc(numerador, denominador);
  novo_racional.numerador/=divisor;
  novo_racional.denominador/=divisor;

  return novo_racional;
}

racional soma (racional racional1, racional racional2){
  int novo_numerador=(racional1.numerador*racional2.denominador)+(racional2.numerador*racional1.denominador);

  int novo_denominador=racional1.denominador*racional2.denominador;

    return cria(novo_numerador, novo_denominador);
}

racional multiplica (racional racional1, racional racional2){
  int novo_numerador=racional1.numerador*racional2.numerador;
  int novo_denominador=racional1.denominador*racional2.denominador;

  return cria(novo_numerador, novo_denominador);
}

int iguais (racional racional1, racional racional2){
  if (racional1.numerador==racional2.numerador) && (racional1.denominador==racional2.denominador){
    return 1;
  }
  else {
    return -1;
  }
}

int main (){
  racional racional1=cria(2,3);
  racional racional2=cria(3,4);
  
  racional soma=soma (racional1, racional2);
  racional multiplica=multiplica (racional1, racional2);

  printf ("Racional 1: %d/%d\nRacional 2: %d/%d", racional1.numerador, racional1.denominador, racional2.numerador, racional2.denominador);
  printf ("Soma: %d/%d\nProduto: %d/%d", soma.numerador, soma.denominador, multiplica.numerador, multiplica.denominador);

  if (iguais(racional1, racional2)==1){
    printf ("São números racionais iguais");
  }
  else {
    printf ("Não são números racionais iguais");
  }
  
  return 0;
}