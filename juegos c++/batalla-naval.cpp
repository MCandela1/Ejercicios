#include <cstdio>
#include <cstdlib>

const int TAMANIO_TABLERO = 10;
const char VACIO = '.';
const char BARCO = 'B';
const char TOCADO = 'X';
const char AGUA = 'O';

void inicializarTablero(char tablero[TAMANIO_TABLERO][TAMANIO_TABLERO]) {
    for (int i = 0; i < TAMANIO_TABLERO; ++i) {
        for (int j = 0; j < TAMANIO_TABLERO; ++j) {
            tablero[i][j] = VACIO;
        }
    }
}

void colocarBarcos(char tablero[TAMANIO_TABLERO][TAMANIO_TABLERO]) {
    for (int i = 0; i < 5; ++i) {
        tablero[4][i] = BARCO;
    }
    for (int i = 0; i < 4; ++i) {
        tablero[i][7] = BARCO;
    }
   for (int i = 0; i < 3; ++i) {
        tablero[7][i + 2] = BARCO;
    }
}

void mostrarTablero(char tablero[TAMANIO_TABLERO][TAMANIO_TABLERO]) {
    printf("  A B C D E F G H I J\n");
    for (int i = 0; i < TAMANIO_TABLERO; ++i) {
        printf("%d ", i + 1);
        for (int j = 0; j < TAMANIO_TABLERO; ++j) {
            printf("%c ", tablero[i][j]);
        }
        printf("%d\n", i + 1);
    }
    printf("  A B C D E F G H I J\n");
}

bool convertirCoordenadas(char columna, int fila, int& colIdx, int& filaIdx) {
    if (columna >= 'A' && columna <= 'J' && fila >= 1 && fila <= 10) {
        colIdx = columna - 'A';
        filaIdx = fila - 1;
        return true;
    }
    return false;
}

bool realizarDisparo(char tablero[TAMANIO_TABLERO][TAMANIO_TABLERO], int fila, int col) {
    if (tablero[fila][col] == BARCO) {
        tablero[fila][col] = TOCADO;
        return true;
    } else if (tablero[fila][col] == VACIO) {
        tablero[fila][col] = AGUA;
        return false;
    }
    return false;
}

bool todosBarcosHundidos(char tablero[TAMANIO_TABLERO][TAMANIO_TABLERO]) {
    for (int i = 0; i < TAMANIO_TABLERO; ++i) {
        for (int j = 0; j < TAMANIO_TABLERO; ++j) {
            if (tablero[i][j] == BARCO) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char tablero[TAMANIO_TABLERO][TAMANIO_TABLERO];
    inicializarTablero(tablero);
    colocarBarcos(tablero);

    char columna;
    int fila;
    int colIdx, filaIdx;
    bool juegoTerminado = false;

    while (!juegoTerminado) {
        mostrarTablero(tablero);

        printf("Introduce las coordenadas para disparar (ej. A5): ");
        scanf(" %c%d", &columna, &fila);

        if (convertirCoordenadas(columna, fila, colIdx, filaIdx)) {
            if (realizarDisparo(tablero, filaIdx, colIdx)) {
                printf("Tocado!\n");
            } else {
                printf("Agua!\n");
            }

            if (todosBarcosHundidos(tablero)) {
                printf("Has hundido todos los barcos! Has ganado!\n");
                juegoTerminado = true;
            }
        } else {
            printf("Coordenadas invalidas. Intenta de nuevo.\n");
        }
    }

    return 0;
}
