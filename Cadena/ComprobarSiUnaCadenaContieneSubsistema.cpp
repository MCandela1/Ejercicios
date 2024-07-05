#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char cadena[1000];
    char subcadena[100];
    printf("Ingrese una cadena principal: ");
    scanf(" %[^\n]", cadena);
    printf("Ingrese la subcadena a buscar: ");
    scanf(" %[^\n]", subcadena);
    if (strstr(cadena, subcadena) != nullptr) {
        printf("La subcadena '%s' se encuentra en la cadena '%s'.\n", subcadena, cadena);
    } else {
        printf("La subcadena '%s' NO se encuentra en la cadena '%s'.\n", subcadena, cadena);
    }

    return 0;
}
