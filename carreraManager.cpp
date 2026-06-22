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
    int idJefeCatedra;

    cout << "ID Carrera: #" << idCarrera << endl;

    cout << "Ingrese nombre de la carrera: ";
    cin.ignore();
    getline(cin, nombre);

    Carrera carrera;

    carrera.setIdCarrera(idCarrera);
    carrera.setNombre(nombre);

    cout << "Ingrese ID del jefe de catedra: ";
    cin >> idJefeCatedra;
    carrera.setIdJefeCatedra(idJefeCatedra);

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
        cout << "Jefe de catedra ID: " << c.getIdJefeCatedra() << endl;
    }
}


void CarreraManager::modificarCarrera(){

    int id;

    cout << "Ingrese ID de la carrera: ";
    cin >> id;

    int pos = _carreraArchivo.getPosByIdCarrera(id);

    if(pos == -1){
        cout << "No existe una carrera con ese ID." << endl;
        return;
    }

    Carrera reg = _carreraArchivo.leer(pos);

    string nombre;

    cout << "Nuevo nombre: ";
    cin.ignore();
    getline(cin, nombre);

    int nuevoIdJefeCatedra;
    cout << "(Consulte la lista de docentes para ver los IDs disponibles)" << endl;
    cout << "Nuevo ID jefe de catedra: ";
    cin >> nuevoIdJefeCatedra;

    reg.setNombre(nombre);
    reg.setIdJefeCatedra(nuevoIdJefeCatedra);

    if(_carreraArchivo.modificar(reg, pos)){
        cout << "Carrera modificada correctamente." << endl;
    }
    else{
        cout << "No se pudo modificar." << endl;
    }
}

void CarreraManager::bajaCarrera(){

    int id;

    cout << "Ingrese ID de la carrera: ";
    cin >> id;

    int pos = _carreraArchivo.getPosByIdCarrera(id);

    if(pos == -1){
        cout << "No existe una carrera con ese ID." << endl;
        return;
    }

    Carrera reg = _carreraArchivo.leer(pos);

    reg.setEliminado(true);

    if(_carreraArchivo.modificar(reg, pos)){
        cout << "Carrera dada de baja correctamente." << endl;
    }
    else{
        cout << "No se pudo realizar la baja." << endl;
    }
}
