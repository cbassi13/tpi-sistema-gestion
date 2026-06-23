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

    cout << "Ingrese el ID de la Carrera: ";
    cin >> idCarrera;

    cout << "Ingrese tipo: ";
    cin.ignore();
    getline(cin, tipo);

    cout << "Ingrese porcentaje de la beca: ";
    cin >> porcentaje;

    cout << "Ingrese fecha de asignacion" << endl ;
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

        if(!beca.getEliminado()) {
            cout << "-----------------------" << endl;
            cout << "ID Beca: #" << beca.getIdBeca() << endl;
            cout << "Legajo: " << beca.getLegajo() << endl;
            cout << "Tipo: " <<beca.getTipo() << endl;
            cout << "ID de la carrera: " << beca.getIdCarrera() << endl;
            cout << "Fecha de asignacion: "
               << beca.getFechaAsignacion().getDia() << "/"
               << beca.getFechaAsignacion().getMes() << "/"
               << beca.getFechaAsignacion().getAnio() << endl;;
            cout << "Porcentaje: " << beca.getPorcentaje() << "%" << endl;

            cout << endl;
        }
    }
}

void BecaManager::modificarBeca() {
    int id;
    cout << "Ingrese ID de beca a modificar: ";
    cin >> id;

    int cantidad = _becaArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        Beca beca = _becaArchivo.leer(i);

        if (beca.getIdBeca() == id) {

            int nuevoLegajo;
            int nuevaCarrera;
            char nuevoTipo[100];
            float nuevoPorcentaje;
            Fecha nuevaFecha;

            cout << "Nuevo legajo: ";
            cin >> nuevoLegajo;

            cout << "Nuevo ID de carrera: ";
            cin >> nuevaCarrera;

            cout << "Nuevo tipo de beca: ";
            cin.ignore();
            cin.getline(nuevoTipo, 100);

            cout << "Nuevo porcentaje: ";
            cin >> nuevoPorcentaje;

            /// Cargar nueva fecha
            int dia, mes, anio;
            cout << "Nueva fecha de asignacion" <<endl;
            cout << "Dia: ";
            cin >> dia;
            cout << "Mes: ";
            cin >> mes;
            cout << "Anio: ";
            cin >> anio;

            nuevaFecha.setDia(dia);
            nuevaFecha.setMes(mes);
            nuevaFecha.setAnio(anio);

            beca.setLegajo(nuevoLegajo);
            beca.setIdCarrera(nuevaCarrera);
            beca.setTipo(nuevoTipo);
            beca.setPorcentaje(nuevoPorcentaje);
            beca.setFechaAsignacion(nuevaFecha);

            if (_becaArchivo.modificar(beca, i)) {
                cout << "Beca modificada correctamente" << endl;
            } else {
                cout << "No se modifico" << endl;
            }

            return;
        }
    }

    cout << "No se encontro la beca" << endl;
}

void BecaManager::bajaBeca(){

    int id;

    cout << "Ingrese ID de la Beca: ";
    cin >> id;

    int pos = _becaArchivo.getPosByIdBeca(id);

    if(pos == -1){
        cout << "No existe una beca con ese ID." << endl;
        return;
    }

    Beca beca = _becaArchivo.leer(pos);

    beca.setEliminado(true);

    if(_becaArchivo.modificar(beca, pos)){
        cout << "Beca dada de baja correctamente." << endl;
    }
    else{
        cout << "No se pudo realizar la baja." << endl;
    }
}
