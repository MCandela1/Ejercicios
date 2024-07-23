#include <stdio.h>

using namespace std;

void cargarPrecios(float precios[],int max_tipo_lombriz){
 for(int i=0; i< max_tipo_lombriz;i++){
    printf("Ingrese el precio del tipo de la lombriz %d: ",i+1);
    scanf("%f",&precios[i]);
 }
}

int sumaVertical(int matriz[][3],int filas, int columna){
 int suma=0;
 for(int i=0; i<filas;i++){
    suma +=matriz[i][columna];
 }
 return suma;
}

int sumaHorizontal(int matriz[][3],int columnas,int fila){
 int suma=0;
 for(int i=0;i<columnas;i++){
    suma += matriz[fila][i];
 }
 return suma;
}

void analizarGranjas(float precios[],int max_tipo_lombriz){
int tipoLombriz;

do{
    printf("Ingresar el tipo de lombriz del 1 al %d: ",max_tipo_lombriz);
    scanf("%d",&tipoLombriz);
}while(tipoLombriz<1||tipoLombriz>max_tipo_lombriz);

int filas=3, columnas=3;
int matriz[3][3];

printf("Ingrese la cantidad de lombrices en cada celda:\n");
for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
      printf("Celda [%d][%d]: ",i,j);
      scanf("%d",&matriz[i][j]);
    }
  }
  int x,y;
  do{
    printf("Ingresar las coordenadas de la celda de referencia (x y): ");
    scanf("%d %d",&x, &y);
  }while(x<0||x>=filas||y<0||y>=columnas);

  int maxVertical= sumaVertical(matriz, filas, y);
  int maxHorizontal= sumaHorizontal(matriz, columnas, x);

  int maxLombrices;
  if(maxVertical>maxHorizontal){
    maxLombrices=maxVertical;
  }else{
    maxLombrices=maxHorizontal;
  }
  float importe=maxLombrices*precios[tipoLombriz-1];

  printf("Maximo de lombrices cosechadas es: %d\n",maxLombrices);
  printf("El importe a pagar es: %.2f\n",importe);
}

int main(){
int max_tipo_lombriz;
printf("Ingresar el numero maximo de tipo de lombriz: ");
scanf("%d",&max_tipo_lombriz);

float precios[max_tipo_lombriz];
int opcion;

do{
    printf("\n---Menu---\n");
    printf("1. Cargar precios de lombrices\n");
    printf("2. Analizar granja\n");
    printf("3. Salir\n");
    printf("Seleccione cualquiera de estas opciones: ");
    scanf("%d",&opcion);

    switch(opcion){
    case 1:
        cargarPrecios(precios, max_tipo_lombriz);
        break;
    case 2:
        analizarGranjas(precios,max_tipo_lombriz);
        break;
    case 3:
        printf("Saliendo del programa.\n");
        break;
    default:
        printf("La opcion ingresada no es valida.\n");
        break;
    }
}while(opcion!=3);
return 0;
}

