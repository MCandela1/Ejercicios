#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constantes
const int FILAS = 5;
const int COLUMNAS = 4;
const int MINAS_MIN = 3;
const int MINAS_MAX = 5;
const char* CREADOR = "Desarrollado por [Tu Nombre]";

// Función para inicializar el tablero y el revelado
void inicializarTablero(int tablero[FILAS][COLUMNAS], int revelado[FILAS][COLUMNAS]) {
    int numMinas = MINAS_MIN + (rand() % (MINAS_MAX - MINAS_MIN + 1));

    // Inicializar el tablero con 0 (zonas seguras)
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = 0;
            revelado[i][j] = 0;
        }
    }

    // Colocar las minas en el tablero
    int colocadas = 0;
    while (colocadas < numMinas) {
        int fila = rand() % FILAS;
        int columna = rand() % COLUMNAS;
        if (tablero[fila][columna] == 0) {
            tablero[fila][columna] = 1;
            colocadas++;
        }
    }
}

// Función para mostrar el tablero con las posiciones
void mostrarTableroConPosiciones() {
    printf("   ");
    for (int j = 0; j < COLUMNAS; j++) {
        printf("%d ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < FILAS; i++) {
        printf("%c: ", 'A' + i);
        for (int j = 0; j < COLUMNAS; j++) {
            printf(". ");
        }
        printf("\n");
    }
}

// Función para mostrar el tablero revelado
void mostrarTableroRevelado(int tablero[FILAS][COLUMNAS], int revelado[FILAS][COLUMNAS]) {
    printf("   ");
    for (int j = 0; j < COLUMNAS; j++) {
        printf("%d ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < FILAS; i++) {
        printf("%c: ", 'A' + i);
        for (int j = 0; j < COLUMNAS; j++) {
            if (revelado[i][j] == 1) {
                if (tablero[i][j] == 0) {
                    printf("0 ");
                } else {
                    printf("1 ");
                }
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Función para convertir las coordenadas ingresadas por el usuario a índices de matriz
void convertirCoordenadas(char coordenadas[], int* fila, int* columna) {
    *fila = coordenadas[0] - 'A';
    *columna = coordenadas[1] - '1';
}

// Función para explorar el tablero
void explorar(int tablero[FILAS][COLUMNAS], int revelado[FILAS][COLUMNAS]) {
    int vidas = 2;
    while (vidas > 0) {
        char coordenadas[3];
        int fila, columna;
        printf("Ingrese la posición a explorar (por ejemplo, B2): ");
        scanf("%s", coordenadas);

        convertirCoordenadas(coordenadas, &fila, &columna);

        if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS) {
            printf("Posición fuera de rango. Intente de nuevo.\n");
            continue;
        }

        if (tablero[fila][columna] == 1) {
            printf("¡BOOM! Mina encontrada en %c%d. Has perdido una vida.\n", 'A' + fila, columna + 1);
            vidas--;
            if (vidas > 0) {
                printf("Te queda 1 vida.\n");
            }
        } else {
            revelado[fila][columna] = 1;
            printf("Zona segura en %c%d. Puedes seguir explorando.\n", 'A' + fila, columna + 1);
        }

        if (vidas > 0) {
            mostrarTableroRevelado(tablero, revelado);
        } else {
            printf("Se acabaron las vidas. Fin del juego.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    int tablero[FILAS][COLUMNAS];
    int revelado[FILAS][COLUMNAS];
    int opcion;

    inicializarTablero(tablero, revelado);

    do {
        printf("\nMenú:\n");
        printf("1) Crear nueva partida\n");
        printf("2) Explorar\n");
        printf("3) Mostrar el tablero\n");
        printf("4) Créditos\n");
        printf("5) Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                inicializarTablero(tablero, revelado);
                printf("Nueva partida creada.\n");
                break;
            case 2:
                explorar(tablero, revelado);
                break;
            case 3:
                mostrarTableroConPosiciones();
                break;
            case 4:
                printf("%s\n", CREADOR);
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}

