#include <iostream>
#include <cstring>
using namespace std;

int main(){

  char CAD1[]="Este es un mensaje de prueba";//el numero 28 es la cantidad de caracteres//
  char CAD2[]="de";

  if (strstr(CAD1, CAD2)== nullptr){
    printf("CAD2 no aparece en CAD1");
    }else{
          if(strcmp(CAD1, CAD2)==0){
             printf("\nCAD1 y CAD2 son iguales");
             }else{
                printf("\nCAD1 y CAD2 son distintas");
                  }
         }
  printf("\n\nLa longitud de CAD1 es %d\n ",strlen(CAD1));
 return 0;
}
