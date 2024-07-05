#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;

    printf("Ingrese el numero de elementos del vector: ");
    scanf("%d", &n);

    int arr[n];
    printf("Ingrese los elementos del vector:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int mayor = arr[0];
    int menor = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > mayor) {
            mayor = arr[i];
        }
        if (arr[i] < menor) {
            menor = arr[i];
        }
    }

    printf("El mayor elemento es: %d\n", mayor);
    printf("El menor elemento es: %d\n", menor);

    return 0;
}
