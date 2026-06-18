#include <iostream>
#include "aula.h"
#include "aulaManager.h"

using namespace std;

AulaManager::AulaManager()
: _aulaArchivo() {
}

Aula AulaManager::crearAula() {
    int id = _aulaArchivo.getNuevoId();
    int capacidad;
    bool proyector, equipos;

    cout << "ID de aula: #" << id << endl;

    cout << "Ingrese capacidad: ";
    cin >> capacidad;

    cout << "Tiene proyector? (1=SI / 0=NO): ";
    cin >> proyector;

    cout << "Tiene equipos informaticos? (1=SI / 0=NO): ";
    cin >> equipos;

    return Aula(id, capacidad, proyector, equipos);
}

void AulaManager::guardarAula() {
    Aula aula = crearAula();
    if(_aulaArchivo.guardar(aula)) {
        cout << "Se guardo exitosamente" << endl;
    } else {
        cout << "No se pudo guardar" << endl;
    }
}

void AulaManager::listarAulas() {
    int cantidad = _aulaArchivo.getCantidadRegistros();
    for(int i = 0; i < cantidad; i++) {
        Aula aula = _aulaArchivo.leer(i);
        cout << "-----------------------" << endl;
        cout << "ID Aula: #" << aula.getIdAula() << endl;
        cout << "Capacidad: " << aula.getCapacidad() << endl;
        cout << "Proyector: ";
        if(aula.getProyector()) {
            cout << "SI";
        } else {
            cout << "NO";
        }
        cout << endl;
        cout << "Equipos informaticos: ";
        if(aula.getEquipos()) {
            cout << "SI";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
}
