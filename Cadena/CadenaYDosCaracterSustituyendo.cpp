//Pide una cadena y dos caracteres, sustituye
//la aparición del primer caracter
//en la cadena por el segundo caracter

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char cadena[1000];
    char caracterOriginal, caracterNuevo;
    printf("Ingrese una cadena de caracteres: ");
    scanf(" %[^\n]", cadena);
    printf("Ingrese el caracter a reemplazar: ");
    scanf(" %c", &caracterOriginal);
    printf("Ingrese el nuevo caracter: ");
    scanf(" %c", &caracterNuevo);
    int longitud = strlen(cadena);
    for (int i = 0; i < longitud; i++) {
        if (cadena[i] == caracterOriginal) {
            cadena[i] = caracterNuevo;
        }
    }
    printf("La cadena modificada es: %s\n", cadena);

    return 0;
}
