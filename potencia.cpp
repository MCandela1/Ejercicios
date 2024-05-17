#include <iostream>
#include <stdlib.h>

using namespace std;

int exponentes(int numero,int exponente){

  if(exponente==1){
    return numero;
  }else{
       numero=numero*exponentes(numero,exponente-1);
       return numero;
  }
}

int main (){

  int numero, exponente, potencia;

  printf("Ingrese un numero: ");
  scanf("%d",&numero);

  printf("Ingrese un exponente: ");
  scanf("%d",&exponente);

  potencia=exponentes(numero,exponente);

  printf("La potencia es: %d",potencia);
}

