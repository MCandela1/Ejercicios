//Crea un programa que gestione una lista de estudiantes. Cada estudiante debe tener un ID, un nombre y una calificaci�n.

//Requisitos:
//Crear: A�adir un nuevo estudiante a la lista.
//Leer: Mostrar todos los estudiantes.
//Actualizar: Modificar un estudiante existente.
//Eliminar: Eliminar un estudiante de la lista.
#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAX_ESTUDIANTES = 100;
const int LONGITUD_MAX_NOMBRE = 50;

struct Estudiante {
    int id;
    char nombre[LONGITUD_MAX_NOMBRE];
    float calificacion;
};

Estudiante estudiantes[MAX_ESTUDIANTES];
int numEstudiantes = 0;

// Prototipos de funciones
void crearEstudiante();
void mostrarEstudiantes();
void actualizarEstudiante();
void eliminarEstudiante();

int main() {
    int opcion;

    while (true) {
        printf("\nMen�:\n");
        printf("1. Crear estudiante\n");
        printf("2. Mostrar estudiantes\n");
        printf("3. Actualizar estudiante\n");
        printf("4. Eliminar estudiante\n");
        printf("5. Salir\n");
        printf("Ingrese su opci�n: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                crearEstudiante();
                break;
            case 2:
                mostrarEstudiantes();
                break;
            case 3:
                actualizarEstudiante();
                break;
            case 4:
                eliminarEstudiante();
                break;
            case 5:
                printf("Saliendo del programa.\n");
                return 0;
            default:
                printf("Opci�n no v�lida. Intente de nuevo.\n");
                break;
        }
    }

    return 0;
}

void crearEstudiante() {
    if (numEstudiantes < MAX_ESTUDIANTES) {
        printf("\nIngrese el ID del estudiante: ");
        scanf("%d", &estudiantes[numEstudiantes].id);

        printf("Ingrese el nombre del estudiante: ");
        scanf(" %[^\n]s", estudiantes[numEstudiantes].nombre);

        printf("Ingrese la calificaci�n del estudiante: ");
        scanf("%f", &estudiantes[numEstudiantes].calificacion);

        numEstudiantes++;
        printf("Estudiante a�adido correctamente.\n");
    } else {
        printf("No se pueden a�adir m�s estudiantes. La lista est� llena.\n");
    }
}

void mostrarEstudiantes() {
    if (numEstudiantes > 0) {
        printf("\nLista de estudiantes:\n");
        printf("ID\tNombre\t\tCalificaci�n\n");
        for (int i = 0; i < numEstudiantes; ++i) {
            printf("%d\t%s\t\t%.2f\n", estudiantes[i].id, estudiantes[i].nombre, estudiantes[i].calificacion);
        }
    } else {
        printf("No hay estudiantes en la lista.\n");
    }
}

void actualizarEstudiante() {
    int idActualizar;
    printf("\nIngrese el ID del estudiante a actualizar: ");
    scanf("%d", &idActualizar);

    for (int i = 0; i < numEstudiantes; ++i) {
        if (estudiantes[i].id == idActualizar) {
            printf("Nuevo nombre para %s: ", estudiantes[i].nombre);
            scanf(" %[^\n]s", estudiantes[i].nombre);

            printf("Nueva calificaci�n para %s: ", estudiantes[i].nombre);
            scanf("%f", &estudiantes[i].calificacion);

            printf("Estudiante actualizado correctamente.\n");
            return;
        }
    }

    printf("Estudiante no encontrado con ID %d.\n", idActualizar);
}

void eliminarEstudiante() {
    int idEliminar;
    printf("\nIngrese el ID del estudiante a eliminar: ");
    scanf("%d", &idEliminar);

    for (int i = 0; i < numEstudiantes; ++i) {
        if (estudiantes[i].id == idEliminar) {
            // Eliminar el estudiante moviendo los siguientes estudiantes una posici�n hacia atr�s
            for (int j = i; j < numEstudiantes - 1; ++j) {
                estudiantes[j] = estudiantes[j + 1];
            }
            numEstudiantes--;
            printf("Estudiante eliminado correctamente.\n");
            return;
        }
    }

    printf("Estudiante no encontrado con ID %d.\n", idEliminar);
}
