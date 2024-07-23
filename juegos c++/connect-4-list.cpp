#include <stdio.h>

const int FILAS = 6;
const int COLUMNAS = 7;
const int MAX_MOVIMIENTOS = FILAS * COLUMNAS;

struct Nodo {
    int fila;
    int columna;
    struct Nodo* siguiente;
};

struct Nodo historial[MAX_MOVIMIENTOS];
int indiceHistorial = 0;

struct Nodo* crearNodo(int fila, int columna) {
    if (indiceHistorial < MAX_MOVIMIENTOS) {
        historial[indiceHistorial].fila = fila;
        historial[indiceHistorial].columna = columna;
        historial[indiceHistorial].siguiente = NULL;
        return &historial[indiceHistorial++];
    }
    return NULL;
}

void agregarMovimiento(struct Nodo** cabeza, int fila, int columna) {
    struct Nodo* nuevoNodo = crearNodo(fila, columna);
    if (nuevoNodo != NULL) {
        nuevoNodo->siguiente = *cabeza;
        *cabeza = nuevoNodo;
    }
}
void imprimirTablero(char tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("| %c ", tablero[i][j]);
        }
        printf("|\n");
    }
    printf("  1   2   3   4   5   6   7\n");
}

int realizarMovimiento(char tablero[FILAS][COLUMNAS], int columna, char jugador) {
    for (int i = FILAS - 1; i >= 0; i--) {
        if (tablero[i][columna] == ' ') {
            tablero[i][columna] = jugador;
            return i;
        }
    }
    return -1;
}

int verificarVictoria(char tablero[FILAS][COLUMNAS], int fila, int columna, char jugador) {
    // Verificar horizontal, vertical y diagonales
    int direccion[4][2] = { {0, 1}, {1, 0}, {1, 1}, {1, -1} };
    for (int d = 0; d < 4; d++) {
        int cuenta = 1;
        for (int i = 1; i < 4; i++) {
            int f = fila + i * direccion[d][0];
            int c = columna + i * direccion[d][1];
            if (f >= 0 && f < FILAS && c >= 0 && c < COLUMNAS && tablero[f][c] == jugador) {
                cuenta++;
            } else {
                break;
            }
        }
        for (int i = 1; i < 4; i++) {
            int f = fila - i * direccion[d][0];
            int c = columna - i * direccion[d][1];
            if (f >= 0 && f < FILAS && c >= 0 && c < COLUMNAS && tablero[f][c] == jugador) {
                cuenta++;
            } else {
                break;
            }
        }
        if (cuenta >= 4) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char tablero[FILAS][COLUMNAS];
    struct Nodo* historial = NULL;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = ' ';
        }
    }

    int jugador = 1;
    while (1) {
        imprimirTablero(tablero);
        int columna;
        printf("Jugador %d, elige una columna (1-7): ", jugador);
        scanf("%d", &columna);
        columna--;

        if (columna < 0 || columna >= COLUMNAS) {
            printf("Columna invalida. Intenta nuevamente.\n");
            continue;
        }

        int fila = realizarMovimiento(tablero, columna, jugador == 1 ? 'X' : 'O');
        if (fila == -1) {
            printf("Columna llena. Intenta nuevamente.\n");
            continue;
        }

        agregarMovimiento(&historial, fila, columna);

        if (verificarVictoria(tablero, fila, columna, jugador == 1 ? 'X' : 'O')) {
            imprimirTablero(tablero);
            printf("Jugador %d gana!\n", jugador);
            break;
        }

        jugador = 3 - jugador;
    }

    return 0;
}

