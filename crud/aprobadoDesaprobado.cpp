#include <cstdio>
#include <cstring>

const int MAX_LONGITUD_NOMBRE = 50;
const int MAX_ESTUDIANTES = 100;

struct Estudiante {
    int legajo;
    char nombre[MAX_LONGITUD_NOMBRE];
    char apellido[MAX_LONGITUD_NOMBRE];
    float notas[4];
};

Estudiante estudiantes[MAX_ESTUDIANTES];
int contadorEstudiantes = 0;
int proximoLegajo = 1;

void copiarCadena(char destino[MAX_LONGITUD_NOMBRE], const char* origen) {
    int i;
    for (i = 0; i < MAX_LONGITUD_NOMBRE - 1 && origen[i] != '\0'; i++) {
        destino[i] = origen[i];
    }
    destino[i] = '\0';
}

void agregarEstudiante(const char* nombre, const char* apellido, const float notas[4]) {
    if (contadorEstudiantes >= MAX_ESTUDIANTES) {
        printf("No se pueden agregar más estudiantes.\n");
        return;
    }

    estudiantes[contadorEstudiantes].legajo = proximoLegajo;
    copiarCadena(estudiantes[contadorEstudiantes].nombre, nombre);
    copiarCadena(estudiantes[contadorEstudiantes].apellido, apellido);
    for (int i = 0; i < 4; i++) {
        estudiantes[contadorEstudiantes].notas[i] = notas[i];
    }
    contadorEstudiantes++;
    proximoLegajo++;
}

void mostrarEstudiantes() {
    if (contadorEstudiantes == 0) {
        printf("No hay estudiantes en la lista.\n");
    } else {
        printf("Lista de Estudiantes:\n");
        for (int i = 0; i < contadorEstudiantes; i++) {
            printf("Legajo: %d, Nombre: %s, Apellido: %s, Notas: %.2f, %.2f, %.2f, %.2f\n",
                   estudiantes[i].legajo, estudiantes[i].nombre, estudiantes[i].apellido,
                   estudiantes[i].notas[0], estudiantes[i].notas[1], estudiantes[i].notas[2], estudiantes[i].notas[3]);
            bool aprobado = true;
            for (int j = 0; j < 4; j++) {
                if (estudiantes[i].notas[j] < 6) {
                    aprobado = false;
                    break;
                }
            }
            if (aprobado) {
                printf("Estado: Aprobado\n");
            } else {
                printf("Estado: Desaprobado\n");
            }
        }
    }
}

int buscarEstudiantePorLegajo(int legajo) {
    for (int i = 0; i < contadorEstudiantes; i++) {
        if (estudiantes[i].legajo == legajo) {
            return i;
        }
    }
    return -1;
}

bool actualizarEstudiante(int legajo, const char* nuevoNombre, const char* nuevoApellido, const float nuevasNotas[4]) {
    int indice = buscarEstudiantePorLegajo(legajo);
    if (indice != -1) {
        copiarCadena(estudiantes[indice].nombre, nuevoNombre);
        copiarCadena(estudiantes[indice].apellido, nuevoApellido);
        for (int i = 0; i < 4; i++) {
            estudiantes[indice].notas[i] = nuevasNotas[i];
        }
        return true;
    }
    return false;
}

bool eliminarEstudiante(int legajo) {
    int indice = buscarEstudiantePorLegajo(legajo);
    if (indice != -1) {
        for (int i = indice; i < contadorEstudiantes - 1; i++) {
            estudiantes[i] = estudiantes[i + 1];
        }
        contadorEstudiantes--;
        return true;
    }
    return false;
}

int main() {
    float notas1[4] = {6.0, 7.5, 8.0, 9.0};
    float notas2[4] = {5.0, 4.5, 6.0, 7.0};
    agregarEstudiante("Juan", "Perez", notas1);
    agregarEstudiante("Ana", "Gomez", notas2);

    mostrarEstudiantes();

    float nuevasNotas[4] = {7.0, 8.0, 6.0, 7.5};
    actualizarEstudiante(1, "Juan", "Perez Modificado", nuevasNotas);

    mostrarEstudiantes();

    eliminarEstudiante(2);

    mostrarEstudiantes();

    return 0;
}

