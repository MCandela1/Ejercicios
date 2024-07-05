#include <cstdio>

int main() {
    int array[10];
    printf("Introduce los elementos del arreglo (10 enteros):\n");
    for (int i = 0; i < 10; ++i) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("El arreglo invertido es:\n");
    for (int i = 9; i >= 0; --i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
