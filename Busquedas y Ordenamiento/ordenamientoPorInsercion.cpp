#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;

    printf("Ingrese el numero de elementos del arreglo: ");
    scanf("%d", &n);

    int arr[n];

    printf("Ingrese los elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Arreglo ordenado en orden ascendente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
