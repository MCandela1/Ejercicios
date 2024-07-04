#include <cstdio>

const int MAX = 100;
int vector[MAX];
int tam;

void ingresarVector() {
    printf("Ingrese el tamaño del vector: ");
    scanf("%d", &tam);
    printf("Ingrese los elementos del vector:\n");
    for (int i = 0; i < tam; ++i) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &vector[i]);
    }
}

void buscarElemento() {
    int elemento;
    printf("Ingrese el elemento a buscar: ");
    scanf("%d", &elemento);
    for (int i = 0; i < tam; ++i) {
        if (vector[i] == elemento) {
            printf("Elemento encontrado en la posición %d\n", i);
            return;
        }
    }
    printf("Elemento no encontrado.\n");
}

void encontrarMayorMenor() {
    int mayor = vector[0], menor = vector[0];
    for (int i = 1; i < tam; ++i) {
        if (vector[i] > mayor) {
            mayor = vector[i];
        }
        if (vector[i] < menor) {
            menor = vector[i];
        }
    }
    printf("El número mayor es: %d\n", mayor);
    printf("El número menor es: %d\n", menor);
}

void ordenarAscendente() {
    for (int i = 0; i < tam - 1; ++i) {
        for (int j = 0; j < tam - 1 - i; ++j) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
    printf("Vector ordenado de forma ascendente:\n");
    for (int i = 0; i < tam; ++i) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void mostrarSuma() {
    int suma = 0;
    for (int i = 0; i < tam; ++i) {
        suma += vector[i];
    }
    printf("La suma de los elementos del vector es: %d\n", suma);
}

void eliminarElemento() {
    int indice;
    printf("Ingrese el índice del elemento a eliminar (0 a %d): ", tam - 1);
    scanf("%d", &indice);

    if (indice < 0 || indice >= tam) {
        printf("Índice fuera de rango. No se puede eliminar.\n");
        return;
    }

    for (int i = indice; i < tam - 1; ++i) {
        vector[i] = vector[i + 1];
    }
    tam--;

    printf("Elemento eliminado. El vector ahora es:\n");
    for (int i = 0; i < tam; ++i) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int main() {
    int opcion;

    while (true) {
        printf("1. Ingresar vector\n");
        printf("2. Buscar elemento en el vector\n");
        printf("3. Encontrar número mayor y menor en el vector\n");
        printf("4. Ordenar vector de forma ascendente\n");
        printf("5. Mostrar suma de los elementos del vector\n");
        printf("6. Eliminar un elemento del vector\n");
        printf("7. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarVector();
                break;
            case 2:
                buscarElemento();
                break;
            case 3:
                encontrarMayorMenor();
                break;
            case 4:
                ordenarAscendente();
                break;
            case 5:
                mostrarSuma();
                break;
            case 6:
                eliminarElemento();
                break;
            case 7:
                return 0;
            default:
                printf("Opción no válida.\n");
        }
    }

    return 0;
}

