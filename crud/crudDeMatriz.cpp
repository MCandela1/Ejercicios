#include <cstdio>

using namespace std;

const int tamanio=3;

void ingresarMatriz(int matriz[tamanio][tamanio]){
   printf("Ingresar los elementos de una matriz 3x3:\n");
   for(int i=0; i<tamanio;i++){
      for(int j=0; j<tamanio;j++){
        printf("Elemento[%d][%d]: ",i,j);
        scanf("%d", &matriz[i][j]);
      }
   }
}

void buscarElemento(int matriz[tamanio][tamanio]){
   int elemento;
   printf("Ingrese el elemento a buscar: ");
   scanf("%d", &elemento);
   for(int i=0; i<tamanio;i++){
    for(int j=0;j<tamanio;j++){
        if(matriz[i][j]==elemento){
            printf("Elemento encontrado en [%d][%d]\n",i,j);
            return;
        }
    }
   }
   printf("No se encontro el elemento.\n");
}

void actualizarElemento(int matriz[tamanio][tamanio]){
   int fila, columna, nuevoValor;
   printf("Ingresar la fila de la matriz a actualizar (0 a %d)",tamanio -1);
   scanf("%d",&fila);

   printf("Ingresar la columna de la matriz a actualizar (0 a %d)",tamanio -1);
   scanf("%d",&columna);

   printf("Ingresar nuevo valor: ");
   scanf("%d",&nuevoValor);

   if(fila>=0 && fila<tamanio && columna>=0 && columna<tamanio){
        matriz[fila][columna]=nuevoValor;
        printf("Matriz actualizada.\n");
   }else{
        printf("Indice fuera de rango. No se puede actualizar.\n");
   }
}

void eliminarMatriz(int matriz [tamanio][tamanio], int fila, int columna){
  if (fila<0 || fila >= tamanio || columna <0 || columna>=tamanio){
    printf("Indice fuera de rangi. No se puede eliminar.\n");
    return;
  }
  matriz[fila][columna]=0;
  printf("Elemeno eliminado.\n");
}

void mostrarMatriz(int matriz [tamanio][tamanio]){
  for(int i=0; i<tamanio;i++){
    for(int j=0; j<tamanio;j++){
        printf("[%d]", matriz[i][j]);
    }
    printf("\n");
  }
}

int main(){
   int matriz[tamanio][tamanio];
   int opcion;

   while(true){
    printf("1. Ingresar matriz.\n");
    printf("2. Buscar un elemento de la matriz.\n");
    printf("3. Actualizar elemento de la matriz.\n");
    printf("4. Eliminar un elemento de la matriz.\n");
    printf("5. Imprimir la matriz.\n");
    printf("6. Salir.\n");
    scanf("%d", &opcion);

    switch (opcion){
        case 1:
              ingresarMatriz(matriz);
              break;
        case 2:
              buscarElemento(matriz);
              break;
        case 3:
              actualizarElemento(matriz);
              break;
        case 4:
              int fila, columna;
              printf("Ingresar la fila del elemento a eliminar (0 a %d): ",tamanio-1);
              scanf("%d",&fila);
              printf("Ingresar la columna del elemento a eliminar (0 a %d): ",tamanio-1);
              scanf("%d",&columna);
              eliminarMatriz(matriz, fila, columna);
              break;
        case 5:
              mostrarMatriz(matriz);
              break;
        case 6:
              return 0;
        default:
            printf("La opcion ingresada no es valida.\n");
    }
   }
   return 0;
}

