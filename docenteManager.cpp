#include <iostream>
#include "docente.h"
#include "docenteManager.h"

using namespace std;

DocenteManager::DocenteManager()
    : _docenteArchivo() {

}
Docente DocenteManager::crearDocente() {
    int legajo = _docenteArchivo.getNuevoLegajo();
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

    return Docente(legajo, dni, nombre, apellido,
                   email, telefono, direccion,
                   fechaNacimiento);
}

void DocenteManager::guardarDocente() {
    Docente reg = crearDocente();

    if (_docenteArchivo.guardar(reg)) {
        cout << "Se guardo exitosamente" << endl;
    }
    else {
        cout << "No se pudo guardar" << endl;
    }
}

void DocenteManager::listarDocentes() {
    int cantidad = _docenteArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        Docente d = _docenteArchivo.leer(i);

        cout << "-----------------------" << endl;
        cout << "Legajo #" << d.getLegajo() << endl;
        cout << "Nombre: " << d.getNombre() << " "
             << d.getApellido() << endl;

        cout << "Fecha de nacimiento: "
             << d.getFechaNacimiento().getDia() << "/"
             << d.getFechaNacimiento().getMes() << "/"
             << d.getFechaNacimiento().getAnio() << endl;
    }
}
void DocenteManager::modificarDocente() {
      int legajo;
      cout << "Ingrese legajo del docente: ";
      cin >> legajo;

      int pos = _docenteArchivo.getPosByLegajo(legajo);

      if (pos == -1) {
          cout << "No existe un docente con ese legajo." << endl;
          return;
      }

      Docente reg = _docenteArchivo.leer(pos);

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

      if (_docenteArchivo.modificar(reg, pos)) {
          cout << "Docente modificado correctamente." << endl;
      } else {
          cout << "No se pudo modificar." << endl;
      }
  }

  void DocenteManager::bajaDocente() {
      int legajo;
      cout << "Ingrese legajo del docente: ";
      cin >> legajo;

      int pos = _docenteArchivo.getPosByLegajo(legajo);

      if (pos == -1) {
          cout << "No existe un docente con ese legajo." << endl;
          return;
      }

      Docente reg = _docenteArchivo.leer(pos);
      reg.setEliminado(true);

      if (_docenteArchivo.modificar(reg, pos)) {
          cout << "Docente dado de baja correctamente." << endl;
      } else {
          cout << "No se pudo realizar la baja." << endl;
      }
  }
