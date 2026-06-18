#include <iostream>
#include "aulaMenu.h"

using namespace std;

AulaMenu::AulaMenu() {
}

void AulaMenu::mostrarOpciones() {
    cout << "---------------------" << endl;
    cout << "1. Guardar Aula" << endl;
    cout << "2. Modificar Aula" << endl;
    cout << "3. Baja Aula" << endl;
    cout << "4. Listar Aulas" << endl;
    cout << "0. Salir" << endl;
    cout << "---------------------" << endl;
}

void AulaMenu::ejecutarOpcion(int opcion) {
    switch(opcion) {
    case 1:
        _managerAula.guardarAula();
        break;
    case 2:
        /// _managerAula.modificarAula();
        break;
    case 3:
        /// _managerAula.bajaAula();
        break;
    case 4:
        _managerAula.listarAulas();
        break;
    case 0:
        cout << "Saliendo del menu!" << endl;
        break;
    default:
        cout << "Opcion incorrecta" << endl;
    }
}
