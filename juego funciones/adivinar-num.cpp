#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void jugarAdivinaElNumero() {
    int numeroSecreto, intento, maxIntentos = 5;

    srand(time(NULL));
    numeroSecreto = rand() % 100 + 1;

    printf("Adivina el n�mero entre 1 y 100. Tienes %d intentos.\n", maxIntentos);

    for (int i = 0; i < maxIntentos; i++) {
        printf("Intento %d: ", i + 1);
        scanf("%d", &intento);

        if (intento == numeroSecreto) {
            printf("�Felicidades! Has adivinado el n�mero.\n");
            return;
        } else if (intento < numeroSecreto) {
            printf("El n�mero es mayor.\n");
        } else {
            printf("El n�mero es menor.\n");
        }
    }

    printf("Lo siento, no has adivinado el n�mero. Era %d.\n", numeroSecreto);
}

int main() {
    jugarAdivinaElNumero();
    return 0;
}
