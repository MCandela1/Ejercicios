#include <stdio.h>
#include <stdbool.h>

const int FILAS = 5;
const int COLUMNAS = 5;

void mostrarMatriz(const char matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int calcularLongitud(const char* cadena) {
    int longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}

bool buscarPalabraHorizontal(const char matriz[FILAS][COLUMNAS], const char* palabra) {
    int longitud = calcularLongitud(palabra);

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j <= COLUMNAS - longitud; j++) {
            bool encontrado = true;
            for (int k = 0; k < longitud; k++) {
                if (matriz[i][j + k] != palabra[k]) {
                    encontrado = false;
                    break;
                }
            }
            if (encontrado) return true;
        }
    }
    return false;
}

bool buscarPalabraVertical(const char matriz[FILAS][COLUMNAS], const char* palabra) {
    int longitud = calcularLongitud(palabra);

    for (int j = 0; j < COLUMNAS; j++) {
        for (int i = 0; i <= FILAS - longitud; i++) {
            bool encontrado = true;
            for (int k = 0; k < longitud; k++) {
                if (matriz[i + k][j] != palabra[k]) {
                    encontrado = false;
                    break;
                }
            }
            if (encontrado) return true;
        }
    }
    return false;
}

int main() {
    char matriz[FILAS][COLUMNAS] = {
        {'F', 'E', 'R', 'I', 'A'},
        {'F', 'G', 'H', 'I', 'A'},
        {'P', 'E', 'R', 'R', 'O'},
        {'P', 'V', 'R', 'S', 'O'},
        {'U', 'A', 'W', 'X', 'B'}
    };

    mostrarMatriz(matriz);

    char palabra[20];
    printf("Introduce la palabra a buscar: ");
    scanf("%19s", palabra);

    if (buscarPalabraHorizontal(matriz, palabra) || buscarPalabraVertical(matriz, palabra)) {
        printf("Palabra encontrada.\n");
    } else {
        printf("Palabra no encontrada.\n");
    }

    return 0;
}
