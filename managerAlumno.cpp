#include <iostream>
#include "alumno.h"
#include "managerAlumno.h"
#include "utils.h"
using namespace std;

AlumnoManager::AlumnoManager()
   : _repoAlumno(){

}

Alumno AlumnoManager::crearAlumno(){
   int id = _repoAlumno.getNuevoLegajo();
   string legajo;

   cout << "Legajo: #" << legajo << endl;
   cout << "Ingrese nombre: ";
   nombre = cargarNombre();
   cout

   return Alumno(legajo, nombre, 1); /// objeto anonimo
}

void AlumnoManager::guardarAlumno(){
   Alumno reg = crearAlumno();
   if(_repoAlumno.guardar(reg)){
      cout << "Se guardo exitosamente" << endl;
   }
   else{
      cout << "No se pudo guardar" << endl;
   }
}

void AlumnoManager::listarAlumno(){
   int cantidad = _repoAlumno.getCantidadRegistros();

   for(int i=0; i<cantidad; i++){
      Alumno a = _repoAlumno.leer(i);
      cout << "-----------------------"<<endl;
      cout << "Legajo #" << a.getLegajo() << endl;
      cout << "Nombre " << a.getNombre()  << endl;
      cout << "Apellido " << a.getApellido()  << endl;
      cout << "Fecha de nacimiento: " <<
            t.getFechaCreacion().getDia()
            << "/" << t.getFechaCreacion().getMes()
            << "/" << t.getFechaCreacion().getAnio() << endl;
   }
}
