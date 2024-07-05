#include <iostream>
using namespace std;
int main (){

   const int num=6;
   int numero[num];
   int mayor=0;
   int contador= 0;

   cout <<"Ingrse los valores del array:  "<<endl;


   while (contador < num && cin >> numero[contador] ){
     if (numero[contador]>mayor){
        mayor= numero[contador];
     }
   }
   cout<<"El numero mayor es:  "<< mayor<<endl;
return 0;
}
