#include <cstdio>
#include <cstring>

const int MAX_NOMBRE = 50;

struct Paciente {
    char nombre[MAX_NOMBRE];
    char genero[10];
    int edad;
    int num_historia_clinica;
    bool activo;
    Paciente* siguiente;
};

Paciente* lista_pacientes = nullptr; // Inicialmente la lista est� vac�a

void inicializarPaciente(Paciente* paciente) {
    paciente->activo = true;
    paciente->siguiente = nullptr;
}

Paciente* obtenerNodoLibre() {
    Paciente* nuevoNodo = new Paciente;
    inicializarPaciente(nuevoNodo);
    return nuevoNodo;
}

void agregarPaciente() {
    Paciente* nuevoPaciente = obtenerNodoLibre();

    printf("Ingrese nombre del paciente: ");
    scanf("%s", nuevoPaciente->nombre);
    printf("Ingrese g�nero del paciente (Masculino/Femenino): ");
    scanf("%s", nuevoPaciente->genero);
    printf("Ingrese edad del paciente: ");
    scanf("%d", &nuevoPaciente->edad);
    printf("Ingrese n�mero de historia cl�nica del paciente: ");
    scanf("%d", &nuevoPaciente->num_historia_clinica);

    nuevoPaciente->siguiente = lista_pacientes;
    lista_pacientes = nuevoPaciente;

    printf("Paciente agregado correctamente.\n");
}

void mostrarPacientes() {
    Paciente* actual = lista_pacientes;
    bool hayPacientes = false;

    printf("Lista de Pacientes:\n");
    while (actual != nullptr) {
        if (actual->activo) {
            printf("Nombre: %s, ", actual->nombre);
            printf("G�nero: %s, ", actual->genero);
            printf("Edad: %d, ", actual->edad);
            printf("Nro. Historia Cl�nica: %d\n", actual->num_historia_clinica);
            hayPacientes = true;
        }
        actual = actual->siguiente;
    }

    if (!hayPacientes) {
        printf("No hay pacientes registrados.\n");
    }
}

void buscarPaciente(int num_historia_clinica) {
    Paciente* actual = lista_pacientes;
    bool encontrado = false;

    while (actual != nullptr) {
        if (actual->activo && actual->num_historia_clinica == num_historia_clinica) {
            printf("Paciente encontrado:\n");
            printf("Nombre: %s, ", actual->nombre);
            printf("G�nero: %s, ", actual->genero);
            printf("Edad: %d, ", actual->edad);
            printf("Nro. Historia Cl�nica: %d\n", actual->num_historia_clinica);
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (!encontrado) {
        printf("No se encontr� paciente con n�mero de historia cl�nica %d.\n", num_historia_clinica);
    }
}

void eliminarPaciente(int num_historia_clinica) {
    Paciente* actual = lista_pacientes;
    bool encontrado = false;

    while (actual != nullptr) {
        if (actual->activo && actual->num_historia_clinica == num_historia_clinica) {
            actual->activo = false;
            printf("Paciente con n�mero de historia cl�nica %d eliminado correctamente.\n", num_historia_clinica);
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (!encontrado) {
        printf("No se encontr� paciente con n�mero de historia cl�nica %d.\n", num_historia_clinica);
    }
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
                liberarMemoria();
                break;
            default:
                printf("Opci�n inv�lida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}

