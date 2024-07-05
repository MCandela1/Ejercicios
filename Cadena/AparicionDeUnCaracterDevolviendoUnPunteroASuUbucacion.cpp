#include <cstdio>
#include <cstring>

int main() {
    char cadena[100];
    char caracter;

    printf("Introduce una cadena: ");
    scanf("%99s", cadena);

    printf("Introduce el car�cter a buscar: ");
    scanf(" %c", &caracter);

    char *puntero = strchr(cadena, caracter);

    if (puntero != nullptr) {
        printf("El car�cter '%c' se encuentra en la posici�n %ld de la cadena.\n", caracter, puntero - cadena);
    } else {
        printf("El car�cter '%c' no se encuentra en la cadena.\n", caracter);
    }

    return 0;
}
