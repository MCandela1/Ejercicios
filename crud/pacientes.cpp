#include <stdio.h>
#include <string.h>

struct Paciente {
    char nombre[50];
    char apellido[50];
    int edad;
    int num_historia_clinica;
    char genero[10];
    int fue_a_consulta;
    int atendido_por_medico;
};

void ingresarPaciente(Paciente &paciente) {
    printf("Ingrese el nombre del paciente: ");
    scanf("%s", paciente.nombre);
    printf("Ingrese el apellido del paciente: ");
    scanf("%s", paciente.apellido);
    printf("Ingrese la edad del paciente: ");
    scanf("%d", &paciente.edad);
    printf("Ingrese el numero de historia clinica del paciente: ");
    scanf("%d", &paciente.num_historia_clinica);
    printf("Ingrese el genero del paciente (Masculino/Femenino): ");
    scanf("%s", paciente.genero);
    printf("El paciente fue a la consulta medica? (0: No, 1: Sí): ");
    scanf("%d", &paciente.fue_a_consulta);
    if (paciente.fue_a_consulta) {
        printf("El paciente fue atendido por el medico tratante? (0: No, 1: Sí): ");
        scanf("%d", &paciente.atendido_por_medico);
    }
}

void mostrarPaciente(const Paciente &paciente) {
    printf("Nombre: %s\n", paciente.nombre);
    printf("Apellido: %s\n", paciente.apellido);
    printf("Edad: %d\n", paciente.edad);
    printf("Numero de Historia Clínica: %d\n", paciente.num_historia_clinica);
    printf("Genero: %s\n", paciente.genero);
    printf("Fue a la consulta medica: %s\n", paciente.fue_a_consulta ? "Si" : "No");
    if (paciente.fue_a_consulta) {
        printf("Atendido por el medico tratante: %s\n", paciente.atendido_por_medico ? "Si" : "No");
    }
}

void actualizarPaciente(Paciente &paciente) {
    printf("Actualizar informacion del paciente:\n");

    char nuevo_valor[50];
    printf("Nombre actual: %s\n", paciente.nombre);
    printf("Ingrese el nuevo nombre: ");
    scanf("%s", nuevo_valor);
    if (nuevo_valor[0] != '\0') {
        for (int i = 0; i < 50; ++i) {
            paciente.nombre[i] = nuevo_valor[i];
            if (nuevo_valor[i] == '\0') break;
        }
    }

    printf("Apellido actual: %s\n", paciente.apellido);
    printf("Ingrese el nuevo apellido: ");
    scanf("%s", nuevo_valor);
    if (nuevo_valor[0] != '\0') {
        for (int i = 0; i < 50; ++i) {
            paciente.apellido[i] = nuevo_valor[i];
            if (nuevo_valor[i] == '\0') break;
        }
    }

    printf("Edad actual: %d\n", paciente.edad);
    printf("Ingrese la nueva edad: ");
    int temp;
    scanf("%d", &temp);
    if (temp > 0) {
        paciente.edad = temp;
    }

    printf("Número de Historia Clinica actual: %d\n", paciente.num_historia_clinica);
    printf("Ingrese el nuevo número de historia clinica: ");
    scanf("%d", &temp);
    if (temp > 0) {
        paciente.num_historia_clinica = temp;
    }

    printf("Genero actual: %s\n", paciente.genero);
    printf("Ingrese el nuevo genero (Masculino/Femenino): ");
    scanf("%s", nuevo_valor);
    if (nuevo_valor[0] != '\0') {
        for (int i = 0; i < 10; ++i) {
            paciente.genero[i] = nuevo_valor[i];
            if (nuevo_valor[i] == '\0') break;
        }
    }

    printf("El paciente fue a la consulta medica? (0: No, 1: Si): ");
    scanf("%d", &paciente.fue_a_consulta);
    if (paciente.fue_a_consulta) {
        printf("El paciente fue atendido por el medico tratante? (0: No, 1: Si): ");
        scanf("%d", &paciente.atendido_por_medico);
    }
}

void eliminarPaciente(Paciente pacientes[], int &total_pacientes, int indice) {
    if (indice < 0 || indice >= total_pacientes) {
        printf("Numero de paciente no valido.\n");
        return;
    }
    for (int i = indice; i < total_pacientes - 1; i++) {
        pacientes[i] = pacientes[i + 1];
    }
    total_pacientes--;
    printf("Paciente eliminado.\n");
}

int main() {
    int num_pacientes = 100;
    Paciente pacientes[num_pacientes];
    int total_pacientes = 0;

    int opcion;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Ingresar paciente\n");
        printf("2. Mostrar pacientes\n");
        printf("3. Actualizar paciente\n");
        printf("4. Eliminar paciente\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (total_pacientes < num_pacientes) {
                    ingresarPaciente(pacientes[total_pacientes]);
                    total_pacientes++;
                } else {
                    printf("Capacidad maxima de pacientes alcanzada.\n");
                }
                break;
            case 2:
                for (int i = 0; i < total_pacientes; i++) {
                    printf("\nPaciente %d:\n", i + 1);
                    mostrarPaciente(pacientes[i]);
                }
                break;
            case 3:
                printf("Ingrese el numero del paciente a actualizar (1 a %d): ", total_pacientes);
                int num_paciente_actualizar;
                scanf("%d", &num_paciente_actualizar);
                if (num_paciente_actualizar > 0 && num_paciente_actualizar <= total_pacientes) {
                    actualizarPaciente(pacientes[num_paciente_actualizar - 1]);
                } else {
                    printf("Numero de paciente no valido.\n");
                }
                break;
            case 4:
                printf("Ingrese el numero del paciente a eliminar (1 a %d): ", total_pacientes);
                int num_paciente_eliminar;
                scanf("%d", &num_paciente_eliminar);
                if (num_paciente_eliminar > 0 && num_paciente_eliminar <= total_pacientes) {
                    eliminarPaciente(pacientes, total_pacientes, num_paciente_eliminar - 1);
                } else {
                    printf("Numero de paciente no válido.\n");
                }
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}

