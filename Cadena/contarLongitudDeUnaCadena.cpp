#include <cstdio>
#include <cstring>

int main() {
    const int MAX_LENGTH = 100;
    char str[MAX_LENGTH];

    printf("Introduce una cadena de caracteres: ");
    scanf("%99s", str);

    int length = strlen(str);
    printf("La longitud de la cadena es: %d\n", length);

    return 0;
}
