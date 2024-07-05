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
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

void eliminarDuplicados(Nodo* cabeza) {
    Nodo* actual = cabeza;
    Nodo* anterior=nullptr;

    while (actual != nullptr && actual->siguiente != nullptr) {
        Nodo* comparador = actual;
        Nodo* anteriorComparador= actual;
        while (comparador->siguiente != nullptr) {
            if (actual->dato == comparador->siguiente->dato) {
                Nodo* nodoDuplicado = comparador->siguiente;
                comparador->siguiente = nodoDuplicado->siguiente;
                delete nodoDuplicado;
            } else {
                anteriorComparador = comparador;
                comparador = comparador->siguiente;
            }
        }
        anterior = actual;
        actual = actual->siguiente;
    }
}

int main() {
    Nodo* cabeza = nullptr;
    int valor;

    printf("Ingrese numeros (ingresar una letra para terminar): ");
    while(scanf("%d", &valor)==1){
        insertarAlInicio(cabeza, valor);
    }

    printf("Lista original: ");
    imprimirLista(cabeza);

    eliminarDuplicados(cabeza);

    printf("Lista sin duplicados: ");
    imprimirLista(cabeza);

    Nodo* temp;
    while (cabeza != nullptr) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    return 0;
}
