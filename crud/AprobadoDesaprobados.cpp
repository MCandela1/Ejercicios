#include <stdio.h>
#include <cstring>

using namespace std;

struct Alumno{
 char nombre[50];
 char apellido[50];
 float ejer1;
 float ejer2;
 float ejer3;
 float ejer4;
 float nota_final;
 bool aprobado;
 };

 void agregarAlumno(Alumno* alumnos, int &cantidad_alumnos) {
    printf("Ingresar el nombre del alumno y apellido: ");
    scanf("%s %s", alumnos[cantidad_alumnos].nombre, alumnos[cantidad_alumnos].apellido);
    printf("Ingresar los puntos realizados del alumno (cada punto de los cuatro ejercicios vale 2.5):\n");
    printf("Ejercicio 1: "); scanf("%f", &alumnos[cantidad_alumnos].ejer1);
    printf("Ejercicio 2: "); scanf("%f", &alumnos[cantidad_alumnos].ejer2);
    printf("Ejercicio 3: "); scanf("%f", &alumnos[cantidad_alumnos].ejer3);
    printf("Ejercicio 4: "); scanf("%f", &alumnos[cantidad_alumnos].ejer4);

    alumnos[cantidad_alumnos].nota_final = (alumnos[cantidad_alumnos].ejer1 + alumnos[cantidad_alumnos].ejer2 + alumnos[cantidad_alumnos].ejer3 + alumnos[cantidad_alumnos].ejer4);
    alumnos[cantidad_alumnos].aprobado = alumnos[cantidad_alumnos].nota_final >= 6;
    cantidad_alumnos++;
}

void listarAlumnos(Alumno* alumnos, int cantidad_alumnos) {
    for (int i = 0; i < cantidad_alumnos; i++) {
        printf("Alumno: %s %s, nota final: %.2f, condicion: %s\n",
               alumnos[i].nombre, alumnos[i].apellido, alumnos[i].nota_final, (alumnos[i].aprobado ? "Aprobado" : "Desaprobado"));
    }
}
void actualizarAlumno(Alumno* alumnos, int cantidad_alumnos){
  char nombre[50], apellido[50];
  printf("Ingresar el nombre y apellido del alumno a actualizar: ");
  scanf("%s %s",nombre,apellido);

  for (int i=0; i<cantidad_alumnos;i++){
    bool nombre_igaul=true;
    for(int j=0;nombre[j] !='\0' || alumnos[i].nombre[j] !='\0';j++){
        if(nombre[j] != alumnos[i].nombre[j]){
            nombre_igaul=false;
            break;
        }
    }
    bool apellido_igaul=true;
    for(int j=0;apellido[j] !='\0' || alumnos[i].apellido[j] !='\0';j++){
        if(apellido[j] != alumnos[i].apellido[j]){
            apellido_igaul=false;
            break;
    }
  }
  if (nombre_igaul && apellido_igaul){
    printf("Ingrese los nuevos puntos realizados del alumno (cada punto de los cuatro ejercicios vale 2.5):\n");
    printf("Ejercicio 1: "); scanf("%f", &alumnos[i].ejer1);
    printf("Ejercicio 2: "); scanf("%f", &alumnos[i].ejer2);
    printf("Ejercicio 3: "); scanf("%f", &alumnos[i].ejer3);
    printf("Ejercicio 4: "); scanf("%f", &alumnos[i].ejer4);

    alumnos[i].nota_final = (alumnos[i].ejer1 + alumnos[i].ejer2 + alumnos[i].ejer3 + alumnos[i].ejer4);
    alumnos[i].aprobado = alumnos[i].nota_final >= 6;
    printf("Alumno actualizado exitosamente.\n");
    return;
  }
}
printf("Alumno no encontrado.\n");
}

void eliminarAlumno(Alumno* alumnos, int &cantidad_alumnos){
  char nombre[50], apellido[50];
  printf("Ingresar el nombre y apellido del alumno a eliminar: ");
  scanf("%s %s",nombre,apellido);

   for (int i = 0; i < cantidad_alumnos; i++) {
        bool nombre_igual = true;
        for (int j = 0; nombre[j] != '\0' || alumnos[i].nombre[j] != '\0'; j++) {
            if (nombre[j] != alumnos[i].nombre[j]) {
                nombre_igual = false;
                break;
            }
        }

        bool apellido_igual = true;
        for (int j = 0; apellido[j] != '\0' || alumnos[i].apellido[j] != '\0'; j++) {
            if (apellido[j] != alumnos[i].apellido[j]) {
                apellido_igual = false;
                break;
            }
        }

        if (nombre_igual && apellido_igual) {
            for (int j = i; j < cantidad_alumnos - 1; j++) {
                alumnos[j] = alumnos[j + 1];
            }
            cantidad_alumnos--;
            printf("Alumno eliminado exitosamente.\n");
            return;
        }
    }

    printf("Alumno no encontrado.\n");
}

int main (){
 int cantidad_alumnos=0;
 Alumno alumnos[100];

 int opcion;
 do{
     printf("\n--- Menu ---\n");
     printf("1. Agregar Alumno\n");
     printf("2. Mostrar Alumnos\n");
     printf("3. Actualizar Alumno\n");
     printf("4. Eliminar Alumno\n");
     printf("5. Salir\n");
     printf("Seleccione una opcion: ");
     scanf("%d", &opcion);

     switch(opcion){
   case 1:
    if(cantidad_alumnos<100){
        agregarAlumno(alumnos, cantidad_alumnos);
    }else{
       printf("No se puede ingresar mas alumnos.\n");
    }
    break;

   case 2:
    listarAlumnos(alumnos, cantidad_alumnos);
    break;

   case 3:
    actualizarAlumno(alumnos, cantidad_alumnos);
    break;

   case 4:
    eliminarAlumno(alumnos, cantidad_alumnos);
    break;

   case 5:
    printf("Saliendo del programa...\n");
    break;

   default:
    printf("La opcion ingresada eno es valida.\n");
    break;
   }
 }while(opcion !=5);
 return 0;
}
