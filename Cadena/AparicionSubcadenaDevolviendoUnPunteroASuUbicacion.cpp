#include <cstdio>
#include <cstring>

int main() {
    char cadena[100];
    char subcadena[50];

    printf("Introduce una cadena: ");
    scanf("%99s", cadena);

    printf("Introduce la subcadena a buscar: ");
    scanf("%49s", subcadena);

    char *puntero = strstr(cadena, subcadena);

    if (puntero != nullptr) {
        printf("La subcadena '%s' se encuentra en la posición %ld de la cadena.\n", subcadena, puntero - cadena);
    } else {
        printf("La subcadena '%s' no se encuentra en la cadena.\n", subcadena);
    }

    return 0;
}
