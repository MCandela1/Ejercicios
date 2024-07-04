#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char cadena[1000];
    char cadenaInvertida[1000];
    printf("Ingrese una cadena de caracteres: ");
    scanf(" %[^\n]", cadena);
    int longitud = strlen(cadena);
    for (int i = 0; i < longitud; i++) {
        cadenaInvertida[i] = cadena[longitud - 1 - i];
    }
    cadenaInvertida[longitud] = '\0';
    printf("La cadena invertida es: %s\n", cadenaInvertida);

    return 0;
}
