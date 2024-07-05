#include <cstdio>
#include <cstring>

const int MAX_LONGITUD_NOMBRE = 50;

struct Estudiante {
    int legajo;
    char nombre[MAX_LONGITUD_NOMBRE];
    char apellido[MAX_LONGITUD_NOMBRE];
    float notas[2];
    Estudiante* siguiente;
};

Estudiante* inicio = nullptr;
int proximoLegajo = 1;

void copiarCadena(char destino[MAX_LONGITUD_NOMBRE], const char* origen) {
    int i;
    for (i = 0; i < MAX_LONGITUD_NOMBRE - 1 && origen[i] != '\0'; i++) {
        destino[i] = origen[i];
    }
    destino[i] = '\0';
}

void agregarEstudiante(const char* nombre, const char* apellido, const float notas[2]) {
    Estudiante* nuevoEstudiante = new Estudiante;
    nuevoEstudiante->legajo = proximoLegajo;
    copiarCadena(nuevoEstudiante->nombre, nombre);
    copiarCadena(nuevoEstudiante->apellido, apellido);
    nuevoEstudiante->notas[0] = notas[0];
    nuevoEstudiante->notas[1] = notas[1];
    nuevoEstudiante->siguiente = nullptr;

    if (!inicio) {
        inicio = nuevoEstudiante;
    } else {
        Estudiante* actual = inicio;
        while (actual->siguiente) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoEstudiante;
    }

    proximoLegajo++;
}

void mostrarEstudiantes() {
    if (!inicio) {
        printf("No hay estudiantes en la lista.\n");
    } else {
        printf("Lista de Estudiantes:\n");
        Estudiante* actual = inicio;
        while (actual) {
            float promedio = (actual->notas[0] + actual->notas[1]) / 2.0;
            printf("Legajo: %d, Nombre: %s, Apellido: %s, Notas: %.2f, %.2f. Promedio: %.2f. Estado: ",
                   actual->legajo, actual->nombre, actual->apellido,
                   actual->notas[0], actual->notas[1], promedio);
            if (promedio >= 8) {
                printf("Promovido\n");
            } else if (promedio >= 6) {
                printf("Aprobado\n");
            } else {
                printf("Desaprobado. Debe realizar el globalizador.\n");
            }
            actual = actual->siguiente;
        }
    }
}

Estudiante* buscarEstudiantePorLegajo(int legajo) {
    Estudiante* actual = inicio;
    while (actual) {
        if (actual->legajo == legajo) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

bool actualizarEstudiante(int legajo, const char* nuevoNombre, const char* nuevoApellido, const float nuevasNotas[2]) {
    Estudiante* estudiante = buscarEstudiantePorLegajo(legajo);
    if (estudiante) {
        copiarCadena(estudiante->nombre, nuevoNombre);
        copiarCadena(estudiante->apellido, nuevoApellido);
        estudiante->notas[0] = nuevasNotas[0];
        estudiante->notas[1] = nuevasNotas[1];
        return true;
    }
    return false;
}

bool eliminarEstudiante(int legajo) {
    if (!inicio) {
        return false;
    }
    if (inicio->legajo == legajo) {
        Estudiante* eliminar = inicio;
        inicio = inicio->siguiente;
        delete eliminar;
        return true;
    }
    Estudiante* actual = inicio;
    while (actual->siguiente) {
        if (actual->siguiente->legajo == legajo) {
            Estudiante* eliminar = actual->siguiente;
            actual->siguiente = eliminar->siguiente;
            delete eliminar;
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void liberarMemoria() {
    Estudiante* actual = inicio;
    while (actual) {
        Estudiante* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    inicio = nullptr;
}

int main() {
    int opcion;

    while (true) {
        printf("\n1. Agregar estudiante.\n");
        printf("2. Mostrar estudiantes.\n");
        printf("3. Actualizar estudiante.\n");
        printf("4. Eliminar estudiante.\n");
        printf("5. Salir.\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                char nombre[MAX_LONGITUD_NOMBRE];
                char apellido[MAX_LONGITUD_NOMBRE];
                float notas[2];
                printf("Ingrese nombre del estudiante: ");
                scanf("%s", nombre);
                printf("Ingrese apellido del estudiante: ");
                scanf("%s", apellido);
                printf("Ingrese nota del primer parcial: ");
                scanf("%f", &notas[0]);
                printf("Ingrese nota del segundo parcial: ");
                scanf("%f", &notas[1]);

                agregarEstudiante(nombre, apellido, notas);
                break;
            }
            case 2:
                mostrarEstudiantes();
                break;
            case 3: {
                int legajo;
                char nuevoNombre[MAX_LONGITUD_NOMBRE];
                char nuevoApellido[MAX_LONGITUD_NOMBRE];
                float nuevasNotas[2];
                printf("Ingrese legajo del estudiante a actualizar: ");
                scanf("%d", &legajo);
                printf("Ingrese nuevo nombre del estudiante: ");
                scanf("%s", nuevoNombre);
                printf("Ingrese nuevo apellido del estudiante: ");
                scanf("%s", nuevoApellido);
                printf("Ingrese nuevas notas del estudiante:\n");
                printf("Primer parcial: ");
                scanf("%f", &nuevasNotas[0]);
                printf("Segundo parcial: ");
                scanf("%f", &nuevasNotas[1]);

                if (!actualizarEstudiante(legajo, nuevoNombre, nuevoApellido, nuevasNotas)) {
                    printf("Estudiante no encontrado.\n");
                }
                break;
            }
            case 4: {
                int legajo;
                printf("Ingrese legajo del estudiante a eliminar: ");
                scanf("%d", &legajo);
                if (!eliminarEstudiante(legajo)) {
                    printf("Estudiante no encontrado.\n");
                }
                break;
            }
            case 5:
                liberarMemoria();
                printf("Saliendo del programa.\n");
                return 0;
            default:
                printf("Opción no válida.\n");
        }
    }

    return 0;
}
