#include <cstdio>

int main() {
    int array[10], sum = 0;
    printf("Introduce los elementos del arreglo (10 enteros):\n");
    for (int i = 0; i < 10; ++i) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < 10; ++i) {
        sum += array[i];
    }
    printf("La suma de los elementos es: %d\n", sum);

return 0;
}
