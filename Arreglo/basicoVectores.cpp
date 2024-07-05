#include <iostream>
#include <vector>

 using namespace std;

int main (){

 int numeros[]={1,2,3,4,5,6,7,8,9};

 //numeros.push_back(10); //--> agrega un elemento a un vecttor

 //numeros.pop_back()//--> quita el ultimo elemento del vector (guardarlo en una variable)

 //numeros.empty()//--> se fija si el vector esta vacio (me devuelve un booleano)

 int longitud = sizeof(numeros)/sizeof(*numeros);//--> da el largo del vector
 ///---> sintaxis => sixeof(array)/sizeof(*array)
 ///---> usamos un puntero para acceder a la cantidad de byts en la memoria

 cout<<longitud;

 return 0;
}
