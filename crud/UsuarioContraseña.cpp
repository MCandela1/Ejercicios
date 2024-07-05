#include <cstdio>
#include <cstring>

const int MAX_USERS = 100;
const int MAX_LENGTH = 50;

struct Usuario {
    char nombre[MAX_LENGTH];
    char contrasenia[MAX_LENGTH];
};

Usuario usuarios[MAX_USERS];
int totalUsuarios = 0;

bool compararCadenas(const char* cadena1, const char* cadena2) {
    int i = 0;
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            return false;
        }
        i++;
    }
    return cadena1[i] == '\0' && cadena2[i] == '\0';
}

void agregarUsuario() {
    if (totalUsuarios >= MAX_USERS) {
        printf("No se pueden agregar más usuarios.\n");
        return;
    }

    printf("Ingrese el nombre del usuario: ");
    scanf("%s", usuarios[totalUsuarios].nombre);
    printf("Ingrese la contraseña del usuario: ");
    scanf("%s", usuarios[totalUsuarios].contrasenia);

    totalUsuarios++;
    printf("Usuario agregado correctamente.\n");
}

void buscarUsuario() {
    char nombre[MAX_LENGTH];
    printf("Ingrese el nombre del usuario a buscar: ");
    scanf("%s", nombre);

    for (int i = 0; i < totalUsuarios; i++) {
        if (compararCadenas(usuarios[i].nombre, nombre)) {
            printf("Usuario encontrado: %s, Contrasenia: %s\n", usuarios[i].nombre, usuarios[i].contrasenia);
            return;
        }
    }
    printf("Usuario no encontrado.\n");
}

void actualizarUsuario() {
    char nombre[MAX_LENGTH];
    printf("Ingrese el nombre del usuario a actualizar: ");
    scanf("%s", nombre);

    for (int i = 0; i < totalUsuarios; i++) {
        if (compararCadenas(usuarios[i].nombre, nombre)) {
            printf("Ingrese la nueva contrasenia del usuario: ");
            scanf("%s", usuarios[i].contrasenia);
            printf("Contrasenia actualizada correctamente.\n");
            return;
        }
    }
    printf("Usuario no encontrado.\n");
}

void eliminarUsuario() {
    char nombre[MAX_LENGTH];
    printf("Ingrese el nombre del usuario a eliminar: ");
    scanf("%s", nombre);

    for (int i = 0; i < totalUsuarios; i++) {
        if (compararCadenas(usuarios[i].nombre, nombre)) {
            for (int j = i; j < totalUsuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            totalUsuarios--;
            printf("Usuario eliminado correctamente.\n");
            return;
        }
    }
    printf("Usuario no encontrado.\n");
}

void mostrarUsuarios() {
    printf("Lista de usuarios:\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("Usuario: %s, Contrasenia: %s\n", usuarios[i].nombre, usuarios[i].contrasenia);
    }
}

int main() {
    int opcion;

    do {
        printf("\n--- Menu de Usuarios ---\n");
        printf("1. Agregar usuario\n");
        printf("2. Buscar usuario\n");
        printf("3. Actualizar usuario\n");
        printf("4. Eliminar usuario\n");
        printf("5. Mostrar todos los usuarios\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                agregarUsuario();
                break;
            case 2:
                buscarUsuario();
                break;
            case 3:
                actualizarUsuario();
                break;
            case 4:
                eliminarUsuario();
                break;
            case 5:
                mostrarUsuarios();
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        }
    } while(opcion != 6);

    return 0;
}
