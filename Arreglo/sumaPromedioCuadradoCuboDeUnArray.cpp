#include <cstdio>

using namespace std;

int main (){
 const int elemento=10;
 int array[elemento];

 printf("Ingrese %d numeros \n",elemento);
 int suma=0;

 for(int i=0;i<elemento;i++){
    printf("Numero %d: ",i+1);
    scanf("%d",&array[i]);
    suma += array[i];
 }

  double promedio=static_cast<double>(suma)/elemento;

  printf("La suma es: %d\n",suma);
  printf("El promedio es: %.2f\n",promedio);
  printf("El cuadrado de cada elemeto es de: \n");
  for(int i=0; i<elemento; i++){
    printf("%d^2= %d\n",array[i], array[i] * array[i]);
  }
  printf("El cubo de cada elemento es:\n");
  for(int i=0; i<elemento; i++){
    printf("%d^3 = %d\n",array[i], array[i]*array[i]*array[i]);
  }
 return 0;
}
