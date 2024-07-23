#include <stdio.h>

const int MAX_INTENTOS = 6;
const int MAX_PALABRA = 100;
const int NUM_PALABRAS = 4;

char palabras[NUM_PALABRAS][MAX_PALABRA] = {
    "PROGRAMACION",
    "COMPUTADORA",
    "TECLADO",
    "MONITOR"
};

void copiarCadena(char* destino, const char* origen) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';
}

int longitudCadena(const char* cadena) {
    int longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}

void inicializarPalabraSecreta(char* palabraSecreta, const char* palabra) {
    int longitud = longitudCadena(palabra);
    for (int i = 0; i < longitud; i++) {
        palabraSecreta[i] = '_';
    }
    palabraSecreta[longitud] = '\0';
}

void mostrarEstado(const char* palabraSecreta, int intentosRestantes) {
    printf("Palabra: %s\n", palabraSecreta);
    printf("Intentos restantes: %d\n", intentosRestantes);
}

int adivinar(char letra, const char* palabra, char* palabraSecreta) {
    int longitud = longitudCadena(palabra);
    int acierto = 0;
    for (int i = 0; i < longitud; i++) {
        if (palabra[i] == letra) {
            palabraSecreta[i] = letra;
            acierto = 1;
        }
    }
    return acierto;
}

int haGanado(const char* palabraSecreta) {
    for (int i = 0; palabraSecreta[i] != '\0'; i++) {
        if (palabraSecreta[i] == '_') {
            return 0;
        }
    }
    return 1;
}

int main() {
    int indicePalabra = NUM_PALABRAS - 1;  // Simple alternativa para evitar aleatoriedad
    const char* palabra = palabras[indicePalabra];

    char palabraSecreta[MAX_PALABRA];
    inicializarPalabraSecreta(palabraSecreta, palabra);

    int intentosRestantes = MAX_INTENTOS;
    char letra;
    int acierto;

    while (intentosRestantes > 0 && !haGanado(palabraSecreta)) {
        mostrarEstado(palabraSecreta, intentosRestantes);
        printf("Ingrese una letra: ");
        scanf(" %c", &letra);
        acierto = adivinar(letra, palabra, palabraSecreta);
        if (!acierto) {
            intentosRestantes--;
        }
    }

    if (haGanado(palabraSecreta)) {
        printf("¡Felicidades! Has adivinado la palabra: %s\n", palabraSecreta);
    } else {
        printf("Lo siento, has perdido. La palabra era: %s\n", palabra);
    }

    return 0;
}
