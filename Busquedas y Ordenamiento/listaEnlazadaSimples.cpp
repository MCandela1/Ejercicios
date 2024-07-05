#include <iostream>

using namespace std;

struct Nodo{

 int dato;
 Nodo* next;
};

Nodo* cabeza=NULL;

void NuevoNodo (int valor){
  Nodo* nuevoNodo=new Nodo;
  nuevoNodo->dato=valor;
  nuevoNodo->next=NULL;

  if(cabeza==NULL){
    cabeza=nuevoNodo;
  }else{
     Nodo*temporal=cabeza;
     while(temporal->next != NULL){
        temporal=temporal->next;
     }
     temporal->next=nuevoNodo;
  }
}

int main(){

    int numero, valor;
    cout<<"Cantidad de carga de nodos: "<<endl;
    cin>>numero;
for(int i=0; i<numero;i++){
    cout<<"Ingrese el valor del nodo "<<i+1<<": ";
    cin>>valor;
    NuevoNodo(valor);
    }
  Nodo*temporal=cabeza;
   while(temporal != NULL){
    cout<<temporal-> dato<<" ";
    temporal =temporal->next;
   }

return 0;
}

