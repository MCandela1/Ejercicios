#include <cstdio>
#include <cstring>
#include <cctype>


bool esCaracterValido(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}


int esPalindromo(const char* caracter) {
    int len = 0;
    while (caracter[len] != '\0') {
        len++;
    }

    int inicio = 0;
    int fin = len - 1;

    while (inicio < fin) {

        while (!esCaracterValido(tolower(caracter[inicio])) && inicio < fin) {
            inicio++;
        }

        while (!esCaracterValido(tolower(caracter[fin])) && fin > inicio) {
            fin--;
        }

        if (tolower(caracter[inicio]) != tolower(caracter[fin])) {
            return 0;
        }

        inicio++;
        fin--;
    }

    return 1;
}

int main() {
    const int MAX_LENGTH = 100;
    char cadena[MAX_LENGTH];

    printf("Introduce una palabra o frase para verificar si es un palindromo: ");
    scanf(" %[^\n]", cadena);

    int resultado = esPalindromo(cadena);

    if (resultado == 1) {
        printf("La cadena '%s' es un palindromo.\n", cadena);
    } else {
        printf("La cadena '%s' no es un palihondromo.\n", cadena);
    }

    return 0;
}
