#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    const int MAX_LENGTH = 100;
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Introduce la primera cadena de caracteres: ");
    scanf("%99s", str1);
    printf("Introduce la segunda cadena de caracteres: ");
    scanf("%99s", str2);

    if (strcmp(str1, str2) == 0) {
        printf("Las cadenas son iguales.\n");
    } else {
        printf("Las cadenas son diferentes.\n");
    }

    return 0;
}
