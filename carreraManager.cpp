#include <iostream>
#include "carrera.h"
#include "carreraManager.h"

using namespace std;

CarreraManager::CarreraManager()
    : _carreraArchivo() {

}

Carrera CarreraManager::crearCarrera() {
    int idCarrera = _carreraArchivo.getNuevoIdCarrera();
    string nombre;

    cout << "ID Carrera: #" << idCarrera << endl;

    cout << "Ingrese nombre de la carrera: ";
    cin.ignore();
    getline(cin, nombre);

    Carrera carrera;

    carrera.setIdCarrera(idCarrera);
    carrera.setNombre(nombre);

    return carrera;
}

void CarreraManager::guardarCarrera() {
    Carrera reg = crearCarrera();

    if (_carreraArchivo.guardar(reg)) {
        cout << "Se guardo exitosamente" << endl;
    }
    else {
        cout << "No se pudo guardar" << endl;
    }
}

void CarreraManager::listarCarreras() {
    int cantidad = _carreraArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {

        Carrera c = _carreraArchivo.leer(i);

        cout << "-----------------------" << endl;
        cout << "ID Carrera: " << c.getIdCarrera() << endl;
        cout << "Nombre: " << c.getNombre() << endl;
    }
}
