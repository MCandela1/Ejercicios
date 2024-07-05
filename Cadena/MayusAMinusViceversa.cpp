#include <iostream>
#include <cstdio>
#include <cctype>  // Para toupper y tolower

using namespace std;

int main() {
    char cadena[1000];
    printf("Ingrese una cadena de caracteres: ");
    scanf(" %[^\n]", cadena);
    for (int i = 0; cadena[i] != '\0'; i++) {

        if (islower(cadena[i])) {
            cadena[i] = toupper(cadena[i]);
        } else if (isupper(cadena[i])) {
            cadena[i] = tolower(cadena[i]);
        }
    }
    printf("La cadena con letras intercambiadas es: %s\n", cadena);

    return 0;
}
