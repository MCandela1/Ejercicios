#include <cstdio>


int main(){

  const int tamanio_array=200;
  char array[tamanio_array];
  char letra;
  int contador=0;

  printf("Ingrese solo 10 letras\n");
  //INGRESAR 10 LETRAS(BUCLE)
  while(contador<10){

     printf("Ingrese la letra %d: ",contador+1);
     scanf(" %c",&letra);
     array[contador]=letra;
     contador++;
  }

  printf("La cadena es: ");

  for(int i=0; i<contador; i++){
    printf("%c",array[i]);
  }

  printf("\n");

return 0;
}
