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
