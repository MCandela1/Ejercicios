#include <cstdio>
#include <cstdlib>

struct Nodo {
    int dato;
    Nodo* siguiente;
};

Nodo* crearNodo(int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void insertar(Nodo** cabeza, int dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        Nodo* temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

void imprimirLista(Nodo* cabeza) {
    Nodo* temp = cabeza;
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void actualizar(Nodo* cabeza, int valorViejo, int valorNuevo) {
    Nodo* temp = cabeza;
    while (temp != NULL) {
        if (temp->dato == valorViejo) {
            temp->dato = valorNuevo;
            return;
        }
        temp = temp->siguiente;
    }
    printf("No se encontro el valor %d en la lista.\n", valorViejo);
}

void eliminar(Nodo** cabeza, int dato) {
    Nodo* temp = *cabeza;
    Nodo* prev = NULL;

    // se sabe si la cabeza contiene el dato a eliminar
    if (temp != NULL && temp->dato == dato) {
        *cabeza = temp->siguiente;
        free(temp);
        return;
    }

    // se lo busca para eliminarlo
    while (temp != NULL && temp->dato != dato) {
        prev = temp;
        temp = temp->siguiente;
    }

    // el dato no se encuentra en la lista
    if (temp == NULL) {
        printf("No se encontro el valor %d en la lista.\n", dato);
        return;
    }

    // Desvincular el nodo de la lista y liberar memoria
    prev->siguiente = temp->siguiente;
    free(temp);
}

int main() {
    Nodo* cabeza = NULL;
    int opcion, valor, nuevoValor;

    while (true) {
        printf("1. Insertar\n");
        printf("2. Imprimir\n");
        printf("3. Actualizar\n");
        printf("4. Eliminar\n");
        printf("5. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &valor);
                insertar(&cabeza, valor);
                break;
            case 2:
                imprimirLista(cabeza);
                break;
            case 3:
                printf("Ingrese el valor a actualizar: ");
                scanf("%d", &valor);
                printf("Ingrese el nuevo valor: ");
                scanf("%d", &nuevoValor);
                actualizar(cabeza, valor, nuevoValor);
                break;
            case 4:
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &valor);
                eliminar(&cabeza, valor);
                break;
            case 5:
                return 0;
            default:
                printf("Opción no valida.\n");
        }
    }
    return 0;
}


