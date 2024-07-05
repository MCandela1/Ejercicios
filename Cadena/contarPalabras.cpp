#include <cstdio>
#include <cstring>
#include <cctype>

int contarOcurrencias(const char* texto, const char* palabra) {
    int contador = 0;
    int lenTexto = strlen(texto);
    int lenPalabra = strlen(palabra);

    for (int i = 0; i <= lenTexto - lenPalabra; ++i) {
        bool coincidencia = true;
        for (int j = 0; j < lenPalabra; ++j) {
            if (tolower(texto[i + j]) != tolower(palabra[j])) {
                coincidencia = false;
                break;
            }
        }
        if (coincidencia) {
            contador++;
        }
    }

    return contador;
}

int main() {
    const int MAX_LENGTH = 1000;
    char texto[MAX_LENGTH];
    char palabra[MAX_LENGTH];

    printf("Introduce un texto: ");
    scanf(" %[^\n]", texto);

    printf("Introduce una palabra para buscar: ");
    scanf(" %s", palabra);

    int ocurrencias = contarOcurrencias(texto, palabra);
    printf("La palabra '%s' aparece %d veces en el texto.\n", palabra, ocurrencias);

    return 0;
}
