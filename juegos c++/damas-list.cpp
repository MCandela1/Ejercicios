#include <cstdio>
#include <cstdlib>

const int tamanio_tablero =8;
const char vacio='.';
const char jugador1='o';
const char jugador2='x';

void inicializarTablero(char tablero[tamanio_tablero][tamanio_tablero]){
for (int i=0;i<tamanio_tablero;i++){
    for(int j=0;j<tamanio_tablero;j++){
        if(i%2 != j%2){
            if(i<3){
                tablero[i][j]=jugador1;
            }else if (i>4){
             tablero [i][j] =jugador2;
            }else{
              tablero[i][j]=vacio;
            }
        }else{
          tablero[i][j]=vacio;
        }
    }
  }
}

void mostrarTablero(char tablero[tamanio_tablero][tamanio_tablero]){
printf("  a b c d e f g h\n");
    for (int i = 0; i < tamanio_tablero; ++i) {
        printf("%d ", i + 1);
        for (int j = 0; j < tamanio_tablero; ++j) {
            printf("%c ", tablero[i][j]);
        }
        printf("%d\n", i + 1);
    }
    printf("  a b c d e f g h\n");
}

bool convertirCoordenadas(char columna, int fila, int& colIdx, int& filaIdx) {
    if (columna >= 'a' && columna <= 'h' && fila >= 1 && fila <= 8) {
        colIdx = columna - 'a';
        filaIdx = fila - 1;
        return true;
    }
    return false;
}
bool moverPieza(char tablero[tamanio_tablero][tamanio_tablero], int filaIni, int colIni, int filaFin, int colFin) {
    if (tablero[filaIni][colIni] == vacio || tablero[filaFin][colFin] != vacio) {
        return false;
    }

    tablero[filaFin][colFin] = tablero[filaIni][colIni];
    tablero[filaIni][colIni] = vacio;
    return true;
}

int main() {
    char tablero[tamanio_tablero][tamanio_tablero];
    inicializarTablero(tablero);

    char columnaIni, columnaFin;
    int filaIni, filaFin;
    int colIdxIni, colIdxFin, filaIdxIni, filaIdxFin;
    int turno = 1;

    while (true) {
        mostrarTablero(tablero);

        if (turno == 1) {
            printf("Turno del Jugador 1 (o):\n");
        } else {
            printf("Turno del Jugador 2 (x):\n");
        }

        printf("Introduce la posicion inicial (ej. a3): ");
        scanf(" %c%d", &columnaIni, &filaIni);
        printf("Introduce la posicion final (ej. b4): ");
        scanf(" %c%d", &columnaFin, &filaFin);

        if (convertirCoordenadas(columnaIni, filaIni, colIdxIni, filaIdxIni) &&
            convertirCoordenadas(columnaFin, filaFin, colIdxFin, filaIdxFin)) {
            if (moverPieza(tablero, filaIdxIni, colIdxIni, filaIdxFin, colIdxFin)) {
                turno = (turno == 1) ? 2 : 1;
            } else {
                printf("Movimiento invalido. Intenta de nuevo.\n");
            }
        } else {
            printf("Coordenadas invalidas. Intenta de nuevo.\n");
        }
    }

    return 0;
}
