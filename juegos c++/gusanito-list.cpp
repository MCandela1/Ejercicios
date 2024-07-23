#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Segmento {
    int x, y;
    struct Segmento *siguiente;
} Segmento;

typedef struct {
    Segmento *cabeza;
    int longitud;
} Gusano;

void inicializarGusano(Gusano *gusano) {
    gusano->cabeza = (Segmento*)malloc(sizeof(Segmento));
    gusano->cabeza->x = 5;
    gusano->cabeza->y = 5;
    gusano->cabeza->siguiente = NULL;
    gusano->longitud = 1;
}

void mostrarTablero(Gusano *gusano) {
    system("cls");

    Segmento *actual = gusano->cabeza;
    while (actual != NULL) {
        printf("Segmento en: (%d, %d)\n", actual->x, actual->y);
        actual = actual->siguiente;
    }

    printf("\nPresiona una tecla y luego Enter para continuar...\n");
}

void moverGusano(Gusano *gusano, int direccion) {
    Segmento *actual = gusano->cabeza;
    while (actual != NULL) {
        switch (direccion) {
            case 0: actual->x--; break;
            case 1: actual->x++; break;
            case 2: actual->y--; break;
            case 3: actual->y++; break;
        }
        actual = actual->siguiente;
    }
}

int main() {
    Gusano gusano;
    int direccion = 0;
    char tecla;

    inicializarGusano(&gusano);

    while (1) {
        mostrarTablero(&gusano);


        printf("Introduce la dirección (a=izquierda, d=derecha, w=arriba, s=abajo): ");
        scanf(" %c", &tecla);

        switch (tecla) {
            case 'a': direccion = 0; break;
            case 'd': direccion = 1; break;
            case 'w': direccion = 2; break;
            case 's': direccion = 3; break;
            default: continue;
        }

        moverGusano(&gusano, direccion);
    }

    return 0;
}
