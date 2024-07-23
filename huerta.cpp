#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3;
const int NUM_TIPOS = 6;

void cargarPrecios(float precios[]);
void analizarHuertos(float precios[]);
int sumarVerduras(int huerto[N][N], int x, int y, int* maxHorizontal, int* maxVertical);
bool esSalir(const char nombre[]);

int main() {
    int opcion;
    float precios[NUM_TIPOS] = {0};

    do {
        printf("Menú de opciones:\n");
        printf("1. Cargar precios de verduras\n");
        printf("2. Análisis de huertos\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                cargarPrecios(precios);
                break;
            case 2:
                analizarHuertos(precios);
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
    for (int i = 0; i < NUM_TIPOS; ++i) {
        printf("Ingrese el precio para el tipo de verdura %d: ", i + 1);
        scanf("%f", &precios[i]);
    }
}

void analizarHuertos(float precios[]) {
    char nombre[50];
    int tipo, huerto[N][N], x, y;
    int verduras, maxVerdurasGlobal = 0;
    char mejorHuerto[50] = "";
    int maxHorizontal, maxVertical;

    while (true) {
        printf("Ingrese el nombre del huerto (o 'salir' para terminar): ");
        scanf("%s", nombre);

        if (esSalir(nombre)) {
            break;
        }

        do {
            printf("Ingrese el número del tipo de verdura (1-%d): ", NUM_TIPOS);
            scanf("%d", &tipo);
        } while (tipo < 1 || tipo > NUM_TIPOS);

        printf("Ingrese la cantidad de verduras en cada celda (3x3):\n");
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                printf("Celda [%d][%d]: ", i, j);
                scanf("%d", &huerto[i][j]);
            }
        }

        do {
            printf("Ingrese las coordenadas de referencia (x y) (0-2): ");
            scanf("%d %d", &x, &y);
        } while (x < 0 || x >= N || y < 0 || y >= N);

        verduras = sumarVerduras(huerto, x, y, &maxHorizontal, &maxVertical);

        printf("Nombre del huerto: %s\n", nombre);
        printf("Verduras cosechadas: %d\n", verduras);
        printf("Importe a abonar: %.2f\n", verduras * precios[tipo - 1]);

        if (verduras > maxVerdurasGlobal) {
            maxVerdurasGlobal = verduras;
            int i = 0;
            while (nombre[i] != '\0') {
                mejorHuerto[i] = nombre[i];
                i++;
            }
            mejorHuerto[i] = '\0';
        }
    }

    if (maxVerdurasGlobal > 0) {
        printf("El huerto con mayor producción es: %s\n", mejorHuerto);
    } else {
        printf("No se analizaron huertos.\n");
    }
}

int sumarVerduras(int huerto[N][N], int x, int y, int* maxHorizontal, int* maxVertical) {
    *maxHorizontal = 0;
    *maxVertical = 0;

    for (int i = 0; i < N; ++i) {
        *maxHorizontal += huerto[x][i];
        *maxVertical += huerto[i][y];
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
