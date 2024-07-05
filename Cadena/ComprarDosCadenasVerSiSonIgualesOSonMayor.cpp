#include <cstdio>
#include <cstring>

int main() {
    char cadena1[100];
    char cadena2[100];

    printf("Introduce la primera cadena: ");
    scanf("%99s", cadena1);

    printf("Introduce la segunda cadena: ");
    scanf("%99s", cadena2);

    int resultado = strcmp(cadena1, cadena2);///-->comparo las dos cadenas

    if (resultado == 0) {
        printf("Las cadenas son iguales.\n");
    } else if (resultado < 0) {
        printf("La primera cadena es menor que la segunda.\n");
    } else {
        printf("La primera cadena es mayor que la segunda.\n");
    }

    return 0;
}
