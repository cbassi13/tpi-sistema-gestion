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

        if(!d.getEliminado()) {
          cout << "-----------------------"<<endl;
          cout << "Legajo #" << d.getLegajo() << endl;
          cout << "Nombre: " << d.getNombre() << endl;
          cout << "Apellido: " << d.getApellido() << endl;
          cout << "DNI: " << d.getDni() << endl;
          cout << "Email: " << d.getEmail() << endl;
          cout << "Telefono: " << d.getTelefono() << endl;
          cout << "Direccion: " << d.getDireccion() << endl;
          cout << "Fecha de nacimiento: "
               << d.getFechaNacimiento().getDia() << "/"
               << d.getFechaNacimiento().getMes() << "/"
               << d.getFechaNacimiento().getAnio() << endl;
      }
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

void DocenteManager::buscarDocentePorLegajo() {
    int legajo;
    cout << "Ingrese legajo a buscar: ";
    cin >> legajo;

    int cantidad = _docenteArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        Docente d = _docenteArchivo.leer(i);

        if (d.getEliminado() == false) {
            if (d.getLegajo() == legajo) {
                cout << "-----------------------" << endl;
                cout << "Legajo: #" << d.getLegajo() << endl;
                cout << "Nombre: " << d.getNombre() << " " << d.getApellido() << endl;
                cout << "DNI: " << d.getDni() << endl;
                cout << "Email: " << d.getEmail() << endl;
                cout << "Telefono: " << d.getTelefono() << endl;
                cout << "Direccion: " << d.getDireccion() << endl;
                cout << "Fecha de nacimiento: "
                    << d.getFechaNacimiento().getDia() << "/"
                    << d.getFechaNacimiento().getMes() << "/"
                    << d.getFechaNacimiento().getAnio() << endl;
                return;
            }
        }
    }

    cout << "No se encontro un docente con ese legajo." << endl;
}

