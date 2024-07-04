#include <cstdio>
#include <cstring>

int main() {
    const int MAX_LENGTH = 100;
    char cadena1[MAX_LENGTH], cadena2[MAX_LENGTH];
    printf("Introduce la primera cadena de caracteres: ");
    scanf(" %99[^\n]", cadena1);

    printf("Introduce la segunda cadena de caracteres: ");
    scanf(" %99[^\n]", cadena2);
    int comparacion = strcmp(cadena1, cadena2);

    if (comparacion == 0) {
        printf("Las dos cadenas son iguales.\n");
    } else if (comparacion < 0) {
        printf("La cadena '%s' es mayor alfabeticamente que la cadena '%s'.\n", cadena2, cadena1);
    } else {
        printf("La cadena '%s' es mayor alfabeticamente que la cadena '%s'.\n", cadena1, cadena2);
    }

    return 0;
}
