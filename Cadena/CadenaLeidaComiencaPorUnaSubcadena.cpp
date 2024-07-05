#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char cadena[100];
    char subcadena[100];
    printf("Ingrese la cadena principal: ");
    scanf("%s", cadena);
    printf("Ingrese la subcadena: ");
    scanf("%s", subcadena);
    int lenCadena = strlen(cadena);
    int lenSubcadena = strlen(subcadena);
    bool comienzaConSubcadena = false;
    if (lenSubcadena <= lenCadena) {
        if (strncmp(cadena, subcadena, lenSubcadena) == 0) {
            comienzaConSubcadena = true;
        }
    }
    if (comienzaConSubcadena) {
        printf("La cadena \"%s\" comienza con la subcadena \"%s\".\n", cadena, subcadena);
    } else {
        printf("La cadena \"%s\" no comienza con la subcadena \"%s\".\n", cadena, subcadena);
    }

    return 0;
}
