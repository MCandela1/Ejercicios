#include <cstdio>
#include <cstring>

int main() {
    char cadena[100];

    printf("Introduce una cadena de caracteres: ");
    scanf("%99s", cadena);
    int longitud = strlen(cadena);
    if (longitud > 10) {
        printf("La cadena introducida es: %s\n", cadena);
    } else {
        printf("La cadena introducida tiene 10 caracteres o menos.\n");
    }

    return 0;
}
