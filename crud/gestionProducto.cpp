//Crear: Añadir un nuevo producto a la lista (nombre, precio y cantidad).
//Leer: Mostrar todos los productos.
//Actualizar: Modificar los datos de un producto existente.
//Eliminar: Eliminar un producto de la lista.

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct Producto {
    char nombre[50];
    float precio;
    int cantidad;
};

void imprimirProductos(const vector<Producto>& productos) {
    for (int i = 0; i < productos.size(); ++i) {
        printf("Producto %d: Nombre = %s, Precio = %.2f, Cantidad = %d\n", i + 1, productos[i].nombre, productos[i].precio, productos[i].cantidad);
    }
}

void agregarProducto(vector<Producto>& productos) {
    Producto nuevoProducto;
    printf("Ingrese el nombre del producto: ");
    scanf("%s", nuevoProducto.nombre);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &nuevoProducto.precio);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &nuevoProducto.cantidad);
    productos.push_back(nuevoProducto);
}

void actualizarProducto(vector<Producto>& productos) {
    int indice;
    printf("Ingrese el índice del producto a actualizar (1 a %d): ", productos.size());
    scanf("%d", &indice);
    --indice;

    if (indice >= 0 && indice < productos.size()) {
        printf("Ingrese el nuevo nombre del producto: ");
        scanf("%s", productos[indice].nombre);
        printf("Ingrese el nuevo precio del producto: ");
        scanf("%f", &productos[indice].precio);
        printf("Ingrese la nueva cantidad del producto: ");
        scanf("%d", &productos[indice].cantidad);
    } else {
        printf("Índice fuera de rango.\n");
    }
}

void eliminarProducto(vector<Producto>& productos) {
    int indice;
    printf("Ingrese el índice del producto a eliminar (1 a %d): ", productos.size());
    scanf("%d", &indice);
    --indice;

    if (indice >= 0 && indice < productos.size()) {
        for (int i = indice; i < productos.size() - 1; ++i) {
            productos[i] = productos[i + 1];
        }
        productos.pop_back();
    } else {
        printf("Índice fuera de rango.\n");
    }
}

int main() {
    vector<Producto> productos;
    int opcion;

    do {
        printf("\nMenú de opciones:\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Actualizar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                agregarProducto(productos);
                break;
            case 2:
                imprimirProductos(productos);
                break;
            case 3:
                actualizarProducto(productos);
                break;
            case 4:
                eliminarProducto(productos);
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 5);

    return 0;
}
