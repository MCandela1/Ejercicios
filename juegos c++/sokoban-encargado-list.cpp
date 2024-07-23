#include <stdio.h>

const int tamanio=4;

struct Nodo{
int valor;
Nodo* arriba;
Nodo* abajo;
Nodo* izquierda;
Nodo* derecha;
};

Nodo tablero[tamanio][tamanio];
int indiceAlternante =0;
void iniciaizarTablero(){
for(int i=0;i<tamanio;i++){
  for(int j=0;j<tamanio;j++){
    tablero[i][j].valor = 0;
            if (i > 0) {
                tablero[i][j].arriba = &tablero[i - 1][j];
            } else {
                tablero[i][j].arriba = NULL;
            }
            if (i < tamanio - 1) {
                tablero[i][j].abajo = &tablero[i + 1][j];
            } else {
                tablero[i][j].abajo = NULL;
            }
            if (j > 0) {
                tablero[i][j].izquierda = &tablero[i][j - 1];
            } else {
                tablero[i][j].izquierda = NULL;
            }
            if (j < tamanio - 1){
                tablero[i][j].derecha = &tablero[i][j + 1];
            } else {
                tablero[i][j].derecha = NULL;
            }
        }
    }
}

void mostrarTablero(){
for(int i=0;i<tamanio;i++){
    for(int j=0;j<tamanio;j++){
        printf("%4d",tablero[i][j].valor);
    }
    printf("\n");
  }
}

int generarNumeroAleatorio() {
    int numeros[] = {2, 4};
    indiceAlternante = (indiceAlternante + 1) % 2;
}
void agregarNumeroAleatorio(){
int posicionesVacias[tamanio * tamanio][2];
int contador =0;
for(int i=0;i<tamanio;i++){
    for(int j=0;j<tamanio;j++){
        if(tablero[i][j].valor ==0){
            posicionesVacias[contador][0]=i;
            posicionesVacias[contador][1]=j;
            contador++;
        }
    }
  }
  if(contador>0){
    int indice=contador-1;
    int fila=posicionesVacias[indice][0];
    int columna=posicionesVacias[indice][1];
    tablero[fila][columna].valor=generarNumeroAleatorio();
   }
}

void moverIzquierda() {
    for (int i = 0; i < tamanio; ++i) {
        for (int j = 1; j < tamanio; ++j) {
            if (tablero[i][j].valor != 0) {
                int k = j;
                while (k > 0 && tablero[i][k - 1].valor == 0) {
                    tablero[i][k - 1].valor = tablero[i][k].valor;
                    tablero[i][k].valor = 0;
                    --k;
                }
                if (k > 0 && tablero[i][k - 1].valor == tablero[i][k].valor) {
                    tablero[i][k - 1].valor *= 2;
                    tablero[i][k].valor = 0;
                }
            }
        }
    }
}

void moverDerecha() {
    for (int i = 0; i < tamanio; ++i) {
        for (int j = tamanio - 2; j >= 0; --j) {
            if (tablero[i][j].valor != 0) {
                int k = j;
                while (k < tamanio - 1 && tablero[i][k + 1].valor == 0) {
                    tablero[i][k + 1].valor = tablero[i][k].valor;
                    tablero[i][k].valor = 0;
                    ++k;
                }
                if (k < tamanio - 1 && tablero[i][k + 1].valor == tablero[i][k].valor) {
                    tablero[i][k + 1].valor *= 2;
                    tablero[i][k].valor = 0;
                }
            }
        }
    }
}

void moverArriba() {
    for (int j = 0; j < tamanio; ++j) {
        for (int i = 1; i < tamanio; ++i) {
            if (tablero[i][j].valor != 0) {
                int k = i;
                while(k > 0 && tablero[k - 1][j].valor == 0) {
                    tablero[k - 1][j].valor = tablero[k][j].valor;
                    tablero[k][j].valor = 0;
                    --k;
                }
                if (k > 0 && tablero[k - 1][j].valor == tablero[k][j].valor) {
                    tablero[k - 1][j].valor *= 2;
                    tablero[k][j].valor = 0;
                }
            }
        }
    }
}

void moverAbajo() {
    for (int j = 0; j < tamanio; ++j) {
        for (int i = tamanio - 2; i >= 0; --i) {
            if (tablero[i][j].valor != 0) {
                int k = i;
                while (k < tamanio - 1 && tablero[k + 1][j].valor == 0) {
                    tablero[k + 1][j].valor = tablero[k][j].valor;
                    tablero[k][j].valor = 0;
                    ++k;
                }
                if (k < tamanio - 1 && tablero[k + 1][j].valor == tablero[k][j].valor) {
                    tablero[k + 1][j].valor *= 2;
                    tablero[k][j].valor = 0;
                }
            }
        }
    }
}

int main(){
iniciaizarTablero();
agregarNumeroAleatorio();
agregarNumeroAleatorio();

mostrarTablero();
char movimiento;
while(1){
    printf("Ingresar el movimiento(a: izqueirda/ d:derecha/ w:arriba/ s:abajo): ");
    scanf(" %c",&movimiento);
    switch(movimiento){
      case 'a': moverIzquierda();break;
      case 'd':moverDerecha();break;
      case 'w':moverArriba();break;
      case 's':moverAbajo();break;
      default: continue;
    }
    agregarNumeroAleatorio();
    mostrarTablero();
}
return 0;
}
