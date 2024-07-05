#include <cstdio>
#include <cstring>

const int MAX_PILOTOS = 100;

struct Piloto {
    char nombre[50];
    char apellido[50];
    int edad;
    bool correra;
    int posicionCarrera;
};

Piloto pilotos[MAX_PILOTOS];
int cantidadPilotos = 0;

void agregarPiloto() {
    if (cantidadPilotos >= MAX_PILOTOS) {
        printf("No se pueden agregar más pilotos.\n");
        return;
    }

    Piloto nuevoPiloto;
    printf("Ingrese nombre del piloto: ");
    scanf("%s", nuevoPiloto.nombre);
    printf("Ingrese apellido del piloto: ");
    scanf("%s", nuevoPiloto.apellido);
    printf("Ingrese edad del piloto: ");
    scanf("%d", &nuevoPiloto.edad);
    nuevoPiloto.correra = false;
    nuevoPiloto.posicionCarrera = -1;

    pilotos[cantidadPilotos++] = nuevoPiloto;
    printf("Piloto agregado con éxito.\n");
}

void mostrarPilotos() {
    for (int i = 0; i < cantidadPilotos; ++i) {
        printf("Piloto #%d\n", i + 1);
        printf("Nombre: %s\n", pilotos[i].nombre);
        printf("Apellido: %s\n", pilotos[i].apellido);
        printf("Edad: %d\n", pilotos[i].edad);
        printf("¿Correrá en la carrera?: %s\n", pilotos[i].correra ? "Sí" : "No");
        if (pilotos[i].posicionCarrera != -1) {
            printf("Posición en la carrera: %d\n", pilotos[i].posicionCarrera);
        }
        printf("\n");
    }
}

void actualizarEstadoCarrera() {
    int indice;
    printf("Ingrese el número del piloto a actualizar el estado de la carrera: ");
    scanf("%d", &indice);
    --indice;

    if (indice < 0 || indice >= cantidadPilotos) {
        printf("Número de piloto inválido.\n");
        return;
    }

    int correra;
    printf("¿Correrá en la carrera? (1 para sí, 0 para no): ");
    scanf("%d", &correra);
    pilotos[indice].correra = correra == 1;

    if (pilotos[indice].correra) {
        printf("Ingrese la posición que obtuvo en la carrera (1-100, o -1 si aún no ha corrido): ");
        scanf("%d", &pilotos[indice].posicionCarrera);
    } else {
        pilotos[indice].posicionCarrera = -1;
    }

    printf("Estado de la carrera actualizado con éxito.\n");
}

void eliminarPiloto() {
    int indice;
    printf("Ingrese el número del piloto a eliminar: ");
    scanf("%d", &indice);
    --indice;

    if (indice < 0 || indice >= cantidadPilotos) {
        printf("Número de piloto inválido.\n");
        return;
    }

    for (int i = indice; i < cantidadPilotos - 1; ++i) {
        pilotos[i] = pilotos[i + 1];
    }
    --cantidadPilotos;

    printf("Piloto eliminado con éxito.\n");
}

int main() {
    int opcion;
    do {
        printf("\n---- Menu ----\n");
        printf("\n1. Agregar piloto\n");
        printf("2. Mostrar pilotos\n");
        printf("3. Actualizar estado de carrera\n");
        printf("4. Eliminar piloto\n");
        printf("5. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarPiloto();
                break;
            case 2:
                mostrarPilotos();
                break;
            case 3:
                actualizarEstadoCarrera();
                break;
            case 4:
                eliminarPiloto();
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}
