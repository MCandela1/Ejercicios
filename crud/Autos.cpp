#include <cstdio>
#include <cstring>

const int MAX_AUTOS = 100;

struct Auto {
    char modelo[50];
    int anio;
    float precio;
    bool vendido;
    char nombreComprador[50];
    char apellidoComprador[50];
};

Auto autos[MAX_AUTOS];
int cantidadAutos = 0;

void agregarAuto() {
    if (cantidadAutos >= MAX_AUTOS) {
        printf("No se pueden agregar más autos.\n");
        return;
    }

    Auto nuevoAuto;
    printf("Ingrese modelo del auto: ");
    scanf("%s", nuevoAuto.modelo);
    printf("Ingrese año del auto: ");
    scanf("%d", &nuevoAuto.anio);
    printf("Ingrese precio del auto: ");
    scanf("%f", &nuevoAuto.precio);
    nuevoAuto.vendido = false;
    strcpy(nuevoAuto.nombreComprador, "");
    strcpy(nuevoAuto.apellidoComprador, "");

    autos[cantidadAutos++] = nuevoAuto;
    printf("Auto agregado con éxito.\n");
}

void mostrarAutos() {
    for (int i = 0; i < cantidadAutos; ++i) {
        printf("Auto #%d\n", i + 1);
        printf("Modelo: %s\n", autos[i].modelo);
        printf("Año: %d\n", autos[i].anio);
        printf("Precio: %.2f\n", autos[i].precio);
        if (autos[i].vendido) {
            printf("Estado: Vendido\n");
            printf("Comprador: %s %s\n", autos[i].nombreComprador, autos[i].apellidoComprador);
        } else {
            printf("Estado: Disponible\n");
        }
        printf("\n");
    }
}

void venderAuto() {
    char modelo[50];
    int anio;
    printf("Ingrese el modelo del auto a vender: ");
    scanf("%s", modelo);
    printf("Ingrese el año del auto a vender: ");
    scanf("%d", &anio);

    bool autoEncontrado = false;
    for (int i = 0; i < cantidadAutos; ++i) {
        if (strcmp(autos[i].modelo, modelo) == 0 && autos[i].anio == anio) {
            if (autos[i].vendido) {
                printf("Este auto ya fue vendido.\n");
            } else {
                printf("Ingrese nombre del comprador: ");
                scanf("%s", autos[i].nombreComprador);
                printf("Ingrese apellido del comprador: ");
                scanf("%s", autos[i].apellidoComprador);
                autos[i].vendido = true;
                printf("Auto vendido con éxito.\n");
                printf("Modelo: %s, Año: %d\n", autos[i].modelo, autos[i].anio);
            }
            autoEncontrado = true;
            break;
        }
    }

    if (!autoEncontrado) {
        printf("No se encontró un auto con ese modelo y año.\n");
    }
}

void editarAuto() {
    int indice;
    printf("Ingrese el número del auto a editar: ");
    scanf("%d", &indice);
    --indice;

    if (indice < 0 || indice >= cantidadAutos) {
        printf("Número de auto inválido.\n");
        return;
    }

    printf("Ingrese nuevo modelo del auto: ");
    scanf("%s", autos[indice].modelo);
    printf("Ingrese nuevo año del auto: ");
    scanf("%d", &autos[indice].anio);
    printf("Ingrese nuevo precio del auto: ");
    scanf("%f", &autos[indice].precio);

    printf("Auto editado con éxito.\n");
}

void eliminarAuto() {
    int indice;
    printf("Ingrese el número del auto a eliminar: ");
    scanf("%d", &indice);
    --indice;

    if (indice < 0 || indice >= cantidadAutos) {
        printf("Número de auto inválido.\n");
        return;
    }

    for (int i = indice; i < cantidadAutos - 1; ++i) {
        autos[i] = autos[i + 1];
    }
    --cantidadAutos;

    printf("Auto eliminado con éxito.\n");
}

int main() {
    int opcion;
    do {
        printf("\n---- Menu ----\n");
        printf("\n1. Agregar auto\n");
        printf("2. Mostrar autos\n");
        printf("3. Vender auto\n");
        printf("4. Editar auto\n");
        printf("5. Eliminar auto\n");
        printf("6. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarAuto();
                break;
            case 2:
                mostrarAutos();
                break;
            case 3:
                venderAuto();
                break;
            case 4:
                editarAuto();
                break;
            case 5:
                eliminarAuto();
                break;
            case 6:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}

