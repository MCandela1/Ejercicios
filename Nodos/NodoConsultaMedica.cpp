#include <cstdio>
#include <cstring>

struct Paciente {
    char nombre[50];
    char apellido[50];
    int edad;
    int num_historia_clinica;
    char genero[10];
    int fue_a_consulta;
    int atendido_por_medico;
    Paciente* siguiente;
};

Paciente* lista_pacientes = nullptr; // Puntero al inicio de la lista de pacientes

void inicializarPaciente(Paciente* paciente) {
    paciente->siguiente = nullptr;
}

Paciente* obtenerNodoLibre() {
    Paciente* nuevoNodo = new Paciente;
    inicializarPaciente(nuevoNodo);
    return nuevoNodo;
}

void ingresarPaciente() {
    Paciente* nuevoPaciente = obtenerNodoLibre();

    printf("Ingrese el nombre del paciente: ");
    scanf("%s", nuevoPaciente->nombre);
    printf("Ingrese el apellido del paciente: ");
    scanf("%s", nuevoPaciente->apellido);
    printf("Ingrese la edad del paciente: ");
    scanf("%d", &nuevoPaciente->edad);
    printf("Ingrese el número de historia clínica del paciente: ");
    scanf("%d", &nuevoPaciente->num_historia_clinica);
    printf("Ingrese el género del paciente (Masculino/Femenino): ");
    scanf("%s", nuevoPaciente->genero);
    printf("El paciente fue a la consulta médica? (0: No, 1: Sí): ");
    scanf("%d", &nuevoPaciente->fue_a_consulta);
    if (nuevoPaciente->fue_a_consulta) {
        printf("El paciente fue atendido por el médico tratante? (0: No, 1: Sí): ");
        scanf("%d", &nuevoPaciente->atendido_por_medico);
    }

    // Insertar el nuevo paciente al inicio de la lista
    nuevoPaciente->siguiente = lista_pacientes;
    lista_pacientes = nuevoPaciente;

    printf("Paciente agregado correctamente.\n");
}

void mostrarPacientes() {
    Paciente* actual = lista_pacientes;
    bool hayPacientes = false;
    int contador = 1;

    printf("Lista de Pacientes:\n");
    while (actual != nullptr) {
        printf("Paciente %d:\n", contador);
        printf("Nombre: %s\n", actual->nombre);
        printf("Apellido: %s\n", actual->apellido);
        printf("Edad: %d\n", actual->edad);
        printf("Número de Historia Clínica: %d\n", actual->num_historia_clinica);
        printf("Género: %s\n", actual->genero);
        printf("Fue a la consulta médica: %s\n", actual->fue_a_consulta ? "Sí" : "No");
        if (actual->fue_a_consulta) {
            printf("Atendido por el médico tratante: %s\n", actual->atendido_por_medico ? "Sí" : "No");
        }
        printf("\n");
        actual = actual->siguiente;
        contador++;
        hayPacientes = true;
    }

    if (!hayPacientes) {
        printf("No hay pacientes registrados.\n");
    }
}

void actualizarPaciente() {
    if (lista_pacientes == nullptr) {
        printf("No hay pacientes para actualizar.\n");
        return;
    }

    int num_paciente_actualizar;
    printf("Ingrese el número del paciente a actualizar (1 a N): ");
    scanf("%d", &num_paciente_actualizar);

    Paciente* actual = lista_pacientes;
    int contador = 1;

    while (actual != nullptr && contador < num_paciente_actualizar) {
        actual = actual->siguiente;
        contador++;
    }

    if (actual == nullptr) {
        printf("Número de paciente no válido.\n");
        return;
    }

    printf("Actualización para Paciente %d:\n", num_paciente_actualizar);
    printf("Nombre actual: %s\n", actual->nombre);
    printf("Ingrese el nuevo nombre: ");
    scanf("%s", actual->nombre);

    printf("Apellido actual: %s\n", actual->apellido);
    printf("Ingrese el nuevo apellido: ");
    scanf("%s", actual->apellido);

    printf("Edad actual: %d\n", actual->edad);
    printf("Ingrese la nueva edad: ");
    scanf("%d", &actual->edad);

    printf("Número de Historia Clínica actual: %d\n", actual->num_historia_clinica);
    printf("Ingrese el nuevo número de historia clínica: ");
    scanf("%d", &actual->num_historia_clinica);

    printf("Género actual: %s\n", actual->genero);
    printf("Ingrese el nuevo género (Masculino/Femenino): ");
    scanf("%s", actual->genero);

    printf("El paciente fue a la consulta médica? (0: No, 1: Sí): ");
    scanf("%d", &actual->fue_a_consulta);
    if (actual->fue_a_consulta) {
        printf("El paciente fue atendido por el médico tratante? (0: No, 1: Sí): ");
        scanf("%d", &actual->atendido_por_medico);
    }

    printf("Paciente actualizado correctamente.\n");
}

void eliminarPaciente() {
    if (lista_pacientes == nullptr) {
        printf("No hay pacientes para eliminar.\n");
        return;
    }

    int num_paciente_eliminar;
    printf("Ingrese el número del paciente a eliminar (1 a N): ");
    scanf("%d", &num_paciente_eliminar);

    Paciente* anterior = nullptr;
    Paciente* actual = lista_pacientes;
    int contador = 1;

    while (actual != nullptr && contador < num_paciente_eliminar) {
        anterior = actual;
        actual = actual->siguiente;
        contador++;
    }

    if (actual == nullptr) {
        printf("Número de paciente no válido.\n");
        return;
    }

    // Eliminar el nodo de la lista
    if (anterior == nullptr) {
        // Caso especial: el nodo a eliminar es el primero
        lista_pacientes = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    delete actual;
    printf("Paciente eliminado correctamente.\n");
}

void liberarMemoria() {
    Paciente* actual = lista_pacientes;
    Paciente* siguiente = nullptr;

    while (actual != nullptr) {
        siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }

    lista_pacientes = nullptr;
}

int main() {
    int opcion;

    do {
        printf("\n--- Menú ---\n");
        printf("1. Ingresar paciente\n");
        printf("2. Mostrar pacientes\n");
        printf("3. Actualizar paciente\n");
        printf("4. Eliminar paciente\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarPaciente();
                break;
            case 2:
                mostrarPacientes();
                break;
            case 3:
                actualizarPaciente();
                break;
            case 4:
                eliminarPaciente();
                break;
            case 5:
                printf("Saliendo del programa.\n");
                liberarMemoria();
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}

