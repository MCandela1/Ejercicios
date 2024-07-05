#include <iostream>
#include <array>
/*
-->DECLARAMOS FUNCION bool BUSQUEDA LINEAL (array, elemento)
      |---> for ()
--------------------------------------------------------------
   [] Declaramos la funcion y variable
   [] int lista[7]={6,44,3,11}
   // solicitar elemento a buscar
 //invoco a la funcion --> busqueda lineal(lista, elemento)
 // if --> para encontrar
 //else --> no lo encontre
 //
*/
using namespace std;

int main(){

 int lista[]={6,44,3,67,11};

 int length= end (lista)-begin(lista);

 printf("\n\nLa lectura del array es: %i \n\n",length);

return 0;
}
