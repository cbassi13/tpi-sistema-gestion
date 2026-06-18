#include <iostream>
#include "menuDocente.h"
#include <cstdio>

using namespace std;

DocenteMenu::DocenteMenu() {
}

void DocenteMenu::mostrarOpciones() {
    cout << "---------------------" << endl;
    cout << "1. Guardar Docente" << endl;
    cout << "2. Modificar Docente" << endl;
    cout << "3. Baja Docente" << endl;
    cout << "4. Listar Docentes" << endl;
    cout << "0. Salir" << endl;
    cout << "---------------------" << endl;
}

void DocenteMenu::ejecutarOpcion(int opcion) {
    switch(opcion) {
    case 1:
        _managerDocente.guardarDocente();
        break;
    case 2:
        /// _managerDocente.modificarDocente();
        break;
    case 3:
        /// _managerDocente.bajaDocente();
        break;
    case 4:
        _managerDocente.listarDocentes();
        break;
    case 0:
        cout << "Saliendo del menu!" << endl;
        break;
     default:
        cout << "Opcion incorrecta" << endl;
    }
}
