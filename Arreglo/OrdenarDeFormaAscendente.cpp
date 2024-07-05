#include <cstdio>

void Burbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int array[10];
    printf("Introduce los elementos del arreglo (10 enteros):\n");
    for (int i = 0; i < 10; ++i) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    Burbuja(array, 10);
    printf("El arreglo ordenado es:\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
