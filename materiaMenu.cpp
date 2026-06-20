#include <iostream>
#include "materiaMenu.h"

using namespace std;

MateriaMenu::MateriaMenu() {
}

void MateriaMenu::mostrarOpciones() {
    cout << "---------------------" << endl;
    cout << "1. Guardar Materia" << endl;
    cout << "2. Modificar Materia" << endl;
    cout << "3. Baja Materia" << endl;
    cout << "4. Listar Materias" << endl;
    cout << "0. Salir" << endl;
    cout << "---------------------" << endl;
}

void MateriaMenu::ejecutarOpcion(int opcion) {
    switch(opcion) {
    case 1:
        _managerMateria.guardarMateria();
        break;
    case 2:
        _managerMateria.modificarMateria();
        break;
    case 3:
        /// _managerMateria.bajaMateria();
        break;
    case 4:
        _managerMateria.listarMaterias();
        break;
    case 0:
        cout << "Saliendo del menu!" << endl;
        break;
    default:
        cout << "Opcion incorrecta" << endl;
    }
}
