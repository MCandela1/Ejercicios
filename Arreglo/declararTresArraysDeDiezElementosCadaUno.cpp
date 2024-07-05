#include <cstdio>

int main(){

   const int tamanio=10;
   int array1[tamanio];
   int array2[tamanio];
   int suma[tamanio];

   //SE INGRESA LOS VALORES DEL PRIMER ARRAY
   printf("Igrese los valores para el primer array\n");

       for(int i=0; i<tamanio; ++i){
          printf("Ingrese el valor %d: ",i+1);
           scanf("%d",&array1[i]);
        }

   printf("\nIngrese los valores del segundo array\n");

       for(int i=0; i<tamanio;++i){
          printf("Ingrese el valor %d: ",i+1);
          scanf("%d",&array2[i]);
       }



       for(int i=0; i<tamanio; ++i){

        suma[i]=array1[i] + array2[i];
       }

   printf("\nLa suma de los elementos de la misma oposicion es\n");

        for(int i=0; i<tamanio;++i){
            printf("La suma[%d] = %d\n",i,suma[i]);
        }
return 0;
}
