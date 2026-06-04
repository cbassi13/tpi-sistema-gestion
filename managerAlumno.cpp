#include <iostream>
#include "alumno.h"
#include "managerAlumno.h"
using namespace std;

AlumnoManager::AlumnoManager()
   : _alumnoArchivo(){

}

Alumno AlumnoManager::crearAlumno(){
   int legajo = _alumnoArchivo.getNuevoLegajo();
   string nombre;

   cout << "Legajo: #" << legajo << endl;
   cout << "Ingrese nombre: ";
   cin.ignore();                 // limpia el \n que pueda haber quedado
   getline(cin, nombre);         // lee toda la línea (con espacios)


   return Alumno(legajo, nombre, 1); /// objeto anonimo
}

void AlumnoManager::guardarAlumno(){
   Alumno reg = crearAlumno();
   if(_alumnoArchivo.guardar(reg)){
      cout << "Se guardo exitosamente" << endl;
   }
   else{
      cout << "No se pudo guardar" << endl;
   }
}

void AlumnoManager::listarAlumnos(){
   int cantidad = _alumnoArchivo.getCantidadRegistros();

   for(int i=0; i<cantidad; i++){
      Alumno a = _alumnoArchivo.leer(i);
      cout << "-----------------------"<<endl;
      cout << "Legajo #" << a.getLegajo() << endl;
      cout << "Nombre: " << a.getNombre() << endl;
      cout << "Fecha de nacimiento: "
           << a.getFechaNacimiento().getDia() << "/"
           << a.getFechaNacimiento().getMes() << "/"
           << a.getFechaNacimiento().getAnio() << endl;
   }
}
