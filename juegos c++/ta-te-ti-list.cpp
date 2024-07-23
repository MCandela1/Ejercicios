#include <cstdio>

const int tamanio=3;

struct Juego{
char tablero[tamanio][tamanio];
char jugadorActual;
};

void inicializarJuego(Juego &juego){
for(int i=0;i<tamanio;i++){
    for(int j=0;j<tamanio;j++){
        juego.tablero[i][j]= ' ';
    }
  }
  juego.jugadorActual= 'X';
}
void dibujarTablero(Juego &juego){
printf( "%c | %c | %c \n", juego.tablero[0][0],juego.tablero[0][1],juego.tablero[0][2]);
printf("---|---|---\n");
printf( "%c | %c | %c \n", juego.tablero[1][0],juego.tablero[1][1],juego.tablero[1][2]);
printf("---|---|---\n");
printf( "%c | %c | %c \n", juego.tablero[2][0],juego.tablero[2][1],juego.tablero[2][2]);
}

int movimientoValido(Juego &juego, int fila, int columna){
if(fila>=0 && fila<tamanio && columna>=0 && columna<tamanio && juego.tablero[fila][columna] == ' '){
    return 1;
  }
  return 0;
}

void actualizarJuego(Juego &juego, int fila, int columna){
if (movimientoValido(juego, fila,columna)){
    juego.tablero[fila][columna]=juego.jugadorActual;
    if (juego.jugadorActual == 'X'){
        juego.jugadorActual= 'O';
    }else{
       juego.jugadorActual='X';
    }
  }else{
      printf("El movimiento ingresado es invalido. Intentelo de nuevo.\n");
  }
}
char verificarGanador(Juego &juego){
 for(int i=0;i<tamanio;i++){
    if(juego.tablero[i][0] == juego.tablero[i][1]  && juego.tablero[i][1] == juego.tablero[i][2] && juego.tablero[i][0] != ' '){
       return juego.tablero[i][0];
    }
  }
 for(int i=0;i<tamanio;i++){
    if (juego.tablero[0][i] == juego.tablero[1][i] && juego.tablero[1][i] == juego.tablero[2][i] && juego.tablero[0][i] != ' '){
        return juego.tablero[0][i];
    }
  }
   if (juego.tablero[0][0] == juego.tablero[1][1] && juego.tablero[1][1] == juego.tablero[2][2] && juego.tablero[0][0] != ' ') {
        return juego.tablero[0][0];
    }
    if (juego.tablero[0][2] == juego.tablero[1][1] && juego.tablero[1][1] == juego.tablero[2][0] && juego.tablero[0][2] != ' ') {
        return juego.tablero[0][2];
    }
    int empate =1;
    for(int i=0;i<tamanio;i++){
        for(int j=0;j<tamanio;j++){
            if (juego.tablero[i][j] == ' '){
                empate=0;
                break;
            }
        }
        if(empate ==0) break;
    }
    if (empate) return 'E';
    return ' ';
}

int main (){
Juego juego;
inicializarJuego(juego);
char ganador= ' ';

while(ganador == ' '){
    dibujarTablero(juego);
    int fila, columna;
    printf("Jugador %c, ingresar su jugada (fila columna): ",juego.jugadorActual);
    scanf("%d %d",&fila, &columna);
    actualizarJuego(juego, fila-1, columna-1);
    ganador=verificarGanador(juego);
}
dibujarTablero(juego);
if(ganador == 'E'){
    printf("¡Los jugadores empataron!\n");
}else{
 printf("¡El jugador %c es el ganador!\n",ganador);
}
return 0;
}
