#include <cstdio>
#include <cstring>
#include<cctype>
using namespace std;
int main() {
    char cadena[100];
    int vocales = 0;

    printf("Ingrese una cadena: ");
    scanf("%[^\n]s", cadena);
    for (int i = 0; i < strlen(cadena); ++i) {

        char caracter = cadena[i];

        switch (tolower(caracter)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vocales++;
                break;
            default:
                break;
        }
    }
    printf("La cantidad de vocales en la cadena es: %d\n", vocales);

    return 0;
}
