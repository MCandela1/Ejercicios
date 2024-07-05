//Operaciones CRUD con Matrices

//Crear una matriz: Pide al usuario que ingrese las dimensiones de la matriz (filas y columnas) y luego los elementos para llenarla.

//Leer una matriz: Muestra todos los elementos de la matriz.

//Actualizar una matriz: Permite al usuario modificar un elemento específico de la matriz.

//Borrar elementos de una matriz: Elimina un elemento en una posición dada por el usuario.

#include <cstdio>
#include <vector>

using namespace std;

void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (int i = 0; i < matriz.size(); ++i) {
        for (int j = 0; j < matriz[i].size(); ++j) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void eliminarElemento(vector<vector<int>>& matriz, int filaEliminar, int colEliminar) {
    if (filaEliminar < 0 || filaEliminar >= matriz.size() ||
        colEliminar < 0 || colEliminar >= matriz[0].size()) {
        printf("Índices fuera de rango. No se puede eliminar.\n");
        return;
    }

    // Eliminar fila
    for (int i = filaEliminar; i < matriz.size() - 1; ++i) {
        matriz[i] = matriz[i + 1];
    }
    matriz.pop_back();

    // Eliminar columna
    for (int i = 0; i < matriz.size(); ++i) {
        for (int j = colEliminar; j < matriz[i].size() - 1; ++j) {
            matriz[i][j] = matriz[i][j + 1];
        }
        matriz[i].pop_back();
    }
}

int main() {
    vector<vector<int>> matriz;
    int filas, columnas;

    printf("Ingrese el número de filas de la matriz: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas de la matriz: ");
    scanf("%d", &columnas);

    printf("Ingrese los elementos para llenar la matriz %dx%d:\n", filas, columnas);
    for (int i = 0; i < filas; ++i) {
        vector<int> fila(columnas);
        for (int j = 0; j < columnas; ++j) {
            scanf("%d", &fila[j]);
        }
        matriz.push_back(fila);
    }

    printf("La matriz ingresada es:\n");
    imprimirMatriz(matriz);

    int filaActualizar, colActualizar, nuevoValor;
    printf("Ingrese el número de fila del elemento que desea actualizar (0 a %d): ", filas - 1);
    scanf("%d", &filaActualizar);
    printf("Ingrese el número de columna del elemento que desea actualizar (0 a %d): ", columnas - 1);
    scanf("%d", &colActualizar);

    if (filaActualizar >= 0 && filaActualizar < filas && colActualizar >= 0 && colActualizar < columnas) {
        printf("Ingrese el nuevo valor para este elemento: ");
        scanf("%d", &nuevoValor);
        matriz[filaActualizar][colActualizar] = nuevoValor; // Actualizar el valor en la posición especificada
        printf("La matriz actualizada es:\n");
        imprimirMatriz(matriz);
    } else {
        printf("Índices fuera de rango. No se puede actualizar.\n");
    }

    int filaEliminar, colEliminar;
    printf("Ingrese el número de fila del elemento que desea eliminar (0 a %d): ", filas - 1);
    scanf("%d", &filaEliminar);
    printf("Ingrese el número de columna del elemento que desea eliminar (0 a %d): ", columnas - 1);
    scanf("%d", &colEliminar);

    eliminarElemento(matriz, filaEliminar, colEliminar);

    printf("La matriz después de eliminar el elemento es:\n");
    imprimirMatriz(matriz);

    return 0;
}
