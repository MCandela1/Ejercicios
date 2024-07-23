#include <stdio.h>

const int FILAS = 3;
const int COLUMNAS = 3;

void mostrarMatriz(char matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

bool verificarGanador(const char matriz[FILAS][COLUMNAS], char jugador) {
    for (int i = 0; i < FILAS; i++) {
        bool filaGanadora = true;
        bool columnaGanadora = true;
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] != jugador) filaGanadora = false;
            if (matriz[j][i] != jugador) columnaGanadora = false;
        }
        if (filaGanadora || columnaGanadora) return true;
    }

    bool diagonalPrincipal = true;
    bool diagonalSecundaria = true;
    for (int i = 0; i < FILAS; i++) {
        if (matriz[i][i] != jugador) diagonalPrincipal = false;
        if (matriz[i][FILAS - i - 1] != jugador) diagonalSecundaria = false;
    }
    return diagonalPrincipal || diagonalSecundaria;
}

int main() {
    char matriz[FILAS][COLUMNAS] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int fila, columna;
    char jugador = 'X';
    bool ganador = false;

    while (!ganador) {
        mostrarMatriz(matriz);
        printf("Jugador %c, elige una fila y columna (1-3): ", jugador);
        scanf("%d %d", &fila, &columna);
        fila--; columna--;

        if (fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS && matriz[fila][columna] != 'X' && matriz[fila][columna] != 'O') {
            matriz[fila][columna] = jugador;
            if (verificarGanador(matriz, jugador)) {
                mostrarMatriz(matriz);
                printf("¡Jugador %c gana!\n", jugador);
                ganador = true;
            } else {
                if (jugador == 'X') {
                    jugador = 'O';
                } else {
                    jugador = 'X';
                }
            }
        } else {
            printf("Movimiento inválido, intenta de nuevo.\n");
        }
    }

    return 0;
}
