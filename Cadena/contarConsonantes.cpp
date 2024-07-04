#include <cstdio>
#include <cstring>
#include <cctype>

bool es_vocal(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    char cadena[100];
    int consonantes = 0;

    printf("Ingrese una cadena: ");
    scanf(" %[^\n]s", cadena);
    for (int i = 0; i < strlen(cadena); ++i) {
        char caracter = tolower(cadena[i]);
        if (caracter >= 'a' && caracter <= 'z' && !es_vocal(caracter)) {

            consonantes++;
        }
    }

    printf("La cantidad de consonantes en la cadena es: %d\n", consonantes);

    return 0;
}
