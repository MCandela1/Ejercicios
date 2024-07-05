#include <cstdio>
#include <cstdlib>

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


void invertirLista(Nodo*& cabeza) {
    Nodo* previo = nullptr;
    Nodo* actual = cabeza;
    Nodo* siguiente = nullptr;

    while (actual != nullptr) {
        siguiente = actual->siguiente;
        actual->siguiente = previo;
        previo = actual;
        actual = siguiente;
    }

    cabeza = previo;
}

int main() {
    Nodo* cabeza = nullptr;
    int opcion, valor;

    insertarAlInicio(cabeza, 3);
    insertarAlInicio(cabeza, 7);
    insertarAlInicio(cabeza, 12);
    insertarAlInicio(cabeza, 5);

    printf("Lista original: ");
    imprimirLista(cabeza);

    invertirLista(cabeza);

    printf("Lista invertida: ");
    imprimirLista(cabeza);

    Nodo* temp;
    while (cabeza != nullptr) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    return 0;
}
