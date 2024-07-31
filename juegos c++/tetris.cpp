#include <cstdio>
#include <cstdlib>

const int FILAS = 20;
const int COLUMNAS = 10;

const char VACIO = '.';
const char PIEZA = '#';

struct Pieza {
    int forma[4][4];
    int tamanio;
};

Pieza piezas[7] = {
    {{{1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 4},  // I
    {{{1, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 3},  // T
    {{{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 2},  // O
    {{{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 3},  // Z
    {{{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 3},  // S
    {{{1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 3},  // J
    {{{0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, 3},  // L
};

char tablero[FILAS][COLUMNAS];

int xActual = 0, yActual = 0;
int piezaActual = 0;
int nivel = 1;
int puntaje = 0;
int velocidad = 1000;

void inicializarTablero() { ///inicializo con celdas vacias
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            tablero[i][j] = VACIO;
        }
    }
}

void mostrarTablero() {
    system("cls");
    printf("Puntaje: %d\n", puntaje);
    printf("Nivel: %d\n", nivel);
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

void colocarPieza(Pieza& p, int x, int y, char simbolo) {
    for (int i = 0; i < p.tamanio; ++i) {
        for (int j = 0; j < p.tamanio; ++j) {
            if (p.forma[i][j] == 1) {
                tablero[y + i][x + j] = simbolo;
            }
        }
    }
}

void rotarPieza(Pieza& p) {///agrege la rotacion de la pieza para que encaje bien en los espacios y llene los espacios vacios
    Pieza rotada = p;
    for (int i = 0; i < p.tamanio; ++i) {
        for (int j = 0; j < p.tamanio; ++j) {
            rotada.forma[j][p.tamanio - 1 - i] = p.forma[i][j];
        }
    }
    p = rotada;
}

bool comprobarColision(Pieza& p, int x, int y) {///tengo que comprobar la colision asi evito que se superpongan las piezas
    for (int i = 0; i < p.tamanio; ++i) {
        for (int j = 0; j < p.tamanio; ++j) {
            if (p.forma[i][j] == 1) {
                if (y + i >= FILAS || x + j >= COLUMNAS || x + j < 0 || tablero[y + i][x + j] != VACIO) {
                    return true;
                }
            }
        }
    }
    return false;
}

void actualizarPuntuacion(int lineasCompletas) {
    puntaje += lineasCompletas * 100;
    if (puntaje >= nivel * 500) {
        nivel++;
        velocidad = velocidad * 0.9;
    }
}

void detectarYEliminarLineas() {/// elimina las filas que se completan
    for (int i = 0; i < FILAS; ++i) {
        bool completa = true;
        for (int j = 0; j < COLUMNAS; ++j) {
            if (tablero[i][j] == VACIO) {
                completa = false;
                break;
            }
        }
        if (completa) {
            for (int k = i; k > 0; --k) {
                for (int l = 0; l < COLUMNAS; ++l) {
                    tablero[k][l] = tablero[k - 1][l];
                }
            }
            for (int l = 0; l < COLUMNAS; ++l) {
                tablero[0][l] = VACIO;
            }
            actualizarPuntuacion(1);
        }
    }
}

bool finDelJuego() {
    for (int j = 0; j < COLUMNAS; ++j) {
        if (tablero[0][j] != VACIO) {
            return true;
        }
    }
    return false;
}
int main() {
    inicializarTablero();
    piezaActual = 0;
    bool juegoTerminado = false;
    xActual = COLUMNAS / 2 - 2;
    yActual = 0;

    while (!juegoTerminado) {
        colocarPieza(piezas[piezaActual], xActual, yActual, PIEZA);
        mostrarTablero();
        colocarPieza(piezas[piezaActual], xActual, yActual, VACIO);

        char input;
        scanf(" %c", &input);
        if (input == 'a') {
            if (!comprobarColision(piezas[piezaActual], xActual - 1, yActual)) xActual--;
        } else if (input == 'd') {
            if (!comprobarColision(piezas[piezaActual], xActual + 1, yActual)) xActual++;
        } else if (input == 's') {
            if (!comprobarColision(piezas[piezaActual], xActual, yActual + 1)) yActual++;
        } else if (input == 'w') {
            rotarPieza(piezas[piezaActual]);
            if (comprobarColision(piezas[piezaActual], xActual, yActual)) {
                rotarPieza(piezas[piezaActual]);
                rotarPieza(piezas[piezaActual]);
                rotarPieza(piezas[piezaActual]);
            }
        }

        if (!comprobarColision(piezas[piezaActual], xActual, yActual + 1)) {
            yActual++;
        } else {
            colocarPieza(piezas[piezaActual], xActual, yActual, PIEZA);
            detectarYEliminarLineas();
            if (finDelJuego()) {
                printf("¡Juego terminado!\n");
                juegoTerminado = true;
            } else {
                piezaActual = rand() % 7;
                xActual = COLUMNAS / 2 - 2;
                yActual = 0;
            }
        }
        _sleep(velocidad);
    }
    return 0;
}


