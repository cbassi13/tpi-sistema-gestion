#include <iostream>
#include "carreraMenu.h"
#include <cstdio>

using namespace std;

CarreraMenu::CarreraMenu() {
}
void CarreraMenu::mostrarOpciones() {
    cout << "---------------------" << endl;
    cout << "1. Guardar Carrera" << endl;
    cout << "2. Modificar Carrera" << endl;
    cout << "3. Baja Carrera" << endl;
    cout << "4. Listar Carreras" << endl;
    cout << "5. Buscar Carrera por ID" << endl;
    cout << "6. Buscar Carrera por nombre" << endl;
    cout << "0. Salir" << endl;
    cout << "---------------------" << endl;
}

void CarreraMenu::ejecutarOpcion(int opcion) {
    switch(opcion) {
    case 1:
        _managerCarrera.guardarCarrera();
        break;

    case 2:
        _managerCarrera.modificarCarrera();
        break;

    case 3:
        _managerCarrera.bajaCarrera();
        break;

    case 4:
        _managerCarrera.listarCarreras();
        break;

         case 5:
        _managerCarrera.buscarCarreraPorId();
        break;

         case 6:
        _managerCarrera.buscarCarreraPorNombre();
        break;


    case 0:
        cout << "Saliendo del menu!" << endl;
        break;
    }
}
