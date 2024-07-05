#include <cstdio>
#include <cstring>

using namespace std;
const int max_estudiantes=100;
const int max_nombres=50;

struct Estudiantes{
   int legajo;
   char nombre[max_nombres];
   char apellido[max_nombres];
   float notas[2];
};

Estudiantes estudiantes[max_estudiantes];
int contadorEstudiantes=0;
int proximoLegajo=1;

void copiarCadena(char destino[max_nombres], const char* origen){
   int i;
   for( i=0; i<max_nombres - 1 && origen[i] !='\0';i++){
       destino[i]=origen[i];
   }
   destino[i]='\0';
}

void agregarEstudiante(const char* nombre, const char* apellido, const float notas[2]) {
    if (contadorEstudiantes >= max_estudiantes) {
        printf("No se pueden agregar más estudiantes.\n");
        return;
    }

    estudiantes[contadorEstudiantes].legajo = proximoLegajo;
    copiarCadena(estudiantes[contadorEstudiantes].nombre, nombre);
    copiarCadena(estudiantes[contadorEstudiantes].apellido, apellido);
    estudiantes[contadorEstudiantes].notas[0] = notas[0];
    estudiantes[contadorEstudiantes].notas[1] = notas[1];
    contadorEstudiantes++;
    proximoLegajo++;
}

void mostrarEstudiantes(){
  if(contadorEstudiantes==0){
    printf("El estudiante no existe enla lista.\n");
  }else{
    printf("Lista de los estudiantes:\n");
    for(int i=0; i<contadorEstudiantes;i++){
        float promedio=(estudiantes[i].notas[0]+estudiantes[i].notas[1])/2;
        printf("Legajo: %d. Nombre: %s. Apellido: %s. Notas: %.2f, %.2f. Promedio final: %.2f. Estado del estudiante: ",estudiantes[i].legajo, estudiantes[i].nombre, estudiantes[i].apellido, estudiantes[i].notas[0], estudiantes[i].notas[1], promedio);

        if(promedio>=8){
            printf("Promovido\n");
        }else if(promedio>=6){
           printf("Aprobado\n");
        }else{
           printf("Desaprobado. El estudiante debe realizar el globalizador.\n");
        }
     }
   }
}

int buscarEstudianteLegajo(int legajo){
   for(int i=0; i<contadorEstudiantes;i++){
      if(estudiantes[i].legajo==legajo){
        return 1;
      }
   }
   return -1;
}
bool actualizarEstudiante(int legajo, const char* nuevoNombre, const char* nuevoApellido, const float nuevaNotas[2]){
   int indice= buscarEstudianteLegajo(legajo);
   if (indice != -1){
       copiarCadena(estudiantes[indice].nombre, nuevoNombre);
       copiarCadena(estudiantes[indice].apellido, nuevoApellido);
       estudiantes[indice].notas[0]=nuevaNotas[0];
       estudiantes[indice].notas[1]=nuevaNotas[1];
       return true;
   }
   return false;
}

bool eliminarEstudiante(int legajo){
  int indice=buscarEstudianteLegajo(legajo);
  if(indice != -1){
    for(int i=indice; i<contadorEstudiantes-1;i++){
        estudiantes[i]=estudiantes[i+1];
    }
    contadorEstudiantes--;
    return true;
  }
  return false;
}

int main (){
  int opcion;

  while(true){
    printf("1. Agregar estudiante.\n");
    printf("2.Mostrar estudiantes.\n");
    printf("3. Actualizar estudiante.\n");
    printf("4. Eliminar estudiante\n");
    printf("5. Salir.\n");
    printf("Eliga cualquiera de estas opciones.\n");
    scanf("%d", &opcion);

    switch(opcion){
  case 1:
    char nombre[max_nombres];
    char apellido[max_nombres];
    float notas[2];
    printf("Ingrese nombre del estudiante: ");
    scanf("%s",nombre);
    printf("Ingrese el apellido: ");
    scanf("%s",apellido);
    printf("Ingresar la nota del primer parcial: ");
    scanf("%d",&notas[0]);
    printf("Ingresar la nota del sgundo parcial: ");
    scanf("%d",&notas[1]);

    agregarEstudiante(nombre, apellido, notas);
    break;

  case 2:
    mostrarEstudiantes();
    break;

  case 3:{
    int legajo;
    char nuevoNombre[max_nombres];
    char nuevoApellido[max_nombres];
    float nuevaNotas[2];
    printf("Ingrese el legajo del estudiante a actualizar: ");
    scanf("%d", &legajo);
    printf("Ingrese el nuevo nombre del estudiante: ");
    scanf("%s", nuevoNombre);
    printf("Ingrese el nuevo apellido del estudiante: ");
    scanf("%s", nuevoApellido);
    printf("Ingrese la nueva nota del primer parcial: ");
    scanf("%f", &nuevaNotas[0]);
    printf("Ingrese la nueva nota del segundo parcial: ");
    scanf("%f", &nuevaNotas[1]);

    if(!actualizarEstudiante(legajo, nuevoNombre, nuevoApellido,nuevaNotas)){
        printf("El estudiante ingresado no fue encontrado.\n");
    }
    break;
    }
  case 4:{
    int legajo;
    printf("Ingresar el legajo para eliminar al estudiante: ");
    scanf("%d", &legajo);
    if(!eliminarEstudiante(legajo)){
        printf("Estudiante no encontrado.\n");
    }
    break;
  }
  case 5:
    return 0;
  default:
    printf("La opcion ingresada no es valida.\n");
}

}
return 0;
}


