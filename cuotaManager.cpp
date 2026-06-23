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

    int mesCorrespondiente;
    cout << "Ingrese mes correspondiente (1-12): ";
    cin >> mesCorrespondiente;

    cout << "Ingrese monto: ";
    cin >> monto;

      cout << "Ingrese fecha de pago:" << endl;
      cout << "Dia: ";
      cin >> dia;
      cout << "Mes: ";
      cin >> mes;
      cout << "Anio: ";
      cin >> anio;

   Fecha fechaPago(dia, mes, anio);

    return Cuota(nroCuota, legajo, monto, fechaPago, mesCorrespondiente);
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

      if (!cuota.getEliminado()) {
          cout << "-----------------------" << endl;
          cout << "Nro. de Cuota: #" << cuota.getNroCuota() << endl;
          cout << "Legajo: " << cuota.getLegajo() << endl;
          cout << "Monto: $" << cuota.getMonto() << endl;
          cout << "Mes correspondiente: " << cuota.getMesCorrespondiente() << endl;
          cout << "Fecha de pago: "
               << cuota.getFechaPago().getDia() << "/"
               << cuota.getFechaPago().getMes() << "/"
               << cuota.getFechaPago().getAnio() << endl;
          cout << "Pagada: " << (cuota.getPagada() ? "SI" : "NO") << endl;
      }
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
            int nuevoLegajo, nuevoMes, dia, mes, anio;

              cout << "Nuevo legajo (" << cuota.getLegajo() << "): ";
              cin >> nuevoLegajo;

              cout << "Nuevo monto (" << cuota.getMonto() << "): ";
              cin >> nuevoMonto;

              cout << "Nuevo mes correspondiente (" << cuota.getMesCorrespondiente() << "): ";
              cin >> nuevoMes;

              cout << "Nueva fecha de pago ("
                    << cuota.getFechaPago().getDia() << "/"
                    << cuota.getFechaPago().getMes() << "/"
                    << cuota.getFechaPago().getAnio() << "): " << endl;
              cout << "Dia: ";
              cin >> dia;
              cout << "Mes: ";
              cin >> mes;
              cout << "Anio: ";
              cin >> anio;

              Fecha nuevaFecha(dia, mes, anio);

              cuota.setLegajo(nuevoLegajo);
              cuota.setMonto(nuevoMonto);
              cuota.setMesCorrespondiente(nuevoMes);
              cuota.setFechaPago(nuevaFecha);

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

///--------------------REGISTRAR EL PAGO CUOTA-----------------------

void CuotaManager::pagoCuota(){

    int id;

    cout << "Ingrese Numero de la Cuota: ";
    cin >> id;

    int pos = _cuotaArchivo.getPosByIdCuota(id);

    if(pos == -1){
        cout << "No existe una cuota con ese Nro. ID." << endl;
        return;
    }

    Cuota cuota = _cuotaArchivo.leer(pos);

    cuota.setPagada(true);

    if(_cuotaArchivo.modificar(cuota, pos)){
        cout << "El pago se registró correctamente." << endl;
    }
    else{
        cout << "No se pudo registrar el pago." << endl;
    }
}

///--------------------BAJA CUOTA-----------------------

void CuotaManager::bajaCuota(){

    int id;

    cout << "Ingrese ID de la Cuota: ";
    cin >> id;

    int pos = _cuotaArchivo.getPosByIdCuota(id);

    if(pos == -1){
        cout << "No existe una cuota con ese ID." << endl;
        return;
    }

    Cuota cuota = _cuotaArchivo.leer(pos);

    cuota.setEliminado(true);

    if(_cuotaArchivo.modificar(cuota, pos)){
        cout << "Cuota dada de baja correctamente." << endl;
    }
    else{
        cout << "No se pudo realizar la baja." << endl;
    }
}

///-------------LISTAR PAGOS POR ALUMNO-------------------

void CuotaManager::listarPagosPorAlumno() {

    int legajo;
    bool encontrado = false;

    cout << "Ingrese legajo del alumno: ";
    cin >> legajo;

    int cantidad = _cuotaArchivo.getCantidadRegistros();

    for(int i = 0; i < cantidad; i++) {

        Cuota cuota = _cuotaArchivo.leer(i);

        if(cuota.getEliminado() == false) {

            if(cuota.getPagada() == true && cuota.getLegajo() == legajo) {

                cout << "-----------------------" << endl;
                cout << "Legajo: " << cuota.getLegajo() << endl;
                cout << "Nro. Cuota: #" << cuota.getNroCuota() << endl;
                cout << "Monto: $" << cuota.getMonto() << endl;
                cout << "Mes Correspondiente: " << cuota.getMesCorrespondiente() << endl;

                cout << "Fecha de Pago: "
                     << cuota.getFechaPago().getDia() << "/"
                     << cuota.getFechaPago().getMes() << "/"
                     << cuota.getFechaPago().getAnio() << endl;

                encontrado = true;
            }
        }
    }

    if(encontrado == false) {
        cout << "No hay pagos registrados." << endl;
    }
}
