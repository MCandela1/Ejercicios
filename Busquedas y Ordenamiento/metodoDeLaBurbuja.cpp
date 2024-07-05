#include <iostream>

using namespace std;

void burbuja(int numero[],int largoArray){
  for (int i=0;i<largoArray;i++){
    for(int j=0;j<largoArray -1;j++){
        if(numero[j]>numero[j+i]){
            int desplazamientio=numero[j];
            numero[j]=numero[j+1];
            numero[j+1]=desplazamientio;
        }
    }
  }

}

int main (){
  int numero[]={10,16,55,22,4,81,12,33,1};
  int largoArray=sizeof(numero)/sizeof(*numero);
  cout<<"\nEl array desordenado de ve asi: ";
  for(int i=0; i<largoArray;i++){
    cout<<numero[i]<<" ";
  }

  burbuja(numero, largoArray);
  cout<<"\nEl array ordenado se muestra de la siguiente manera: ";
  for(int i=0; i<largoArray;i++){
    cout<<numero[i]<<" ";
  }
return 0;
}
