#include <iostream>
#include "inscripcionesMenu.h"

using namespace std;

InscripcionMenu::InscripcionMenu() {

}

void InscripcionMenu::mostrarOpciones() {
    cout << "---------------------" << endl;
    cout << "1. Guardar Inscripcion" << endl;
    cout << "2. Modificar Inscripcion" << endl;
    cout << "3. Baja Inscripcion" << endl;
    cout << "4. Listar Inscripciones" << endl;
    cout << "0. Salir" << endl;
    cout << "---------------------" << endl;
}

void InscripcionMenu::ejecutarOpcion(int opcion) {
    switch(opcion) {

    case 1:
        _managerInscripcion.guardarInscripcion();
        break;

    case 2:
        _managerInscripcion.modificarInscripcion();
        break;

    case 3:
        _managerInscripcion.bajaInscripcion();
        break;

    case 4:
        _managerInscripcion.listarInscripciones();
        break;

    case 0:
        cout << "Saliendo del menu!" << endl;
        break;

    default:
        cout << "Opcion incorrecta" << endl;
        break;
    }
}
