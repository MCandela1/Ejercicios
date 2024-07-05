#include <cstdio>

int main() {
    int array[10], resultado[10], n = 10, m = 0;
    printf("Introduce los elementos del arreglo (10 enteros):\n");
    for (int i = 0; i < 10; ++i) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; ++i) {
        bool encontrado = false;
        for (int j = 0; j < m; ++j) {
            if (array[i] == resultado[j]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            resultado[m++] = array[i];
        }
    }
    printf("El arreglo sin duplicados es:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
