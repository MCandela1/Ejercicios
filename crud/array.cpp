#include <cstdio>

const int TAMANIO = 10;
int array[TAMANIO];
int cantidadElementos = 0;

void crear() {
    printf("Ingrese hasta %d elementos (Ingrese -1 para terminar):\n", TAMANIO);
    for (int i = 0; i < TAMANIO; ++i) {
        int valor;
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        if (valor == -1) break;
        array[i] = valor;
        cantidadElementos++;
    }
}

void leer() {
    printf("Array:\n");
    for (int i = 0; i < cantidadElementos; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void actualizar() {
    int indice, nuevoValor;
    printf("Ingrese el indice del elemento a actualizar (0-%d): ", cantidadElementos - 1);
    scanf("%d", &indice);
    if (indice >= 0 && indice < cantidadElementos) {
        printf("Ingrese el nuevo valor: ");
        scanf("%d", &nuevoValor);
        array[indice] = nuevoValor;
    } else {
        printf("indice no válido.\n");
    }
}

void eliminar() {
    int indice;
    printf("Ingrese el indice del elemento a eliminar (0-%d): ", cantidadElementos - 1);
    scanf("%d", &indice);
    if (indice >= 0 && indice < cantidadElementos) {
        for (int i = indice; i < cantidadElementos - 1; ++i) {
            array[i] = array[i + 1];
        }
        cantidadElementos--;
    } else {
        printf("indice no valido.\n");
    }
}

int main() {
    int opcion;

    while (true) {
        printf("1. Crear array\n");
        printf("2. Leer array\n");
        printf("3. Actualizar elemento\n");
        printf("4. Eliminar elemento\n");
        printf("5. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                crear();
                break;
            case 2:
                leer();
                break;
            case 3:
                actualizar();
                break;
            case 4:
                eliminar();
                break;
            case 5:
                return 0;
            default:
                printf("Opcion no valida.\n");
        }
    }

    return 0;
}

