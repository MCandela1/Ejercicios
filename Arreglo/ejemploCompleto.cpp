#include <iostream>
#include <vector>

using namespace std;

int main (){

  vector <int> num;

  num.push_back (1);
  num.push_back (2);
  num.push_back (3);

  cout   <<"Los numeros del vector son: ";

  for( int value : num){
    cout << value <<" ";

  }
  cout<<endl;

  num.pop_back();

  cout<<"Elementos despues del pop_back(: ";

  for(int value : num ){

    cout<< value << " ";
  }
  cout<<endl;

  cout << "Tamanio: "<<num.size()<<endl;
  cout <<" Esta vacio? "<<(num.empty () ? "Si" : "No")<<endl;

  return 0;
}
