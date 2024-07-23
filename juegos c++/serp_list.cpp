#include <cstdio>

const int TAM = 10;
const int MAX_LONGITUD = 100;

struct Nodo {
    int x, y;
    int siguiente;
};

void inicializarTablero(char tablero[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tablero[i][j] = ' ';
        }
    }
}

void mostrarTablero(char tablero[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("|%c", tablero[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

void colocarComida(int &comidaX, int &comidaY, char tablero[TAM][TAM], int posX, int posY) {
    comidaX = posX;
    comidaY = posY;
    tablero[comidaX][comidaY] = 'X';
}

int moverSerpiente(char tablero[TAM][TAM], Nodo serpiente[MAX_LONGITUD], int &longitud, int &comidaX, int &comidaY, char &direccion) {
    int nuevaX = serpiente[0].x, nuevaY = serpiente[0].y;

    switch (direccion) {
        case 'w': nuevaX--; break;
        case 's': nuevaX++; break;
        case 'a': nuevaY--; break;
        case 'd': nuevaY++; break;
        default: return 0;
    }

   if (nuevaX < 0 || nuevaX >= TAM || nuevaY < 0 || nuevaY >= TAM) {
        return 1;
    }

    for (int i = 0; i < longitud; i++) {
        if (serpiente[i].x == nuevaX && serpiente[i].y == nuevaY) {
            return 1;
        }
    }

    if (nuevaX == comidaX && nuevaY == comidaY) {
        longitud++;
        colocarComida(comidaX, comidaY, tablero, (comidaX + 3) % TAM, (comidaY + 3) % TAM);
    }

    for (int i = longitud - 1; i > 0; i--) {
        serpiente[i] = serpiente[i - 1];
    }

    serpiente[0].x = nuevaX;
    serpiente[0].y = nuevaY;

    inicializarTablero(tablero);
    for (int i = 0; i < longitud; i++) {
        tablero[serpiente[i].x][serpiente[i].y] = 'O';
    }
    tablero[comidaX][comidaY] = 'X';

    return 0;
}

int main() {
    char tablero[TAM][TAM];
    Nodo serpiente[MAX_LONGITUD];
    int longitud = 1;
    int comidaX, comidaY;
    char direccion = 'd';
    int estadoJuego = 0;

    inicializarTablero(tablero);
    serpiente[0].x = TAM / 2;
    serpiente[0].y = TAM / 2;
    tablero[serpiente[0].x][serpiente[0].y] = 'O';
    colocarComida(comidaX, comidaY, tablero, 2, 2);

    while (estadoJuego == 0) {
        mostrarTablero(tablero);
        printf("Ingrese direccion (w/a/s/d): ");
        scanf(" %c", &direccion);

        estadoJuego = moverSerpiente(tablero, serpiente, longitud, comidaX, comidaY, direccion);
    }

    printf("Juego terminado! Puntuación: %d\n", longitud - 1);

    return 0;
}
