#include <cstdio>
#include <cctype>

int contarPalabras(const char* caracter) {
    int palabras = 0;
    bool enPalabra = false;
    for (int i = 0; caracter[i] != '\0'; ++i) {
        if (isspace(caracter[i])) {
            enPalabra = false;
        } else {
            if (!enPalabra) {
                palabras++;
                enPalabra = true;
            }
        }
    }

    return palabras;
}
int main() {
    const int MAX_LENGTH = 100;
    char cadena[MAX_LENGTH];
    printf("Introduce una cadena de caracteres: ");
    scanf(" %99[^\n]", cadena);
    int numPalabras = contarPalabras(cadena);
    printf("Numero de palabras en la cadena: %d\n", numPalabras);

    return 0;
}
