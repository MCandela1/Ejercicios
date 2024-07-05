#include <cstdio>

using namespace std;

int main(){
  int filas, columnas;

  printf("Ingrese numero de la fila: ");
  scanf("%d",&filas);

  printf("Ingrese numero de la columna: ");
  scanf("%d",&columnas);

  int elemento=filas*columnas;
  int matriz[elemento];

  printf("Ingrese valores para la matriz (%d filas x %d columnas:\n",filas,columnas);

  for(int i=0;i<elemento;i++){
    printf("Elemento %d: ",i+1);
    scanf("%d",&matriz[i]);
  }
  printf("\nMatriz completa:\n");
  for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
        printf("%d ",matriz[i*columnas+j]);
    }
    printf("\n");
  }
 return 0;
}
