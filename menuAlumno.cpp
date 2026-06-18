#include <iostream>
#include "menuAlumno.h"
#include <cstdio>

using namespace std;

AlumnoMenu::AlumnoMenu(){
}

void AlumnoMenu::mostrarOpciones(){ /// << este no....
   cout << "---------------------"<<endl;
   cout << "1. Guardar Alumno" << endl;   cout << "2. Modificar Alumno" << endl;
   cout << "3. Baja Alumno" << endl;
   cout << "4. Listar Alumnos" << endl;   cout << "0. Salir" << endl;
   cout << "---------------------"<<endl;
}

void AlumnoMenu::ejecutarOpcion(int opcion){ /// particular
   switch(opcion){
   case 1:
      _managerAlumno.guardarAlumno();
      break;
   case 2:
      /// _managerAlumno.modificarAlumno();
      break;
   case 3:
      /// _managerAlumno.bajaAlumno();
      break;
   case 4:
      _managerAlumno.listarAlumnos();
      break;
   case 0:
      cout << "Saliendo del menu!"<<endl;
      break;
   default:
      cout << "Opcion incorrecta" << endl;
   }
}
