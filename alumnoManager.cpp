#include <iostream>
#include "alumno.h"
#include "alumnoManager.h"

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

      if(!a.getEliminado()) {
          cout << "-----------------------"<<endl;
          cout << "Legajo #" << a.getLegajo() << endl;
          cout << "Nombre: " << a.getNombre() << endl;
          cout << "Fecha de nacimiento: "
               << a.getFechaNacimiento().getDia() << "/"
               << a.getFechaNacimiento().getMes() << "/"
               << a.getFechaNacimiento().getAnio() << endl;
      }
   }
}

  void AlumnoManager::modificarAlumno() {
      int legajo;
      cout << "Ingrese legajo del alumno: ";
      cin >> legajo;

      int pos = _alumnoArchivo.getPosByLegajo(legajo);

      if (pos == -1) {
          cout << "No existe un alumno con ese legajo." << endl;
          return;
      }

      Alumno reg = _alumnoArchivo.leer(pos);

      string nombre, apellido, email, telefono, direccion;

      cout << "Nuevo nombre (" << reg.getNombre() << "): ";
      cin.ignore();
      getline(cin, nombre);

      cout << "Nuevo apellido (" << reg.getApellido() << "): ";
      getline(cin, apellido);

      cout << "Nuevo email (" << reg.getEmail() << "): ";
      getline(cin, email);

      cout << "Nuevo telefono (" << reg.getTelefono() << "): ";
      getline(cin, telefono);

      cout << "Nueva direccion (" << reg.getDireccion() << "): ";
      getline(cin, direccion);

      reg.setNombre(nombre);
      reg.setApellido(apellido);
      reg.setEmail(email);
      reg.setTelefono(telefono);
      reg.setDireccion(direccion);

      if (_alumnoArchivo.modificar(reg, pos)) {
          cout << "Alumno modificado correctamente." << endl;
      } else {
          cout << "No se pudo modificar." << endl;
      }
  }
void AlumnoManager::bajaAlumno() {
      int legajo;
      cout << "Ingrese legajo del alumno: ";
      cin >> legajo;

      int pos = _alumnoArchivo.getPosByLegajo(legajo);

      if (pos == -1) {
          cout << "No existe un alumno con ese legajo." << endl;
          return;
      }

      Alumno reg = _alumnoArchivo.leer(pos);
      reg.setEliminado(true);

      if (_alumnoArchivo.modificar(reg, pos)) {
          cout << "Alumno dado de baja correctamente." << endl;
      } else {
          cout << "No se pudo realizar la baja." << endl;
      }
  }
