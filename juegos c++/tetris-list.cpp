#include <stdio.h>
#include <stdbool.h>

const int FILAS = 20;
const int COLUMNAS = 10;
const char VACIO = '.';
const char PIEZA = '#';

struct Coordenada {
    int fila;
    int columna;
};

struct Pieza {
    Coordenada coordenadas[4];
    char forma[4];
    struct Pieza* siguiente;
};

void inicializarTablero(char tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = VACIO;
        }
    }
}

void mostrarTablero(char tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

void colocarPieza(char tablero[FILAS][COLUMNAS], Pieza* pieza) {
    for (int i = 0; i < 4; i++) {
        Coordenada c = pieza->coordenadas[i];
        if (c.fila >= 0 && c.fila < FILAS && c.columna >= 0 && c.columna < COLUMNAS) {
            tablero[c.fila][c.columna] = PIEZA;
        }
    }
}

bool puedeMoverse(char tablero[FILAS][COLUMNAS], Pieza* pieza, Coordenada movimiento) {
    for (int i = 0; i < 4; i++) {
        Coordenada c = pieza->coordenadas[i];
        Coordenada nueva = {c.fila + movimiento.fila, c.columna + movimiento.columna};
        if (nueva.fila < 0 || nueva.fila >= FILAS || nueva.columna < 0 || nueva.columna >= COLUMNAS || tablero[nueva.fila][nueva.columna] == PIEZA) {
            return false;
        }
    }
    return true;
}

void moverPieza(char tablero[FILAS][COLUMNAS], Pieza* pieza, Coordenada movimiento) {
    if (puedeMoverse(tablero, pieza, movimiento)) {
        for (int i = 0; i < 4; i++) {
            Coordenada c = pieza->coordenadas[i];
            tablero[c.fila][c.columna] = VACIO;
        }
        for (int i = 0; i < 4; i++) {
            pieza->coordenadas[i].fila += movimiento.fila;
            pieza->coordenadas[i].columna += movimiento.columna;
        }
        colocarPieza(tablero, pieza);
    }
}

void inicializarPieza(Pieza* pieza, const Coordenada coordenadas[4], const char forma[4]) {
    for (int i = 0; i < 4; i++) {
        pieza->coordenadas[i] = coordenadas[i];
        pieza->forma[i] = forma[i];
    }
    pieza->siguiente = NULL;
}

void rotarPieza(Pieza* pieza) {
    for (int i = 0; i < 4; i++) {
        int temp = pieza->coordenadas[i].fila;
        pieza->coordenadas[i].fila = -pieza->coordenadas[i].columna;
        pieza->coordenadas[i].columna = temp;
    }
}

int main() {
    char tablero[FILAS][COLUMNAS];
    inicializarTablero(tablero);

    Coordenada formaPieza[4] = {{0, 4}, {0, 5}, {1, 4}, {1, 5}};
    char formaCaracteres[4] = {'#', '#', '#', '#'};
    Pieza pieza;
    inicializarPieza(&pieza, formaPieza, formaCaracteres);

    colocarPieza(tablero, &pieza);
    mostrarTablero(tablero);


    Coordenada movimiento = {1, 0};
    moverPieza(tablero, &pieza, movimiento);
    mostrarTablero(tablero);

    rotarPieza(&pieza);
    moverPieza(tablero, &pieza, movimiento);
    mostrarTablero(tablero);

    return 0;
}

