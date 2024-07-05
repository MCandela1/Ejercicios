//Crear un vector: Solicita al usuario que ingrese el tama�o del vector y luego los elementos para llenarlo.

//Leer un vector: Imprime todos los elementos de un vector dado.

//Actualizar un vector: Permite al usuario modificar un elemento espec�fico del vector.

//Borrar elementos de un vector: Elimina un elemento en una posici�n dada por el usuario.

#include <cstdio>
#include <vector>

using namespace std;

void imprimirVector(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        printf("%d", vec[i]);
        if (i != vec.size() - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void eliminarElemento(vector<int>& vec, int indiceAEliminar) {
    if (indiceAEliminar < 0 || indiceAEliminar >= vec.size()) {
        printf("�ndice fuera de rango. No se puede eliminar.\n");
        return;
    }

    for (int i = indiceAEliminar; i < vec.size() - 1; ++i) {
        vec[i] = vec[i + 1];
    }
    vec.pop_back();
}

int main() {
    vector<int> numeros;
    int tamano;

    printf("Ingrese el tama�o del vector: ");
    scanf("%d", &tamano);

    printf("Ingrese %d n�meros para llenar el vector:\n", tamano);
    for (int i = 0; i < tamano; ++i) {
        int num;
        scanf("%d", &num);
        numeros.push_back(num);
    }

    printf("El vector ingresado es: ");
    imprimirVector(numeros);

    // Actualizar un vector: Modificar un elemento espec�fico
    int indiceActualizar, nuevoValor;
    printf("Ingrese el �ndice del elemento que desea actualizar (0 a %d): ", numeros.size() - 1);
    scanf("%d", &indiceActualizar);

    if (indiceActualizar >= 0 && indiceActualizar < numeros.size()) {
        printf("Ingrese el nuevo valor para este elemento: ");
        scanf("%d", &nuevoValor);
        numeros[indiceActualizar] = nuevoValor; // Actualizar el valor en el �ndice especificado
        printf("El vector actualizado es: ");
        imprimirVector(numeros);
    } else {
        printf("�ndice fuera de rango. No se puede actualizar.\n");
    }

    int indiceEliminar;
    printf("Ingrese el �ndice del elemento que desea eliminar (0 a %d): ", numeros.size() - 1);
    scanf("%d", &indiceEliminar);

    eliminarElemento(numeros, indiceEliminar);

    printf("El vector despu�s de eliminar el elemento es: ");
    imprimirVector(numeros);

    return 0;
}

