#include <stdio.h>

struct Pieza{
char tipo[10];
char color[10];
int fila;
int columna;
struct Pieza* siguiente;
};

void copiarCadena(char destino[],const char origen[]){
int i=0;
while(origen[i] != '\0'){
    destino[i]=origen[i];
    i++;
}
destino[i]='\0';
}

void agregarPieza(struct Pieza piezas[],int* contador, const char* tipo, const char* color, int fila, int columna){
if(*contador >=32){
    printf("No se puede agregar mas piezas.\n");
    return;
}
    copiarCadena(piezas[*contador].tipo, tipo);
    copiarCadena(piezas[*contador].color, color);
    piezas[*contador].fila = fila;
    piezas[*contador].columna = columna;
    piezas[*contador].siguiente = NULL;
  if(*contador>0){
    piezas[*contador-1].siguiente =&piezas[*contador];
  }
  (*contador)++;
}

void mostrarTablero(struct Pieza piezas[],int contador){
char tablero[8][8]={0};
for(int i=0;i<contador;i++){
  tablero[piezas[i].fila][piezas[i].columna] = piezas[i].tipo[0];
}
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        if(tablero[i][j]==0){
            printf(". ");
        }else{
          printf("%c ",tablero[i][j]);
        }
    }
    printf("\n");
  }
}

int main(){
struct Pieza piezas[32];
int contador=0;
int opcion;
char tipo[10], color[10];
int fila, columna;

while(1){
    printf("---Menu---\n");
    printf("1. Agregar pieza\n");
    printf("2. Mostrar tablero\n");
    printf("3. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch(opcion){
  case 1:
    printf("Ingresar el tipo de pieza(Reina, Rey, Torre): ");
    scanf("%s",tipo);
    printf("Ingresar el color de la pieza (blanco o negro): ");
    scanf("%s",color);
    printf("Ingresar la fila (0-7): ");
    scanf("%d",&fila);
    printf("Ingresar la columna (0-7): ");
    scanf("%d",&columna);
    agregarPieza(piezas, &contador, tipo, color, fila, columna);
    break;

  case 2:
    mostrarTablero(piezas,contador);
    break;
  case 3:
    return 0;
  default:
    printf("La opcion ingresada no es valida.\n");
    }
}
return 0;
}
