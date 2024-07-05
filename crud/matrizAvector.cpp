#include <cstdio>

const int TAMANIO = 3;
int matriz[TAMANIO][TAMANIO];
int vector[TAMANIO * TAMANIO];

void ingresarMatriz() {
    printf("Ingrese los elementos de una matriz 3x3:\n");
    for (int i = 0; i < TAMANIO; ++i) {
        for (int j = 0; j < TAMANIO; ++j) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void convertirMatrizAVector() {
    int k = 0;
    for (int i = 0; i < TAMANIO; ++i) {
        for (int j = 0; j < TAMANIO; ++j) {
            vector[k++] = matriz[i][j];
        }
    }
}

void imprimirVector() {
    printf("Vector:\n");
    for (int i = 0; i < TAMANIO * TAMANIO; ++i) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void ordenarBurbuja() {
    for (int i = 0; i < TAMANIO * TAMANIO - 1; ++i) {
        for (int j = 0; j < TAMANIO * TAMANIO - 1 - i; ++j) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

void actualizarElementoMatriz() {
    int fila, columna, nuevoValor;
    printf("Ingrese la fila del elemento a actualizar (0-2): ");
    scanf("%d", &fila);
    printf("Ingrese la columna del elemento a actualizar (0-2): ");
    scanf("%d", &columna);
    if (fila >= 0 && fila < TAMANIO && columna >= 0 && columna < TAMANIO) {
        printf("Ingrese el nuevo valor: ");
        scanf("%d", &nuevoValor);
        matriz[fila][columna] = nuevoValor;
    } else {
        printf("Índice no válido.\n");
    }
}

void eliminarElementoMatriz() {
    int fila, columna;
    printf("Ingrese la fila del elemento a eliminar (0-2): ");
    scanf("%d", &fila);
    printf("Ingrese la columna del elemento a eliminar (0-2): ");
    scanf("%d", &columna);
    if (fila >= 0 && fila < TAMANIO && columna >= 0 && columna < TAMANIO) {
        matriz[fila][columna] = 0;  // Asignar 0 para "eliminar" el elemento
    } else {
        printf("Índice no válido.\n");
    }
}

void imprimirMatriz() {
    printf("Matriz:\n");
    for (int i = 0; i < TAMANIO; ++i) {
        for (int j = 0; j < TAMANIO; ++j) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int opcion;

    while (true) {
        printf("1. Ingresar matriz\n");
        printf("2. Convertir matriz a vector\n");
        printf("3. Imprimir vector\n");
        printf("4. Ordenar vector (Burbuja)\n");
        printf("5. Actualizar elemento de la matriz\n");
        printf("6. Eliminar elemento de la matriz\n");
        printf("7. Imprimir matriz\n");
        printf("8. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarMatriz();
                break;
            case 2:
                convertirMatrizAVector();
                break;
            case 3:
                imprimirVector();
                break;
            case 4:
                ordenarBurbuja();
                break;
            case 5:
                actualizarElementoMatriz();
                break;
            case 6:
                eliminarElementoMatriz();
                break;
            case 7:
                imprimirMatriz();
                break;
            case 8:
                return 0;
            default:
                printf("Opción no válida.\n");
        }
    }

    return 0;
}
