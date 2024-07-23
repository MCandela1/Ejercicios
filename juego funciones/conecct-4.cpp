#include <stdio.h>

const int FILAS = 6;
const int COLUMNAS = 7;

void inicializarMatriz(char matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = ' ';
        }
    }
}

void mostrarMatriz(const char matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("| %c ", matriz[i][j]);
        }
        printf("|\n");
    }
    for (int j = 0; j < COLUMNAS; j++) {
        printf("----");
    }
    printf("-\n");
    for (int j = 0; j < COLUMNAS; j++) {
        printf("  %d ", j + 1);
    }
    printf("\n");
}

bool colocarFicha(char matriz[FILAS][COLUMNAS], int columna, char jugador) {
    if (columna < 0 || columna >= COLUMNAS) return false;
    for (int i = FILAS - 1; i >= 0; i--) {
        if (matriz[i][columna] == ' ') {
            matriz[i][columna] = jugador;
            return true;
        }
    }
    return false;
}

bool verificarGanador(const char matriz[FILAS][COLUMNAS], char jugador) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS - 3; j++) {
            if (matriz[i][j] == jugador && matriz[i][j + 1] == jugador &&
                matriz[i][j + 2] == jugador && matriz[i][j + 3] == jugador) {
                return true;
            }
        }
    }

    for (int i = 0; i < FILAS - 3; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == jugador && matriz[i + 1][j] == jugador &&
                matriz[i + 2][j] == jugador && matriz[i + 3][j] == jugador) {
                return true;
            }
        }
    }

    for (int i = 0; i < FILAS - 3; i++) {
        for (int j = 0; j < COLUMNAS - 3; j++) {
            if (matriz[i][j] == jugador && matriz[i + 1][j + 1] == jugador &&
                matriz[i + 2][j + 2] == jugador && matriz[i + 3][j + 3] == jugador) {
                return true;
            }
        }
    }

    for (int i = 3; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS - 3; j++) {
            if (matriz[i][j] == jugador && matriz[i - 1][j + 1] == jugador &&
                matriz[i - 2][j + 2] == jugador && matriz[i - 3][j + 3] == jugador) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    char matriz[FILAS][COLUMNAS];
    int columna;
    char jugador = 'X';
    bool ganador = false;

    inicializarMatriz(matriz);

    while (!ganador) {
        mostrarMatriz(matriz);
        printf("Jugador %c, elige una columna (1-%d): ", jugador, COLUMNAS);
        scanf("%d", &columna);
        columna--;
        if (colocarFicha(matriz, columna, jugador)) {
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
            printf("Columna inválida o llena, intenta de nuevo.\n");
        }
    }

    return 0;
}
