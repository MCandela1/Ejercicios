#include <stdio.h>

#define MAX_EMPLEADOS 100

struct Empleado {
    char nombre[50];
    int numeroEmpleado;
    float salario;
};

void agregarEmpleado(Empleado empleados[], int *numEmpleados) {
    if (*numEmpleados < MAX_EMPLEADOS) {
        Empleado nuevoEmpleado;
        printf("Nombre del empleado: ");
        scanf("%s", nuevoEmpleado.nombre);
        printf("Número de empleado: ");
        scanf("%d", &nuevoEmpleado.numeroEmpleado);
        printf("Salario: ");
        scanf("%f", &nuevoEmpleado.salario);

        empleados[(*numEmpleados)++] = nuevoEmpleado;
        printf("Empleado agregado correctamente.\n");
    } else {
        printf("No se puede agregar más empleados. Lista llena.\n");
    }
}

void mostrarEmpleados(const Empleado empleados[], int numEmpleados) {
    printf("Lista de empleados:\n");
    for (int i = 0; i < numEmpleados; ++i) {
        printf("Nombre: %s, ", empleados[i].nombre);
        printf("Número de empleado: %d, ", empleados[i].numeroEmpleado);
        printf("Salario: %.2f\n", empleados[i].salario);
    }
}

void buscarEmpleado(const Empleado empleados[], int numEmpleados, int numBuscar) {
    int encontrado = 0;
    for (int i = 0; i < numEmpleados; ++i) {
        if (empleados[i].numeroEmpleado == numBuscar) {
            printf("Empleado encontrado:\n");
            printf("Nombre: %s, ", empleados[i].nombre);
            printf("Número de empleado: %d, ", empleados[i].numeroEmpleado);
            printf("Salario: %.2f\n", empleados[i].salario);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Empleado no encontrado.\n");
    }
}

void eliminarEmpleado(Empleado empleados[], int *numEmpleados, int numEliminar) {
    int encontrado = 0;
    for (int i = 0; i < *numEmpleados; ++i) {
        if (empleados[i].numeroEmpleado == numEliminar) {
            for (int j = i; j < *numEmpleados - 1; ++j) {
                empleados[j] = empleados[j + 1];
            }
            --(*numEmpleados);
            encontrado = 1;
            printf("Empleado eliminado correctamente.\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Empleado no encontrado. No se realizó ninguna eliminación.\n");
    }
}

float salarioPromedio(const Empleado empleados[], int numEmpleados) {
    if (numEmpleados == 0) {
        return 0.0;
    }

    float sumaSalarios = 0.0;
    for (int i = 0; i < numEmpleados; ++i) {
        sumaSalarios += empleados[i].salario;
    }

    return sumaSalarios / numEmpleados;
}

int main() {
    Empleado empleados[MAX_EMPLEADOS];
    int numEmpleados = 0;
    int opcion;

    do {
        printf("\nMenú:\n");
        printf("1. Agregar nuevo empleado\n");
        printf("2. Mostrar todos los empleados\n");
        printf("3. Buscar empleado por número de empleado\n");
        printf("4. Eliminar empleado por número de empleado\n");
        printf("5. Calcular salario promedio de todos los empleados\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarEmpleado(empleados, &numEmpleados);
                break;
            case 2:
                mostrarEmpleados(empleados, numEmpleados);
                break;
            case 3:
                int numBuscar;
                printf("Ingrese el número de empleado a buscar: ");
                scanf("%d", &numBuscar);
                buscarEmpleado(empleados, numEmpleados, numBuscar);
                break;
            case 4:
                int numEliminar;
                printf("Ingrese el número de empleado a eliminar: ");
                scanf("%d", &numEliminar);
                eliminarEmpleado(empleados, &numEmpleados, numEliminar);
                break;
            case 5:
                printf("Salario promedio de todos los empleados: %.2f\n", salarioPromedio(empleados, numEmpleados));
                break;
            case 6:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
                break;
        }

    } while (opcion != 6);

    return 0;
}
