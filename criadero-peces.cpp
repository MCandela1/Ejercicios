#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3;
const int NUM_ESPECIES = 6;

void cargarPrecios(float precios[]);
void analizarCriaderos(float precios[]);
int sumarPeces(int criadero[N][N], int x, int y, int* maxHorizontal, int* maxVertical);
bool esSalir(const char nombre[]);

int main() {
    int opcion;
    float precios[NUM_ESPECIES] = {0};

    do {
        printf("Menú de opciones:\n");
        printf("1. Cargar precios de peces\n");
        printf("2. Análisis de criaderos\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                cargarPrecios(precios);
                break;
            case 2:
                analizarCriaderos(precios);
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

void cargarPrecios(float precios[]) {
    for (int i = 0; i < NUM_ESPECIES; ++i) {
        printf("Ingrese el precio para la especie de pez %d: ", i + 1);
        scanf("%f", &precios[i]);
    }
}

void analizarCriaderos(float precios[]) {
    char nombre[50];
    int tipo, criadero[N][N], x, y;
    int peces, maxPecesGlobal = 0;
    char mejorCriadero[50] = "";
    int maxHorizontal, maxVertical;

    while (true) {
        printf("Ingrese el nombre del criadero (o 'salir' para terminar): ");
        scanf("%s", nombre);

        if (esSalir(nombre)) {
            break;
        }

        do {
            printf("Ingrese el número de la especie de pez (1-%d): ", NUM_ESPECIES);
            scanf("%d", &tipo);
        } while (tipo < 1 || tipo > NUM_ESPECIES);

        printf("Ingrese la cantidad de peces en cada celda (3x3):\n");
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                printf("Celda [%d][%d]: ", i, j);
                scanf("%d", &criadero[i][j]);
            }
        }

        do {
            printf("Ingrese las coordenadas de referencia (x y) (0-2): ");
            scanf("%d %d", &x, &y);
        } while (x < 0 || x >= N || y < 0 || y >= N);

        peces = sumarPeces(criadero, x, y, &maxHorizontal, &maxVertical);

        printf("Nombre del criadero: %s\n", nombre);
        printf("Peces cosechados: %d\n", peces);
        printf("Importe a abonar: %.2f\n", peces * precios[tipo - 1]);

        if (peces > maxPecesGlobal) {
            maxPecesGlobal = peces;
            int i = 0;
            while (nombre[i] != '\0') {
                mejorCriadero[i] = nombre[i];
                i++;
            }
            mejorCriadero[i] = '\0';
        }
    }

    if (maxPecesGlobal > 0) {
        printf("El criadero con mayor producción es: %s\n", mejorCriadero);
    } else {
        printf("No se analizaron criaderos.\n");
    }
}

int sumarPeces(int criadero[N][N], int x, int y, int* maxHorizontal, int* maxVertical) {
    *maxHorizontal = 0;
    *maxVertical = 0;

    for (int i = 0; i < N; ++i) {
        *maxHorizontal += criadero[x][i];
        *maxVertical += criadero[i][y];
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
