#include <stdio.h>

int busquedaBinariaRecursiva(int arr[], int cota_inf, int cota_sup, int x) {
    if (cota_inf <= cota_sup) {
        int medio = cota_inf + (cota_sup - cota_inf) / 2;


        if (arr[medio] == x) // Verifico si el elemento está presente en el medio
            return medio;

        // Si el elemento es menor que el medio, entonces solo puede estar en el subarreglo izquierdo
        if (arr[medio] > x)
            return busquedaBinariaRecursiva(arr, cota_inf, medio - 1, x);

        // Si el elemento es mayor que el medio, entonces solo puede estar en el subarreglo derecho
        return busquedaBinariaRecursiva(arr, medio + 1, cota_sup, x);
    }

    // Si llegamos aquí, el elemento no está presente
    return -1;
}

int main() {
    int n;
    printf("Ingrese el numero de elementos en el arreglo: ");
    scanf("%d", &n);

    // Definir el arreglo con el tamaño dado por el usuario
    int arr[n];

    printf("Ingrese los elementos del arreglo en orden ascendente: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;

    printf("Ingrese el elemento a buscar: ");
    scanf("%d", &x);

    int resultado = busquedaBinariaRecursiva(arr, 0, n - 1, x);

    if (resultado != -1) {
        printf("El elemento esta presente en el indice %d\n", resultado);
    } else {
        printf("El elemento no esta presente en el arreglo\n");
    }

    return 0;
}


