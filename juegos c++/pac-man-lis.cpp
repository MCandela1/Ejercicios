#include <cstdio>

const int ancho=20;
const int alto=10;
const int num_ghost=4;

struct entidad{
int x;
int y;
char simbolo;
};

struct Juego{
entidad pacman;
entidad ghost[num_ghost];
char tablero[alto][ancho];
};

void iniciarJuego(Juego &juego){

for(int i=0;i<alto;i++){
    for(int j=0;j<ancho;j++){
        juego.tablero[i][j]=' ';
    }
  }
  for(int i=0;i<ancho;i++){
    juego.tablero[0][i]= '#';
    juego.tablero[alto-1][i]= '#';
  }
  for(int i=0; i<alto;i++){
    juego.tablero[i][0]='#';
    juego.tablero[i][ancho-1]= '#';
  }
  juego.pacman.x=ancho/2;
  juego.pacman.y=alto/2;
  juego.pacman.simbolo='P';

  for(int i=0;i<num_ghost;i++){
    juego.ghost[i].x=1+i*2;
    juego.ghost[i].y=1;
    juego.ghost[i].simbolo='G';
  }
}

void crearTablero(Juego &juego){
for(int i=1; i<alto-1;i++){
    for(int j=0;j<ancho-1;j++){
        juego.tablero[i][j]=' ';
    }
  }
juego.tablero[juego.pacman.y][juego.pacman.x] = juego.pacman.simbolo;

for(int i=0;i<num_ghost;i++){
juego.tablero[juego.ghost[i].y][juego.ghost[i].x] = juego.ghost[i].simbolo;
}
for(int i=0;i<alto;i++){
    for(int j=0;j<ancho;j++){
        printf("%c",juego.tablero[i][j]);
    }
    printf("\n");
  }
}

void actualizarJuego(Juego &juego, char entrada){
switch(entrada)
{
 case 'w': if (juego.tablero[juego.pacman.y - 1][juego.pacman.x] != '#') juego.pacman.y -= 1; break;
 case 's': if (juego.tablero[juego.pacman.y + 1][juego.pacman.x] != '#') juego.pacman.y += 1; break;
 case 'a': if (juego.tablero[juego.pacman.y][juego.pacman.x - 1] != '#') juego.pacman.x -= 1; break;
 case 'd': if (juego.tablero[juego.pacman.y][juego.pacman.x + 1] != '#') juego.pacman.x += 1; break;
}
for(int i=0;i<num_ghost;i++){
      if (juego.ghost[i].x < ancho- 2 && juego.tablero[juego.ghost[i].y][juego.ghost[i].x + 1] != '#') {
            juego.ghost[i].x += 1;
      }else if (juego.ghost[i].y < alto - 2 && juego.tablero[juego.ghost[i].y + 1][juego.ghost[i].x] != '#') {
            juego.ghost[i].y += 1;
      } else if (juego.ghost[i].x > 1 && juego.tablero[juego.ghost[i].y][juego.ghost[i].x - 1] != '#') {
            juego.ghost[i].x -= 1;
     } else if (juego.ghost[i].y > 1 && juego.tablero[juego.ghost[i].y - 1][juego.ghost[i].x] != '#') {
            juego.ghost[i].y -= 1;
    }
  }
}

int main(){
Juego juego;

iniciarJuego(juego);
while(true){
    crearTablero(juego);
    printf("Mover pacman (w/a/s/d): ");
    char entrada;
    scanf(" %c",&entrada);
    actualizarJuego(juego, entrada);
}
return 0;
}
