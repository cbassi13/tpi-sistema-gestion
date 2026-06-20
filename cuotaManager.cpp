#include <iostream>
#include "cuota.h"
#include "cuotaManager.h"

using namespace std;

CuotaManager::CuotaManager()
: _cuotaArchivo() {
}

Cuota CuotaManager::crearCuota() {
    int nroCuota = _cuotaArchivo.getNuevoId();
    int legajo;
    float monto;
    int dia, mes, anio;

    cout << "ID de cuota: #" << nroCuota << endl;

    cout << "Ingrese legajo: ";
    cin >> legajo;

    cout << "Ingrese monto: ";
    cin >> monto;

   cout << "Ingrese fecha de pago (Formato dd/mm/aaaa): ";
   cin >> dia;

   cout << "/";
   cin >> mes;

   cout << "/";
   cin >> anio;

   Fecha fechaNacimiento(dia, mes, anio); Fecha fechaPago;

    return Cuota(nroCuota, legajo, monto, fechaPago);
}

void CuotaManager::guardarCuota() {
    Cuota cuota = crearCuota();
    if(_cuotaArchivo.guardar(cuota)) {
        cout << "Se guardo exitosamente" << endl;
    } else {
        cout << "No se pudo guardar" << endl;
    }
}

void CuotaManager::listarCuotas() {
    int cantidad = _cuotaArchivo.getCantidadRegistros();
    for(int i = 0; i < cantidad; i++) {
        Cuota cuota = _cuotaArchivo.leer(i);
        cout << "-----------------------" << endl;
        cout << "Nro. de Cuota: #" << cuota.getNroCuota() << endl;
        cout << "Legajo: " << cuota.getLegajo() << endl;
        cout << "Monto: " << cuota.getMonto() << endl;
        cout << "Fecha de pago: "
        << cuota.getFechaPago().getDia() << "/"
        << cuota.getFechaPago().getMes() << "/"
        << cuota.getFechaPago().getAnio() << endl;
    }

}

void CuotaManager::modificarCuota() {
    int nro;
    cout << "Ingrese nro de cuota a modificar: ";
    cin >> nro;

    int cantidad = _cuotaArchivo.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++) {
        Cuota cuota = _cuotaArchivo.leer(i);

        if (cuota.getNroCuota() == nro) {

            float nuevoMonto;
            int nuevoLegajo;

            cout << "Nuevo legajo: ";
            cin >> nuevoLegajo;

            cout << "Nuevo monto: ";
            cin >> nuevoMonto;

            cuota.setLegajo(nuevoLegajo);
            cuota.setMonto(nuevoMonto);

            if (_cuotaArchivo.modificar(cuota, i)) {
                cout << "Cuota modificada correctamente" << endl;
            } else {
                cout << "Error al modificar" << endl;
            }

            return;
        }
    }

    cout << "No se encontro la cuota" << endl;
}
