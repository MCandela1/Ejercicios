#include <cstdio>
 using namespace std;
struct Nodo {
    int dato;
    Nodo* siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};
void insertarEnPosicion(Nodo*& cabeza, int valor, int posicion) {
    Nodo* nuevoNodo = new Nodo(valor);
    if (cabeza == nullptr) {
        nuevoNodo->siguiente = nuevoNodo;
        cabeza = nuevoNodo;
        return;
    }

    Nodo* actual = cabeza;
    for (int i = 1; i < posicion - 1; ++i) {
        actual = actual->siguiente;
        if (actual == cabeza) {
            printf("Posici�n fuera de rango.\n");
            delete nuevoNodo;
            return;
        }
    }

    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
}

void eliminarEnPosicion(Nodo*& cabeza, int posicion) {
    if (cabeza == nullptr) {
        printf("La lista est� vac�a.\n");
        return;
    }

    Nodo* temp;
    Nodo* actual = cabeza;

    if (posicion == 1) {
        temp = cabeza;
        if (cabeza->siguiente == cabeza) {
            cabeza = nullptr;
        } else {
            while (actual->siguiente != cabeza) {
                actual = actual->siguiente;
            }
            actual->siguiente = cabeza->siguiente;
            cabeza = cabeza->siguiente;
        }
        delete temp;
        return;
    }

    for (int i = 1; i < posicion - 1; i++) {
        actual = actual->siguiente;
        if (actual->siguiente == cabeza) {
            printf("Posici�n fuera de rango.\n");
            return;
        }
    }

    temp = actual->siguiente;
    actual->siguiente = temp->siguiente;
    delete temp;
}

void imprimirDesde(Nodo* inicio) {
    if (inicio == nullptr) {
        printf("La lista est� vac�a.\n");
        return;
    }

    Nodo* actual = inicio;
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != inicio);

    printf("(Inicio)\n");
}

int main() {
    Nodo* cabeza = nullptr;
    int opcion, valor, posicion;

    do {
        printf("\n1. Insertar en posici�n\n");
        printf("2. Eliminar en posici�n\n");
        printf("3. Imprimir lista desde un nodo\n");
        printf("0. Salir\n");
        printf("Ingrese una opci�n: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &valor);
                printf("Ingrese la posici�n: ");
                scanf("%d", &posicion);
                insertarEnPosicion(cabeza, valor, posicion);
                break;
            case 2:
                printf("Ingrese la posici�n a eliminar: ");
                scanf("%d", &posicion);
                eliminarEnPosicion(cabeza, posicion);
                break;
            case 3:
                printf("Ingrese el nodo desde el cual imprimir (valor): ");
                scanf("%d", &valor);
                Nodo* inicio = nullptr;
                Nodo* actual = cabeza;
                do {
                    if (actual->dato == valor) {
                        inicio = actual;
                        break;
                    }
                    actual = actual->siguiente;
                } while (actual != cabeza);

                if (inicio == nullptr) {
                    printf("No se encontr� el nodo con ese valor.\n");
                } else {
                    printf("Lista desde el nodo %d: ", inicio->dato);
                    imprimirDesde(inicio);
                }
                break;
         case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opci�n no v�lida. Intentelo de nuevo.\n");
                break;
        }

    } while (opcion != 0);

    if (cabeza != nullptr) {
        Nodo* temp;
        Nodo* actual = cabeza;
        do {
            temp = actual;
            actual = actual->siguiente;
            delete temp;
        } while (actual != cabeza);
    }

    return 0;
}
