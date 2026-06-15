#include <iostream>
#include "alumno.h"
#include "managerAlumno.h"

using namespace std;

AlumnoManager::AlumnoManager()
   : _alumnoArchivo(){

}

Alumno AlumnoManager::crearAlumno(){
   int legajo = _alumnoArchivo.getNuevoLegajo();
   string nombre, apellido, email, direccion, telefono;
   int dni, dia, mes, anio;

   cout << "Legajo: #" << legajo << endl;
   cout << "Ingrese nombre: ";
   cin.ignore();                 /// limpia el \n que pueda haber quedado
   getline(cin, nombre);         /// lee toda la línea (con espacios)
   cout << "Ingrese apellido: ";
   cin.ignore();
   getline(cin, apellido);
   cout << "Ingrese DNI: ";
   cin.ignore();
   cin>> dni;
   cout << "Ingrese email: ";
   cin.ignore();
   getline(cin, email);
   cout << "Ingrese telefono: ";
   cin.ignore();
   getline(cin, telefono);
   cout << "Ingrese direccion: ";
   cin.ignore();
   getline(cin, direccion);
   cout << "Ingrese dia de nacimiento: ";
   cin >> dia;
   cin.ignore();
   cout << "Ingrese mes de nacimiento: ";
   cin >> mes;
   cin.ignore();
   cout << "Ingrese anio de nacimiento: ";
   cin >> anio;
   cin.ignore();

   Fecha fechaNacimiento(dia, mes, anio);

   return Alumno(legajo, dni, nombre, apellido, email, telefono, direccion, fechaNacimiento);
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
