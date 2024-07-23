#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int NUM_DADOS = 5;
const int MAX_LANZAMIENTOS = 3;

struct NodoDado {
    int valor;
    NodoDado* siguiente;
};

NodoDado* crearNodoDado(int valor) {
    NodoDado* nuevoNodo = (NodoDado*)malloc(sizeof(NodoDado));
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void lanzarDado(NodoDado* dado) {
    dado->valor = rand() % 6 + 1;
}

void lanzarDados(NodoDado* cabeza) {
    NodoDado* actual = cabeza;
    while (actual != NULL) {
        lanzarDado(actual);
        actual = actual->siguiente;
    }
}


void mostrarDados(NodoDado* cabeza) {
    NodoDado* actual = cabeza;
    int contador = 1;
    while (actual != NULL) {
        printf("Dado %d: %d\n", contador++, actual->valor);
        actual = actual->siguiente;
    }
}


int contarValor(NodoDado* cabeza, int valor) {
    int count = 0;
    NodoDado* actual = cabeza;
    while (actual != NULL) {
        if (actual->valor == valor) {
            ++count;
        }
        actual = actual->siguiente;
    }
    return count;
}

void verificarCombinacion(NodoDado* cabeza) {
    int counts[7] = {0};

    NodoDado* actual = cabeza;
    while (actual != NULL) {
        counts[actual->valor]++;
        actual = actual->siguiente;
    }

    bool generala = false;
    bool full = false;
    bool poker = false;
    bool escalera = false;
    bool trio = false;
    bool par = false;

    for (int i = 1; i <= 6; ++i) {
        if (counts[i] == 5) generala = true;
        if (counts[i] == 4) poker = true;
        if (counts[i] == 3) trio = true;
        if (counts[i] == 2) par = true;
    }
    if (trio && par) full = true;

    bool secuencia[6] = {0};
    actual = cabeza;
    while (actual != NULL) {
        secuencia[actual->valor - 1] = true;
        actual = actual->siguiente;
    }
    if ((secuencia[0] && secuencia[1] && secuencia[2] && secuencia[3] && secuencia[4]) ||
        (secuencia[1] && secuencia[2] && secuencia[3] && secuencia[4] && secuencia[5])) {
        escalera = true;
    }

    if (generala) printf("¡Generala!\n");
    else if (full) printf("¡Full!\n");
    else if (poker) printf("¡Póker!\n");
    else if (escalera) printf("¡Escalera!\n");
    else if (trio) printf("¡Trío!\n");
    else if (par) printf("¡Par!\n");
    else printf("Ninguna combinación.\n");
}

void liberarLista(NodoDado* cabeza) {
    NodoDado* actual = cabeza;
    NodoDado* siguiente;
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}

int main() {
    srand(time(NULL));

    NodoDado* cabeza = NULL;
    NodoDado* actual = NULL;

    for (int i = 0; i < NUM_DADOS; ++i) {
        NodoDado* nuevoNodo = crearNodoDado(0);
        if (cabeza == NULL) {
            cabeza = nuevoNodo;
            actual = cabeza;
        } else {
            actual->siguiente = nuevoNodo;
            actual = nuevoNodo;
        }
    }

    int lanzamientos = 0;

    while (lanzamientos < MAX_LANZAMIENTOS) {
        printf("Lanzamiento %d:\n", lanzamientos + 1);
        lanzarDados(cabeza);
        mostrarDados(cabeza);

        if (lanzamientos < MAX_LANZAMIENTOS - 1) {
            char respuesta;
            printf("¿Desea lanzar los dados nuevamente? (s/n): ");
            scanf(" %c", &respuesta);

            if (respuesta != 's' && respuesta != 'S') {
                break;
            }
        }

        lanzamientos++;
    }

    printf("Resultados finales:\n");
    mostrarDados(cabeza);
    verificarCombinacion(cabeza);
    liberarLista(cabeza);

    return 0;
}
