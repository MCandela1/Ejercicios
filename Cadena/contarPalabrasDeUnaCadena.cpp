#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char frase[1000];
    printf("Ingrese una frase: ");
    scanf(" %[^\n]", frase);
    int contadorPalabras = 0;

    bool enPalabra = false;

    for(int i=0; frase[i] != '\0';i++){
        if(frase[i] != ' '&& frase[i] !='\t'&& frase[i]!='\n'){
            if(!enPalabra){
                contadorPalabras++;
                enPalabra=true;
            }
        }else{
          enPalabra=false;
        }
    }

    printf("La frase tiene %d palabras.\n", contadorPalabras);

    return 0;
}
