#include <cstdio>

using namespace std;

int main(){
  const int numero=10;
  int array[numero];

  printf("Ingrese los 10 elementos(valores)\n");
  int suma=0;

  for(int i=0; i<numero;i++){
      printf("Elemento numero %d: ",i+1);
      scanf("%d",&array[i]);
      suma +=array[i];
  }
  double promedio=static_cast<double>(suma)/numero; //-->static_cast es un operador de conversión en C++ que se utiliza para realizar conversiones de tipos de datos de forma segura en tiempo de compilación.
                                                  // Se utiliza para convertir un tipo de datos en otro compatible, pero no necesariamente relacionado, siempre que
                                                  //la conversión sea segura y no implique pérdida de información.
  printf("\nCantidad de elemento ingresado: %d\n",numero);
  printf("\nLa suma total de los 10 elemento ingresado: %d\n",suma);
  printf("\nEl promedio es de: %.2f\n",promedio);

  return 0;
}
