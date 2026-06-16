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
   cin.ignore();
   getline(cin, nombre);

   cout << "Ingrese apellido: ";
   getline(cin, apellido);

   cout << "Ingrese DNI: ";
   cin >> dni;

   cout << "Ingrese email: ";
   cin.ignore();
   getline(cin, email);

   cout << "Ingrese telefono: ";
   getline(cin, telefono);

   cout << "Ingrese direccion: ";
   getline(cin, direccion);

   cout << "Ingrese dia de nacimiento: ";
   cin >> dia;

   cout << "Ingrese mes de nacimiento: ";
   cin >> mes;

   cout << "Ingrese anio de nacimiento: ";
   cin >> anio;

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
