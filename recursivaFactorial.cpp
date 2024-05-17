#include <iostream>
#include <stdlib.h>
using namespace std;

int factorial (int n){
  if(n==0) return 1;
  else return n*factorial(n-1);
}

int main(){
  int n;
  printf("Ingrese un valor: ");
  scanf("%d",&n);

  printf("El facrotial del numero %d es %d",n,factorial(n));

}

