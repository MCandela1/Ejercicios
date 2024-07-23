#include <stdio.h>

void inicializarMatriz(char matriz[5][5]) {
    char laberinto[5][5] = {
        {'S', ' ', 'X', 'X', 'X'},
        {'X', ' ', ' ', ' ', 'X'},
        {'X', 'X', 'X', ' ', 'X'},
        {'X', ' ', ' ', ' ', 'X'},
        {'X', 'X', 'X', ' ', 'E'}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = laberinto[i][j];
        }
    }
}

void mostrarMatriz(const char matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int moverJugador(char matriz[5][5], int* fila, int* columna, char direccion) {
    int nuevaFila = *fila;
    int nuevaColumna = *columna;

    switch (direccion) {
        case 'w': nuevaFila--; break;
        case 's': nuevaFila++; break;
        case 'a': nuevaColumna--; break;
        case 'd': nuevaColumna++; break;
        default: return 0;
    }

    if (nuevaFila >= 0 && nuevaFila < 5 && nuevaColumna >= 0 && nuevaColumna < 5 && matriz[nuevaFila][nuevaColumna] != 'X') {
        matriz[*fila][*columna] = ' ';
        matriz[nuevaFila][nuevaColumna] = 'S';
        *fila = nuevaFila;
        *columna = nuevaColumna;
        return 1;
    }

    return 0;
}

int main() {
    char matriz[5][5];
    int fila = 0, columna = 0;
    char direccion;
    int metaAlcanzada = 0;

    inicializarMatriz(matriz);

    while (!metaAlcanzada) {
        mostrarMatriz(matriz);
        printf("Introduce la dirección (w/a/s/d): ");
        scanf(" %c", &direccion);

        if (moverJugador(matriz, &fila, &columna, direccion)) {
            if (matriz[fila][columna] == 'E') {
                metaAlcanzada = 1;
                printf("¡Has alcanzado la meta!\n");
            }
        } else {
            printf("Movimiento inválido.\n");
        }
    }

    return 0;
}
