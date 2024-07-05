#include <iostream>

using namespace std;

void burbuja(char letras[], int largo){
  for(int i=0;i<largo-1;i++){
    if(letras[i]>letras[i+1]){
        char datoTemporal=letras[i];
        letras [i]=letras[i+1];
        letras[i+1]=datoTemporal;
    }
  }
}
int main (){
  char letras[]={'s','z','i','a','n','s'};
  int largoArray=sizeof(letras)/sizeof(*letras);
  cout<<"\nEl arrray desordenado se ve asi: ";
  for(int i=0;i<largoArray;i++){
    cout<<letras[i]<<" ";
  }
  burbuja(letras,largoArray);
   cout<<"\nEl arrray ordenado se ve asi: ";
  for(int i=0;i<largoArray;i++){
    cout<<letras[i]<<" ";
  }

return 0;
}
