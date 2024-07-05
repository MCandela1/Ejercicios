#include  <cstdio>
using namespace std;
int main(){
  const int elemento =10;
  int array1[elemento];
  int array2[elemento];

  printf("Ingresar los elementos (valores) para el primer array:\n ");
  int suma1=0;

  for(int i=0; i<elemento;i++){
    printf("Valor del elemento %d es: ",i+1);
    scanf("%d",&array1[i]);
    suma1 +=array1[i];
  }

  printf("Ingresar los elementos (valores) para el segundo array \n");
  int suma2=0;

  for(int i=0; i<elemento;i++){
     printf("Valor del elemento %d es: ",i+1);
    scanf("%d",&array2[i]);
    suma2 +=array2[i];
  }

  int sumaTotal=suma1+suma2;

  printf("\n La suma del primer array es: %d\n",suma1);
  printf("\n La suma del segundo array es: %d\n",suma2);
  printf("\n La suma del ambos arrays es de: %d\n",sumaTotal);
}
