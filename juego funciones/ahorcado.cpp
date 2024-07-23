#include <stdio.h>
#include <stdbool.h>

const int MAX_LONGITUD = 100;

void mostrarPalabra(const char* palabra, const bool* letrasAdivinadas, int longitud) {
    for (int i = 0; i < longitud; i++) {
        if (letrasAdivinadas[i]) {
            printf("%c ", palabra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

bool adivinarLetra(const char* palabra, char letra, bool* letrasAdivinadas, int longitud) {
    bool encontrada = false;
    for (int i = 0; i < longitud; i++) {
        if (palabra[i] == letra) {
            letrasAdivinadas[i] = true;
            encontrada = true;
        }
    }
    return encontrada;
}

int main() {
    char palabra[MAX_LONGITUD] = "PROGRAMACION";
    bool letrasAdivinadas[MAX_LONGITUD] = { false };
    char letra;
    int intentosRestantes = 7;
    int longitudPalabra = 0;

    while (palabra[longitudPalabra] != '\0') {
        longitudPalabra++;
    }

    printf("Bienvenido al juego del ahorcado!\n");

    while (intentosRestantes > 0) {
        mostrarPalabra(palabra, letrasAdivinadas, longitudPalabra);
        printf("Introduce una letra: ");
        scanf(" %c", &letra);

        if (adivinarLetra(palabra, letra, letrasAdivinadas, longitudPalabra)) {
            printf("Correcto!\n");
        } else {
            intentosRestantes--;
            printf("Incorrecto! Te quedan %d intentos.\n", intentosRestantes);
        }

        bool palabraCompletada = true;
        for (int i = 0; i < longitudPalabra; i++) {
            if (!letrasAdivinadas[i]) {
                palabraCompletada = false;
                break;
            }
        }

        if (palabraCompletada) {
            printf("¡Felicidades, has adivinado la palabra!\n");
            break;
        }
    }

    if (intentosRestantes == 0) {
        printf("Has perdido. La palabra era: %s\n", palabra);
    }

    return 0;
}
