#include <stdio.h>

// Funci�n para realizar la b�squeda lineal
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

    // Ingresar el tama�o del arreglo
    printf("Ingrese el n�mero de elementos en el arreglo: ");
    scanf("%d", &n);

    // Definir el arreglo con el tama�o dado por el usuario
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
        printf("El elemento est� presente en el �ndice %d\n", resultado);
    } else {
        printf("El elemento no est� presente en el arreglo\n");
    }

    return 0;
}
