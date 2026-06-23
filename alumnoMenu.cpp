#include <iostream>
#include "alumnoMenu.h"
#include <cstdio>

using namespace std;

AlumnoMenu::AlumnoMenu(){
}

void AlumnoMenu::mostrarOpciones(){
   cout << "---------------------"<<endl;
   cout << "1. Guardar Alumno" << endl;
   cout << "2. Modificar Alumno" << endl;
   cout << "3. Baja Alumno" << endl;
   cout << "4. Listar Alumnos" << endl;
   cout << "5. Buscar Alumno por Legajo" << endl;
   cout << "6. Buscar Alumno por Apellido" << endl;
   cout << "7. Listar Alumnos Deudores" << endl;
   cout << "0. Salir" << endl;
   cout << "---------------------"<<endl;
}

void AlumnoMenu::ejecutarOpcion(int opcion){
   switch(opcion){
   case 1:
      _alumnoManager.guardarAlumno();
      break;
   case 2:
      _alumnoManager.modificarAlumno();
      break;
   case 3:
      _alumnoManager.bajaAlumno();
      break;
   case 4:
      _alumnoManager.listarAlumnos();
      break;
   case 5:
      _alumnoManager.buscarAlumnoPorLegajo();
      break;
   case 6:
      _alumnoManager.buscarAlumnoPorApellido();
      break;
   case 7:
      _alumnoManager.listarAlumnosDeudores();
      break;
   case 0:
      cout << "Saliendo del menu!"<<endl;
      break;
   default:
      cout << "Opcion incorrecta" << endl;
   }
}
