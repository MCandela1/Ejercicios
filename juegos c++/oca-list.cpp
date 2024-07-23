#include <cstdio>
#include <cstdlib>
#include <ctime>

struct Casilla {
    int numero;
    const char *descripcion;
    Casilla *siguiente;
};

struct Jugador {
    const char *nombre;
    int posicion;
};

void crearTablero(Casilla *&inicio) {
    const char *descripciones[] = {
        "Salida", "Puente", "Posada", "Pozo", "Laberinto",
        "Carcel", "Dado", "Oca", "Fin"
    };

    Casilla *actual = nullptr;
    for (int i = 0; i < 9; i++) {
        Casilla *nueva = new Casilla;
        nueva->numero = i;
        nueva->descripcion = descripciones[i];
        nueva->siguiente = nullptr;
        if (inicio == nullptr) {
            inicio = nueva;
        } else {
            actual->siguiente = nueva;
        }
        actual = nueva;
    }
}

void mostrarTablero(Casilla *inicio) {
    Casilla *actual = inicio;
    while (actual != nullptr) {
        printf("Casilla %d: %s\n", actual->numero, actual->descripcion);
        actual = actual->siguiente;
    }
}

int lanzarDado() {
    return rand() % 6 + 1;
}

void moverJugador(Jugador &jugador, int pasos, Casilla *inicio) {
    Casilla *actual = inicio;
    while (actual != nullptr && actual->numero != jugador.posicion) {
        actual = actual->siguiente;
    }
    for (int i = 0; i < pasos; i++) {
        if (actual != nullptr && actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
    }
    if (actual != nullptr) {
        jugador.posicion = actual->numero;
        printf("%s ha avanzado a la casilla %d: %s\n", jugador.nombre, actual->numero, actual->descripcion);
    }
}

int main() {
    srand(time(0));

    Casilla *tablero = nullptr;
    crearTablero(tablero);
    Jugador jugador = {"Jugador 1", 0};

    int opcion;
    do {
        printf("\n--- Juego de la Oca ---\n");
        printf("1. Mostrar Tablero\n");
        printf("2. Lanzar Dado\n");
        printf("3. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarTablero(tablero);
                break;
            case 2: {
                int dado = lanzarDado();
                printf("Has lanzado el dado y ha salido: %d\n", dado);
                moverJugador(jugador, dado, tablero);
                break;
            }
            case 3:
                printf("Saliendo del juego...\n");
                break;
            default:
                printf("Opción no válida. Inténtalo de nuevo.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}
