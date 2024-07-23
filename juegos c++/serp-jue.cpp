#include <cstdio>


const int tam=10;
const int max_long=100;

void iniciarTablero(char tablero[tam][tam]){
for (int i=0;i<tam;i++){
    for(int j=0;j<tam;j++){
        tablero[i][j]= ' ';
    }
  }
}

void mostrarTablero(char tablero[tam][tam]){
for(int i=0;i<tam;i++){
    for(int j=0;j<tam;j++){
        printf("|%c");
    }
      printf("|\n");
  }
  printf("\n");
}

void colocarComida(int &comidaX,int &comidaY,char tablero[tam][tam],int posicionX,int posicionY){
comidaX=posicionX;
comidaY =posicionY;
tablero[comidaX][comidaY]= 'X';
}

int moverSerpiente(char tablero[tam][tam], int serpienteX[max_long],int serpienteY[max_long],int &longitud,int &comidaX, int &comidaY, char &direccion){
int nuevaX=serpienteX[0],nuevaY=serpienteY[0];

switch(direccion){
case 'w':
    nuevaX--;
    break;

case's':
    nuevaX++;
    break;

case 'a':
    nuevaY--;
    break;

case 'd':
    nuevaY++;
    break;
default:
    return 0;
}
if(nuevaX<0||nuevaX>=tam||nuevaY<0||nuevaY>=tam|| tablero[nuevaX][nuevaY] =='0'){
  return 1;
}
if(nuevaX == comidaX && nuevaY == comidaY){
    longitud++;
    colocarComida(comidaX, comidaY, tablero,(comidaX+3)%tam,(comidaY + 3)%tam);
}
for (int i=longitud-1;i>0;i--){
    serpienteX[i]=serpienteX[i-1];
    serpienteY[i]=serpienteY[i-1];
}
serpienteX[0]=nuevaX;
serpienteY[0]=nuevaY;

for (int i=0;i<longitud;i++){
    tablero[serpienteX[i]][serpienteY[i]]='0';
}
return 0 ;
}

int main(){
char tablero[tam][tam];
int serpienteX[max_long], serpienteY[max_long];
int longitud=1;
int comidaX, comidaY;
char direccion='d';
int estadoJuego=0;

iniciarTablero(tablero);
serpienteX[0]=tam/2;
serpienteY[0]=tam/2;
tablero[serpienteX[0]][serpienteY[0]]='0';
colocarComida(comidaX, comidaY,tablero,2,2);

while(estadoJuego == 0){
    mostrarTablero(tablero);
    printf("Ingresar direccion (w/a/s/d): ");
    scanf("%c",&direccion);

    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            if (tablero[i][j] !='X'){
                tablero[i][j]=' ';
            }
        }
     }
    estadoJuego=moverSerpiente(tablero,serpienteX,serpienteY,longitud,comidaX,comidaY,direccion);
   }
   printf("El juego ha termindao! Puntuacion: %d\n:",longitud-1);
 return 0;
}
