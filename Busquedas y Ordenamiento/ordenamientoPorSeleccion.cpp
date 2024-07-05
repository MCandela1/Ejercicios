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
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        int temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
    printf("Arreglo ordenado en orden descendente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
