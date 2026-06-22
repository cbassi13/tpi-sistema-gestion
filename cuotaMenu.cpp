#include <iostream>
#include "cuotaMenu.h"

using namespace std;

CuotaMenu::CuotaMenu() {
}

void CuotaMenu::mostrarOpciones() {
    cout << "---------------------" << endl;
    cout << "1. Guardar Cuota" << endl;
    cout << "2. Modificar Cuota" << endl;
    cout << "3. Baja Cuota" << endl;
    cout << "4. Listar Cuotas" << endl;
    cout << "5. Registrar el pago de una cuota" << endl;
    cout << "0. Salir" << endl;
    cout << "---------------------" << endl;
}

void CuotaMenu::ejecutarOpcion(int opcion) {
    switch(opcion) {
    case 1:
        _managerCuota.guardarCuota();
        break;
    case 2:
        _managerCuota.modificarCuota();
        break;
    case 3:
        _managerCuota.bajaCuota();
        break;
    case 4:
        _managerCuota.listarCuotas();
        break;
    case 5:
        _managerCuota.pagoCuota();
        break;
    case 0:
        cout << "Saliendo del menu!" << endl;
        break;
    default:
        cout << "Opcion incorrecta" << endl;
    }
}
