#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

int main() {
    char nombreApellido[100];
    printf("Ingrese el nombre y apellido: ");
    scanf(" %[^\n]", nombreApellido);
    bool inicioPalabra = true;

    printf("Las iniciales en mayúsculas son: ");
    for (int i = 0; nombreApellido[i] != '\0'; i++) {
        if (inicioPalabra && nombreApellido[i]!= ' ' && (i == 0 || nombreApellido[i - 1] == ' ')) {
            printf("%c", toupper(nombreApellido[i]));
            inicioPalabra = false;
        }
        if (nombreApellido[i] == ' ') {
            inicioPalabra = true;
        }
    }

    printf("\n");

    return 0;
}
