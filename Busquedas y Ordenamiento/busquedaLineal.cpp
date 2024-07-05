#include <stdio.h>

// Función para realizar la búsqueda lineal
int busquedaLineal(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;

    // Ingresar el tamaño del arreglo
    printf("Ingrese el número de elementos en el arreglo: ");
    scanf("%d", &n);

    // Definir el arreglo con el tamaño dado por el usuario
    int arr[n];

    // Ingresar los elementos del arreglo
    printf("Ingrese los elementos del arreglo: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Ingrese el elemento a buscar: ");
    scanf("%d", &x);
    int resultado = busquedaLineal(arr, n, x);

    if (resultado != -1) {
        printf("El elemento está presente en el índice %d\n", resultado);
    } else {
        printf("El elemento no está presente en el arreglo\n");
    }

    return 0;
}
