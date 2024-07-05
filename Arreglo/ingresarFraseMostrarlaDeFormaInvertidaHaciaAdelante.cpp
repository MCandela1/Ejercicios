#include <iostream>
#include <cstring>

using namespace std;
//FUNCION PARA INVERTIR CADENA DE CARACTERES
void invertirFrase(char cadena[], int longitud ){
  int inicio=0;
  int fin=longitud-1;

  while (inicio<fin){
    //INTERCAMBIA CARACTERES
    char temp=cadena[inicio];
    cadena[inicio]=cadena[fin];
    cadena[fin]=temp;

    //LOS MUEVE
    inicio++;
    fin--;
  }
}

int main (){

  const int MAX_LONGITUD=100;
  char frase[MAX_LONGITUD];
  //INGRESA EL USUARIO UNA FRASE
  printf("Ingrese la frase: ");
  scanf("%99[^\n]",&frase);

  //SE OBTIENE LA LONGUITUD DE LA FRASE
  int longitud=strlen(frase);
  //SE INVIERTE LA FRASE
  invertirFrase(frase,longitud);

  if(longitud==strlen(frase)){

      printf("\nSe contabilizo el largo en forma correcta\n\n");
  }else{
      printf("\n\nError en el largo de la frase\n\n");
  }

  printf("La frase invertida se muestra de la siguiente manera: %s\n",frase);

return 0;
 }
