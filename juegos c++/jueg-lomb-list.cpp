#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

const int FILAS = 20;
const int COLUMNAS = 20;
const int MAX_LONGITUD = 100;
const char VACIO = ' ';
const char COMIDA = '*';
const char LOMBRIZ = '#';
const char PARED = '#';

struct Segmento {
    int fila, columna;
};

void inicializarTablero(char tablero[FILAS][COLUMNAS], Segmento lombriz[MAX_LONGITUD], int longitud, int &comidaFila, int &comidaColumna) {
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            if (i == 0 || i == FILAS - 1 || j == 0 || j == COLUMNAS - 1) {
                tablero[i][j] = PARED;
            } else {
                tablero[i][j] = VACIO;
            }
        }
    }

    for (int i = 0; i < longitud; ++i) {
        lombriz[i].fila = FILAS / 2;
        lombriz[i].columna = COLUMNAS / 2 - i;
    }

    srand(rand());
    comidaFila = rand() % (FILAS - 2) + 1;
    comidaColumna = rand() % (COLUMNAS - 2) + 1;
}

void mostrarTablero(char tablero[FILAS][COLUMNAS], Segmento lombriz[MAX_LONGITUD], int longitud, int comidaFila, int comidaColumna) {

    for (int i = 1; i < FILAS - 1; ++i) {
        for (int j = 1; j < COLUMNAS - 1; ++j) {
            tablero[i][j] = VACIO;
        }
    }

    for (int i = 0; i < longitud; ++i) {
        tablero[lombriz[i].fila][lombriz[i].columna] = LOMBRIZ;
    }

    tablero[comidaFila][comidaColumna] = COMIDA;

   for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            printf("%c", tablero[i][j]);
        }
        printf("\n");
    }
}

void moverLombriz(Segmento lombriz[MAX_LONGITUD], int &longitud, int nuevaFila, int nuevaColumna, bool crecer) {
    for (int i = longitud - 1; i > 0; --i) {
        lombriz[i] = lombriz[i - 1];
    }

    lombriz[0].fila = nuevaFila;
    lombriz[0].columna = nuevaColumna;

    if (crecer) {
        longitud++;
    }
}

bool verificarColision(Segmento lombriz[MAX_LONGITUD], int longitud) {
    int cabezaFila = lombriz[0].fila;
    int cabezaColumna = lombriz[0].columna;
    for (int i = 1; i < longitud; ++i) {
        if (lombriz[i].fila == cabezaFila && lombriz[i].columna == cabezaColumna) {
            return true;
        }
    }
    return false;
}

int main() {
    char tablero[FILAS][COLUMNAS];
    Segmento lombriz[MAX_LONGITUD];
    int longitud = 5;
    int comidaFila, comidaColumna;
    char direccion = 'd';
    bool crecer = false;

    inicializarTablero(tablero, lombriz, longitud, comidaFila, comidaColumna);

    while (true) {
        mostrarTablero(tablero, lombriz, longitud, comidaFila, comidaColumna);
        printf("Ingrese la direccion (w: arriba, s: abajo, a: izquierda, d: derecha): ");
        scanf(" %c", &direccion);

        int nuevaFila = lombriz[0].fila;
        int nuevaColumna = lombriz[0].columna;

        switch (direccion) {
            case 'w':
                nuevaFila--;
                break;
            case 's':
                nuevaFila++;
                break;
            case 'a':
                nuevaColumna--;
                break;
            case 'd':
                nuevaColumna++;
                break;
            default:
                printf("Direccion invalida. Usa w, s, a o d.\n");
                continue;
        }

        if (nuevaFila <= 0 || nuevaFila >= FILAS - 1 || nuevaColumna <= 0 || nuevaColumna >= COLUMNAS - 1) {
            printf("¡Perdiste! Chocaste con el borde.\n");
            break;
        }

        if (verificarColision(lombriz, longitud)) {
            printf("¡Perdiste! Chocaste contigo mismo.\n");
            break;
        }

        if (nuevaFila == comidaFila && nuevaColumna == comidaColumna) {
            crecer = true;
            comidaFila = rand() % (FILAS - 2) + 1;
            comidaColumna = rand() % (COLUMNAS - 2) + 1;
        } else {
            crecer = false;
        }

        moverLombriz(lombriz, longitud, nuevaFila, nuevaColumna, crecer);
    }

    return 0;
}
