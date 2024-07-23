#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int FILAS = 10;
const int COLUMNAS = 10;

void mostrarMatriz(const bool matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c ", matriz[i][j] ? '*' : '.');
        }
        printf("\n");
    }
}

int contarVecinosVivos(const bool matriz[FILAS][COLUMNAS], int fila, int columna) {
    int vecinosVivos = 0;
    for (int i = fila - 1; i <= fila + 1; i++) {
        for (int j = columna - 1; j <= columna + 1; j++) {
            if (i >= 0 && i < FILAS && j >= 0 && j < COLUMNAS && (i != fila || j != columna) && matriz[i][j]) {
                vecinosVivos++;
            }
        }
    }
    return vecinosVivos;
}

void actualizarMatriz(const bool matriz[FILAS][COLUMNAS], bool nuevaMatriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            int vecinosVivos = contarVecinosVivos(matriz, i, j);
            if (matriz[i][j]) {
                nuevaMatriz[i][j] = (vecinosVivos == 2 || vecinosVivos == 3);
            } else {
                nuevaMatriz[i][j] = (vecinosVivos == 3);
            }
        }
    }
}

int main() {
    bool matriz[FILAS][COLUMNAS] = { false };
    bool nuevaMatriz[FILAS][COLUMNAS];
    int iteraciones;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = rand() % 2;
        }
    }

    printf("Introduce el número de iteraciones: ");
    scanf("%d", &iteraciones);

    for (int k = 0; k < iteraciones; k++) {
        mostrarMatriz(matriz);
        actualizarMatriz(matriz, nuevaMatriz);
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                matriz[i][j] = nuevaMatriz[i][j];
            }
        }
        printf("\n");
    }

    return 0;
}
