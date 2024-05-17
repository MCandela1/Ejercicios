#include <iostream>
using namespace std;

int fibonacci(int n){
  if (n<=1)
    return n;
  return fibonacci(n-1)+(n-2);

}
int main(){

  int n=10;
  printf("%d El fibonacci del numero es: %d",n,fibonacci(n));
  return 0;

}

