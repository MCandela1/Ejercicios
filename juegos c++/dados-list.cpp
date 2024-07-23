#include <cstdio>
#include <cstdlib>

struct Nodo{
int dado1;
int dado2;
Nodo*  siguiente;
};
const int max_nodos=100;
Nodo nodos[max_nodos];
int nodo_actual=0;

void agregarResultado(Nodo*& cabeza,int dado1,int dado2){
if (nodo_actual<max_nodos){
    nodos[nodo_actual].dado1=dado1;
    nodos[nodo_actual].dado2=dado2;
    nodos[nodo_actual].siguiente=cabeza;
    cabeza= &nodos[nodo_actual];
    nodo_actual++;
}else{
   printf("Se alcanzo el limite de maximo de nodos.\n");
 }
}

void mostrarResultados(Nodo* cabeza){
Nodo* actual = cabeza;
if(actual ==  nullptr){
    printf("No se encuenttra el resultado para mostrar.\n");
}else{
    printf("Resultado de los dados lanzados:\n");
    while(actual != nullptr){
        printf("Dado 1: %d, Dado 2: %d\n",actual->dado1, actual->dado2);
        actual=actual->siguiente;
    }
  }
}

int main (){
Nodo* resultados=nullptr;
int opcion;
int dado1, dado2;

do{
    printf("\n--Menu--\n");
    printf("1) Lanzar los dador\n");
    printf("2) Mostrar resultaods\n");
    printf("3) Salir\n");
    printf("Seleccione cualquier opcion: ");
    scanf("%d", &opcion);

    switch(opcion){
  case 1:
    dado1=(rand()%6)+1;
    dado2=(rand()%6)+1;
    printf("Resultado: Dado 1= %d, Dado 2 = %d\n",dado1,dado2);
    agregarResultado(resultados,dado1,dado2);
    break;
  case 2:
    mostrarResultados(resultados);
    break;
  case 3:
    printf("Saliendo del juego...\n");
    break;
  default :
    printf ("La opcion ingresada no es valida. Intente de nuevo.\n");
    break;
    }
  }while (opcion != 3);
return 0;
}
