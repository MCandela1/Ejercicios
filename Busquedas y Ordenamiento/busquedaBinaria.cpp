#include <stdio.h>


int busquedaBinaria(int arr[], int n, int x) {
    int cota_inf = 0, cota_sup = n - 1;

    while (cota_inf <= cota_sup) {
        int medio = cota_inf + (cota_sup - cota_inf) / 2;

        if (arr[medio] == x)
            return medio;

        if (arr[medio] < x)
            cota_inf = medio + 1;

        else
            cota_sup = medio - 1;
    }

    return -1;
}

int main() {
    int n;
    // Ingresar el tamaño del arreglo
    printf("Ingrese el numero de elementos en el arreglo: ");
    scanf("%d", &n);

    int arr[n];
    // Ingresar los elementos del arreglo
    printf("Ingrese los elementos del arreglo: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    // Ingresar el elemento a buscar
    printf("Ingrese el elemento a buscar:");
    scanf("%d", &x);
    // Realizar la búsqueda binaria
    int resultado = busquedaBinaria(arr, n, x);

    if(resultado != -1) {
        printf("El elemento esta presente en el indice %d\n", resultado);
    } else {
        printf("El elemento no esta presente en el arreglo\n");
    }

    return 0;
}
