#include <cstdio>

const int TAMANIO = 3;

void ingresarMatriz(int matriz[TAMANIO][TAMANIO]) {
    printf("Ingrese los elementos de una matriz 3x3:\n");
    for (int i = 0; i < TAMANIO; ++i) {
        for (int j = 0; j < TAMANIO; ++j) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void buscarElemento(int matriz[TAMANIO][TAMANIO]) {
    int elemento;
    printf("Ingrese el elemento a buscar: ");
    scanf("%d", &elemento);
    for (int i = 0; i < TAMANIO; ++i) {
        for (int j = 0; j < TAMANIO; ++j) {
            if (matriz[i][j] == elemento) {
                printf("Elemento encontrado en [%d][%d]\n", i, j);
                return;
            }
        }
    }
    printf("Elemento no encontrado.\n");
}

int calcularDeterminante(int matriz[TAMANIO][TAMANIO]) {
    int determinante = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1])
                     - matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0])
                     + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]);
    return determinante;
}

void identificarParImpar(int matriz[TAMANIO][TAMANIO]) {
    printf("Números pares en la matriz:\n");
    for (int i = 0; i < TAMANIO; ++i) {
        for (int j = 0; j < TAMANIO; ++j) {
            if (matriz[i][j] % 2 == 0) {
                printf("%d ", matriz[i][j]);
            }
        }
    }
    printf("\nNúmeros impares en la matriz:\n");
    for (int i = 0; i < TAMANIO; ++i) {
        for (int j = 0; j < TAMANIO; ++j) {
            if (matriz[i][j] % 2 != 0) {
                printf("%d ", matriz[i][j]);
            }
        }
    }
    printf("\n");
}

void mostrarTranspuesta(int matriz[TAMANIO][TAMANIO]) {
    printf("Matriz transpuesta:\n");
    for (int i = 0; i < TAMANIO; ++i) {
        for (int j = 0; j < TAMANIO; ++j) {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }
}

void multiplicarMatrices(int matriz1[TAMANIO][TAMANIO], int matriz2[TAMANIO][TAMANIO], int resultado[TAMANIO][TAMANIO]) {
    for (int i = 0; i < TAMANIO; ++i) {
        for (int j = 0; j < TAMANIO; ++j) {
            resultado[i][j] = 0;
            for (int k = 0; k < TAMANIO; ++k) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

void sumarMatrices(int matriz1[TAMANIO][TAMANIO], int matriz2[TAMANIO][TAMANIO], int resultado[TAMANIO][TAMANIO]) {
    for (int i = 0; i < TAMANIO; ++i) {
        for (int j = 0; j < TAMANIO; ++j) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void imprimirMatriz(int matriz[TAMANIO][TAMANIO]) {
    for (int i = 0; i < TAMANIO; ++i) {
        for (int j = 0; j < TAMANIO; ++j) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void eliminarElemento(int matriz[TAMANIO][TAMANIO], int fila, int columna) {
    if (fila < 0 || fila >= TAMANIO || columna < 0 || columna >= TAMANIO) {
        printf("Índice fuera de rango. No se puede eliminar.\n");
        return;
    }
    matriz[fila][columna] = 0;
    printf("Elemento eliminado.\n");
}

int main() {
    int matriz1[TAMANIO][TAMANIO], matriz2[TAMANIO][TAMANIO], resultado[TAMANIO][TAMANIO];
    int opcion;

    while (true) {
        printf("1. Ingresar matriz\n");
        printf("2. Buscar elemento en matriz\n");
        printf("3. Calcular determinante de la matriz\n");
        printf("4. Identificar números pares e impares en la matriz\n");
        printf("5. Mostrar matriz transpuesta\n");
        printf("6. Multiplicar dos matrices\n");
        printf("7. Sumar dos matrices\n");
        printf("8. Imprimir matriz\n");
        printf("9. Eliminar un elemento de la matriz\n");
        printf("10. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarMatriz(matriz1);
                break;
            case 2:
                buscarElemento(matriz1);
                break;
            case 3:
                printf("La determinante de la matriz es: %d\n", calcularDeterminante(matriz1));
                break;
            case 4:
                identificarParImpar(matriz1);
                break;
            case 5:
                mostrarTranspuesta(matriz1);
                break;
            case 6:
                printf("Ingrese la segunda matriz para multiplicar:\n");
                ingresarMatriz(matriz2);
                multiplicarMatrices(matriz1, matriz2, resultado);
                printf("El resultado de la multiplicación es:\n");
                imprimirMatriz(resultado);
                break;
            case 7:
                printf("Ingrese la segunda matriz para sumar:\n");
                ingresarMatriz(matriz2);
                sumarMatrices(matriz1, matriz2, resultado);
                printf("El resultado de la suma es:\n");
                imprimirMatriz(resultado);
                break;
            case 8:
                imprimirMatriz(matriz1);
                break;
            case 9:
                int fila, columna;
                printf("Ingrese la fila del elemento a eliminar (0 a %d): ", TAMANIO - 1);
                scanf("%d", &fila);
                printf("Ingrese la columna del elemento a eliminar (0 a %d): ", TAMANIO - 1);
                scanf("%d", &columna);
                eliminarElemento(matriz1, fila, columna);
                break;
            case 10:
                return 0;
            default:
                printf("Opción no válida.\n");
        }
    }

    return 0;
}

