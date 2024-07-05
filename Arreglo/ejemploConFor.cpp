#include <iostream>
#include <vector>

using namespace std;

int main (){

    vector <int> numeroDinamico={1,2,3,4,5};

    numeroDinamico.push_back (8);

    cout<<numeroDinamico[3]<<endl;

    size_t longitud = numeroDinamico.size();

    ///bucle formal
    for(int i=0; i< numeroDinamico.size(); i++){
        cout << numeroDinamico[i]<<" ";
        cout<<endl;
    }
    ///Basado en rango
    for(int value : numeroDinamico){
        cout <<value<<" ";

    }


return 0;
}
