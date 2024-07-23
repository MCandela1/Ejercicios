#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3;

void cargarPrecios(float precios[], int size);
void analizarPlantaciones(float precios[], int size);
int sumarManzanas(int plantacion[N][N], int x, int y, int* maxHorizontal, int* maxVertical);
bool esSalir(const char nombre[]);

int main() {
    int opcion;
    float precios[6] = {0};

    do {
        printf("Menú de opciones:\n");
        printf("1. Cargar precios de manzanas\n");
        printf("2. Análisis de plantaciones\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                cargarPrecios(precios, 6);
                break;
            case 2:
                analizarPlantaciones(precios, 6);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 3);

    return 0;
}

void cargarPrecios(float precios[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("Ingrese el precio para la variedad de manzana %d: ", i + 1);
        scanf("%f", &precios[i]);
    }
}

void analizarPlantaciones(float precios[], int size) {
    char nombre[50];
    int tipo, plantacion[N][N], x, y;
    int maxManzanas = 0, manzanas, maxManzanasGlobal = 0;
    char mejorPlantacion[50] = "";
    int maxHorizontal, maxVertical;

    while (true) {
        printf("Ingrese el nombre de la plantación (o 'salir' para terminar): ");
        scanf("%s", nombre);

        if (esSalir(nombre)) {
            break;
        }

        do {
            printf("Ingrese el número de la variedad de manzana (1-6): ");
            scanf("%d", &tipo);
        } while (tipo < 1 || tipo > 6);

        printf("Ingrese la cantidad de manzanas en cada celda (3x3):\n");
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                printf("Celda [%d][%d]: ", i, j);
                scanf("%d", &plantacion[i][j]);
            }
        }

        do {
            printf("Ingrese las coordenadas de referencia (x y) (0-2): ");
            scanf("%d %d", &x, &y);
        } while (x < 0 || x >= N || y < 0 || y >= N);

        manzanas = sumarManzanas(plantacion, x, y, &maxHorizontal, &maxVertical);

        printf("Nombre de la plantación: %s\n", nombre);
        printf("Manzanas cosechadas: %d\n", manzanas);
        printf("Importe a abonar: %.2f\n", manzanas * precios[tipo - 1]);

        if (manzanas > maxManzanasGlobal) {
            maxManzanasGlobal = manzanas;
            int i = 0;
            while (nombre[i] != '\0') {
                mejorPlantacion[i] = nombre[i];
                i++;
            }
            mejorPlantacion[i] = '\0';
        }
    }

    if (maxManzanasGlobal > 0) {
        printf("La plantación con mayor producción es: %s\n", mejorPlantacion);
    } else {
        printf("No se analizaron plantaciones.\n");
    }
}

int sumarManzanas(int plantacion[N][N], int x, int y, int* maxHorizontal, int* maxVertical) {
    *maxHorizontal = 0;
    *maxVertical = 0;

    for (int i = 0; i < N; ++i) {
        *maxHorizontal += plantacion[x][i];
        *maxVertical += plantacion[i][y];
    }

    if (*maxHorizontal > *maxVertical) {
        return *maxHorizontal;
    } else {
        return *maxVertical;
    }
}

bool esSalir(const char nombre[]) {
    return nombre[0] == 's' && nombre[1] == 'a' && nombre[2] == 'l' && nombre[3] == 'i' && nombre[4] == 'r' && nombre[5] == '\0';
}
