#include <cstdio>


struct Nodo {
    int dato;
    Nodo* siguiente;
};

void insertarAlInicio(Nodo*& cabeza, int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int main() {
    Nodo* cabeza = nullptr;
    int opcion, valor;

    do {
        printf("\n1. Insertar elemento al inicio\n");
        printf("2. Imprimir lista\n");
        printf("3. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &valor);
                insertarAlInicio(cabeza, valor);
                break;
            case 2:
                printf("Lista actual: ");
                imprimirLista(cabeza);
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 3);

    Nodo* temp;
    while (cabeza != nullptr) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    return 0;
}
