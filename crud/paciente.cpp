//Hacer un programa donde requieran una estructura pacientes donde
//tenga que tener el nombre del paciente el g�nero la edad y
//su n�mero de historia clinica crear un men� donde muestre

//Agregar paciente
//Mostrar paciente
//Buscar paciente  por su n�mero de historia cl�nica
//Y eliminar paciente

#include <stdio.h>

// Definici�n de la estructura de paciente
typedef struct {
    char nombre[50];
    char genero[10]; // "Masculino" o "Femenino"
    int edad;
    int num_historia_clinica;
} Paciente;

void ingresarPaciente(Paciente &paciente) {
    printf("Ingrese el nombre del paciente: ");
    scanf("%s", paciente.nombre);
    printf("Ingrese el g�nero del paciente (Masculino/Femenino): ");
    scanf("%s", paciente.genero);
    printf("Ingrese la edad del paciente: ");
    scanf("%d", &paciente.edad);
    printf("Ingrese el n�mero de historia cl�nica del paciente: ");
    scanf("%d", &paciente.num_historia_clinica);
}

void mostrarPaciente(const Paciente &paciente) {
    printf("Nombre: %s\n", paciente.nombre);
    printf("G�nero: %s\n", paciente.genero);
    printf("Edad: %d\n", paciente.edad);
    printf("N�mero de Historia Cl�nica: %d\n", paciente.num_historia_clinica);
}

void buscarPaciente(const Paciente pacientes[], int total_pacientes, int num_historia_clinica) {
    for (int i = 0; i < total_pacientes; i++) {
        if (pacientes[i].num_historia_clinica == num_historia_clinica) {
            printf("Paciente encontrado:\n");
            mostrarPaciente(pacientes[i]);
            return;
        }
    }
    printf("Paciente con n�mero de historia cl�nica %d no encontrado.\n", num_historia_clinica);
}

void eliminarPaciente(Paciente pacientes[], int &total_pacientes, int num_historia_clinica) {
    for (int i = 0; i < total_pacientes; i++) {
        if (pacientes[i].num_historia_clinica == num_historia_clinica) {
            for (int j = i; j < total_pacientes - 1; j++) {
                pacientes[j] = pacientes[j + 1];
            }
            total_pacientes--;
            printf("Paciente con n�mero de historia cl�nica %d eliminado.\n", num_historia_clinica);
            return;
        }
    }
    printf("Paciente con n�mero de historia cl�nica %d no encontrado.\n", num_historia_clinica);
}

int main() {
    int num_pacientes = 100; // Capacidad m�xima de pacientes
    Paciente pacientes[num_pacientes];
    int total_pacientes = 0;

    int opcion;
    do {
        printf("\n--- Men� ---\n");
        printf("1. Agregar paciente\n");
        printf("2. Mostrar pacientes\n");
        printf("3. Buscar paciente por n�mero de historia cl�nica\n");
        printf("4. Eliminar paciente\n");
        printf("5. Salir\n");
        printf("Seleccione una opci�n: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (total_pacientes < num_pacientes) {
                    ingresarPaciente(pacientes[total_pacientes]);
                    total_pacientes++;
                } else {
                    printf("Capacidad m�xima de pacientes alcanzada.\n");
                }
                break;
            case 2:
                for (int i = 0; i < total_pacientes; i++) {
                    printf("\nPaciente %d:\n", i + 1);
                    mostrarPaciente(pacientes[i]);
                }
                break;
            case 3:
                printf("Ingrese el n�mero de historia cl�nica del paciente a buscar: ");
                int num_historia_buscar;
                scanf("%d", &num_historia_buscar);
                buscarPaciente(pacientes, total_pacientes, num_historia_buscar);
                break;
            case 4:
                printf("Ingrese el n�mero de historia cl�nica del paciente a eliminar: ");
                int num_historia_eliminar;
                scanf("%d", &num_historia_eliminar);
                eliminarPaciente(pacientes, total_pacientes, num_historia_eliminar);
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opci�n no v�lida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}
