#include <cstdio>
#include <cctype>
#include <conio.h> //-->para getche()

int main(){

  const int tamanio_array=11;
  char array[tamanio_array];
  char letra;
  int contador=0;

  printf("Ingrese las letras. Presionar espacio para finalizar\n");
  //INGRESAR 10 LETRAS(BUCLE)
  while(contador< 10){//-->se evita un desbordamiento del array
         letra=getche();

         if(isspace(letra)){ //--> isspace es identificar si el caracter ingresado es un espacio
            printf("\nIngreso espacio por lo que se finalizo el programa\n");
            break;//-->lo finaliza
         }

         array[contador]=letra;
         contador++;
  }
   array[contador]=NULL;

  printf("La palabra ingresada es: %s\n ",array);


return 0;
}
