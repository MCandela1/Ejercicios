//Hacer un programa donde requieran una estructura pacientes donde
//tenga que tener el nombre del paciente el g�nero la edad y
//su n�mero de historia clinica crear un men� donde muestre

//Agregar paciente
//Mostrar paciente
//Buscar paciente  por su n�mero de historia cl�nica
//Y eliminar paciente

#include <cstdio>
#include <cstring>

const int MAX_PACIENTES = 100;
const int MAX_NOMBRE = 50;

struct Paciente {
    char nombre[MAX_NOMBRE];
    char genero[10];
    int edad;
    int num_historia_clinica;
};

Paciente pacientes[MAX_PACIENTES];
int total_pacientes = 0;

void agregarPaciente() {
    if (total_pacientes >= MAX_PACIENTES) {
        printf("No se pueden agregar m�s pacientes. Capacidad m�xima alcanzada.\n");
        return;
    }

    Paciente nuevoPaciente;
    printf("Ingrese nombre del paciente: ");
    scanf("%s", nuevoPaciente.nombre);
    printf("Ingrese g�nero del paciente (Masculino/Femenino): ");
    scanf("%s", nuevoPaciente.genero);
    printf("Ingrese edad del paciente: ");
    scanf("%d", &nuevoPaciente.edad);
    printf("Ingrese n�mero de historia cl�nica del paciente: ");
    scanf("%d", &nuevoPaciente.num_historia_clinica);

    pacientes[total_pacientes] = nuevoPaciente;
    total_pacientes++;

    printf("Paciente agregado correctamente.\n");
}

void mostrarPacientes() {
    if (total_pacientes == 0) {
        printf("No hay pacientes registrados.\n");
        return;
    }

    printf("Lista de Pacientes:\n");
    for (int i = 0; i < total_pacientes; ++i) {
        printf("Nombre: %s, ", pacientes[i].nombre);
        printf("G�nero: %s, ", pacientes[i].genero);
        printf("Edad: %d, ", pacientes[i].edad);
        printf("Nro. Historia Cl�nica: %d\n", pacientes[i].num_historia_clinica);
    }
}

void buscarPaciente(int num_historia_clinica) {
    bool encontrado = false;
    for (int i = 0; i < total_pacientes; ++i) {
        if (pacientes[i].num_historia_clinica == num_historia_clinica) {
            printf("Paciente encontrado:\n");
            printf("Nombre: %s, ", pacientes[i].nombre);
            printf("G�nero: %s, ", pacientes[i].genero);
            printf("Edad: %d, ", pacientes[i].edad);
            printf("Nro. Historia Cl�nica: %d\n", pacientes[i].num_historia_clinica);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("No se encontr� paciente con n�mero de historia cl�nica %d.\n", num_historia_clinica);
    }
}

void eliminarPaciente(int num_historia_clinica) {
    bool encontrado = false;
    for (int i = 0; i < total_pacientes; ++i) {
        if (pacientes[i].num_historia_clinica == num_historia_clinica) {
            for (int j = i; j < total_pacientes - 1; ++j) {
                pacientes[j] = pacientes[j + 1];
            }
            total_pacientes--;
            printf("Paciente con n�mero de historia cl�nica %d eliminado correctamente.\n", num_historia_clinica);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("No se encontr� paciente con n�mero de historia cl�nica %d.\n", num_historia_clinica);
    }
}

int main() {
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
                agregarPaciente();
                break;
            case 2:
                mostrarPacientes();
                break;
            case 3:
                int num_historia_clinica;
                printf("Ingrese n�mero de historia cl�nica a buscar: ");
                scanf("%d", &num_historia_clinica);
                buscarPaciente(num_historia_clinica);
                break;
            case 4:
                int num_historia_eliminar;
                printf("Ingrese n�mero de historia cl�nica a eliminar: ");
                scanf("%d", &num_historia_eliminar);
                eliminarPaciente(num_historia_eliminar);
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opci�n inv�lida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}


