#include <iostream>
using namespace std;

long binario (long numero){
  if (numero<2){
    return numero;
  }else{
     return numero%2+(10*binario(numero/2));
  }
}

int main(){

  long numero, resultadoBinario;
  printf("Ingrese un numero: ");
  scanf("%d",&numero);

  resultadoBinario=binario(numero);
  printf("El binario del numero %d es %d ", numero, resultadoBinario);
return 0;
}
