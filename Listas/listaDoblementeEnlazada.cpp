#include <cstdio>

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

void insertarAlInicio(Nodo*& cabeza, int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = cabeza;

    if (cabeza != nullptr) {
        cabeza->anterior = nuevoNodo;
    }

    cabeza = nuevoNodo;
}

void insertarAlFinal(Nodo*& cabeza, Nodo*& cola, int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = cola;

    if (cola != nullptr) {
        cola->siguiente = nuevoNodo;
    }

    cola = nuevoNodo;

    if (cabeza == nullptr) {
        cabeza = cola;
    }
}


void eliminarInicio(Nodo*& cabeza, Nodo*& cola) {
    if (cabeza == nullptr) {
        printf("La lista está vacía. No se puede eliminar.\n");
        return;
    }

    Nodo* temp = cabeza;
    cabeza = cabeza->siguiente;

    if (cabeza != nullptr) {
        cabeza->anterior = nullptr;
    } else {
        cola = nullptr;
    }

    delete temp;
}

void eliminarFinal(Nodo*& cabeza, Nodo*& cola) {
    if (cola == nullptr) {
        printf("La lista está vacía. No se puede eliminar.\n");
        return;
    }

    Nodo* temp = cola;
    cola = cola->anterior;

    if (cola != nullptr) {
        cola->siguiente = nullptr;
    } else {
        cabeza = nullptr;
    }

    delete temp;
}

void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        printf("%d <-> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int main() {
    Nodo* cabeza = nullptr;
    Nodo* cola = nullptr;
    int opcion, valor;

    do {

        printf("\n1. Insertar al inicio\n");
        printf("2. Insertar al final\n");
        printf("3. Eliminar inicio\n");
        printf("4. Eliminar final\n");
        printf("5. Imprimir lista\n");
        printf("0. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor a insertar al inicio: ");
                scanf("%d", &valor);
                insertarAlInicio(cabeza, valor);
                break;
            case 2:
                printf("Ingrese el valor a insertar al final: ");
                scanf("%d", &valor);
                insertarAlFinal(cabeza, cola, valor);
                break;
            case 3:
                eliminarInicio(cabeza, cola);
                break;
            case 4:
                eliminarFinal(cabeza, cola);
                break;
            case 5:
                printf("Lista actual: ");
                imprimirLista(cabeza);
                break;
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
                break;
        }

    } while (opcion != 0);
    Nodo* temp;
    while (cabeza != nullptr) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    return 0;
}
