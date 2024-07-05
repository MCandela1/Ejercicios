#include <iostream>

using namespace std;

int mian (){

 int numeros[3];
 int completo[3]={11,3,7};



 for( int i=0; i<=2; ++i){

    printf("\n %d", completo[i]);
 }

  for (int a=0;a<3;++a){

    printf("Ingrese numero del array lugar %d: ", a);
    scanf("%d",&numeros[a]);

  }

  printf("Resultado de lo que completaste: \n");
  for (int b=0; b<3; ++b){
    printf("%d",numeros[b]);
  }
return 0;
}
