#include <stdio.h>
#include <string.h>

struct Pieza {
    char tipo[10];
    char color[10];
    int fila;
    int columna;
    struct Pieza* siguiente;
};

void copiarCadena(char destino[], const char origen[]) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';
}

void agregarPieza(struct Pieza** cabeza, const char* tipo, const char* color, int fila, int columna) {
    static struct Pieza piezas[32];
    static int contador = 0;
    if (contador >= 32) {
        printf("No se pueden agregar más piezas.\n");
        return;
    }
    copiarCadena(piezas[contador].tipo, tipo);
    copiarCadena(piezas[contador].color, color);
    piezas[contador].fila = fila;
    piezas[contador].columna = columna;
    piezas[contador].siguiente = *cabeza;
    *cabeza = &piezas[contador];
    contador++;
}

void mostrarTablero(struct Pieza* cabeza) {
    char tablero[8][8] = {0};
    struct Pieza* actual = cabeza;
    while (actual != NULL) {
        tablero[actual->fila][actual->columna] = actual->tipo[0];
        actual = actual->siguiente;
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tablero[i][j] == 0) {
                printf(". ");
            } else {
                printf("%c ", tablero[i][j]);
            }
        }
        printf("\n");
    }
}

void moverPieza(struct Pieza* cabeza, const char* tipo, const char* color, int nuevaFila, int nuevaColumna) {
    struct Pieza* actual = cabeza;
    while (actual != NULL) {
        if (strcmp(actual->tipo, tipo) == 0 && strcmp(actual->color, color) == 0) {
            actual->fila = nuevaFila;
            actual->columna = nuevaColumna;
            return;
        }
        actual = actual->siguiente;
    }
    printf("No se encontró la pieza especificada.\n");
}

void eliminarPieza(struct Pieza** cabeza, const char* tipo, const char* color) {
    struct Pieza* actual = *cabeza;
    struct Pieza* anterior = NULL;
    while (actual != NULL) {
        if (strcmp(actual->tipo, tipo) == 0 && strcmp(actual->color, color) == 0) {
            if (anterior == NULL) {
                *cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            printf("Pieza eliminada.\n");
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    printf("No se encontró la pieza especificada.\n");
}

int main() {
    struct Pieza* listaPiezas = NULL;
    int opcion;
    char tipo[10], color[10];
    int fila, columna;

    while (1) {
        printf("Menu:\n");
        printf("1. Agregar pieza\n");
        printf("2. Mostrar tablero\n");
        printf("3. Mover pieza\n");
        printf("4. Eliminar pieza\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el tipo de pieza (ej. rey, reina, torre): ");
                scanf("%s", tipo);
                printf("Ingrese el color de la pieza (blanco/negro): ");
                scanf("%s", color);
                printf("Ingrese la fila (0-7): ");
                scanf("%d", &fila);
                printf("Ingrese la columna (0-7): ");
                scanf("%d", &columna);
                agregarPieza(&listaPiezas, tipo, color, fila, columna);
                break;
            case 2:
                mostrarTablero(listaPiezas);
                break;
            case 3:
                printf("Ingrese el tipo de pieza a mover: ");
                scanf("%s", tipo);
                printf("Ingrese el color de la pieza a mover: ");
                scanf("%s", color);
                printf("Ingrese la nueva fila (0-7): ");
                scanf("%d", &fila);
                printf("Ingrese la nueva columna (0-7): ");
                scanf("%d", &columna);
                moverPieza(listaPiezas, tipo, color, fila, columna);
                break;
            case 4:
                printf("Ingrese el tipo de pieza a eliminar: ");
                scanf("%s", tipo);
                printf("Ingrese el color de la pieza a eliminar: ");
                scanf("%s", color);
                eliminarPieza(&listaPiezas, tipo, color);
                break;
            case 5:
                return 0;
            default:
                printf("Opcion no valida.\n");
        }
    }

    return 0;
}
