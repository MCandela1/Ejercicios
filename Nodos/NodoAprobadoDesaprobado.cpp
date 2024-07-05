#include <cstdio>
#include <cstring>

const int MAX_LONGITUD_NOMBRE = 50;

struct Estudiante {
    int legajo;
    char nombre[MAX_LONGITUD_NOMBRE];
    char apellido[MAX_LONGITUD_NOMBRE];
    float notas[4];
    Estudiante* siguiente;
};

Estudiante* inicio = nullptr;

void copiarCadena(char destino[MAX_LONGITUD_NOMBRE], const char* origen) {
    int i;
    for (i = 0; i < MAX_LONGITUD_NOMBRE - 1 && origen[i] != '\0'; i++) {
        destino[i] = origen[i];
    }
    destino[i] = '\0';
}

void agregarEstudiante(int legajo, const char* nombre, const char* apellido, const float notas[4]) {
    Estudiante* nuevoEstudiante = new Estudiante;
    nuevoEstudiante->legajo = legajo;
    copiarCadena(nuevoEstudiante->nombre, nombre);
    copiarCadena(nuevoEstudiante->apellido, apellido);
    for (int i = 0; i < 4; i++) {
        nuevoEstudiante->notas[i] = notas[i];
    }
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
}

void mostrarEstudiantes() {
    if (!inicio) {
        printf("No hay estudiantes en la lista.\n");
    } else {
        printf("Lista de Estudiantes:\n");
        Estudiante* actual = inicio;
        while (actual) {
            printf("Legajo: %d, Nombre: %s, Apellido: %s, Notas: %.2f, %.2f, %.2f, %.2f\n",
                   actual->legajo, actual->nombre, actual->apellido,
                   actual->notas[0], actual->notas[1], actual->notas[2], actual->notas[3]);
            bool aprobado = true;
            for (int j = 0; j < 4; j++) {
                if (actual->notas[j] < 6) {
                    aprobado = false;
                    break;
                }
            }
            if (aprobado) {
                printf("Estado: Aprobado\n");
            } else {
                printf("Estado: Desaprobado\n");
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

bool actualizarEstudiante(int legajo, const char* nuevoNombre, const char* nuevoApellido, const float nuevasNotas[4]) {
    Estudiante* estudiante = buscarEstudiantePorLegajo(legajo);
    if (estudiante) {
        copiarCadena(estudiante->nombre, nuevoNombre);
        copiarCadena(estudiante->apellido, nuevoApellido);
        for (int i = 0; i < 4; i++) {
            estudiante->notas[i] = nuevasNotas[i];
        }
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

int main() {
    agregarEstudiante(1, "Juan", "Perez", new float[4]{6.0, 7.5, 8.0, 9.0});
    agregarEstudiante(2, "Ana", "Gomez", new float[4]{5.0, 4.5, 6.0, 7.0});

    mostrarEstudiantes();

    actualizarEstudiante(1, "Juan", "Perez Modificado", new float[4]{7.0, 8.0, 6.0, 7.5});

    mostrarEstudiantes();

    eliminarEstudiante(2);

    mostrarEstudiantes();

    return 0;
}
