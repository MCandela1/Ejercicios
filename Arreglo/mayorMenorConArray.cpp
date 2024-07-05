#include <cstdio>

int main() {
    int array[10];
    printf("Introduce los elementos del arreglo (10 enteros):\n");
    for (int i = 0; i < 10; ++i) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    int mayor = array[0];
    int menor = array[0];

    for (int i = 1; i < 10; ++i) {
        if (array[i] > mayor) {
            mayor = array[i];
        }
        if (array[i] < menor) {
            menor = array[i];
        }
    }
    printf("El mayor elemento es: %d\n", mayor);
    printf("El menor elemento es: %d\n", menor);

    return 0;
}
