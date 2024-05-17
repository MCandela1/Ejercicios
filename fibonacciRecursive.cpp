#include <iostream>
using namespace std;

int fibonacci(int n){
  if (n<=1)
    return n;
  return fibonacci(n-1)+(n-2);

}
int main(){
  int n;
  printf("Ingrese un numero: ");
  scanf("%d",&n);
  printf("%d El fibonacci del numero es: %d",n,fibonacci(n));
  return 0;

}
