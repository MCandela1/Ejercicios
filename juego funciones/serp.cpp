#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int FILAS = 20;
const int COLUMNAS = 20;

const char VACIO = ' ';
const char COMIDA = 'F';
const char SERPIENTE = 'S';

struct Posicion {
    int x, y;
};

void inicializarMatriz(char matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = VACIO;
        }
    }
}

void mostrarMatriz(const char matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

void moverSerpiente(struct Posicion* cabeza, char direccion) {
    switch (direccion) {
        case 'w':
            cabeza->x--;
            break;
        case 's':
            cabeza->x++;
            break;
        case 'a':
            cabeza->y--;
            break;
        case 'd':
            cabeza->y++;
            break;
    }
}

int generarNumeroAleatorio(int limite) {
    return rand() % limite;
}

int main() {
    char matriz[FILAS][COLUMNAS];
    struct Posicion cabeza = { FILAS / 2, COLUMNAS / 2 };
    struct Posicion comida = { generarNumeroAleatorio(FILAS), generarNumeroAleatorio(COLUMNAS) };
    char direccion = 'd';

    inicializarMatriz(matriz);

    while (true) {
        inicializarMatriz(matriz);
        matriz[cabeza.x][cabeza.y] = SERPIENTE;
        matriz[comida.x][comida.y] = COMIDA;

        mostrarMatriz(matriz);

        printf("Introduce la dirección (w: arriba, s: abajo, a: izquierda, d: derecha): ");
        scanf(" %c", &direccion);

        moverSerpiente(&cabeza, direccion);

    }

    return 0;
}
