#include <cstdio>
#include <cstring>
#include <cctype>

const int MAX = 100;

void ingresarCadena(char cadena[]) {
    printf("Ingrese una cadena: ");
    scanf(" %[^\n]", cadena);
}

void contarLongitud(char cadena[]) {
    int longitud = strlen(cadena);
    printf("La longitud de la cadena es: %d\n", longitud);
}

void contarLetrasRepetidas(char cadena[]) {
    int contador[256] = {0};
    for (int i = 0; cadena[i] != '\0'; i++) {
        contador[tolower(cadena[i])]++;
    }
    printf("Letras que se repiten:\n");
    for (int i = 0; i < 256; i++) {
        if (contador[i] > 1) {
            printf("'%c' se repite %d veces\n", i, contador[i]);
        }
    }
}

void compararCadenas(char cadena1[], char cadena2[]) {
    if (strcmp(cadena1, cadena2) == 0) {
        printf("Las cadenas son iguales.\n");
    } else {
        printf("Las cadenas son diferentes.\n");
    }
}

void concatenarCadenas(char cadena1[], char cadena2[], char resultado[]) {
    strcpy(resultado, cadena1);
    strcat(resultado, cadena2);
    printf("La cadena concatenada es: %s\n", resultado);
}

void verificarPalindroma(char cadena[]) {
    int longitud = strlen(cadena);
    bool esPalindroma = true;
    for (int i = 0; i < longitud / 2; i++) {
        if (tolower(cadena[i]) != tolower(cadena[longitud - i - 1])) {
            esPalindroma = false;
            break;
        }
    }
    if (esPalindroma) {
        printf("La cadena es palíndroma.\n");
    } else {
        printf("La cadena no es palíndroma.\n");
    }
}

void eliminarCaracter(char cadena[], char caracter) {
    int longitud = strlen(cadena);
    int j = 0;
    for (int i = 0; i < longitud; i++) {
        if (tolower(cadena[i]) != tolower(caracter)) {
            cadena[j++] = cadena[i];
        }
    }
    cadena[j] = '\0';
    printf("Cadena después de eliminar '%c': %s\n", caracter, cadena);
}

int main() {
    char cadena1[MAX], cadena2[MAX], resultado[MAX * 2];
    int opcion;

    while (true) {
        printf("1. Ingresar cadena\n");
        printf("2. Contar longitud de la cadena\n");
        printf("3. Contar letras que se repiten\n");
        printf("4. Comparar dos cadenas\n");
        printf("5. Concatenar dos cadenas\n");
        printf("6. Verificar si una cadena es palíndroma\n");
        printf("7. Eliminar un carácter de la cadena\n");
        printf("8. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarCadena(cadena1);
                break;
            case 2:
                contarLongitud(cadena1);
                break;
            case 3:
                contarLetrasRepetidas(cadena1);
                break;
            case 4:
                printf("Ingrese la segunda cadena para comparar: ");
                scanf(" %[^\n]", cadena2);
                compararCadenas(cadena1, cadena2);
                break;
            case 5:
                printf("Ingrese la segunda cadena para concatenar: ");
                scanf(" %[^\n]", cadena2);
                concatenarCadenas(cadena1, cadena2, resultado);
                break;
            case 6:
                verificarPalindroma(cadena1);
                break;
            case 7:
                char caracter;
                printf("Ingrese el carácter a eliminar: ");
                scanf(" %c", &caracter);
                eliminarCaracter(cadena1, caracter);
                break;
            case 8:
                return 0;
            default:
                printf("Opción no válida.\n");
        }
    }

    return 0;
}
