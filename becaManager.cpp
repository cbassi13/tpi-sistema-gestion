#include <iostream>
#include "beca.h"
#include "becaManager.h"

using namespace std;

BecaManager::BecaManager()
: _becaArchivo() {
}

Beca BecaManager::crearBeca() {
    int idBeca = _becaArchivo.getNuevoId();
    int legajo, idCarrera;
    string tipo;
    float porcentaje;
    int dia, mes, anio;

    cout << "ID de beca: #" << idBeca << endl;

    cout << "Ingrese legajo: ";
    cin >> legajo;

    cout << "Ingrese el ID de la Carrera";
    cin >> idCarrera;

    cout << "Ingrese tipo: ";
    cin >> tipo;

    cout << "Ingrese porcentaje de la beca: ";
    cin >> porcentaje;

    cout << "Ingrese fecha de asginacion";
    cout << "Ingrese dia: ";
    cin >> dia;

    cout << "Ingrese mes: ";
    cin >> mes;

    cout << "Ingrese anio: ";
    cin >> anio;

    Fecha fechaAsignacion(dia, mes, anio);

    return Beca(idBeca, legajo, idCarrera, tipo, porcentaje, fechaAsignacion);
}

void BecaManager::guardarBeca() {
    Beca beca = crearBeca();
    if(_becaArchivo.guardar(beca)) {
        cout << "Se guardo exitosamente" << endl;
    } else {
        cout << "No se pudo guardar" << endl;
    }
}

void BecaManager::listarBecas() {
    int cantidad = _becaArchivo.getCantidadRegistros();
    for(int i = 0; i < cantidad; i++) {
        Beca beca = _becaArchivo.leer(i);
        cout << "-----------------------" << endl;
        cout << "ID Beca: #" << beca.getIdBeca() << endl;
        cout << "Legajo: " << beca.getLegajo() << endl;
        cout << "Tipo: " <<beca.getTipo() << endl;
        cout << "ID de la carrera: " <<beca.getIdCarrera() << endl;

        cout << endl;
    }
}
