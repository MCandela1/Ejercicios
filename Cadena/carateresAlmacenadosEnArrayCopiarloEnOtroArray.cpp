#include <cstdio>

int main() {
    const int maximaLong = 100;
    char original[maximaLong];
    char temp[maximaLong];


    printf("Introduce una cadena de caracteres (máximo %d caracteres): ", maximaLong - 1);
    scanf("%99s", original);

    int i = 0;
    while (original[i] != '\0') {
        temp[i] = original[i];
        i++;
    }
    temp[i] = '\0';
    printf("La cadena copiada es: %s\n", temp);

    return 0;
}
