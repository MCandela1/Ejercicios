#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3;

void cargarPrecios(float precios[6]);
void analizarViñedos(float precios[6]);
int sumarUvas(int viñedo[N][N], int x, int y, int& maxHorizontal, int& maxVertical);
bool esNombreSalir(const char nombre[]);

int main() {
    int opcion;
    float precios[6] = {0};

    do {
        printf("Menú de opciones:\n");
        printf("1. Cargar precios de uvas\n");
        printf("2. Análisis de viñedos\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                cargarPrecios(precios);
                break;
            case 2:
                analizarViñedos(precios);
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

void cargarPrecios(float precios[6]) {
    for (int i = 0; i < 6; ++i) {
        printf("Ingrese el precio para el tipo de uva %d: ", i + 1);
        scanf("%f", &precios[i]);
    }
}

void analizarViñedos(float precios[6]) {
    char nombre[50];
    int tipo, viñedo[N][N], x, y;
    int maxUvas = 0, uvas, maxUvasGlobal = 0;
    char mejorViñedo[50] = "";
    int maxHorizontal, maxVertical;

    while (true) {
        printf("Ingrese el nombre del viñedo (o 'salir' para terminar): ");
        scanf("%s", nombre);

        if (esNombreSalir(nombre)) {
            break;
        }

        do {
            printf("Ingrese el número del tipo de uva (1-6): ");
            scanf("%d", &tipo);
        } while (tipo < 1 || tipo > 6);

        printf("Ingrese la cantidad de uvas en cada celda (3x3):\n");
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                printf("Celda [%d][%d]: ", i, j);
                scanf("%d", &viñedo[i][j]);
            }
        }

        do {
            printf("Ingrese las coordenadas de referencia (x y) (0-2): ");
            scanf("%d %d", &x, &y);
        } while (x < 0 || x >= N || y < 0 || y >= N);

        uvas = sumarUvas(viñedo, x, y, maxHorizontal, maxVertical);

        printf("Nombre del viñedo: %s\n", nombre);
        printf("Uvas cosechadas: %d\n", uvas);
        printf("Importe a abonar: %.2f\n", uvas * precios[tipo - 1]);

        if (uvas > maxUvasGlobal) {
            maxUvasGlobal = uvas;
            int i = 0;
            while (nombre[i] != '\0') {
                mejorViñedo[i] = nombre[i];
                i++;
            }
            mejorViñedo[i] = '\0';
        }
    }

    if (maxUvasGlobal > 0) {
        printf("El viñedo con mayor producción es: %s\n", mejorViñedo);
    } else {
        printf("No se analizaron viñedos.\n");
    }
}

int sumarUvas(int viñedo[N][N], int x, int y, int& maxHorizontal, int& maxVertical) {
    maxHorizontal = 0;
    maxVertical = 0;

    for (int i = 0; i < N; ++i) {
        maxHorizontal += viñedo[x][i];
        maxVertical += viñedo[i][y];
    }

    if (maxHorizontal > maxVertical) {
        return maxHorizontal;
    } else {
        return maxVertical;
    }
}

bool esNombreSalir(const char nombre[]) {
    const char salir[] = "salir";
    int i = 0;

    while (nombre[i] != '\0' && salir[i] != '\0') {
        if (nombre[i] != salir[i]) {
            return false;
        }
        i++;
    }

    return nombre[i] == '\0' && salir[i] == '\0';
}
