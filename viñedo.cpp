#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3;

void cargarPrecios(float precios[6]);
void analizarVi�edos(float precios[6]);
int sumarUvas(int vi�edo[N][N], int x, int y, int& maxHorizontal, int& maxVertical);
bool esNombreSalir(const char nombre[]);

int main() {
    int opcion;
    float precios[6] = {0};

    do {
        printf("Men� de opciones:\n");
        printf("1. Cargar precios de uvas\n");
        printf("2. An�lisis de vi�edos\n");
        printf("3. Salir\n");
        printf("Seleccione una opci�n: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                cargarPrecios(precios);
                break;
            case 2:
                analizarVi�edos(precios);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opci�n no v�lida. Intente nuevamente.\n");
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

void analizarVi�edos(float precios[6]) {
    char nombre[50];
    int tipo, vi�edo[N][N], x, y;
    int maxUvas = 0, uvas, maxUvasGlobal = 0;
    char mejorVi�edo[50] = "";
    int maxHorizontal, maxVertical;

    while (true) {
        printf("Ingrese el nombre del vi�edo (o 'salir' para terminar): ");
        scanf("%s", nombre);

        if (esNombreSalir(nombre)) {
            break;
        }

        do {
            printf("Ingrese el n�mero del tipo de uva (1-6): ");
            scanf("%d", &tipo);
        } while (tipo < 1 || tipo > 6);

        printf("Ingrese la cantidad de uvas en cada celda (3x3):\n");
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                printf("Celda [%d][%d]: ", i, j);
                scanf("%d", &vi�edo[i][j]);
            }
        }

        do {
            printf("Ingrese las coordenadas de referencia (x y) (0-2): ");
            scanf("%d %d", &x, &y);
        } while (x < 0 || x >= N || y < 0 || y >= N);

        uvas = sumarUvas(vi�edo, x, y, maxHorizontal, maxVertical);

        printf("Nombre del vi�edo: %s\n", nombre);
        printf("Uvas cosechadas: %d\n", uvas);
        printf("Importe a abonar: %.2f\n", uvas * precios[tipo - 1]);

        if (uvas > maxUvasGlobal) {
            maxUvasGlobal = uvas;
            int i = 0;
            while (nombre[i] != '\0') {
                mejorVi�edo[i] = nombre[i];
                i++;
            }
            mejorVi�edo[i] = '\0';
        }
    }

    if (maxUvasGlobal > 0) {
        printf("El vi�edo con mayor producci�n es: %s\n", mejorVi�edo);
    } else {
        printf("No se analizaron vi�edos.\n");
    }
}

int sumarUvas(int vi�edo[N][N], int x, int y, int& maxHorizontal, int& maxVertical) {
    maxHorizontal = 0;
    maxVertical = 0;

    for (int i = 0; i < N; ++i) {
        maxHorizontal += vi�edo[x][i];
        maxVertical += vi�edo[i][y];
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
