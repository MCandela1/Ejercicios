//Crea un programa que gestione una lista de estudiantes.
// Cada estudiante debe tener un ID, un nombre y una calificación.

//Requisitos:
//Crear: Añadir un nuevo estudiante a la lista.
//Leer: Mostrar todos los estudiantes.
//Actualizar: Modificar un estudiante existente.
//Eliminar: Eliminar un estudiante de la lista.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Producto {
    int codigo;
    string nombre;
    int cantidad;
    double precio;
};

void agregarProducto(vector<Producto>& inventario) {
    Producto nuevoProducto;
    cout << "Ingrese el código del producto: ";
    cin >> nuevoProducto.codigo;
    cout << "Ingrese el nombre del producto: ";
    cin >> nuevoProducto.nombre;
    cout << "Ingrese la cantidad del producto: ";
    cin >> nuevoProducto.cantidad;
    cout << "Ingrese el precio del producto: ";
    cin >> nuevoProducto.precio;
    inventario.push_back(nuevoProducto);
    cout << "Producto agregado exitosamente.\n";
}

void mostrarProductos(const vector<Producto>& inventario) {
    if (inventario.empty()) {
        cout << "No hay productos para mostrar.\n";
        return;
    }
    for (size_t i = 0; i < inventario.size(); ++i) {
        cout << "Producto " << i + 1 << ":\n";
        cout << "Código: " << inventario[i].codigo << "\n";
        cout << "Nombre: " << inventario[i].nombre << "\n";
        cout << "Cantidad: " << inventario[i].cantidad << "\n";
        cout << "Precio: $" << inventario[i].precio << "\n";
    }
}

void actualizarProducto(vector<Producto>& inventario) {
    int codigo;
    cout << "Ingrese el código del producto que desea actualizar: ";
    cin >> codigo;

    for (size_t i = 0; i < inventario.size(); ++i) {
        if (inventario[i].codigo == codigo) {
            cout << "Ingrese el nuevo nombre del producto: ";
            cin >> inventario[i].nombre;
            cout << "Ingrese la nueva cantidad del producto: ";
            cin >> inventario[i].cantidad;
            cout << "Ingrese el nuevo precio del producto: ";
            cin >> inventario[i].precio;
            cout << "Producto actualizado exitosamente.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

void eliminarProducto(vector<Producto>& inventario) {
    int codigo;
    cout << "Ingrese el código del producto que desea eliminar: ";
    cin >> codigo;

    for (size_t i = 0; i < inventario.size(); ++i) {
        if (inventario[i].codigo == codigo) {
            inventario.erase(inventario.begin() + i);
            cout << "Producto eliminado exitosamente.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

int main() {
    vector<Producto> inventario;
    int opcion;
    do {
        cout << "\n1. Agregar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Actualizar producto\n";
        cout << "4. Eliminar producto\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                agregarProducto(inventario);
                break;
            case 2:
                mostrarProductos(inventario);
                break;
            case 3:
                actualizarProducto(inventario);
                break;
            case 4:
                eliminarProducto(inventario);
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 5);

    return 0;
}
