#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, valor, encontrado = 0;

    printf("Ingrese el numero de elementos del vector: ");
    scanf("%d", &n);

    int arr[n];
    printf("Ingrese los elementos del vector:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Ingrese el valor a buscar en el vector: ");
    scanf("%d", &valor);
    for (int i = 0; i < n; i++) {
        if (arr[i] == valor) {
            encontrado = 1;
            break;
        }
    }
    if (encontrado) {
        printf("El valor %d esta en el vector.\n", valor);
    } else {
        printf("El valor %d no esta en el vector.\n", valor);
    }

    return 0;
}
