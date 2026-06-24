#include <iostream>
#include "becaMenu.h"

using namespace std;

BecaMenu::BecaMenu() {
}

void BecaMenu::mostrarOpciones() {
    cout << "---------------------" << endl;
    cout << "1. Guardar Beca" << endl;
    cout << "2. Modificar Beca" << endl;
    cout << "3. Baja Beca" << endl;
    cout << "4. Listar Becas" << endl;
    cout << "5. Buscar por Legajo" <<endl;
    cout << "0. Salir" << endl;
    cout << "---------------------" << endl;
}

void BecaMenu::ejecutarOpcion(int opcion) {
    switch(opcion) {
    case 1:
        _managerBeca.guardarBeca();
        break;
    case 2:
        _managerBeca.modificarBeca();
        break;
    case 3:
        _managerBeca.bajaBeca();
        break;
    case 4:
        _managerBeca.listarBecas();
        break;
    case 5:
        _managerBeca.buscarPorLegajo();
        break;
    case 0:
        cout << "Saliendo del menu!" << endl;
        break;
    default:
        cout << "Opcion incorrecta" << endl;
    }
}
