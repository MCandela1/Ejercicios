//Se le pide al desarrollador (ustedes) que cree el siguiente programa:

// crear: El docente deberá ingresar la cantidad de alumnos que rindieron el examen.Luego deberá ingresar el apellido del alumnoLuego las notas de cada uno de los 4 ejercicio. El programa deberá Sumar las 4 notas de los ejercicios. y validar si el alumno aprobó o no.

//Leer: El programa deberá mostrar una lista con los alumnos aprobados con su respectiva nota y una lista con todos los alumnos que rindieron con su respectiva nota
//Actualizar: Modificar un estudiante existente.
//Eliminar: Eliminar un estudiante de la lista.

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Student {
    char apellido[50];
    int notas[4];
    int totalNotas;
    bool aprobado;
};

void crearAlumno(vector<Student>& alumnos) {
    Student alumno;

    printf("Ingrese el apellido del alumno: ");
    scanf("%s", alumno.apellido);

    printf("Ingrese las notas de los 4 ejercicios para el alumno %s:\n", alumno.apellido);
    alumno.totalNotas = 0;
    for (int j = 0; j < 4; ++j) {
        printf("Nota del ejercicio %d: ", j + 1);
        scanf("%d", &alumno.notas[j]);
        alumno.totalNotas += alumno.notas[j];
    }
    alumno.aprobado = alumno.totalNotas >= 60;

    alumnos.push_back(alumno);
}

void mostrarTodosAlumnos(const vector<Student>& alumnos) {
    printf("\nLista de todos los alumnos que rindieron el examen:\n");
    for (int i = 0; i < alumnos.size(); ++i) {
        printf("Apellido: %s\n", alumnos[i].apellido);
        printf("Notas: %d, %d, %d, %d\n", alumnos[i].notas[0], alumnos[i].notas[1], alumnos[i].notas[2], alumnos[i].notas[3]);
        printf("Total de notas: %d\n", alumnos[i].totalNotas);
        printf("Estado: %s\n", alumnos[i].aprobado ? "Aprobado" : "No Aprobado");
        printf("\n");
    }
}

void mostrarAlumnosAprobados(const vector<Student>& alumnos) {
    printf("\nLista de alumnos aprobados:\n");
    for (int i = 0; i < alumnos.size(); ++i) {
        if (alumnos[i].aprobado) {
            printf("Apellido: %s\n", alumnos[i].apellido);
            printf("Nota total: %d\n", alumnos[i].totalNotas);
            printf("\n");
        }
    }
}

void actualizarAlumno(vector<Student>& alumnos, const char* apellidoBuscado) {
    bool encontrado = false;
    for (int i = 0; i < alumnos.size(); ++i) {
        if (strcmp(alumnos[i].apellido, apellidoBuscado) == 0) {

            printf("Ingrese las nuevas notas de los 4 ejercicios para el alumno %s:\n", alumnos[i].apellido);
            alumnos[i].totalNotas = 0;
            for (int j = 0; j < 4; ++j) {
                printf("Nota del ejercicio %d: ", j + 1);
                scanf("%d", &alumnos[i].notas[j]);
                alumnos[i].totalNotas += alumnos[i].notas[j];
            }

            alumnos[i].aprobado = alumnos[i].totalNotas >= 60;

            printf("Alumno actualizado correctamente.\n");
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("No se encontró ningún alumno con el apellido %s.\n", apellidoBuscado);
    }
}

void eliminarAlumno(vector<Student>& alumnos, const char* apellidoBuscado) {
    bool encontrado = false;
    for (int i = 0; i < alumnos.size(); ++i) {
        if (strcmp(alumnos[i].apellido, apellidoBuscado) == 0) {

            for (int j = i; j < alumnos.size() - 1; ++j) {
                alumnos[j] = alumnos[j + 1];
            }
            alumnos.pop_back();
            printf("Alumno eliminado correctamente.\n");
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("No se encontró ningún alumno con el apellido %s.\n", apellidoBuscado);
    }
}

int main() {
    vector<Student> alumnos;

    int opcion;
    char apellidoBuscado[50];

    do {
        printf("\nMenu:\n");
        printf("1. Crear nuevo alumno\n");
        printf("2. Mostrar todos los alumnos\n");
        printf("3. Mostrar alumnos aprobados\n");
        printf("4. Actualizar datos de un alumno\n");
        printf("5. Eliminar un alumno\n");
        printf("6. Salir\n");
        printf("Ingrese la opción deseada: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                crearAlumno(alumnos);
                break;
            case 2:
                mostrarTodosAlumnos(alumnos);
                break;
            case 3:
                mostrarAlumnosAprobados(alumnos);
                break;
            case 4:
                printf("Ingrese el apellido del alumno que desea actualizar: ");
                scanf("%s", apellidoBuscado);
                actualizarAlumno(alumnos, apellidoBuscado);
                break;
            case 5:
                printf("Ingrese el apellido del alumno que desea eliminar: ");
                scanf("%s", apellidoBuscado);
                eliminarAlumno(alumnos, apellidoBuscado);
                break;
            case 6:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}
