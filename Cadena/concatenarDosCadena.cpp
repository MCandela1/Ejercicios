#include <cstdio>
#include <cstring>

int main() {
    const int MAX_LENGTH = 100;
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Introduce la primera cadena de caracteres: ");
    scanf("%99s", str1);
    printf("Introduce la segunda cadena de caracteres: ");
    scanf("%99s", str2);

    strcat(str1, str2);
    printf("La concatenación de las cadenas es: %s\n", str1);

    return 0;
}
