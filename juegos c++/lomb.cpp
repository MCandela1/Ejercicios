#include <stdio.h>

struct Celda {
    int lombrices;
};

struct Granja {
    int id;
    char nombre[50];
    int tipoLombriz;
    struct Celda celdas[3][3];
    int coordReferenciaX;
    int coordReferenciaY;
    struct Granja* siguiente;
};

struct ListaGranjas {
    struct Granja* cabeza;
};

void crearGranja(struct Granja* nueva, int id, const char* nombre, int tipoLombriz, int celdas[3][3], int coordReferenciaX, int coordReferenciaY) {
    nueva->id = id;
    int i = 0;
    while (nombre[i] != '\0' && i < 49) {
        nueva->nombre[i] = nombre[i];
        i++;
    }
    nueva->nombre[i] = '\0';
    nueva->tipoLombriz = tipoLombriz;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            nueva->celdas[i][j].lombrices = celdas[i][j];
    nueva->coordReferenciaX = coordReferenciaX;
    nueva->coordReferenciaY = coordReferenciaY;
    nueva->siguiente = NULL;
}

void agregarGranja(struct ListaGranjas* lista, struct Granja* granja) {
    if (lista->cabeza == NULL) {
        lista->cabeza = granja;
    } else {
        struct Granja* temp = lista->cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = granja;
    }
}

int sumaMaximaLombrices(struct Granja* granja) {
    int sumaVertical = 0;
    int sumaHorizontal = 0;

    for (int i = 0; i < 3; i++) {
        sumaVertical += granja->celdas[i][granja->coordReferenciaY].lombrices;
        sumaHorizontal += granja->celdas[granja->coordReferenciaX][i].lombrices;
    }

    if (sumaVertical > sumaHorizontal) {
        return sumaVertical;
    } else {
        return sumaHorizontal;
    }
}

int main() {
    struct ListaGranjas lista;
    lista.cabeza = NULL;
    int precios[6];

    int opcion;
    do {
        printf("---Menu---\n");
        printf("1. Tipo de lombriz\n");
        printf("2. Analisis de granjas\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf("\nIngrese los precios de los 6 tipos de lombrices:\n");
            for (int i = 0; i < 6; i++) {
                printf("\nPrecio del tipo %d: ", i + 1);
                scanf("%d", &precios[i]);
            }
        } else if (opcion == 2) {
            int id, tipo;
            char nombre[50];
            printf("\nIngrese el ID de la granja: ");
            scanf("%d", &id);
            printf("\nIngrese el nombre de la granja: ");
            scanf("%s", nombre);
            printf("\nIngrese el tipo de lombriz (1-6): ");
            scanf("%d", &tipo);
            if (tipo < 1 || tipo > 6) {
                printf("El tipo de lombriz ingresado es invalido.\n");
                continue;
            }

            int celdas[3][3];
            printf("\nIngrese la cantidad de lombrices en cada una de las 9 celdas:\n");
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    printf("Celda (%d, %d): ", i, j);
                    scanf("%d", &celdas[i][j]);
                }
            }

            int coord_x, coord_y;
            printf("\nIngrese las coordenadas de la celda de referencia (0-2, 0-2): ");
            scanf("%d %d", &coord_x, &coord_y);
            if (coord_x < 0 || coord_x > 2 || coord_y < 0 || coord_y > 2) {
                printf("\nCoordenadas ingresadas invalidas.\n");
                continue;
            }

            struct Granja nuevaGranja;
            crearGranja(&nuevaGranja, id, nombre, tipo, celdas, coord_x, coord_y);
            agregarGranja(&lista, &nuevaGranja);

            int maxLombrices = sumaMaximaLombrices(&nuevaGranja);
            printf("\nMaximo numero de lombrices que se puede cosechar: %d\n", maxLombrices);
            printf("\nImporte a abonar: %d\n", maxLombrices * precios[tipo - 1]);
        }
    } while (opcion != 3);

    return 0;
}
