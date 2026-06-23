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
          cout << "Apellido: " << a.getApellido() << endl;
          cout << "DNI: " << a.getDni() << endl;
          cout << "Email: " << a.getEmail() << endl;
          cout << "Telefono: " << a.getTelefono() << endl;
          cout << "Direccion: " << a.getDireccion() << endl;
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

      int dni, dia, mes, anio;
      string nombre, apellido, email, telefono, direccion;

      cout << "Nuevo DNI (" << reg.getDni() << "): ";
      cin >> dni;

      cout << "Nuevo nombre (" << reg.getNombre() << "): ";
      cin.ignore();
      getline(cin, nombre);

      cout << "Nuevo apellido (" << reg.getApellido() << "): ";
      cin.ignore();
      getline(cin, apellido);

      cout << "Nuevo email (" << reg.getEmail() << "): ";
      cin >> email;

      cout << "Nuevo telefono (" << reg.getTelefono() << "): ";
      cin >> telefono;

      cout << "Nueva direccion (" << reg.getDireccion() << "): ";
      cin.ignore();
      getline(cin, direccion);

      cout << "Nueva fecha de nacimiento ("
                << reg.getFechaNacimiento().getDia() << "/"
                << reg.getFechaNacimiento().getMes() << "/"
                << reg.getFechaNacimiento().getAnio() << "): " << endl;
      cout << "Dia: ";
      cin >> dia;
      cout << "Mes: ";
      cin >> mes;
      cout << "Anio: ";
      cin >> anio;

      Fecha nuevaFecha(dia,mes,anio);

      reg.setDni(dni);
      reg.setNombre(nombre);
      reg.setApellido(apellido);
      reg.setEmail(email);
      reg.setTelefono(telefono);
      reg.setDireccion(direccion);
      reg.setFechaNacimiento(nuevaFecha);

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

void AlumnoManager::buscarAlumnoPorLegajo() {
  int legajo;
  cout << "Ingrese legajo a buscar: ";
  cin >> legajo;
  // cin.ignore();

  int cantidad = _alumnoArchivo.getCantidadRegistros();

  for (int i = 0; i < cantidad; i++) {
      Alumno a = _alumnoArchivo.leer(i);

      if (!a.getEliminado()) {
          if (a.getLegajo() == legajo) {
              cout << "-----------------------" << endl;
              cout << "Legajo: #" << a.getLegajo() << endl;
              cout << "Nombre: " << a.getNombre() << " " << a.getApellido() << endl;
              cout << "DNI: " << a.getDni() << endl;
              cout << "Email: " << a.getEmail() << endl;
              cout << "Telefono: " << a.getTelefono() << endl;
              cout << "Direccion: " << a.getDireccion() << endl;
              cout << "Fecha de nacimiento: "
                   << a.getFechaNacimiento().getDia() << "/"
                   << a.getFechaNacimiento().getMes() << "/"
                   << a.getFechaNacimiento().getAnio() << endl;
              return;
          }
      }
  }

  cout << "No se encontro un alumno con ese legajo." << endl;
}

void AlumnoManager::buscarAlumnoPorApellido() {
    string apellido;
    cout << "Ingrese apellido a buscar: ";
    cin.ignore();
    getline(cin, apellido);

    int cantidad = _alumnoArchivo.getCantidadRegistros();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Alumno a = _alumnoArchivo.leer(i);

        if (!a.getEliminado()) {
            if (a.getApellido() == apellido) {
                cout << "-----------------------" << endl;
                cout << "Legajo: #" << a.getLegajo() << endl;
                cout << "Nombre: " << a.getNombre() << " " << a.getApellido() << endl;
                cout << "DNI: " << a.getDni() << endl;
                cout << "Email: " << a.getEmail() << endl;
                cout << "Telefono: " << a.getTelefono() << endl;
                cout << "Direccion: " << a.getDireccion() << endl;
                cout << "Fecha de nacimiento: "
                    << a.getFechaNacimiento().getDia() << "/"
                    << a.getFechaNacimiento().getMes() << "/"
                    << a.getFechaNacimiento().getAnio() << endl;
                encontrado = true;
            }
        }
    }

    if (encontrado == false) {
        cout << "No se encontro un alumno con ese apellido." << endl;
    }
}

