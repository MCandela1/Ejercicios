#include <iostream>
#include <cstdlib>
#include <cstring>

struct Nodo{
  char *Nombre;
  Nodo *siguiente;
};

Nodo*Lista=nullptr;

bool ListaVacia();
char *SacaLista();
void MuestraListado();
void InsertarLista(const char*Nom);

bool ListaVacia(){
 return Lista==nullptr; ///->se fija si esta vacio o no
}

char *SacaLista(){
  if(ListaVacia()){
    printf("La lista esta vacia\n");
    return nullptr;
  }
  Nodo *temp=Lista;
  char *nombre=strdup(Lista->Nombre); ///->copiamos el nombre
  Lista=Lista->siguiente;
  free(temp->Nombre);///->liberar la memoria del nombre del nodo
  free(temp);///->liberar la memoria del nodo
return nombre;
}

void MuestraListado(){
   if (ListaVacia()){
    printf("La lista esta vacia\n");
    return;
   }
  Nodo *temp=Lista;
 while (temp!=nullptr){
    printf("%s\n\n",temp->Nombre);
    temp=temp->siguiente;
 }
}

int main (){
  system("cls");
  InsertarLista("Ana");
  InsertarLista("Juan");
  InsertarLista("Maria");
  InsertarLista("Martin");
  InsertarLista("Monica");
  InsertarLista("Erick");

  MuestraListado();

  char *nombre=SacaLista();
  if (nombre){
    printf("Elemento extraido: %s\n",nombre);
    free(nombre);///->Liberar la memoria del nombre extraido para no volver a encontrarme un valor en caso de que asigne el mismo espacio de memoria
  }
  MuestraListado();
return 0;
}

void InsertarLista(const char *Nom){///-->me llega el nodo 1
  Nodo *t=new Nodo;
  if (!t){
    printf("No se pudo asignar memoria\n");
    return;
  }
  t->Nombre=strdup(Nom);///->Asignamos el nombre
  t->siguiente=nullptr;

  if(Lista==nullptr){
    Lista=t;
  }else{
    Nodo *q=Lista;
    while(q->siguiente!=nullptr){
        q=q->siguiente;
    }
    q->siguiente=t;
  }
}
