//Crea un programa que gestione una lista de contactos. Cada contacto debe tener un nombre, un número de teléfono y un correo electrónico.

//Requisitos:
//Crear: Añadir un nuevo contacto a la lista.
//Leer: Mostrar todos los contactos.
//Actualizar: Modificar un contacto existente.
//Eliminar: Eliminar un contacto de la lista.
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct Contacto{
   char nombre[50];
   char telefono[20];
   char correo[50];
};

void crearContacto(vector<Contacto>& agenda){
   Contacto nuevoContacto;

   printf("Ingrese el nombre del contacto");
   scanf("%[^\n]", nuevoContacto.nombre);

   printf ("Ingrese el numero de telefono del contacto: ");
   scanf("%[^\n]", nuevoContacto.telefono);

   printf("Ingrese el correo electronico del contacto");
   scanf("%[^\n]", nuevoContacto.correo);

   agenda.push_back(nuevoContacto);
   printf("Contacto agregado correctamente.\n");
}

void mostrarContacto(const vector<Contacto>& agenda){
    printf("\nLista de contactos:\n");
    for(int i=0; i< agenda.size();i++){
        printf("Nombre: %s\n", agenda[i].nombre);
        printf("Telefono: %s\n",agenda[i].telefono);
        printf("Correo: %s\n ",agenda[i].correo);
        printf("\n");
    }
}

void actualizarContacto(vector<Contacto>& agenda, const char* nombreBuscado) {
    bool encontrado = false;
    for (int i = 0; i < agenda.size(); ++i) {
        if (strcmp(agenda[i].nombre, nombreBuscado) == 0) {

            printf("Ingrese el nuevo nombre del contacto: ");
            scanf(" %[^\n]", agenda[i].nombre);

            printf("Ingrese el nuevo número de teléfono del contacto: ");
            scanf(" %[^\n]", agenda[i].telefono);

            printf("Ingrese el nuevo correo electrónico del contacto: ");
            scanf(" %[^\n]", agenda[i].correo);

            printf("Contacto actualizado correctamente.\n");
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("No se encontró ningún contacto con el nombre %s.\n", nombreBuscado);
    }
}

void eliminarContacto(vector<Contacto>& agenda, const char* nombreBuscado) {
    bool encontrado = false;
    for (int i = 0; i < agenda.size(); ++i) {
        if (strcmp(agenda[i].nombre, nombreBuscado) == 0) {
            for (int j = i; j < agenda.size() - 1; ++j) {
                agenda[j] = agenda[j + 1];
            }
            agenda.pop_back();
            printf("Contacto eliminado correctamente.\n");
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("No se encontró ningún contacto con el nombre %s.\n", nombreBuscado);
    }
}

int main (){
   vector<Contacto> agenda;
   int opcion;
   char nombreBuscado[50];

   do{
    printf("\nMenu\n");
    printf("1. Crearnuevo contacto\n");
    printf("2. Mostrar todos los contactos\n");
    printf("3. Actualizar contacto\n");
    printf("4. Eliminar contacto\n");
    printf("5. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    switch (opcion){
           case 1:
                crearContacto(agenda);
                break;
           case 2:
                mostrarContacto(agenda);
                break;
           case 3:
                printf("Ingrese el nombre del contacto que desea actualizar:  ");
                scanf(" %[^\n]",nombreBuscado);
                actualizarContacto(agenda, nombreBuscado);
                break;
           case 4:
                printf("Ingrese el nombre del contacto a borrar: ");
                scanf(" %[^\n]", nombreBuscado);
                eliminarContacto(agenda, nombreBuscado);
                break;
           case 5:
                printf("salir del programa.\n");
                break;
           default:
                 printf("Opcion incorrecta.");
                 break;
    }
   }while(opcion != 5);
return 0;
}








